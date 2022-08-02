#include <stdio.h>
#define MAX_N 100

/**
 * @brief 
 * 
 * @param n 
 * @return int 1：素数，2:合数
 */
int is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main () {
    // 从2开始，因为1肯定是素数
    for (int i = 2; i < MAX_N; i++) {
        // 为了减少缩紧，增加可读性，采用对偶逻辑
        // if (is_prime(i)) {
        //     printf("%d\n", i);
        // }
        if (!is_prime(i)) continue;
        printf("%d\n", i);
    }
    return 0;
}