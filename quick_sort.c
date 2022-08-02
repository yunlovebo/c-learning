#include <stdio.h>

/**
 * @brief 无优化的快排序——挖坑互填法
 * 
 * @param num 
 * @param left 
 * @param right 
 */
void quick_sort(int *num, int left, int right) {
    if (left >= right) { // 只有一个元素，或没有元素了
        return;
    }
    int t = num[left]; // 中间元素，无任何优化的情况下选第一个元素
    // 挖坑互填法
    int l = left, r = right;
    while(l < r) {
        while(l < r && num[r] >= t) {
            r--;
        }
        if (l < r) { // 从右往左找一个比t小的，交换后，右边留下一个坑
            num[l] = num [r];
        }
        while(l < r && num[l] <= t) {
            l++;
        }
        if (l < r) { // 从左往左找一个比t大的，交换后，左边留下一个坑
            num[r] = num[l];
        }
    }
    num[l] = t; // 中间元素找到位置，放入坑中，左侧全比t小，右侧全比t大
    // 然后再递归左右，有二叉树遍历那味了
    quick_sort(num, left, l - 1);
    quick_sort(num, l + 1, right);
}

int main () {
    int n, num[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    quick_sort(num, 0, n - 1);
    for (int i = 0; i < n ; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");

    return 0;
}