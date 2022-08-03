#include <stdio.h>

/**
 * @brief 最大回文乘积：求两个三位数相乘得到的最大的回文数
 * 结果：906609
 */

// 判断x是否为回文数
int func (int x) {
    int t = 0; // x倒转之后的结果
    int r = x; // 保存原始值

    while (x != 0) {
        t = t * 10 + x % 10;
        x /= 10;
    }

    return t == r;
}

int main () {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        // 内层循环从i开始，避免重复相乘(乘法交换律)
        for (int j = i; j < 1000; j++) {
            int t = i * j;
            if (func(t)) {
                if (ans < t) {
                    ans = t;
                }
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}