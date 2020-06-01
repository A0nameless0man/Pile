#pragma once
#include <array>
#include <map>

namespace Tetries
{
template <typename T, std::size_t N, std::size_t... M>
struct MatrixGen
{
    using Type = std::array<typename MatrixGen<T, M...>::Type, N>;
};

template <typename T, std::size_t N>
struct MatrixGen<T, N>
{
    using Type = std::array<T, N>;
};

template <typename T, std::size_t... N>
using Matrix = typename MatrixGen<T, N...>::Type;

using byte = char;
enum class Block
{
    I = 0,
    J,
    L,
    O,
    S,
    T,
    Z
};
enum class Rotate
{
    UP,
    RIGHT,
    DOWN,
    LEFT
};
template <size_t wide, size_t hight>
using GameGrade     = Matrix<byte, hight, wide>;  // It used to be short[hight][wide];
using BlockPoint    = Matrix<byte, 2>;            // short[2];
using BlockDescribe = Matrix<BlockPoint, 4>;      // BlockPoint[4];
using BlockShape    = GameGrade<4, 4>;
static const std::array<BlockShape, static_cast<size_t>(Block::Z)> blockShape = {
    { {1, 1, 1, 1  },
    {  { 1, 0, 0, 0, 1, 1, 1, 0 } },
    { { 0, 0, 1, 0, 1, 1, 1, 0 } }
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
class Tetries
{
private:
    GameGrade<wide, hight> gameBoard;
    Block                  next;
    Tetries<wide, hight> & generateNext(void);

public:
    Block                 getNext(void);
    bool                  tryPutNextAt(size_t x, size_t y, Rotate r);
    Tetries<wide, hight> &putNextAt(size_t x, size_t y, Rotate r);
};

using StanderdTetries = Tetries<10, 20>;
}  // namespace Tetries
