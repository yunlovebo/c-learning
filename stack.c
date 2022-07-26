#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 顺序栈，栈顶在数组的尾部
 * 
 */
typedef struct stack {
    int *data;
    int size, cap; // cap=容量
} stack;

stack * init_stack(int x) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = (int *)malloc(sizeof(int) * x);
    s->size = 0, s->cap = x;
    return s;
}

void delete_stack(stack *s) {
    free(s->data);
    free(s);
}

int push(stack *s, int x) {
    if (s->size == s->cap) { // 扩容2倍
        s->data = (int *)realloc(s->data, s->cap * 2);
        s->cap *= 2;
    }
    s->data[s->size] = x;
    s->size++;
    return 0;
}

int pop(stack *s) {
    if (s->size == 0) {
        return 1;
    }
    s->size--; // 不需释放栈顶元素
    return 0;
}

int top(stack *s) {
    if (s->size == 0) {
        return -1;
    }
    return s->data[s->size - 1];
}

void show_stack(stack *s) {
    printf("size -> %d, cap -> %d\n", s->size, s->cap);
    for (int i = 0; i < s->size; i++) {
        printf("%d ", s->data[i]);
    }
    printf("NULL\n---------------------\n");
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    stack *s = init_stack(m);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) { // 入栈
            int x;
            scanf("%d", &x);
            push(s, x);
        } else if (t == 1) { // chu
            pop(s);
        } else {
            printf("top -> %d\n", top(s));
        }
        show_stack(s);
    }
    return 0;
}
