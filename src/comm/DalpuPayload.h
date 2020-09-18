#include <iostream>

class DalpuPayload {
    public:
        DalpuPayload(uint64_t* msg, uint8_t length);
        static const uint8_t BIT128_TO_BYTES = 16;
        static const uint32_t MAX_SIZE = 1024;
    public: 
      uint8_t input[MAX_SIZE];
	  uint8_t output[MAX_SIZE];
      uint8_t chunkCount;
      uint8_t chunkTotalBytes;
    public:
      uint8_t getChunkNum() const { return chunkCount; }
      uint8_t getTotalChunkBytes() const { return chunkTotalBytes; }
      void copyChunkBytes(uint8_t output[MAX_SIZE]) {
          memcpy(output, input, chunkTotalBytes);
      }
      void updateMessage(uint64_t* msg);

      bool compare_uint8(uint8_t* a, uint8_t* b, uint8_t size);
      bool compare_uint64(uint64_t* a, uint64_t* b, uint8_t size);
      void print_status() { std::cout<< "chunk Count : "<<(uint32_t)chunkCount << " Total Bytes of Chunk : "<< (uint32_t)chunkTotalBytes << std::endl; }
      void print_input() { 
          for(int i=0; i<MAX_SIZE; i++) {
              std::cout<< (uint32_t)input[i] << " ";
          }
          std::cout<<std::endl;
      }
};
