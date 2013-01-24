%{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"
  #include "hashtab/hashtab.h"

  int reg = 0;
  Hashtab *htab;
  char **regtoid;

  void idCopy(char * src, char *dest){
    int i = 0;
    while (src[i] != '\0' && src[i] != ' ' && src[i] != '=' && src[i] != '('){
      dest[i]=src[i];
      i++;
    }
    dest[i] = '\0';
  }


%}
%token AND OR CLASS IF THEN ELSE END WHILE DO DEF LEQ GEQ 
%token STRING FLOAT INT ID FOR TO RETURN IN NEQ
%left '*' 
%left '/'
%left '+' '-'
%left '<' '>' LEQ GEQ EQ
%left AND OR
%union{
  int nombre;
  char *chaine;
  struct mix{int nombre;
  char *chaine;
}mix;}
%type <mix> expr multiplicative_expr additive_expr primary lhs
%type <nombre> INT
%type <chaine> ID
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
{printf("variable %s associee au registre r", $1.chaine);
  hashtab_add(htab,$1.chaine,reg-1); 
  printf("%d\n", hashtab_get(htab,$1.chaine));
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
{$$.chaine = malloc(strlen($1)*sizeof(char));  idCopy($1, $$.chaine); printf("%s\n", $$.chaine);}
                | ID '.' primary
                | ID '(' exprs ')'
;
exprs           : exprs ',' expr
                | expr
;
primary         : lhs
                | STRING 
                | FLOAT
                | INT
{$$.nombre = reg; printf("\%r%d = add i32 0, %d\n", reg, $1); reg++;}
                | '(' expr ')'
;
expr            : expr AND comp_expr
                | expr OR comp_expr
                | comp_expr
;
comp_expr       : additive_expr '<' additive_expr
                | additive_expr '>' additive_expr
                | additive_expr LEQ additive_expr
                | additive_expr GEQ additive_expr
                | additive_expr EQ additive_expr
                | additive_expr NEQ additive_expr
                | additive_expr
;
additive_expr   : 
multiplicative_expr {$$ = $1;}
| additive_expr '+' multiplicative_expr 
{$$.nombre = reg; printf("\%r%d = add i32 \%r%d, \%r%d\n",reg, $1, $3); reg++;}
| additive_expr '-' multiplicative_expr 
{$$.nombre = reg; printf("\%r%d = sub i32 \%r%d, \%r%d\n",reg, $1, $3); reg++;}
;
multiplicative_expr : 
multiplicative_expr '*' primary
{$$.nombre = reg; printf("\%r%d = mul i32 \%r%d, \%r%d\n",reg, $1, $3); reg++;}
| multiplicative_expr '/' primary
{$$.nombre = reg; printf("\%r%d = udiv i32 \%r%d, \%r%d\n",reg, $1, $3); reg++;}
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
int main() {
  htab = hashtab_create();
  regtoid = malloc(10000*sizeof(char*));
  yyparse(); 
  hashtab_delete(htab);
  return 0;
}
