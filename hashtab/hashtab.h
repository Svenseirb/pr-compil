
typedef struct Hashtab{
  int *tab;
  int tmax;
  int taille;
}Hashtab;


Hashtab *hashtab_create_taille(int size);
Hashtab *hashtab_create();
void hashtab_delete(Hashtab *htab);
void hashtab_add(Hashtab *htab, char *id, int reg);
int hashtab_get(Hashtab *htab, char *id);
