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

template <typename T, std::size_t N, std::size_t... M>
struct MatrixGen
{
    using Type = std::array<typename MatrixGen<T, M...>::Type, N>;
};

template <typename T, std::size_t N>
struct MatrixGen<T,N>
{
    using Type = std::array<T, N>;
};


template<typename T,std::size_t ...N>
using Matrix = typename MatrixGen<T,N...>::Type;

template <size_t wide, size_t hight>
using GameGrade     = Matrix<short,hight,wide>;// It used to be short[hight][wide];
using BlockPoint    = Matrix<short,2>;//short[2];
using BlockDescribe = Matrix<BlockPoint,4>;//BlockPoint[4];
using BlockShape    = GameGrade<4, 4>;
template <size_t wide, size_t hight>
class Tetries
{
private:
    GameGrade<wide, hight> gameBoard;

public:
};

using StanderdTetries = Tetries<10, 20>;
}  // namespace Tetries
