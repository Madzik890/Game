#ifndef RANDOMENGINE_HPP
#define RANDOMENGINE_HPP

#include <random>
#include <utility>

#include "common.hpp"

class RandomEngine final 
{
  public:
    RandomEngine();

  public:
    std::pair<unsigned int, unsigned int> generateNumber(GameLevel level) noexcept;
    bool validateAnswer(unsigned int result) const noexcept;

  public:
    unsigned int getFirstNumber() const noexcept { return mFirstNumber; }
    unsigned int getSecondNumber() const noexcept { return mSecondNumber; }
    unsigned int getExpectedResult() const noexcept { return mExpectedResult; }

  private:
    unsigned int mFirstNumber {0};
    unsigned int mSecondNumber {0};
    unsigned int mExpectedResult = {0};

  private:
    std::random_device mDev;
    std::mt19937 mRng;
};

#endif