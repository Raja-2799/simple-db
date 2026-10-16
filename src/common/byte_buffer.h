#include <vector>
namespace simpledb {
  class ByteBuffer {
   public:
    explicit ByteBuffer(size_t size);

    std::vector<std::byte> GetBytes(size_t offset, size_t len);
    void PutBytes(size_t offset, const std::vector<std::byte>& bytes);

    int32_t GetInt(size_t offset);
    void PutInt(size_t offset, int32_t input);

    size_t get_position() const;
    void set_position(size_t position);

   private:
    std::vector<std::byte> byte_array_;
    size_t position_;
  };
}  // namespace simpledb