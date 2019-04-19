#ifndef _TYPES_H_
#define _TYPES_H_

/**
 * セルの状態
 */
enum Cell
{
  EMPTY = 0,  // 無
  CIRCLE = 1, // マル
  CROSS = 2,  // バツ
};

/**
 * プレイヤの種類
 */
enum PlayerType
{
  FIRST = 0,  // 先手 ... 先手はマルとする
  SECOND = 1, // 後手 ... 後手がバツとする
  NONE = 2,   // どちらでもない
};

inline PlayerType getOppType(PlayerType& my_type) {
  return !my_type;
}

#endif // _TYPES_H_
