#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char* bits;
    char* flipped_bits;
    int size;
    int ones;
} Bitset;

Bitset* bitsetCreate(int size) {
    Bitset* obj = (Bitset*)malloc(sizeof(Bitset));
    obj->bits = (char*)malloc(size + 1);
    obj->flipped_bits = (char*)malloc(size + 1);
    memset(obj->bits, '0', size);
    obj->bits[size] = '\0';
    memset(obj->flipped_bits, '1', size);
    obj->flipped_bits[size] = '\0';
    obj->size = size;
    obj->ones = 0;
    return obj;
}

void bitsetFix(Bitset* obj, int idx) {
    if (obj->bits[idx] == '0') {
        obj->bits[idx] = '1';
        obj->flipped_bits[idx] = '0';
        obj->ones++;
    }
}

void bitsetUnfix(Bitset* obj, int idx) {
    if (obj->bits[idx] == '1') {
        obj->bits[idx] = '0';
        obj->flipped_bits[idx] = '1';
        obj->ones--;
    }
}

void bitsetFlip(Bitset* obj) {
    char* temp = obj->bits;
    obj->bits = obj->flipped_bits;
    obj->flipped_bits = temp;
    obj->ones = obj->size - obj->ones;
}

bool bitsetAll(Bitset* obj) {
    return obj->ones == obj->size;
}

bool bitsetOne(Bitset* obj) {
    return obj->ones > 0;
}

int bitsetCount(Bitset* obj) {
    return obj->ones;
}

char* bitsetToString(Bitset* obj) {
    return obj->bits;
}

void bitsetFree(Bitset* obj) {
    free(obj->bits);
    free(obj->flipped_bits);
    free(obj);
}
