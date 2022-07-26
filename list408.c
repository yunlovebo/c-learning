#include<stdio.h>

typedef struct NODE {
    int data;
    NODE *next;
} NODE;


// 时间复杂度O(N)，空间复杂度O(1)
NODE *change(NODE * L) {
    NODE *p, *q, *r, *s;
    // step1. 中间结点，p慢指针一次走一步，q快指针一次走两步
    p = q = L;
    while (q->next) {
        p = p->next;
        q = q->next;
        if (q->next) q = q->next;
    }
    q = p->next;
    p->next = NULL;

    // step2. 后半段逆置，头插法
    while(q) {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }

    // step3. 向前插入
    s = L->next;
    q = p->next;
    p->next = NULL; // 当前是中间结点，算法结束后是尾节点
    while(q) {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
    return L;

}