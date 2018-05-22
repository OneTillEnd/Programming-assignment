//
// Created by xavier on 18-4-11.
//

#include <cstdio>
#include <cstdlib>

typedef struct _node{
    int *data;
    struct _node *next;
}Node;

typedef struct _linkedlist{
    Node *head;
    Node *tail;
}LinkedList;

Node *tmp = (Node*) malloc(sizeof(Node));

void initialize_list(LinkedList *list){
    list->head = NULL;
    list->tail = NULL;
}

int is_empty(LinkedList *list){
    return list->head == NULL;
}

int is_singleton(LinkedList *list){
    return (list->head != NULL)
           && (list->head == list->tail);
}

void add_tail(LinkedList *list, int *data){
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;

    if (is_empty(list)){
        list->head = node;
    } else{
        list->tail->next = node;
    }

    list->tail = node;
    list->tail->next = list->head;
}

void delete_next(LinkedList *list, int k){
    if (is_empty(list)){
        return;
    }
    if (is_singleton(list)){
        list->head = NULL;
        list->tail = NULL;
        free(tmp);
        return;
    }
    for (int i = 1; i < k; ++i) {
        tmp = tmp->next;
    }

    Node *node = tmp->next;
    tmp->next = node->next;

    if (node == list->head){
        list->head = node->next;
    }
    if (node == list->tail){
        list->tail = tmp;
    }
}

void sit_in_circle(LinkedList *list, int n){
    for (int i = 1; i <= n; ++i) {
        int *id = (int *) malloc(sizeof(int));
        *id = i;
        add_tail(list, id);
    }
}

void kill_until_one(LinkedList *list, int k, int m){
    tmp = list->tail;
    for (int i = 1; i < m; ++i) {
        tmp = tmp->next;
    }
    Node *node = tmp->next;
    tmp->next = node->next;
    if (node == list->head){
        list->head = node->next;
    }
    if (node == list->tail){
        list->tail = tmp;
    }

    while (! is_singleton(list)){
        delete_next(list, k);
    }
}

int main(void){
    int n = 0, k = 0, m = 0;

    LinkedList list;

    while (scanf("%d", &n) && n != 0){
        scanf("%d%d", &k, &m);
        initialize_list(&list);

        sit_in_circle(&list, n);

        kill_until_one(&list, k, m);
        printf("%d\n", *(list.head->data));
    }
    return 0;
}
