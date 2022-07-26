#include<stdio.h>
#include<stdlib.h>

/**
 * @brief 链表
 * 
 */


typedef struct node {
    int data;
    struct node *next;
    
} node;

typedef struct list {
    struct node *head;
    int size;
    
} list;

node *get_new_node(int x) {
    node *p = (node *)malloc(sizeof(node));
    p -> data = x;
    p -> next = NULL;
    return p;
}

list *init_list() {
    list *p = (list *)malloc(sizeof(list));
    p->head = get_new_node(0); // 虚拟头节点
    p->size = 0;
    return p;
}

void delete_list(list *p) {
    node *q = p->head;
    while (q != NULL) {
        node *t = q;
        q = q->next;
        free(t);
    }
    free(p);
}

int insert_ele(list *l, int ind, int x) {
    if (ind > l->size) {
        return 1;
    }
    node *p = l->head; // 虚拟头节点，避免特判
    for (int i = 0; i < ind; i++) {
        p = p->next;
    }

    node *t = get_new_node(x);
    t->next = p->next;
    p->next = t;
    l->size++;
    return 0;
}

int delete_ele (list *l, int ind) {
    if (ind >= l->size) {
        return 1;
    }
    node *p = l->head;
    for (int i = 0; i < ind; i++) {
        p = p->next;
    }
    node *t = p->next;
    p->next = t->next;
    free(t);
    l->size--;
    return 0;
}

void show_list(list *l) {
    printf("l->size = %d\n", l->size);
    for (node *p = l->head->next; p != NULL; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL\n--------------------------\n");
}

int main() {
    int n;
    scanf("%d", &n);
    list *l = init_list();
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) { // 插入
            int ind, x;
            scanf("%d%d", &ind, &x);
            insert_ele(l, ind, x);
            show_list(l);
        } else { // 删除
            int ind;
            scanf("%d", &ind);
            delete_ele(l, ind);
            show_list(l);
        }
    }
    delete_list(l);
    return 0;
}