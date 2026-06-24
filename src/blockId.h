#pragma once

#include <cstdint>
#include <string>

namespace simpledb {
  class BlockId {
   public:
    BlockId(std::string filename, int32_t block_num);
    std::string& GetFileName() const;
    int32_t GetBlockNum() const;

   private:
    std::string filename_;
    int32_t block_num_;
  };
}  // namespace simpledb