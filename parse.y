%{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"

  int reg = 0;
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

%}
%token AND OR CLASS IF THEN ELSE END WHILE DO DEF LEQ GEQ 
%token STRING FLOAT INT ID BOOL FOR TO RETURN IN NEQ
%left '*' 
%left '/'
%left '+' '-'
%left '<' '>' LEQ GEQ EQ
%left AND OR
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
                | ID '.' primary
                | ID '(' exprs ')'
;
exprs           : exprs ',' expr
                | expr
;
primary         : lhs
                | STRING
{$$ = reg; clean_string((char *)$1); len_string = strlen((char *)$1) + 1; printf("\%r%d = internal constant [%d x i8] c\"%s\\00\"\n", reg, len_string, (char *)$1); reg++;} 
                | FLOAT
{$$ = reg; printf("\%r%d = fadd i32 0.0, %f\n", reg, $1); reg++;}
                | INT
{$$ = reg; printf("\%r%d = add i32 0, %d\n", reg, $1); reg++;}
                | BOOL
{$$ = reg; printf("\%r%d = add i32 0, %d\n", reg, $1); reg++;}
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
{$$ = reg; printf("\%r%d = add i32 \%r%d, \%r%d\n",reg, (int)$1, (int)$3); reg++;}
| additive_expr '-' multiplicative_expr 
{$$ = reg; printf("\%r%d = sub i32 \%r%d, \%r%d\n",reg, (int)$1, (int)$3); reg++;}
;
multiplicative_expr : 
multiplicative_expr '*' primary
{$$ = reg; printf("\%r%d = mul i32 \%r%d, \%r%d\n",reg, $1, $3); reg++;}
| multiplicative_expr '/' primary
{$$ = reg; printf("\%r%d = udiv i32 \%r%d, \%r%d\n",reg, $1, $3); reg++;}
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
  yyparse(); 
  return 0;
}
