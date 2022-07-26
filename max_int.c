#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

int max_int(int n, ...) {
    int ans = INT32_MIN; // 32位int极小值的宏
    va_list arg;
    va_start(arg, n);
    while(n--) {
        int temp = va_arg(arg, int);
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}


int main () {
    printf("MAX(3, 0, 2, 23) = %d\n", max_int(3, 0, 2, 23));
    printf("MAX(5, 0, -3, 23, 32, 2) = %d\n", max_int(5, 0, -3, 23, 32, 2));
    return 0;
}