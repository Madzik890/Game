#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <utility>
#include <variant>

#include "common.hpp"
#include "srandengine.hpp"
#include "randomengine.hpp"

struct GameStatistics final
{
  unsigned int success = 0;
  unsigned int failed = 0;
};

class GameManager final 
{  
  public:
    void setGameEngine(GameEngine engine) noexcept;    

  public:
    std::pair<unsigned int, unsigned int> generateNumber(GameLevel level) noexcept;
    bool validateAnswer(unsigned int result) noexcept;
    int getExpectedResult() const noexcept;
    const GameStatistics &getGameStatistics() const noexcept { return mGameStatistics; }

  private:  
    GameStatistics mGameStatistics;
    std::variant<SRandGameEngine, RandomEngine> mGameEngine;    
};

#endif