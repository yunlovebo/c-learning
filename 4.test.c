#include<stdio.h>

int main() {
    // 以下代码说明输入的空格用来区分变量
    // int a, b;
    // scanf("%d%d", &a, &b);
    // printf("a = %d, b = %d\n", a ,b);
    // return 0;





    // 字符串输入输出的方法：读入一行字符串，并输出
    char str[100] = {0}; // 清空

    // str就是地址，str本身就是数组的首地址
    // scanf("%s", str); // 不接收空格 hello

    // int ret = scanf("%[^\n]", str); // [] -> 字符匹配集，^\n -> 不匹配\n
    // printf("%s", str); // hello world

    int ret;
    // 以下在输入第一次hello world\n后进入死循环
    // while ((ret = scanf("%[^\n]", str)) != EOF) {
    //     printf("%s ret = %d\n", str, ret);
    // }

    while ((ret = scanf("%[^\n]", str)) != EOF) {
        getchar(); // 强行从输入流中取出第一个字符，此例子中为\n
        int ret = printf("%s", str);
        printf(" has %d chars!\n", ret);
    }
    
    return 0;
}