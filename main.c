#include "key.h"

int main(){
    MyKey key;
    key.len = 4;
    // c++ only
    // key.key = new uint8_t[key.len];
    // uint64_t ret = key;
    // printf("%llu\n", ret);

    // call c libs
    key.key = (uint8_t *)malloc(sizeof(key.len));
    for(uint32_t i=0; i<key.len; i++){
        key.key[i] = i * 2;
    }
    printKey(key);
    uint32_t value = 0;
    void *index = initpgm();
    insertKey(index, key, value);
    uint32_t ret = readKey(index, key);
    printf("read done %d\n", ret);
}