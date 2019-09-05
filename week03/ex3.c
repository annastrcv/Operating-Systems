#include <stdio.h>
#include <stdlib.h>

struct list {
  int data;
  struct list *next;
};

struct list *insert_node(struct list *after, int new_data) {
  struct list *node = malloc(sizeof(struct list));
  node->data = new_data;
  if (after == NULL) {
    return node;
  }
  node->next = after->next;
  after->next = node;
  return after;
}

void print_list(struct list *t) {
  if (t == NULL)
    return;
  printf("%d ", t->data);
  print_list(t->next);
}

struct list *delete_node(struct list *del_after) {
  if (del_after == NULL || del_after->next == NULL)
    return del_after;

  del_after->next = del_after->next->next;
  return del_after;
}

int main() {
  struct list *head = NULL;
  head = insert_node(head, 2);
  head = insert_node(head, 9);
  head->next = insert_node(head->next, 15); 
  print_list(head);

  printf("\n");

  head = delete_node(head); 
  print_list(head);

  printf("\n");

  return 0;
}

