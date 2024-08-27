#include <stdio.h>
#include "circular_doubly_linked_list.h"

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
  CDL_LIST list;
  
  cdll_init_list(&list);

  while (choice) {
    int element, index, ec;
    printf("\n%s\n> ", instructions);
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element: ");
        scanf("%d", &element);
        cdll_insert_front(&list, element);
        break;

      case 2:
        printf("Enter the element: ");
        scanf("%d", &element);
        cdll_insert_back(&list, element);
        break;

      case 3:
        printf("Enter the element: ");
        scanf("%d", &element);
        printf("Enter the index: ");
        scanf("%d", &index);
        cdll_insert_at(&list, element, index);
        break;

      case 4:
        ec = cdll_delete_front(&list, &element);
        if (ec == 0) {
          printf("Deleted %d\n", element);
        }
        break;

      case 5:
        ec = cdll_delete_back(&list, &element);
        if (ec == 0) {
          printf("Deleted %d\n", element);
        }
        break;

      case 6:
        printf("Enter index: ");
        scanf("%d", &index);
        ec = cdll_delete_at(&list, &element, index);
        if (ec == 0) {
          printf("Deleted %d\n", element);
        }
        break;

      case 7:
        printf("Enter element: ");
        scanf("%d", &element);
        ec = cdll_search_list(&list, element);
        if (ec) {
          printf("Found %d in the list\n", element);
        }
        else {
          printf("Did not find %d in the list\n", element);
        }
        break;

      case 8:
        cdll_display_list(&list);
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

  cdll_free_list(&list);
  return 0;
}
