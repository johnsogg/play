
#include "tree.h"
#include "gtest/gtest.h"
#include <iostream>
#include "RetroPrinter.h"

using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;

namespace {

// The fixture for testing class Tree
class TreeTest : public ::testing::Test {
 protected:

  TreeTest() {
    // You can do set-up work for each test here.
    std::cout << "TreeTest()" << std::endl;
    Tree* t = new Tree();
  }

  virtual ~TreeTest() {
    // You can do clean-up work that doesn't throw exceptions here.
    std::cout << "~TreeTest()" << std::endl;
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
    std::cout << "TreeTest SetUp" << std::endl;
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    std::cout << "TreeTest TearDown" << std::endl;
  }

};

TEST_F(TreeTest, InsertNode) {
    std::cout << "TEST_F runs for TreeTest InsertNode" << std::endl;
}

TEST_F(TreeTest, PrintTree) {
    std::cout << "TEST_F runs for TreeTest PrintTree" << std::endl;
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
