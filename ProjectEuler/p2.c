#include <stdio.h>

/**
 * @brief 求斐波那契数列中不超过四百万的项中偶数项之和
 * 结果：4613732
 */

// 空间复杂度O(n)
// 较直观的方法
// int num[4000005];
// int main () {
//     num[1] = 1;
//     num[2] = 2;
//     long long ans = 2;
//     for (int i = 3; 1; i++) { // 循环结尾未知，先写个死循环
//         num[i] = num[i - 1] + num[i - 2];
//         if (num[i] >= 4000000) {
//             break;
//         }

//         if (num[i] % 2 == 0) {
//             ans += num[i];
//         }
//     }

//     printf("%lld\n", ans);
//     return 0;
// }

// 空间复杂度O(1)
int main () {
    int a = 1, b = 2, ans = 0;

    while (b < 4000000) {
        if (b % 2 == 0) {
            ans += b;
        }

        // b、a各向后走一步
        b += a;
        a = b - a;
    }
    printf("%d\n", ans);

    return 0;
}