#include <stdio.h>
#include "singly_linked_list.h"

const char *instructions = "\
1. Insert front\n\
2. Insert back\n\
3. Insert At\n\
4. Delete front\n\
5. Delete back\n\
6. Delete At\n\
7. Search list\n\
8. Display list\n\
9. Exit";

int main() {
  int choice = 1;
  SL_LIST list;

  sll_init_list(&list);

  while (choice) {
    int ec, element, index;
    printf("\n%s\n> ", instructions);
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element: ");
        scanf("%d", &element);
        sll_insert_front(&list, element);
        break;

      case 2:
        printf("Enter the element: ");
        scanf("%d", &element);
        sll_insert_back(&list, element);
        break;

      case 3:
        printf("Enter the element: ");
        scanf("%d", &element);
        printf("Enter index: ");
        scanf("%d", &index);
        sll_insert_at(&list, element, index);
        break;

      case 4:
        ec = sll_delete_front(&list, &element);
        if (ec == 0)
          printf("%d deleted\n", element);
        else
          printf("List is empty\n");
        break;

      case 5:
        ec = sll_delete_back(&list, &element);
        if (ec == 0)
          printf("%d deleted\n", element);
        else
          printf("List is empty\n");
        break;

      case 6:
        printf("Enter index: ");
        scanf("%d", &index);
        ec = sll_delete_at(&list, &element, index);
        if (ec == 0)
          printf("%d deleted\n", element);
        else
          printf("List is empty\n");
        break;

      case 7:
        printf("Enter element: ");
        scanf("%d", & element);
        ec = sll_search_list(&list, element);
        if (ec)
          printf("Element found\n");
        else
          printf("Element not found\n");
        break;

      case 8:
        sll_display_list(&list);
        break;

      case 9:
        choice = 0;
        break;

      default:
        choice = 1;
        break;
    }

    printf("List size: %d\n", list.size);
  }

  sll_free_list(&list);
  return 0;
}
