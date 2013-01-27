#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(Stack** head, Flow value){
  Stack* node = malloc(sizeof(Stack));
  if (node == NULL){
    write(2, "Stack overflow\n", 17);
    exit(EXIT_FAILURE);
  } 
  node->val = value;
  node->next = *head;
  *head = node;
}

void stack_create(Stack **head){
  Flow flow;
  flow.id = -1;
  push(head, flow);
}

Flow pop(Stack **head){
  if(isEmpty(*head)){
    write(2, "Stack underflow\n", 17);
    exit(EXIT_FAILURE);
  }
  Stack *top = *head;
  Flow value = top->val;
  *head = top->next;
  free(top);
  return value;
}

Flow top(Stack **head){
  return (*head)->val;
}

int isEmpty(Stack *head){
  return head->val.id == -1;
}

int main(){
  Stack **st=malloc(sizeof(Stack*));
  stack_create(st);
  Flow flow;
  flow.id = 0;
  flow.type = 3;
  flow.reg = 4;
  push(st, flow);
  flow.reg = 5;
  push(st, flow);
  flow = pop(st);
  printf("%d\n", flow.reg);
  flow = pop(st);
  printf("%d\n", flow.reg);
  return 0;
}
