#include "gamemanager.hpp"
#include "common.hpp"
#include "randomengine.hpp"
#include "srandengine.hpp"
#include <variant>

void GameManager::setGameEngine(GameEngine engine) noexcept
{
  mGameStatistics = {};
  
  switch(engine)
  {
    case GameEngine::SrandEngine:
    {
      mGameEngine.emplace<SRandGameEngine>();
      break;
    } 

    default:
    case GameEngine::Random:
    {
      mGameEngine.emplace<RandomEngine>();
      break;
    }
  }
}

std::pair<unsigned int, unsigned int> GameManager::generateNumber(GameLevel level) noexcept
{
  return std::visit([&level](auto &&engine){
    return engine.generateNumber(level);
  }, mGameEngine);
}

bool GameManager::validateAnswer(unsigned int result) noexcept
{
  const auto validation = std::visit([&result](auto &&engine){
    return engine.validateAnswer(result);
  }, mGameEngine);

  if(validation)
    mGameStatistics.success++;
  else 
    mGameStatistics.failed++;  

  return validation;
}

int GameManager::getExpectedResult() const noexcept
{
  return std::visit([](const auto &game){
    return game.getExpectedResult();
  }, mGameEngine);
}