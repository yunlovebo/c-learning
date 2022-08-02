#include <stdio.h>

/**
 * @brief 选择排序
 * 时间复杂度：最好O(n^2)，最差O(n^2)，平均O(n^2)
 * 空间复杂度：O(1)
 * 稳定性：不稳定
 * 时间复杂度高，又不稳定，存在的意义？思路简单
 * @param num 
 * @param n
 */
void selection_sort(int *num, int n) {
    for (int i = 0; i < n - 1; i++) { // 循环n-1轮
        int ind = i; // 最小元素索引
        for (int j = i + 1; j < n; j++) {
            if (num[j] < num[ind]) {
                ind = j; // 找到新的最小元素
            }
        }
        // 交换未排序区第一个元素与最小元素
        int t = num[i];
        num[i] = num[ind];
        num[ind] = t;
    }
}

int main () {
    int n, num[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    selection_sort(num, n);
    for (int i = 0; i < n ; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");

    return 0;
}
