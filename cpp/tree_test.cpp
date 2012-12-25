#include "tree.h"
#include "gtest/gtest.h"
#include <iostream>
#include "RetroPrinter.h"
#include <string>

using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using std::string;
using std::cout;
using std::endl;

namespace {

// The fixture for testing class Tree
class TreeTest : public ::testing::Test {
private:
  Tree* tree;

protected:
  
  TreeTest() {
    // You can do set-up work for each test here.
    //    std::cout << "TreeTest()" << std::endl;
    tree = new Tree();
  }

  virtual ~TreeTest() {
    // You can do clean-up work that doesn't throw exceptions here.
    delete tree;
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    //    std::cout << "TreeTest TearDown" << std::endl;
  }
  Tree t1;
  Tree t2;
};

TEST_F(TreeTest, InsertNode) {
  EXPECT_EQ(t1.size(), 0);
  t1.insert(5);
  EXPECT_EQ(t1.size(), 1);
}

TEST_F(TreeTest, PrintTree) {
  // string foo("this is a string");
  // string bar("another string");
  // string baz("this is a string");
  // string baf("another string");
  // EXPECT_EQ(foo.compare(baz), 0);
  // EXPECT_EQ(bar.compare(baf), 0);
  // EXPECT_NE(foo.compare(bar), 0);
  // EXPECT_NE(baz.compare(baf), 0);
  
}

}  // namespace

int main(int argc, char **argv) {
  InitGoogleTest(&argc, argv);
  UnitTest& unit_test = *UnitTest::GetInstance();
  TestEventListeners& listeners = unit_test.listeners();

  // if we don't want the default listener printing anything, remove it:
  delete listeners.Release(listeners.default_result_printer());

  // if we do want our custom listener to record success/fail, add it:
  listeners.Append(new RetroPrinter);

  return RUN_ALL_TESTS();
}
