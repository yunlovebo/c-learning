#include<stdio.h>

/**
 * @brief 辗转相除法，欧几里德公式，求最大公约数
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        int result = gcd(a, b);
        printf("%d和%d的最大公约数为%d\n", a, b, result);

    }
    return 0;
}