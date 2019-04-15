#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "state.h"

class Player
{
  Player() = default;
  ~Player();

  /**
   * 行動を決定する
   */
  std::pair<int, int> selectAction(const State &state);
};

#endif // _PLAYER_H_