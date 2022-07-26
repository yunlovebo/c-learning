#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 顺序实现的循环队列，队尾节点不存数据
 * rear取模实现循环
 */

typedef struct queue {
    int *data;
    int front, rear,  cap, size; // size的计算方法：size = ((rear+cap)-front) % cap
    
} queue;

queue *init_queue(int x) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->data = (int *)malloc(sizeof(int) * x);
    q->front = q->rear = q->size = 0;
    q->cap = x;
    return q;
}

void delete_queue(queue *q) {
    free(q->data);
    free(q);
}

int push(queue *q, int x) {
    // if((q->rear + 1) % q->cap === q->front) // 队列满了的另一种判断方式，与下面写法等效
    if (q->size + 1 == q->cap) { // if里做的是扩容
        // 循环队列这样扩容会有问题，不能这样
        // q->cap *= 2;
        // q->data = (int *)realloc(q->data, sizeof(int) * q->cap);
        int *p = (int *)malloc(sizeof(int) * q->cap * 2);
        for (int i = 0, j = q->front; i != q->size; i++, j++, j %= q->cap) {
            p[i] = q->data[j];
        }
        free(q->data);
        q->data = p;
        q->cap *= 2;
        q->front = 0;
        q->rear = q->size;
    }
    q->data[q->rear] = x;
    q->rear++;
    q->rear %= q->cap;
    q->size++;
    return 0;
}

int pop(queue *q) {
    // q->front == q->rear
    if (q->size == 0) {
        return 1;
    }
    q->front++;
    q->front %= q->cap;
    q->size--;
    return 0;
}

int front(queue *q) {
    if (q->size == 0) {
        return -1;
    }
    return q->data[q->front];
}

void show_queue(queue *q) {
    printf("size = %d, cap = %d\n", q->size, q->cap);
    for (int i = q->front; i != q->rear; i++, i %= q->cap) {
        printf("%d ", q->data[i]);
    }
    printf("\n-------------------------\n");
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    queue *q = init_queue(m);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int x;
            scanf("%d", &x);
            push(q, x);
        } else if (t == 1) {
            pop(q);
        } else {
            printf("front -> %d\n", front(q));
        }
        show_queue(q);
    }
    return 0;
}