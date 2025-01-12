#include <gtest/gtest.h>

#include "srandengine.hpp"

static constexpr const auto LEVEL = GameLevel::hard;

TEST(SrandEngine, validateNumber)
{    
  SRandGameEngine engine;

  const auto numbers = engine.generateNumber(LEVEL);
  ASSERT_TRUE(engine.validateAnswer(numbers.first * numbers.second));
}

TEST(SrandEngine, invalidValidateNumber)
{    
  SRandGameEngine engine;

  const auto numbers = engine.generateNumber(LEVEL);
  ASSERT_FALSE(engine.validateAnswer(numbers.first));
}

TEST(SrandEngine, validateGetters)
{    
  SRandGameEngine engine;

  const auto numbers = engine.generateNumber(LEVEL);

  ASSERT_EQ(numbers.first, engine.getFirstNumber());
  ASSERT_EQ(numbers.second, engine.getSecondNumber());
  ASSERT_EQ(numbers.first * numbers.second, engine.getExpectedResult());
}