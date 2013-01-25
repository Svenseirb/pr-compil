#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtab.h"

Hashtab *hashtab_create_taille(int size){
  int i;
  Hashtab *htab = malloc(sizeof(Hashtab));
  htab->tab = malloc(size*sizeof(Cell));
  for(i=0; i<size; i++){
    htab->tab[i].reg = -1;
    htab->tab[i].type = NULL;
  }
  htab->tmax = size;
  htab->taille = 0;
  return htab;
}

Hashtab *hashtab_create(){
  return hashtab_create_taille(256);
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
    code = code + c*pow(7,i);
    i++;
    c = id[i];
  }
  return code;
}

void hashtab_addreg(Hashtab *htab, char *id, int reg){
  int code = hash(id);
  code = abs(code);
  code %= htab->tmax;
  if(htab->tab[code].reg ==-1){
    htab->taille++;
  }
  htab->tab[code].reg = reg;
}

int hashtab_getreg(Hashtab *htab, char *id){
  int code = hash(id);
  code = abs(code);
  code %= htab->tmax;
  return htab->tab[code].reg;
}

void hashtab_addtype(Hashtab *htab, char *id, char *type){
  int code = hash(id);
  code = abs(code);
  code %= htab->tmax;
  htab->tab[code].type = strdup(type);
}

char* hashtab_gettype(Hashtab *htab, char *id){
  int code = hash(id);
  char *type;
  code = abs(code);
  code %= htab->tmax;
  type = strdup(htab->tab[code].type);
  return type;
}
