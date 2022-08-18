#include<stdio.h>


int main() {
    // FILE *fp = fopen("abc.txt", "r");
    // FILE *fp = fopen("abc1.txt", "w+");
    FILE *fp = fopen("abc1.txt", "a+");
    if (fp == NULL) {
        printf("打开失败！\n");
        return 0;
    } else {
        printf("打开成功！\n");
    }

    // fputc('a', fp); // 写入一个字符

    char ch = getchar(); // 从键盘输入一个字符
    while (ch != '#') {
        fputc(ch, fp);
        ch = getchar();
    }

    rewind(fp); // 文件位置指针重新定义文件首部
    ch = fgetc(fp);
    while(ch != EOF) {
        putchar(ch); // 输出到显示器
        ch = fgetchar(fp); // 去文件读出下一个字符
    }

    fclose(fp);

    return 0;
}