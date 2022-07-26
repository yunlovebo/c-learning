#include <stdio.h>

int main () {
    // 时间复杂度O(n) * O(n/2)，即外层循环n次，内层平均循环n/2次，约掉常数得O(n^2)
    int n = 100;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d", i * j);
        }
    }


    // 看见两层循环嵌套，不一定是O(n^2)
    // 时间复杂度O(n + n)，即O(n)
    int n = 100;
    int i = 0, j = 5;
    while (i < n) { // 外层循环O(n)
        i += 5;
        // 内层每次只循环5次，即i += 5这5次，因为j定义在了外面，不会回溯，可以理解为j一直在往前走
        // 内层循环，在整个程序执行中一共走了大概100步
        // 所以与外层循环的关系是相加，不是相乘
        while (j < i) {
            j++;
            printf("%d", i * j);
        }
    }

    // 时间复杂度O(n^1/2)
    // 关键：找出i循环几次，转化为求解不等式
    int n = 100;
    int i = 0, j = 0;
    while (i < n) {
        j++;
        i += j; // i的增量：1+2+3+...+x < n，利用等差数列求和、约掉小项，得出x < n^1/2 
        printf("break\n");
    }



    return 0;
}