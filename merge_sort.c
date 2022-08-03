#include <stdio.h>

/**
 * @brief 归并排序
 * 时间复杂度：最好O(nlogn)，最差O(nlogn)，平均O(nlogn)，第一个n是n个元素，logn是递归层数
 * 空间复杂度：是o(n)，递归层深logn，额外空间用于在合并过程中临时存储数据n，抓大放小所以是o(n)
 * 稳定性：稳定——稳定与否，看相同元素的顺序，在乱序和排好序的数组中，是否有位置交换
 * @param num
 * @param n
 */
void merge_sort(int *num, int l, int r, int *temp) {
    if (l >= r) {
        return;
    }

    // 递归
    int mid = (l + r) / 2;
    merge_sort(num, l, mid, temp); // 对左边排序
    merge_sort(num, mid + 1, r ,temp); // 对右边排序

    // 合并
    // p1 左块起点
    // p2 右块起点
    // n 一共有一个元素
    int p1 = l, p2 = mid + 1, n = r - l + 1;
    for (int i = 0; i < n; i++) {
        // 两种情况选择p1
        // 1. p2遍历完了
        // 2. p1没遍历完，且p1位置的值较小
        if (p2 > r || (p1 <= mid && num[p1] <= num[p2]) ) {
            temp[i] = num[p1];
            p1++;
        } else {
            temp[i] = num[p2];
            p2++;
        }
    }

    // 拷贝回数组
    for (int i = 0, j = l; i < n || j <= r; i++, j++) {
        num[j] = temp[i];
    }

}

int main () {
    int n, num[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    // 归并排序需要开辟额外空间
    int temp[105];
    merge_sort(num, 0, n - 1, temp);
    for (int i = 0; i < n ; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");

    return 0;
}
