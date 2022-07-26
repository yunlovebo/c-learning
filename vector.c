#include<stdio.h>
#include<stdlib.h>

/**
 * @brief 顺序表(数组)
 * 
 */


typedef struct vector
{
    int *data;
    int size, cap;
} vector;
/**
 * @brief 
 * 
 * @param x 
 * @return vector* 整体是一个返回值类型
 */
vector *init_vector(int x) {
    vector *p = (vector *)malloc(sizeof(vector));
    p->data = (int *)malloc(sizeof(int) * x);
    p->size = 0, p->cap = x;
    return p;
}

void delete_vector(vector *p) {
    free(p->data);
    free(p);
}

/**
 * @brief 插入一个元素
 * 
 * @param v 
 * @param ind 插入位置
 * @param x 插入的值
 * @return int 
 */
int insert_ele(vector *v, int ind, int x) {
    if (v->size < ind) { // 不能跳着插入
        return 1;
    }
    if (v->size == v->cap) { // 已满，执行扩容操作
        v->cap *= 2;
        v->data = (int *)realloc(v->data, sizeof(int) * v->cap); // 原地扩容为原来的2倍
    }
    for (int i = v->size - 1; i >= ind; i--) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = x;
    v->size++;
    return 0;
}

int delete_ele(vector *v, int ind) {
    if (v->size <= ind) {
        return 0;
    }
    for (int i = ind + 1; i < v->size; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->size--;
    return 0;
}

void show_vector(vector *v) {
    printf("v->cap = %d, v->size = %d\n", v->cap, v->size);
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i]);
    }
    printf("---------------------------\n");
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector *v = init_vector(m);
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t == 0) { // 插入
            int ind, x;
            scanf("%d%d", &ind, &x);
            insert_ele(v, ind, x);
        } else { // 删除
            int ind;
            scanf("%d", &ind);
            delete_ele(v, ind);
        }
        show_vector(v);
    }
    delete_vector(v);
    return 0;
}

