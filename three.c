#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

/**
 * 2022年统考408 三元组最短距离，搜索关键词“定义三元组”
 * 算法思想：
 * 将集合分别放入s1，s2，s3当中，对应代表i=j=k=0，三个数组均未遍历完成时进入循环
 * 计算当前ijk下表值的距离，与最小距离判断并进行更新；在a b c数组当中找出最小值，将其下标加1
 * 继续循环遍历直到有一个数组遍历完成时退出循环
 * 
 */

/**
 * @brief 求绝对值
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int abs_(int a) {
    if (int a < 0) return 0 - a;
    return a;
}

/**
 * @brief 判断a是否时三元组中的最小值
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return true 
 * @return false 
 */
bool min_(int a, int b, int c) {
    return a<=b && a <=c;
}

int findMin(int *s1, int l, int *s2, int m, int *s3, int n) {
    // ijk下表从0开始，min存储当前最短距离，D代表当前三元组计算出的距离
    int i = 0, j = 0, k = 0, min = INT8_MAX, D;
    while(i < l && j < m && k < n && min >= 0) {
        // 计算三元组距离
        D = abs_(s1[i] - s2[j]) + abs_(s2[j] - s3[k]) + abs_(s3[k] - s1[i]);
        if (D < min) min = D; // 与最小值min对比并更新

        // 以下3行：找出三元组中最小值并将其下标后移
        if (min_(s1[i], s2[j], s3[k])) i++;
        else if (min_(s2[j], s1[i], s3[k])) j++;
        else k++;
    }
}

int main () {
    int s1[] = {}, s2[] = {}, s3[] = {};
    int l = , m = , n = ;
    printf()
    return 0;
}