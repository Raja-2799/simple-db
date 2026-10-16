#include "byte_buffer.h"
namespace simpledb {
  namespace {
    void CheckOverflow(size_t byte_array_size, size_t input_len, size_t input_offset) {
      if (input_offset > byte_array_size || input_len > byte_array_size - input_offset) {
        throw std::out_of_range("offset out of bounds");
      }
    }
  }  // namespace
  ByteBuffer::ByteBuffer(size_t size) : byte_array_(size), position_(0) {}

  int32_t ByteBuffer::GetInt(size_t offset) {
    CheckOverflow(byte_array_.size(), sizeof(int32_t), offset);
    int32_t val = 0;
    for (size_t i = 0; i < sizeof(int32_t); i++) {
      val = (val << 8) | std::to_integer<unsigned char>(byte_array_[offset + i]);
    }
    return val;
  }

  void ByteBuffer::PutInt(size_t offset, int32_t data) {
    CheckOverflow(byte_array_.size(), sizeof(int32_t), offset);
    uint32_t unsigned_value = static_cast<uint32_t>(data);
    for (size_t i = 0; i < sizeof(int32_t); i++) {
      size_t shift = 8 * (sizeof(int32_t) - i - 1);
      byte_array_[offset + i] = std::byte((unsigned_value >> shift) & 0xFF);
    }
  }

  std::vector<std::byte> ByteBuffer::GetBytes(size_t offset, size_t len) {
    CheckOverflow(byte_array_.size(), len, offset);
    std::vector<std::byte> bytes(len);
    for (size_t i = 0; i < len; i++) {
      bytes[i] = byte_array_[offset + i];
    }
    return bytes;
  }

  void ByteBuffer::PutBytes(size_t offset, const std::vector<std::byte>& bytes) {
    size_t len = bytes.size();
    CheckOverflow(byte_array_.size(), len, offset);
    for (size_t i = 0; i < len; i++) {
      byte_array_[offset + i] = bytes[i];
    }
  }

  void ByteBuffer::set_position(size_t position) {
    if (position > byte_array_.size()) {
      throw std::out_of_range("set_position: position out of bounds");
    }
    position_ = position;
  }

  size_t ByteBuffer::get_position() const { return position_; }

}  // namespace simpledb