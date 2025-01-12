#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>

enum GameLevel : uint8_t
{
  easy, //1-10
  medium, //1-20
  hard //1-50
};

enum GameEngine : uint8_t
{
  SrandEngine,
  Random
};

#endif