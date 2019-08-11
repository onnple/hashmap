#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashmap.h"

    for (int i = 0; i < 10; ++i) {
        printf("%d ", hash_direct_addr(i));
    }
    printf("\n");

    char *phone[4] = {"18925468742", "18424574569", "13012541567", "13725485414"};
    for (int j = 0; j < 4; ++j) {
        printf("%d ", hash_digit_analyze(phone[j], 11));
    }
    printf("\n");

    for (int k = 0; k < 20; ++k) {
        printf("%d ", hash_multiply(k + 1));
    }
    printf("\n");

    int keys[4] = {23648, 1458, 3654, 984};
    for (int l = 0; l < 4; ++l) {
        printf("%d ", hash_square(keys[l]));
    }
    printf("\n");

    int k[4] = {236898998, 145011448, 64241654, 364746984};
    for (int l = 0; l < 4; ++l) {
        printf("%d ", hash_fold(k[l]));
    }
    printf("\n");

    int v[4] = {2368, 1451448, 1654, 36};
    for (int l = 0; l < 4; ++l) {
        printf("%d ", hash_rand(v[l]));
    }
    printf("\n");

    for (int m = 0; m < 20; ++m) {
        printf("%d ", hash_mod(m * m));
    }
    printf("\n");

    int p[4] = {23689, 1456, 41654, 23647};
    for (int m = 0; m < 4; ++m) {
        printf("%d ", hash_sq(p[m]));
    }
    printf("\n");

    for (int m = 0; m < 4; ++m) {
        printf("%d ", hash_fibo(p[m]));
    }
    printf("\n");
}

static void hashmap(void){
    HashMap *hashmap = hashmap_init(13);
    for (int i = 0; i < 100; ++i) {
        Value value;
        value.tag = i * i;
        strcpy(value.message, "100 Years of Solitude");
        hashmap_add(hashmap, i, &value);
    }
    hashmap_traverse(hashmap);

    HNode *node = hashmap_get(hashmap, 39);
    printf("message associated with key 39: {%d %d}\n", node->key, node->value.tag);

    printf("size of hash map: %d\n", hashmap->size);
    hashmap_delete(hashmap, 67);
    printf("size of hash map: %d\n", hashmap->size);

    for (int j = 0; j < 100; ++j) {
        hashmap_delete(hashmap, j);
    }
    printf("size of hash map: %d\n", hashmap->size);

    hashmap_clear(hashmap);
}

int main() {
    hashmap();
    return 0;
}

