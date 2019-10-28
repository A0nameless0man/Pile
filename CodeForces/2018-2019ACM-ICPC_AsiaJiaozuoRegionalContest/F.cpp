#include <iostream>
#include <vector>
#include <queue>
const size_t MAX_N = 1007;
const size_t INF = 0x7ffffff;
int8_t map[MAX_N][MAX_N];
int dis[MAX_N][MAX_N];
const int DIRS = 6;
const int DIR[2][DIRS][2] =
    {
        {//0,2,4,
            {1, -1},
            {1, 0},
            {0, 1},
            {-1, 0},
            {-1, -1},
            {0, -1}
        }
        ,
        {//1,3,5,
            {1, 0},
            {1, 1},
            {0, 1},
            {-1, 1},
            {-1, 0},
            {0, -1}
        }
    };
/*
+---------->+x
|
|  (x,y)
|
|
v +y
   +---5---+
  /      \
  4      0
 /        \
+          +
 \        /
  3       1
  \      /
   +---2---+
*/
void init(int x,int y)
{
    for(int i=0;i<x;i++)
    {
        for(int j = 0;j<y;j++)
        {
            map[i][j]=0x00;
            dis[i][j]=INF;
        }
    }
}