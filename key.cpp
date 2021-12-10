#include "key.h"
#include "PGM-index/include/pgm/pgm_index_dynamic.hpp"

void printKey(MyKey key){
    uint64_t ret = key;
    printf("%llu\n", ret);
}

void *initpgm(){
    pgm::DynamicPGMIndex<uint64_t, uint32_t> * pgm_index = new pgm::DynamicPGMIndex<uint64_t, uint32_t>();
    void *ret = (void *)pgm_index;
    return ret;
}

void insertKey(void *pgm, MyKey key, uint32_t value){
    pgm::DynamicPGMIndex<uint64_t, uint32_t> * pgm_index = (pgm::DynamicPGMIndex<uint64_t, uint32_t> *)pgm;
    pgm_index->insert_or_assign(key, value);
    printf("insert done\n");
}

uint32_t readKey(void *pgm, MyKey key){
    pgm::DynamicPGMIndex<uint64_t, uint32_t> * pgm_index = (pgm::DynamicPGMIndex<uint64_t, uint32_t> *)pgm;
    auto item = pgm_index->find(key);
    uint32_t value = item->second;
    return value;
}

// void *initpgm(){
//     pgm::DynamicPGMIndex<MyKey, uint32_t> * pgm_index = new pgm::DynamicPGMIndex<MyKey, uint32_t>();
//     void *ret = (void *)pgm_index;
//     return ret;
// }

// void insertKey(void *pgm, MyKey key, uint32_t value){
//     pgm::DynamicPGMIndex<MyKey, uint32_t> * pgm_index = (pgm::DynamicPGMIndex<MyKey, uint32_t> *)pgm;
//     pgm_index->insert_or_assign(key, value);
//     printf("insert done\n");
// }

// uint32_t readKey(void *pgm, MyKey key){
//     pgm::DynamicPGMIndex<MyKey, uint32_t> * pgm_index = (pgm::DynamicPGMIndex<MyKey, uint32_t> *)pgm;
//     auto item = pgm_index->find(key);
//     uint32_t value = item->second;
//     return value;
// }

// int main(){
//     MyKey key;
//     key.len = 4;
//     key.key = new uint8_t[key.len];
//     printKey(key);
// }
