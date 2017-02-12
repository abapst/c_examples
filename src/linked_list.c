#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
typedef struct node node_t;
node_t *list_init();
void print_list(node_t *head);
void push_end(node_t *head, int val);
void push_start(node_t **head, int val);
int pop_start(node_t **head);
int pop_end(node_t *head);
void delete_list(node_t *head);
/************************/

typedef struct node
{
  int val;
  struct node *next;
} node_t;

node_t *list_init()
{
  node_t *head = malloc(sizeof(node_t));
  head->val = 1;
  head->next = NULL;
  return head;
}

void print_list(node_t *head)
{
  node_t *current = head;

  while (current != NULL) {
    printf("%d ",current->val);
    current = current->next;
  }
  printf("\n");
}

void push_end(node_t *head, int val)
{
  node_t *current = head;

  /* Navigate to the end of the list */
  while(current->next != NULL) {
    current = current->next;
  }

  /* Add a new item to the list */
  current->next = malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL;
}

void push_start(node_t ** head, int val)
{
  node_t *new_node = malloc(sizeof(node_t));
  new_node->val = val;

  /* We need to use a double pointer so that the head gets modified
     inside the calling function */
  new_node->next = *head;
  *head = new_node; 
}

int pop_start(node_t ** head)
{
  int retval = -1;
  node_t *next_node = NULL;
  
  if (*head == NULL) {
    return -1;
  }

  next_node = (*head)->next;
  retval = (*head)->val;
  free(*head);
  *head = next_node;

  return retval;
}

int pop_end(node_t *head)
{
  node_t *current = head;
  int retval = -1;

  /* If there is only one item in the list, remove it */
  if (head->next == NULL) {
    retval = head->val;
    free(head);
    return retval;
  }

  /* Traverse the list to the second-to-last */
  while(current->next->next != NULL) {
    current = current->next;
  }

  retval = current->next->val;
  free(current->next);
  current->next = NULL;
  return retval;
}

void delete_list(node_t *head)
{
  node_t *current = head;
  node_t *tmp;

  while (current->next != NULL) {
    tmp = current;
    current = current->next;
    free(tmp);
  }
  free(current);
}

int main(int argc, char *argv[])
{

  node_t *list = list_init();
  int ii;
  
  list->val = 0;
  print_list(list);

  for(ii = 1; ii < 10; ii++) {
    push_end(list,ii);
    print_list(list);
  }

  for(ii = 1; ii < 10; ii++) {
    pop_end(list);
    print_list(list);
  }

  /* there is a bug where this call results in error if the list
     head has already been freed (if it was popped) */
  delete_list(list);
  
  return 0;
}
