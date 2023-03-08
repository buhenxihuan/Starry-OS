#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    puts("Running memory tests...");
    uintptr_t *brk = (uintptr_t *) malloc(0);
    printf("top of heap=0x%p\n", brk);

    int n = 9;
    int i = 0;
    uintptr_t **p = (uintptr_t **) malloc(n * sizeof(uint64_t));
    printf("%d(+8)Byte allocated: p=0x%p\n", n * sizeof(uint64_t), p, p[1]);
    printf("allocate %d(+8)Byte for %d times:\n", sizeof(uint64_t), n);
    for(i = 0; i < n; i++) {
        p[i] = (uintptr_t *)malloc(sizeof(uint64_t));
        *p[i] = 233;
        printf("allocated addr=0x%p\n", p[i]);
    }
    for(i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);
    puts("Memory tests run OK!");
    return 0;
}
