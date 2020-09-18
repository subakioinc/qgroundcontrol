#include "DalpuPayload.h"

DalpuPayload::DalpuPayload(uint64_t* msg, uint8_t length) {
    memset(input, 0, MAX_SIZE);
    chunkCount = length / BIT128_TO_BYTES;
    chunkTotalBytes = chunkCount * BIT128_TO_BYTES;

    memcpy(input, (uint8_t *) msg, chunkTotalBytes);
}

bool DalpuPayload::compare_uint8(uint8_t* a, uint8_t* b, uint8_t size)
{
    for(int i=0; i<size; i++) {
        if (a[i] != b[i]) {
            std::cout<<"They're not same!! XXXXXX"<<std::endl;
            return false;
        }
    }
    std::cout<<"They're same! OOOOOO"<<std::endl;
    return true;
}
bool DalpuPayload::compare_uint64(uint64_t* a, uint64_t* b, uint8_t size)
{
    for(int i=0; i<size; i++) {
        if (a[i] != b[i]) {
            std::cout<<"They're not same!! XXXXXX"<<std::endl;
            return false;
        }
    }
    std::cout<<"They're same! OOOOOO"<<std::endl;
    return true;
}

void DalpuPayload::updateMessage(uint64_t* msg)
{
    memcpy((uint8_t *) msg, output, chunkTotalBytes);
}
