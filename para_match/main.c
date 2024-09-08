#include <stdio.h>
#include "stack.h"

#define MAX_STRING_LENGTH 100

int check_balance_parentheses(const char *str);

int main() {
  char str[MAX_STRING_LENGTH];
  scanf("%[^\n]s", str);

  if (check_balance_parentheses(str))
    printf("Balanced\n");
  else
    printf("Not balanced\n");

  return 0;
}

int check_balance_parentheses(const char *str) {
  STACK s;
  stack_init(&s);
  int element;

  for (int i=0; str[i]; i++) {
    switch (str[i]) {
      case '(':
      case '{':
      case '[':
        stack_push(&s, str[i]);
        break;
      case ')':
      case '}':
      case ']':
        if (stack_is_empty(&s))
          return 0;

        stack_pop(&s, &element);
        if (str[i] == ')' && element != '(')
          return 0;
        else if (str[i] == '}' && element != '{')
          return 0;
        else if (str[i] == ']' && element != '[')
          return 0;
        break;
    }
  }

  return stack_is_empty(&s);
}
