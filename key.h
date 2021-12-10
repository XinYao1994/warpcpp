// https://stackoverflow.com/questions/2045774/developing-c-wrapper-api-for-object-oriented-c-code
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct MyKey {
    uint8_t *key;
    uint32_t len;

#ifdef __cplusplus
    operator uint64_t() const { 
        uint64_t x = 0;
        uint32_t _len = len < sizeof(uint64_t) ? len : sizeof(uint64_t);
        for (uint32_t i = 0; i < _len; ++i){
            // x |= T(key[i]) << (8 * (sizeof(T) - i - 1));
            x = x + key[i];
        }
        return x;
    }
#endif /* end section for C++ only */
}MyKey;


#ifdef __cplusplus
extern "C" {
#endif
void printKey(MyKey key);
#ifdef __cplusplus
}
#endif