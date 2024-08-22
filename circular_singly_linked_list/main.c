#include <stdio.h>
#include "circular_singly_linked_list.h"

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
  CSL_LIST list;
  
  csll_init_list(&list);

  while (choice) {
    int element, index, ec;
    printf("\n%s\n> ", instructions);
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element: ");
        scanf("%d", &element);
        csll_insert_front(&list, element);
        break;

      case 2:
        printf("Enter the element: ");
        scanf("%d", &element);
        csll_insert_back(&list, element);
        break;

      case 4:
        ec = csll_delete_front(&list, &element);
        if (ec == 0)
          printf("Deleted %d\n", element);
        break;

      case 5:
        ec = csll_delete_back(&list, &element);
        if (ec == 0)
          printf("Deleted %d\n", element);
        break;

      case 8:
        csll_display_list(&list);
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

  csll_free_list(&list);
  return 0;
}
