%{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"
  #include "hashtab/hashtab.h"
  #include <stdlib.h>

  int reg = 0;
  Hashtab *htab;
  char **regtoid;

  void idCopy(char * src, char *dest){
    int i = 0;
    while (src[i] != '\0' && src[i] != ' ' && src[i] != '=' && src[i] != '(' && src[i] != '\n'){
      dest[i]=src[i];
      i++;
    }
    dest[i] = '\0';
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
    exit(1);
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
  float flottant;
  struct mix{int nombre;
  char *chaine;
}mix;}
%type <mix> expr multiplicative_expr additive_expr primary lhs comp_expr
%type <nombre> INT BOOL
%type <chaine> ID STRING
%type <flottant> FLOAT
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

stmt		: IF expr THEN stmts terms END
                | IF expr THEN stmts terms ELSE stmts terms END 
                | FOR ID IN expr TO expr term stmts terms END
                | WHILE expr DO term stmts terms END 
| lhs '=' expr
{
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
  printf("\%r%d = fadd float 0.0, %f\n", reg, $1); 
  reg++;}
| INT
{$$.nombre = reg; 
  $$.chaine = malloc(4*sizeof(char));
  $$.chaine = "int";
  printf("\%r%d = add i32 0, %d\n", reg, $1); 
  reg++;}
| BOOL
{$$.nombre = reg; 
  $$.chaine = malloc(5*sizeof(char));
  $$.chaine = "bool";
  printf("\%r%d = add i1 0, %d\n", reg, $1); 
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
  printf("\%r%d = icmp ult i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  reg++;
  }
| additive_expr '>' additive_expr
                | additive_expr LEQ additive_expr
                | additive_expr GEQ additive_expr
                | additive_expr EQ additive_expr
                | additive_expr NEQ additive_expr
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
      printf("\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    $$.chaine = malloc(6*sizeof(char));
    $$.chaine = "float"; 
    printf("\%r%d = fadd float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else if(strcmp($1.chaine, "bool")==0 && strcmp($3.chaine, "bool")==0){
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "bool";
    printf("\%r%d = or i1 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else if(strcmp($1.chaine, "bool")==0 ||  strcmp($3.chaine, "bool")==0){
    error("addition d'un booleen avec un autre type");
  }
  else{
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "int"; 
    printf("\%r%d = add i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre); 
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
      printf("\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    $$.chaine = malloc(6*sizeof(char));
    $$.chaine = "float"; 
    printf("\%r%d = fsub float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "int"; 
    printf("\%r%d = sub i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre); 
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
      printf("\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    $$.chaine = malloc(6*sizeof(char));
    $$.chaine = "float"; 
    printf("\%r%d = fmul float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else if(strcmp($1.chaine, "bool")==0 && strcmp($3.chaine, "bool")==0){
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "bool";
    printf("\%r%d = and i1 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else if(strcmp($1.chaine, "bool")==0 ||  strcmp($3.chaine, "bool")==0){
    error("multiplication d'un booleen avec un autre type");
  }
  else{
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "int"; 
    printf("\%r%d = mul i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre); 
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
      printf("\%r%d = sitofp i32 \%r%d to float\n",$1.nombre, ntemp);
    }
    if(strcmp($3.chaine, "int")==0){
      int ntemp = $3.nombre;
      $3.nombre = reg;
      reg++;
      printf("\%r%d = sitofp i32 \%r%d to float\n",$3.nombre, ntemp);
    }
    $$.chaine = malloc(6*sizeof(char));
    $$.chaine = "float"; 
    printf("\%r%d = fdiv float \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre);
  }
  else{
    $$.chaine = malloc(4*sizeof(char));
    $$.chaine = "int"; 
    printf("\%r%d = sdiv i32 \%r%d, \%r%d\n",reg, $1.nombre, $3.nombre); 
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
  regtoid = malloc(10000*sizeof(char*));

  print_begin();
  yyparse(); 
  print_end();

  hashtab_delete(htab);
  return 0;
}
