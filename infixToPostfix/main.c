#include <stdio.h>
#include <ctype.h>
#include "stack.h"

#define MAX_EXP_LENGTH 100

int infixToPostfix(char infix[MAX_EXP_LENGTH], char postfix[MAX_EXP_LENGTH]);
int prcd(char st, char in);

int main() {
  char exp[MAX_EXP_LENGTH];
  char result[MAX_EXP_LENGTH];

  printf("Enter infix expression: ");
  scanf("%s", exp);

  infixToPostfix(exp, result);

  printf("Postfix expression: %s", result);
  return 0;
}

int infixToPostfix(char infix[MAX_EXP_LENGTH], char postfix[MAX_EXP_LENGTH]) {
  int write_head = 0;
  STACK s;
  int e;
  stack_init(&s);

  for (int i=0; infix[i]; i++) {
    if (isdigit(infix[i])) {
      postfix[write_head++] = infix[i];
    }
    else {
      while (!stack_is_empty(&s) && prcd(stack_peek(&s, &e), infix[i])) {
        stack_pop(&s, &e);
        postfix[write_head++] = e;
      }

      if (infix[i] == ')') {
        stack_pop(&s, &e);
      }
      else if (infix[i] != '(') {
        stack_push(&s, infix[i]);
      }

    }
  }

  while (!stack_is_empty(&s)) {
    stack_pop(&s, &e);
    postfix[write_head++] = e;
  }

  postfix[write_head] = 0;
  return 0;
}

int prcd(char st, char in) {
  switch (in) {
    case '+':
    case '-':
      if (st == '(')
        return 0;
      else
        return 1;

    case '*':
    case '/':
      if (st == '+' || st == '-' || st == '(')
        return 0;
      else
        return 1;

    case '(':
      return 0;

    case ')':
      if (st == '(')
        return 0;
      else
        return 1;
  }

  return 0;
}
