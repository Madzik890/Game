#include <gtest/gtest.h>

#include "randomengine.hpp"

static constexpr const auto LEVEL = GameLevel::hard;

TEST(RandomEngine, validateNumber)
{    
  RandomEngine engine;

  const auto numbers = engine.generateNumber(LEVEL);
  ASSERT_TRUE(engine.validateAnswer(numbers.first * numbers.second));
}

TEST(RandomEngine, invalidValidateNumber)
{    
  RandomEngine engine;

  const auto numbers = engine.generateNumber(LEVEL);
  ASSERT_FALSE(engine.validateAnswer(numbers.first));
}

TEST(RandomEngine, validateGetters)
{    
  RandomEngine engine;

  const auto numbers = engine.generateNumber(LEVEL);

  ASSERT_EQ(numbers.first, engine.getFirstNumber());
  ASSERT_EQ(numbers.second, engine.getSecondNumber());
  ASSERT_EQ(numbers.first * numbers.second, engine.getExpectedResult());
}