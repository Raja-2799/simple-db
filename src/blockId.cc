#include "blockId.h"

#include <cstdint>
#include <string>

namespace simpledb {
  BlockId::BlockId(const std::string filename, int32_t block_num)
      : filename_(filename), block_num_(block_num) {}

  const std::string& BlockId::GetFileName() const { return filename_; }

  int32_t BlockId::GetBlockNum() const { return block_num_; }

}  // namespace simpledb