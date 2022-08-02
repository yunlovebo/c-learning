#include <stdio.h>

/**
 * @brief 冒泡排序，有优化，发现某一趟未交换直接跳出循环
 * 时间：最好O(n) 最坏O(n^2) 平均O(n^2)
 * 空间：O(1)
 * 稳定性：稳定
 * 直接插入排序和冒泡排序的区别：前者对已排序区进行操作，后者已排序区没有操作
 * 
 * @param num 
 * @param n 
 */
void bubble_sort(int *num, int n) {
    for (int i = 1; i < n; i++) { // 循环论数
        int flag = 0;
        for (int j = 0; j < n - i; j++) { // 两两相邻比较
            if (num[j] > num [j + 1]) { // 逆序则交换
                int t = num[j];
                num[j] = num[j + 1];
                num[j + 1] = t;
                flag = 1;
            }
            if (flag == 0) { // 某轮没有出触发任何交换，数据已有序，跳出
                break;
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
    bubble_sort(num, n);
    for (int i = 0; i < n ; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");

    return 0;
}