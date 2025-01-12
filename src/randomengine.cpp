#include "randomengine.hpp"

RandomEngine::RandomEngine()
  : mDev(),
    mRng(mDev())
{
}

std::pair<unsigned int, unsigned int> RandomEngine::generateNumber(GameLevel level) noexcept
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

  std::uniform_int_distribution<std::mt19937::result_type> dist6(1,multipler); 
  mFirstNumber = dist6(mRng);
  mSecondNumber = dist6(mRng);
  mExpectedResult = mFirstNumber * mSecondNumber;
  return {mFirstNumber, mSecondNumber};
}

bool RandomEngine::validateAnswer(unsigned int result) const noexcept
{
  return result == mExpectedResult;
}