#include<stdio.h>

// 采用异或交换，不需要中间变量
int main() {
    int a, b;
    while(~scanf("%d%d", &a, &b)) {
        a ^= b;
        b ^= a;
        a ^= b;
        printf("a=%d, b=%d\n", a, b);
    }
    return 0;
}