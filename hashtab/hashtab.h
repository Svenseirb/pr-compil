typedef struct Cell{
  int reg;
  char *type;
}Cell;


typedef struct Hashtab{
  Cell *tab;
  int tmax;
  int taille;
}Hashtab;


Hashtab *hashtab_create_taille(int size);
Hashtab *hashtab_create();
void hashtab_delete(Hashtab *htab);
void hashtab_addreg(Hashtab *htab, char *id, int reg);
int hashtab_getreg(Hashtab *htab, char *id);
void hashtab_addtype(Hashtab *htab, char *id, char *type);
char* hashtab_gettype(Hashtab *htab, char *id);
