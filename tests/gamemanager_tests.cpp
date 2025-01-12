#include <gtest/gtest.h>

#include "gamemanager.hpp"

static constexpr const auto LEVEL = GameLevel::hard;

TEST(GameManager, validateStatistics)
{    
  GameManager game;  

  const auto &statistcs = game.getGameStatistics();
  const auto result = game.generateNumber(LEVEL);

  game.validateAnswer(result.first * result.second);
  ASSERT_EQ(statistcs.success, 1);
  

  game.validateAnswer(result.first);
  ASSERT_EQ(statistcs.failed, 1);
}