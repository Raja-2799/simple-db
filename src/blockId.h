#include <cstdint>
#include <string>
namespace simpledb {
  class BlockId {
   public:
    BlockId(const std::string& file_name, int32_t block_num);

    std::string file_name() const;
    int32_t block_num() const;

   private:
    std::string file_name_;
    int32_t block_num_;
  };
}  // namespace simpledb