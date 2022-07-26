#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ret = printf("%d", n);
    printf(" has %d digits!\n", ret);
    return 0;
}