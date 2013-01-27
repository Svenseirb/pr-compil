typedef struct Flow{
  int id;
  int type;
  int reg;
}Flow;


typedef struct Stack{
  Flow val;
  struct Stack* next;
}Stack;


void push(Stack** head, Flow value);
void stack_create(Stack **head);
Flow pop(Stack **head);
Flow top(Stack **head);
