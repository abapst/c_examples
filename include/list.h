#ifndef LIST_H
#define LIST_H

#define MAXLINE 2048

typedef struct node
{
    int id;
    void *data;
    struct node *next;
} node_t;

/* Function declarations */
typedef struct node node_t;
node_t *list_init();
void print_list(node_t *head);
void push_end(node_t *head, int id, void *data);
void push_start(node_t **head, int id, void *data);
node_t *pop_start(node_t **head);
node_t *pop_end(node_t **head);
void delete_list(node_t **head);
void delete_node(node_t *node);
int list_length(node_t *head);
/************************/

#endif
