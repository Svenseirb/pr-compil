%{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"
  #include "hashtab/hashtab.h"
  #include "stack/stack.h"
  #include "parse.h"
  #include <stdlib.h>

  int reg = 0;
  Hashtab *htab;
  char **regtoid;
  char *buff;
  int curFlow;
  Stack **flowStack;
  Flow flow;

  void idCopy(char * src, char *dest){
    int i = 0;
    while (src[i] != '\0' && src[i] != ' ' && src[i] != '=' && src[i] != '(' && src[i] != '\n'){
      dest[i]=src[i];
      i++;
    }
    dest[i] = '\0';
  }

  void flush(){
    printf("%s", buff);
    buff[0] = '\0';
  }

  int len_string = 0;

  void clean_string(char * s)
  {
    int i;
    int len = strlen(s);
    for (i = 0; i < len - 1; i++)
      {
	s[i] = s[i + 1];
      }
    s[len-2] = '\0';
  }

  void error(char *msg){
    int len = strlen(msg) + 11;
    char *errmsg = malloc(len*sizeof(char));
    strcpy(errmsg, "erreur : ");
    strcat(errmsg, msg);
    strcat(errmsg, "\n");
    write(2, errmsg, len);
    exit(EXIT_FAILURE);
  }

%}
%token AND OR CLASS IF THEN ELSE END WHILE DO DEF LEQ GEQ 
%token STRING FLOAT INT ID BOOL FOR TO RETURN IN NEQ
%left '*' 
%left '/'
%left '+' '-'
%left '<' '>' LEQ GEQ EQ
%left AND OR
%union{
  int nombre;
  char *chaine;
  float flotant;
  struct mix{int nombre;
  char *chaine;
}mix;}
%type <mix> expr multiplicative_expr additive_expr primary lhs comp_expr
%type <nombre> INT BOOL
%type <chaine> ID STRING
%type <flotant> FLOAT
%%
program		:  topstmts opt_terms
;
topstmts        :      
| topstmt
| topstmts terms topstmt
;
topstmt	        : CLASS ID term stmts END 
                | CLASS ID '<' ID term stmts END
                | stmt
;

stmts	        : /* none */
                | stmt
                | stmts terms stmt
                ;

then            : THEN

{ 
  flush();
  flow.haselse = 0;
  flow.id = curFlow;
  push(flowStack, flow);
  printf("br i1 \%r%d, label %cift%d, label %cifnt%d\n", reg-1, '%',curFlow,'%',curFlow);
  printf("ift%d:\n", curFlow);
  curFlow++;
}
;

end             : END
{   
  flow = pop(flowStack);
  flush();
  if(flow.haselse == 0){
    printf("ifnt%d:\n",flow.id);
  }
  else{
    printf("ifend%d:\n",flow.id);
  }
}
;

else            : ELSE
{
  flow = pop(flowStack);
  flush();
  printf("br i1 1, label %cifend%d, label %cifnt%d\n", '%',flow.id, '%', flow.id);
  printf("ifnt%d:\n",flow.id);
  flow.haselse = 1;
  push(flowStack, flow);
}
  


stmt		: 
IF expr then stmts terms end
{
  }

                | IF expr then stmts terms else stmts terms end 
                | FOR ID IN expr TO expr term stmts terms END
                | WHILE expr DO term stmts terms END 
| lhs '=' expr
{
  flush();
  int tmpreg;
  tmpreg = hashtab_getreg(htab, $1.chaine);
  if(tmpreg != -1){
    if(strcmp(hashtab_gettype(htab, $1.chaine),$3.chaine) !=0){
      error("Mauvais type assigne a la variable");
    }
    free(regtoid[tmpreg]);
  }
  else{ 
    hashtab_addtype(htab,$1.chaine, $3.chaine); 
  }
  hashtab_addreg(htab,$1.chaine,reg-1); 
  regtoid[reg-1]=strdup($1.chaine);
  }
                | RETURN expr
                | DEF ID opt_params term stmts terms END
; 

opt_params      : /* none */
                | '(' ')'
                | '(' params ')'
;
params          : ID ',' params
                | ID
; 
lhs             : ID
{
$$.chaine = malloc(strlen($1)*sizeof(char));  
idCopy($1, $$.chaine);}
                | ID '.' primary
                | ID '(' exprs ')'
;
exprs           : exprs ',' expr
                | expr
;


primary         : lhs
{
  idCopy($1.chaine, $1.chaine);
  $$.nombre = hashtab_getreg(htab,$1.chaine);
  $$.chaine = hashtab_gettype(htab,$1.chaine);
  if($$.nombre == -1){
    error("utilisation d'un variable non initialisee");
  }
}
                | STRING
{/*$$.nombre = reg; clean_string((char *)$1); len_string = strlen((char *)$1) + 1; printf("\%r%d = internal constant [%d x i8] c\"%s\\00\"\n", reg, len_string, (char *)$1); reg++;*/} 
| FLOAT
{$$.nombre = reg;
  $$.chaine = malloc(6*sizeof(char));
  $$.chaine = "float"; 
  sprintf(&buff[strlen(buff)],"\%r%d = fadd float 0.0, %f\n", reg, $1); 
  reg++;}
| INT
{$$.nombre = reg; 
  $$.chaine = malloc(4*sizeof(char));
  $$.chaine = "int";
  sprintf(&buff[strlen(buff)],"\%r%d = add i32 0, %d\n", reg, $1); 
  reg++;}
| BOOL
{$$.nombre = reg; 
  $$.chaine = malloc(5*sizeof(char));
  $$.chaine = "bool";
  sprintf(&buff[strlen(buff)],"\%r%d = add i1 0, %d\n", reg, $1); 
  reg++;}
| '(' expr ')'
;


expr            : expr AND comp_expr
                | expr OR comp_expr
                | comp_expr
;


comp_expr       : additive_expr '<' additive_expr
{  
  $$.nombre = reg;
  $$.chaine = malloc(5*sizeof(char));
  $$.chaine = "bool";
  if(strcmp($1.chaine, "float") == 0 || strcmp($1.chaine, "float") == 0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
   sprintf(&buff[strlen(buff)],"\%r%d = fcmp olt float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    sprintf(&buff[strlen(buff)],"\%r%d = icmp slt i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  reg++;
}

| additive_expr '>' additive_expr
{  
  $$.nombre = reg;
  $$.chaine = malloc(5*sizeof(char));
  $$.chaine = "bool";
  if(strcmp($1.chaine, "float") == 0 || strcmp($1.chaine, "float") == 0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    sprintf(&buff[strlen(buff)],"\%r%d = fcmp ogt float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    sprintf(&buff[strlen(buff)],"\%r%d = icmp sgt i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  reg++;
}

| additive_expr LEQ additive_expr
{  
  $$.nombre = reg;
  $$.chaine = malloc(5*sizeof(char));
  $$.chaine = "bool";
  if(strcmp($1.chaine, "float") == 0 || strcmp($1.chaine, "float") == 0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    sprintf(&buff[strlen(buff)],"\%r%d = fcmp ole float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    sprintf(&buff[strlen(buff)],"\%r%d = icmp sle i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  reg++;
}

| additive_expr GEQ additive_expr
{  
  $$.nombre = reg;
  $$.chaine = malloc(5*sizeof(char));
  $$.chaine = "bool";
  if(strcmp($1.chaine, "float") == 0 || strcmp($1.chaine, "float") == 0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    sprintf(&buff[strlen(buff)],"\%r%d = fcmp oge float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    sprintf(&buff[strlen(buff)],"\%r%d = icmp sge i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  reg++;
}


| additive_expr EQ additive_expr
{  
  $$.nombre = reg;
  $$.chaine = malloc(5*sizeof(char));
  $$.chaine = "bool";
  if(strcmp($1.chaine, "float") == 0 || strcmp($1.chaine, "float") == 0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    sprintf(&buff[strlen(buff)],"\%r%d = fcmp oeq float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    sprintf(&buff[strlen(buff)],"\%r%d = icmp eq i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  reg++;
}


| additive_expr NEQ additive_expr
{  
  $$.nombre = reg;
  $$.chaine = malloc(5*sizeof(char));
  $$.chaine = "bool";
  if(strcmp($1.chaine, "float") == 0 || strcmp($1.chaine, "float") == 0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    sprintf(&buff[strlen(buff)],"\%r%d = fcmp one float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    sprintf(&buff[strlen(buff)],"\%r%d = icmp ne i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  reg++;
}

| additive_expr
;

additive_expr   : 
multiplicative_expr {}

| additive_expr '+' multiplicative_expr 
{
  $$.nombre = reg;
  if(strcmp($1.chaine, "float")==0 || strcmp($3.chaine, "float")==0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    $$.chaine = malloc(6*sizeof(char));
    $$.chaine = "float"; 
    sprintf(&buff[strlen(buff)],"\%r%d = fadd float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else if(strcmp($1.chaine, "bool")==0 && strcmp($3.chaine, "bool")==0){
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "bool";
    sprintf(&buff[strlen(buff)],"\%r%d = or i1 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else if(strcmp($1.chaine, "bool")==0 ||  strcmp($3.chaine, "bool")==0){
    error("addition d'un booleen avec un autre type");
  }
  else{
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "int"; 
    sprintf(&buff[strlen(buff)],"\%r%d = add i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre); 
  }
  reg++;
}

| additive_expr '-' multiplicative_expr 
{
  $$.nombre = reg; 
  if(strcmp($1.chaine, "float")==0 || strcmp($3.chaine, "float")==0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    $$.chaine = malloc(6*sizeof(char));
    $$.chaine = "float"; 
    sprintf(&buff[strlen(buff)],"\%r%d = fsub float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "int"; 
    sprintf(&buff[strlen(buff)],"\%r%d = sub i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre); 
  }
  reg++;
}
;


multiplicative_expr : 
multiplicative_expr '*' primary
{
  $$.nombre = reg; 
  if(strcmp($1.chaine, "float")==0 || strcmp($3.chaine, "float")==0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    $$.chaine = malloc(6*sizeof(char));
    $$.chaine = "float"; 
    sprintf(&buff[strlen(buff)],"\%r%d = fmul float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else if(strcmp($1.chaine, "bool")==0 && strcmp($3.chaine, "bool")==0){
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "bool";
    sprintf(&buff[strlen(buff)],"\%r%d = and i1 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else if(strcmp($1.chaine, "bool")==0 ||  strcmp($3.chaine, "bool")==0){
    error("multiplication d'un booleen avec un autre type");
  }
  else{
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "int"; 
    sprintf(&buff[strlen(buff)],"\%r%d = mul i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre); 
  }
  reg++;
}

| multiplicative_expr '/' primary
{
  $$.nombre = reg; 
  if(strcmp($1.chaine, "float")==0 || strcmp($3.chaine, "float")==0){
    if(strcmp($1.chaine, "int")==0){
      int ntemp = $1.nombre;
      $1.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      sprintf(&buff[strlen(buff)],"\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    $$.chaine = malloc(6*sizeof(char));
    $$.chaine = "float"; 
    sprintf(&buff[strlen(buff)],"\%r%d = fdiv float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "int"; 
    sprintf(&buff[strlen(buff)],"\%r%d = sdiv i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre); 
  }
  reg++;
}

| primary 
{$$ = $1;}
;


opt_terms	: /* none */
		| terms
		;

terms		: terms ';'
                | terms '\n'
		| ';'
                | '\n'
		;

term            : ';'
                | '\n'
;


%%

void print_begin() {
        puts("@str = constant [ 7 x i8 ] c\"=> %d\\0A\\00\"");
        puts("declare i32 @printf(i8*, ...)\n");
        puts("define i1 @calcule() {");
}

void print_end() {
	printf("ret i1 \%r%d\n", reg-1);
        puts("}\n");
        puts("define i32 @main() {");
        puts("\t%x = call i1 @calcule()");
        puts("\tcall i32 (i8*, ...)* @printf(i8* getelementptr ([7 x i8]* @str, i32 0, i32 0), i1 %x)");
        puts("\tret i32 0\n}");
}

int main() {
  htab = hashtab_create();
  regtoid = malloc(4096*sizeof(char*));
  buff = malloc(16384*sizeof(char));
  flowStack = malloc(sizeof(Stack*));
  stack_create(flowStack);

  print_begin();
  yyparse(); 
  print_end();

  free(flowStack);
  free(regtoid);
  free(buff);
  hashtab_delete(htab);
  return 0;
}
