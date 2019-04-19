#include "state.h"

/**
 * 状態の初期化
 */
void State::init()
{
  std::memset(board, EMPTY, sizeof board);
  now_player = FIRST;
  winner = NONE;
}

/**
 * 現在の状態が終端状態かどうか
 */
bool State::isEnd()
{
  // いずれかの行がマルまたはバツで埋まっていたら真
  for (int h = 0; h < kSide; ++h)
  {
    // 埋まってないなら飛ばす
    if (board[h][0] == EMPTY)
    {
      continue;
    }

    Cell tmp_cell = board[h][0];
    bool is_complete = true;

    for (int w = 1; w < kSide; ++w)
    {
      if (tmp_cell != board[h][w])
      {
        is_complete = false;
        break;
      }
    }

    // 完成している
    if (is_complete)
    {
      winner = (tmp_cell == CIRCLE ? FIRST : SECOND);
      return true;
    }
  }

  // いずれかの列がマルまたはバツで埋まっていたら真
  for (int w = 0; w < kSide; ++w)
  {
    // 埋まってないなら飛ばす
    if (board[0][w] == EMPTY)
    {
      continue;
    }

    Cell tmp_cell = board[0][w];
    bool is_complete = true;

    for (int h = 1; h < kSide; ++h)
    {
      if (tmp_cell != board[h][w])
      {
        is_complete = false;
        break;
      }
    }

    if (is_complete)
    {
      winner = (tmp_cell == CIRCLE ? FIRST : SECOND);
      return true;
    }
  }

  // 右斜めまたは左斜めがマルまたはバツで埋まっていたら真
  // 右斜め
  if (board[0][0] != EMPTY)
  {
    Cell tmp_cell = board[0][0];
    bool is_complete = true;

    for (int i = 1; i < kSide; ++i)
    {
      if (tmp_cell != board[i][i])
      {
        is_complete = false;
        break;
      }
    }

    if (is_complete)
    {
      winner = (tmp_cell == CIRCLE ? FIRST : SECOND);
      return true;
    }
  }

  // 左斜め
  if (board[0][kSide - 1] != EMPTY)
  {
    Cell tmp_cell = board[0][kSide - 1];
    bool is_complete = true;

    for (int i = 1; i < kSide; ++i)
    {
      if (tmp_cell != board[i][kSide - 1 - i])
      {
        is_complete = false;
        break;
      }
    }

    if (is_complete)
    {
      winner = (tmp_cell == CIRCLE ? FIRST : SECOND);
      return true;
    }
  }

  // それ以外ならゲームは終了していない
  return false;
}

/**
 * 空のセルの座標をまとめて返す
 * 関数名変更した方がいいかも
 */
std::vector<std::pair<int, int>> State::getEmptyCells()
{
  std::vector<std::pair<int, int>> ret;

  for (int h = 0; h < kSide; ++h) {
    for (int w = 0; w < kSide; ++w) {
      if (board[h][w] == EMPTY) {
        ret.push_back(std::make_pair(h, w));
      }
    }
  }

  return ret;
}

/**
 * 勝利したプレイヤを返す
 */
PlayerType State::getWinner()
{
  return winner;
}
