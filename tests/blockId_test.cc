#include "blockId.h"

#include <gtest/gtest.h>

TEST(BlockIdTest, ConstructorStoresValue) {
  simpledb::BlockId blockId("samplefile.db", 2);

  ASSERT_EQ("samplefile.db", blockId.file_name());
  ASSERT_EQ(2, blockId.block_num());
}