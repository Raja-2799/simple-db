#pragma once

#include <cstdint>
#include <string>

namespace simpledb {
  class BlockId {
   public:
    BlockId(const std::string filename, int32_t block_num);
    const std::string& GetFileName() const;
    int32_t GetBlockNum() const;

   private:
    const std::string filename_;
    const int32_t block_num_;
  };
}  // namespace simpledb