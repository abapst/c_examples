#ifndef LIST_H
#define LIST_H

typedef struct node
{
    int val;
    struct node *next;
} node_t;

/* Function declarations */
typedef struct node node_t;
node_t *list_init();
void print_list(node_t *head);
void push_end(node_t *head, int val);
void push_start(node_t **head, int val);
int pop_start(node_t **head);
int pop_end(node_t **head);
void delete_list(node_t **head);
/************************/

#endif
