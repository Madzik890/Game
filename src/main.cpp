#include <cstdint>
#include <iostream>

#include "common.hpp"
#include "gamemanager.hpp"

static constexpr const auto GAME_ENGINE = GameEngine::Random;

int main()
{
  GameManager game;

  game.setGameEngine(GAME_ENGINE);

  std::cout << "Witaj w programie do nauki tabliczki mnozenia!" << std::endl;
  std::cout << "Podawaj odpowiedzi na zadane pytania." << std::endl;
  std::cout << "Aby zakonczyc, wpisz 'n'." << std::endl;

  std::cout << "Poziomy gry: " << std::endl;
  std::cout << "Poziom 1: liczby losowane z przedziału 1-10" << std::endl;
  std::cout << "Poziom 2: liczby losowane z przedziału 1-20" << std::endl;
  std::cout << "Poziom 3: liczby losowane z przedziału 1-50" << std::endl;
  
  GameLevel level;
  {
    uint8_t levelRaw;
    std::cout << "Podaj poziom gry: ";
    std::cin >> levelRaw;
    level = static_cast<GameLevel>(levelRaw);
  }

  while(true)
  {
    const auto numbers = game.generateNumber(level);

    std::cout << "Ile to jest " << numbers.first << " * " << numbers.second << " ?" << std::endl;
    unsigned int result = 0;
    std::cin >> result;

    if(game.validateAnswer(result))
    {
      std::cout << "Brawo! Poprawna odpowiedz." << std::endl;
    }
    else 
    {
      std::cout << "Niestety, zla odpowiedz. Poprawna odpowiedz to " << game.getExpectedResult() << "." << std::endl;
    }

    char wantToContinue;
    std::cout << "Czy chcesz kontynuowac? (t/n): ";
    std::cin >> wantToContinue;
    if(wantToContinue == 'n' || wantToContinue == 'N')
      break;
  }

  std::cout << "Twoje statystki: " << std::endl;
  {
    const auto &gameStatistics = game.getGameStatistics();
    std::cout << "Poprawne odpowiedzi: " << gameStatistics.success << std::endl;
    std::cout << "Niepoprawne odpowiedzi: " << gameStatistics.failed << std::endl;
  }

  return 0;
}