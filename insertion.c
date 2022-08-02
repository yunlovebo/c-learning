#include <stdio.h>
/**
 * @brief 插入类排序
 * 1. 直接插入排序
 * 2. 折半插入排序，效率同直接插入排序
 * 3. 希尔排序
 * 
 */

/**
 * @brief 直接插入排序
 * 时间复杂度：最好O(n)，最差O(n^2)，平均O(n^2)
 * (额外)空间复杂度：O(1)
 * 稳定性：稳定排序(值相同的多个变量，再次排序时是否交换顺序)
 * 
 * @param num 
 * @param n 
 */
void insertion_sort(int *num, int n) {
    for (int i = 1; i < n; i++) { // 循环未排序区，拿出第一个元素 
        for (int j = i - 1; j >= 0; j--) { // 逐个向前比较
            if (num[j] > num[j + 1]) { // 若逆序则交换
                int t = num[j];
                num[j] = num[j + 1];
                num[j + 1] = t;
            } else {
                break; // 否则跳出
            }
        }
    }
}

int main () {
    int n, num[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    insertion_sort(num, n);
    for (int i = 0; i < n ; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");

    return 0;
}