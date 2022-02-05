#include <stdio.h>
#include <stdlib.h>

int intcomp(int *x, int *y) {
    return *x - *y;
}

int a[1000000];
int main(void) {
    int i, n = 0;

    printf("1. 如果不缺内存，如何使用一个具有库的语言来实现一种排序算法以表示和排序集合？\n\n");

    printf("请输入整数，一行一个。按 Ctrl+D 结束输入：\n\n");
    while (scanf("%d", &a[n]) != EOF) {
        n++;
    }

    qsort(a, n, sizeof(int), intcomp);

    printf("排序后的结果是：\n\n");

    for(i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}