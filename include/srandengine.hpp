#ifndef SRANDGAMEENGINE_HPP
#define SRANDGAMEENGINE_HPP

#include <utility>
#include <mutex>

#include "common.hpp"

class SRandGameEngine final 
{ 
  private:  
    inline static std::once_flag mInitSrand {};    

  public:
    SRandGameEngine(); 

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
};

#endif