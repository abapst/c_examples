#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct node
{
    int id;
    void *data;
    struct node *next;
} node_t;

/* Function declarations */
node_t *list_init();
void print_list(node_t *head);
void push_end(node_t *head, int id, void *data);
void push_start(node_t **head, int id, void *data);
node_t *pop_start(node_t **head);
node_t *pop_end(node_t **head);
void delete_list(node_t **head);
void delete_node(node_t *node);
node_t *reverse_list(node_t *head);
int list_length(node_t *head);

#endif /* LINKED_LIST_H */
