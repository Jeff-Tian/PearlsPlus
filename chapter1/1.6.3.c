#include <stdio.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 1000
#define SIZE 1 + N/BITSPERWORD

int a[SIZE];

// 设置位值 
void set(int i ) {
    a[i>>SHIFT] |= (1<<(i & MASK));
}

// 清除位值 
void clr(int i) {
    a[i>>SHIFT] &= ~(1<<(i & MASK));
}

// 测试位值
int test(int i) {
    return a[i>>SHIFT] & (1<<(i & MASK));
}

int printBits(int x) {
    // printf("x = %d\n", x);
    int bits = sizeof(x) * 8;
    int i;
    for(i = 0; i < bits; i++) {
        
        int bit = (x & ((1<<(bits-i)) - 1)) >> (bits-1-i);

        // printf("i = %d, 掩码= %d, %d\n", i, ((1<<(bits-i)) - 1), bit);

        printf("%d(%d) ", bit, i);
    }
    printf("\n");

    return 0;
}

int main(void) {
    int i;
    for (i = 0; i < N; i++) {
        clr(i);
    }

    printf("请输入要排序的数，一行一个。按 Ctrl+D 结束输入：\n\n");

    while (scanf("%d", &i) != EOF) {
        set(i);
    }

    printf("输入完毕，以下是排序后的输入：\n\n");

    for(i = 0; i < N; i++) {
        if(test(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}