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

    bool operator ==(const MyKey& e) const {
        uint64_t l = *this;
        uint64_t r = e;
        return l == r;
    }

    bool operator <(const MyKey& e) const {
        uint64_t l = *this;
        uint64_t r = e;
        return l < r;
    }

    MyKey(int len){
        this->len = len;
        if(this->len){
            this->key = new uint8_t[len];
        }
    }

    // MyKey(){
    //     return MyKey(0);
    // }

#endif /* end section for C++ only */
}MyKey;


#ifdef __cplusplus
inline bool operator ==(const MyKey& lhs, const MyKey& rhs) {
    uint64_t l = lhs;
    uint64_t r = rhs;
    return l == r;
}

inline bool operator <(const MyKey& lhs, const MyKey& rhs) {
    uint64_t l = lhs;
    uint64_t r = rhs;
    return l < r;
}

// inline MyKey& operator +(const MyKey& lhs, int num) {
//     lhs[lhs.len-1] = lhs[lhs.len-1] + num;
//     return lhs;
// }

extern "C" {
#endif
void printKey(MyKey key);
void *initpgm();
void insertKey(void *pgm, MyKey key, uint32_t value);
uint32_t readKey(void *pgm, MyKey key);
#ifdef __cplusplus
}
#endif