#include <stdio.h>
#include <limits.h>
#include "arraylist.h"

const char *instructions = "\
1. Insert at end\n\
2. Delete at end\n\
3. Display list\n\
4. Exit\n";

int main() {
  int choice = 1;
  ArrayList list;

  init_array(&list);

  while (choice) {
    int element;
    int ec;
    printf("\n%s\n> ", instructions);
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the element: ");
      scanf("%d", &element);
      ec = insert_at_end(&list, element);
      if (ec != 0)
        printf("List is full\n");
      break;

    case 2:
      ec = delete_at_end(&list, &element);
      if (ec == 0)
        printf("%d deleted\n", element);
      else
        printf("List is empty\n");
      break;

    case 3:
      display_array(&list);
      break;

    case 4:
      choice = 0;
      break;

    default:
      choice = 1;
      break;
    }
  }
  return 0;
}
