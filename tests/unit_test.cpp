#include "gtest/gtest.h"
#include "LatexTests.hpp"

#include "rdudh001_tests.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
