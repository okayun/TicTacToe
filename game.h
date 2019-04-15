#ifndef _GAME_H_
#define _GAME_H_

#include "state.h"
#include "player.h"

class Game
{
  State state;
  Player player[2];

  Game() = default;
  ~Game();

  /**
   * ゲームの初期化
   */
};

#endif // _GAME_H_