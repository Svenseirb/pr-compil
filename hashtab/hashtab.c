#include <stdlib.h>
#include <stdio.h>

typedef struct Hashtab{
  int *tab;
  int tmax;
  int taille;
}Hashtab;

Hashtab *hashtab_create_taille(int size){
  int i;
  Hashtab *htab = malloc(sizeof(Hashtab));
  htab->tab = malloc(size*sizeof(int));
  for(i=0; i<size; i++){
    htab->tab[i] = -1;
  }
  htab->tmax = size;
  htab->taille = 0;
  return htab;
}

Hashtab *hashtab_create(){
  return *hashtab_create_taille(256);
}

 void hashtab_delete(Hashtab *htab){
  free(htab->tab);
  free(htab);
}

int pow(int a,int b){
  int res = 1, i;
  for(i = 0; i<b; i++)
    res = res*a;
  return res;
}

int abs(int a){
  if(a < 0)
    return -a;
  return a;
}

int hash(char *id){
  char c;
  int code = 0, i = 0;
  c = *id;
  while(c != '\0'){
    code = code + c*pow(31,i);
    i++;
    c = id[i];
  }
  return code;
}

void hashtab_add(Hashtab *htab, char *id, int reg){
  int code = hash(id);
  code = abs(code);
  code %= htab->tmax;
  if(htab->tab[code]==-1){
    htab->taille++;
    htab->tab[code] = reg;
  }
}

int hashtab_get(Hashtab *htab, char *id){
  int code = hash(id);
  code = abs(code);
  code %= htab->tmax;
  return htab->tab[code];
}

int main(){
  printf("%d, %d, %d\n", hash("bla"), hash("alb"), hash("identfiant_random"));
  Hashtab *htab = hashtab_create();
  hashtab_add(htab, "bla", 1);
  hashtab_add(htab, "bal", 2);
  hashtab_add(htab, "lab", 3);
  hashtab_add(htab, "identfiant_random_tres_tres_long_qui_prend_beaucoup_de_place_et_qui_risque_de_faire_bugger_la_table_de_hachage_et_qui_nezldazldkjzldjehldehflehldjzljdilzidlefliezfsdfjzeljdlzejlezjfelqhfehqlfkheqkllfhlekjhfqjehsflkheqkjfhekjqhflekjqemqfsldsfqjesdlfkjmqeslkfjmqeislmdfjmilesmdmlsdnmfnqesdkjfrsjdfneqsfdcjeqbfkqr", 4);
  printf("%d, %d, %d, %d \n", hashtab_get(htab, "bla"), hashtab_get(htab, "bal"), hashtab_get(htab, "lab"), hashtab_get(htab, "identfiant_random_tres_tres_long_qui_prend_beaucoup_de_place_et_qui_risque_de_faire_bugger_la_table_de_hachage_et_qui_nezldazldkjzldjehldehflehldjzljdilzidlefliezfsdfjzeljdlzejlezjfelqhfehqlfkheqkllfhlekjhfqjehsflkheqkjfhekjqhflekjqemqfsldsfqjesdlfkjmqeslkfjmqeislmdfjmilesmdmlsdnmfnqesdkjfrsjdfneqsfdcjeqbfkqr"));
  hashtab_delete(htab);
  return 0;
}
