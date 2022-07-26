#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 链栈，栈定在头节点，入栈用头插法
 * 
 */

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct stack {
    node *head; // 虚拟头节点
    int size;
} stack;

stack *init_stack() {
    stack *s = (stack *)malloc(sizeof(stack));
    s->head = (node *)malloc(sizeof(node));
    s->head->data = 0, s->head->next = NULL;
    s->size = 0;
    return s;
}

/**
 * @brief 一个节点一个节点的释放，才能释放整个栈
 * 
 * @param s 
 */
void delete_stack (stack *s) {
    node *p = s->head;
    while (p != NULL) {
        node *q = p->next; // 暂存下一个节点
        free(p);
        p = q;
    }
    free(s);
}

int push(stack *s, int x) { // 头插法
    // step1. 建立一个临时节点
    node *p = (node *)malloc(sizeof(node)); 
    p->data = x;

    // step2. 调整指针
    p->next = s->head->next;
    s->head->next = p;

    // step3. 调整size
    s->size++;
    return 0;
}

int pop(stack *s) {
    if (s->size == 0) {
        return 1;
    }
    node *p = s->head->next;
    s->head->next = p->next;
    free(p);
    s->size--;
    return 0;
}

int top(stack *s) {
    if (s->size == 0) {
        return -1;
    }
    return s->head->next->data;
}

 void show_stack(stack *s) {
    printf("size -> %d\n", s->size);
    for (node *p = s->head->next; p != NULL; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL\n-----------------------\n");
 }

int main() {
    int n;
    scanf("%d", &n);
    stack *s = init_stack();
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) { // 插入
            int x;
            scanf("%d", &x);
            push(s, x);
        } else if (t == 1) { // 删除
            pop(s);
        } else { // 查看头节点
            printf("top -> %d\n", top(s));
        }
        show_stack(s);
    }
    return 0;
}