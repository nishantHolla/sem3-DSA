#include <stdio.h>
#include "doubly_linked_list.h"

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
  DL_LIST list;

  dll_init_list(&list);

  while (choice) {
    int ec, element, index;
    printf("\n%s\n> ", instructions);
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element: ");
        scanf("%d", &element);
        dll_insert_front(&list, element);
        break;

      case 2:
        printf("Enter the element: ");
        scanf("%d", &element);
        dll_insert_back(&list, element);
        break;

      case 3:
        printf("Enter the element: ");
        scanf("%d", &element);
        printf("Enter the index: ");
        scanf("%d", & index);
        dll_insert_at(&list, element, index);
        break;

      case 4:
        ec = dll_delete_front(&list, &element);
        if (ec == 1)
          printf("List is empty\n");
        else
          printf("%d is deleted\n", element);
        break;

      case 5:
        ec = dll_delete_back(&list, &element);
        if (ec == 1)
          printf("List is empty\n");
        else
          printf("%d is deleted\n", element);
        break;

      case 6:
        printf("Enter the index: ");
        scanf("%d", &index);
        ec = dll_delete_at(&list, &element, index);
        if (ec == 1)
          printf("List is empty\n");
        else
          printf("%d is deleted\n", element);
        break;

      case 8:
        dll_display_list(&list);
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

  dll_free_list(&list);
  return 0;
}
