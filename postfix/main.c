#include "stack.h"
#include <stdio.h>
#include <ctype.h>
#define MAX 100

int postfixEval(char *exp);

int main() {
  char exp[MAX];
  printf("Enter valid postifx expression:");
  scanf("%[^\n]s", exp);
  printf("%d", postfixEval(exp));

  return 0;
}

int postfixEval(char *exp) {
  STACK s;
  stack_init(&s);

  int op1, op2, res;

  for (int i=0; exp[i]; i++) {
    if (isdigit(exp[i]))
      stack_push(&s, exp[i] - '0');
    else {
      stack_pop(&s, &op2);
      stack_pop(&s, &op1);

      switch(exp[i]) {
        case '+':
          res = op2 + op1;
          break;
        case '-':
          res = op2 - op1;
          break;
        case '*':
          res = op2 * op1;
          break;
        case '/':
          res = op2 / op1;
          break;
      }

      stack_push(&s, res);
    }
  }

  stack_pop(&s, &res);
  return res;
}
