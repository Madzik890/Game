#include "srandengine.hpp"
#include "common.hpp"

#include <cstdlib>
#include <ctime>

SRandGameEngine::SRandGameEngine()
{  
  std::call_once(mInitSrand, &::srand, time(nullptr));
}

std::pair<unsigned int, unsigned int> SRandGameEngine::generateNumber(GameLevel level) noexcept
{
  short multipler = 10;
  switch(level)
  {
    case GameLevel::easy:
      multipler = 10;
    break;
    case GameLevel::medium:
      multipler = 20;
    break;
    default:
      multipler = 50;
    break;
  }

  mFirstNumber = ::rand() % multipler + 1;
  mSecondNumber = ::rand() % multipler + 1;
  mExpectedResult = mFirstNumber * mSecondNumber;
  return {mFirstNumber, mSecondNumber};
}

bool SRandGameEngine::validateAnswer(unsigned int result) const noexcept
{
  return result == mExpectedResult;
}