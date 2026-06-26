#include "blockId.h"

#include <gtest/gtest.h>

TEST(BlockIdTest, ConstructorStoresValue) {
  simpledb::BlockId blockId("test.tbl", 1);

  ASSERT_EQ("test.tbl", blockId.GetFileName());
  ASSERT_EQ(1, blockId.GetBlockNum());
}
