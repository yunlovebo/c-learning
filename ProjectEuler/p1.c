#include <stdio.h>

/**
 * @brief 求小于1000的自然数中所有3或5的倍数之和，结果为233168
 */
int main () {
    int ans = 0;

    // 方法1. 传统思路，时间复杂度O(n)
    // for (int i = 1; i < 1000; i++) {
    //     if (i % 3 == 0 || i % 5 == 0) {
    //         ans += i;
    //     }
    // }

    // 方法2 优化算法，利用等差数列求和，时间复杂度O(1)
    int t3 = ((3 + (1000 - 1000 % 3)) * (999 / 3)) / 2; // 333个 (3 + 999) * 333 / 2;
    int t5 = ((5 + (1000 - 1000 % 5)) * (999 / 5)) / 2; // 199个 (5 + 995) * 199 / 2;
    int t15 = ((15 + (1000 - 1000 % 15)) * (999 / 15)) / 2; // 66个 (15 + 990) * 66 / 2;
    ans = t3 + t5 - t15;

    printf("%d\n", ans);
    return 0;
}