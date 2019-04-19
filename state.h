#ifndef _STATE_H_
#define _STATE_H_

#include <vector>
#include <cstring>

#include "types.h"

const int kSide = 3;

/**
 * ゲームの状態
 */
struct State
{
private:
  PlayerType winner; // 勝利したプレイヤ

public:
  Cell board[kSide][kSide]; // ボード全体
  PlayerType now_player;    // 現在の手番プレイヤ

  State() = default;
  ~State();

  /**
   * 状態の初期化
   */
  void init();

  /**
   * ゲームが終了しているかどうかを返す
   */
  bool isEnd();

  /**
   * 何も置かれていないセルの座標をまとめて返す
   */
  std::vector<std::pair<int, int>> getEmptyCells();

  /**
   * 勝利したプレイヤを返す
   */
  PlayerType getWinner();
};

#endif // _STATE_H_
