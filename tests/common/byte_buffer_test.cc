#include "common/byte_buffer.h"

#include <gtest/gtest.h>

namespace {
  TEST(ByteBufferTest, PutAndGetBytesTest) {
    simpledb::ByteBuffer byte_buffer(5);

    const std::vector<std::byte> bytes = {std::byte{1}, std::byte{2}, std::byte{3}};

    byte_buffer.PutBytes(0, bytes);

    const auto output = byte_buffer.GetBytes(0, 1);

    ASSERT_EQ(output, std::vector<std::byte>({std::byte{1}}));
  }
}  // namespace
