#include "common_search_utils.h"
#include <gtest/gtest.h>

namespace {

TEST(difference, isApproximatelyRight) {
  // EXPECT_EQ(DIFF, -0.58578643762);
  EXPECT_LT(CommonSearchUtils::DIFF, -0.58578643762);
  EXPECT_GT(CommonSearchUtils::DIFF, -0.58578643763);
}

TEST(movementCost, oneStepStraight) {
  EXPECT_EQ(CommonSearchUtils::heuristics(1,1, 2, 1), 1.0);
  EXPECT_EQ(CommonSearchUtils::heuristics(1,1, 1, 2), 1.0);
  EXPECT_EQ(CommonSearchUtils::heuristics(1,1, 0, 1), 1.0);
  EXPECT_EQ(CommonSearchUtils::heuristics(1,1, 1, 0), 1.0);
}
TEST(movementCost, diagonalCost) {
  double diag = sqrt(2.0) - 2.0;
  EXPECT_EQ(CommonSearchUtils::heuristics(1,1, 2, 2), diag);
  EXPECT_EQ(CommonSearchUtils::heuristics(1,1, 2, 0), diag);
  EXPECT_EQ(CommonSearchUtils::heuristics(1,1, 0, 0), diag);
  EXPECT_EQ(CommonSearchUtils::heuristics(1,1, 0, 2), diag);
}

TEST(movent, usesOctile) {
  EXPECT_NE(3 * CommonSearchUtils::DIFF + 1,3 );
  EXPECT_EQ(CommonSearchUtils::heuristics(14, 18, 11, 13), 3 * CommonSearchUtils::DIFF + 2);
}

}// double heuristics(int nodex, int nodey, int goalx, int goaly, double diff) {
