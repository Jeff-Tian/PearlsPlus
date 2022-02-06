#include <stdio.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 32
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
    printf("int 型数组 a 的元素个数为： %d\n", SIZE);
    printf("它占用的内存大小为： %lu %s\n", sizeof(a), "字节");

    double sizePerElement = ((double)(sizeof(a))) / ((double)SIZE);

    printf("即每个元素占用的内存大小是： %lu / %d = %f %s\n", sizeof(a), SIZE, sizePerElement, "字节");

    printf("MASK 的值是： %d， 其占用的内存大小是： %lu 字节， 其比特位如下：\n", MASK, sizeof(MASK));

    printBits(MASK);

    printf("当前 a 的值是： %d %d\n", a[0], a[1]);
    printf("其比特位如下： \n");
    
    printBits(a[0]);
    printBits(a[1]);

    printf("执行设置位 0……\n");
    set(0);

    printf("当前 a 的值是： %d %d\n", a[0], a[1]);
    printf("其比特位如下： \n");
    
    printBits(a[0]);
    printBits(a[1]);

    printf("执行设置位 1……\n");
    set(1);


    printf("当前 a 的值是： %d %d\n", a[0], a[1]);
    printf("其比特位如下： \n");
    
    printBits(a[0]);
    printBits(a[1]);

    printf("测试位 0： %d\n", test(0));
    printf("测试位 1： %d\n", test(1));

    printf("执行清除位 1……\n");
    clr(1);

    printf("当前 a 的值是： %d %d\n", a[0], a[1]);
    printf("其比特位如下： \n");
    
    printBits(a[0]);
    printBits(a[1]);

    printf("执行清除位 0……\n");
    clr(0);


    printf("当前 a 的值是： %d %d\n", a[0], a[1]);
    printf("其比特位如下： \n");
    
    printBits(a[0]);
    printBits(a[1]);

    printf("测试位 0： %d\n", test(0));
    printf("测试位 1： %d\n", test(1));
    return 0;
}
