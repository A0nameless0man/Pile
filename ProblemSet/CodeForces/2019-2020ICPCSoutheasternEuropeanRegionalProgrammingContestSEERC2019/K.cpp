#include <iostream>
const int MAX_N      = 507;
const int G_COUNT    = 6;
const int G_DIR[][3] = {
    {
      0,
      0,
      1,
    },
    {
      0,
      0,
      -1,
    },
    {
      0,
      1,
      0,
    },
    {
      0,
      -1,
      0,
    },
    {
      1,
      0,
      0,
    },
    {
      -1,
      0,
      0,
    },
};
struct Pos
{
    int x, y, z;
};
Pos move[MAX_N][MAX_N][MAX_N][G_COUNT];  // where the rob will end at when
enum Block
{
    vac,
    block
};
Block map[MAX_N][MAX_N][MAX_N];
