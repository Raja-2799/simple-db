#include "blockId.h"
namespace simpledb {
  BlockId::BlockId(const std::string& file_name, int32_t block_num)
      : file_name_(file_name), block_num_(block_num) {}

  std::string BlockId::file_name() const { return file_name_; }
  int32_t BlockId::block_num() const { return block_num_; }
}  // namespace simpledb