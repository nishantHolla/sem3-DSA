#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "singly_linked_list.h"

#define MAX_STRING_LENGTH 1000

int main() {
  SL_LIST aList;
  sll_init_list(&aList);

  SL_LIST bList;
  sll_init_list(&bList);

  SL_LIST result;
  sll_init_list(&result);

  char *a = (char *) malloc(sizeof(char) * MAX_STRING_LENGTH);
  char *b = (char *) malloc(sizeof(char) * MAX_STRING_LENGTH);

  printf("A: ");
  scanf("%s", a);

  printf("B: ");
  scanf("%s", b);

  if (strlen(b) > strlen(a)) {
    char *temp = a;
    a = b;
    b = temp;
  }

  for (int i=0; a[i]; i++) {
    sll_insert_front(&aList, a[i] - '0');
  }

  for (int i=0; b[i]; i++) {
    sll_insert_front(&bList, b[i] - '0');
  }

  SLL_NODE *aNode = aList.head;
  SLL_NODE *bNode = bList.head;

  int carry = 0;
  while (aNode && bNode) {
    int addition = aNode->data + bNode->data + carry;
    if (addition > 9) {
      carry = 1;
      addition = addition - 10;
    }
    else {
      carry = 0;
    }
    sll_insert_front(&result, addition);
    aNode = aNode->next;
    bNode = bNode->next;
  }

  while (aNode) {
    int addition = aNode->data + carry;
    if (addition > 9) {
      carry = 1;
      addition = addition - 10;
    }
    else {
      carry = 0;
    }
    sll_insert_front(&result, addition);
    aNode = aNode->next;
  }

  if (carry) {
    sll_insert_front(&result, carry);
  }

  sll_display_list(&result);

  free(a);
  free(b);
  sll_free_list(&aList);
  sll_free_list(&bList);
  sll_free_list(&result);
  return 0;
}
