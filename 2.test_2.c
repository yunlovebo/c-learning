#include <stdio.h>

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b) != EOF) { // 循环读入，如何退出循环：1.杀死当前进程ctrl C 或 2. ctrl D 产生EOF
        printf("a=%d, b=%d\n", a, b);
    }
    return 0;
}