#include "key.h"

void printKey(MyKey key){
    uint64_t ret = key;
    printf("%llu\n", ret);
}

// int main(){
//     MyKey key;
//     key.len = 4;
//     key.key = new uint8_t[key.len];
//     printKey(key);
// }
