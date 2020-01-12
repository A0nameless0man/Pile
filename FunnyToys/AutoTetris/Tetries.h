#pragma once
#include <array>

namespace Tetries
{
enum Block
{
    I = 0,
    J,
    L,
    O,
    S,
    T,
    Z
};
/*
----I
****
----J
*
***
----L
  *
***
----O
**
**
----S
 **
**
----T
 *
***
----Z
**
 **
----
*/

template <size_t wide, size_t hight>
using GameGrade  = short[hight][wide];
using BlockPoint = short[2];
using BlockDescribe = BlockPoint[4];
using BlockShape = GameGrade<4, 4>;
template <size_t wide, size_t hight>
class Tetries
{
private:
    GameGrade<wide, hight> gameBoard;

public:
};

using StanderdTetries = Tetries<10,20>;
}  // namespace Tetries
