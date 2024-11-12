#include "common_search.h"
#include <gtest/gtest.h>

namespace {

TEST(difference, isApproximatelyRight) {
  // EXPECT_EQ(DIFF, -0.58578643762);
  EXPECT_LT(CommonSearch::DIFF, -0.58578643762);
  EXPECT_GT(CommonSearch::DIFF, -0.58578643763);
}

TEST(movementCost, oneStepStraight) {
  EXPECT_EQ(CommonSearch::heuristics(1,1, 2, 1), 1.0);
  EXPECT_EQ(CommonSearch::heuristics(1,1, 1, 2), 1.0);
  EXPECT_EQ(CommonSearch::heuristics(1,1, 0, 1), 1.0);
  EXPECT_EQ(CommonSearch::heuristics(1,1, 1, 0), 1.0);
}
TEST(movementCost, diagonalCost) {
  EXPECT_EQ(CommonSearch::heuristics(1,1, 2, 2), CommonSearch::DIAG);
  EXPECT_EQ(CommonSearch::heuristics(1,1, 2, 0), CommonSearch::DIAG);
  EXPECT_EQ(CommonSearch::heuristics(1,1, 0, 0), CommonSearch::DIAG);
  EXPECT_EQ(CommonSearch::heuristics(1,1, 0, 2), CommonSearch::DIAG);
}

TEST(movent, usesOctile) {
  // EXPECT_NE(3 * CommonSearch::DIFF + 2,3 );
  EXPECT_EQ(CommonSearch::heuristics(14, 18, 17, 23), 3 * CommonSearch::DIAG + 2);
}

}// double heuristics(int nodex, int nodey, int goalx, int goaly, double diff) {
