#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

//#define DEBUG

const int MAX_M         = 100;
const int MAX_N         = 100;
const int DIR[4][2]     = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
using BlockID           = int;
const BlockID VOIDBLOCK = -1;

struct coordinate
{
    int x, y;
};

inline coordinate operator+(const coordinate pos, int dir)
{
    return { pos.x + DIR[dir][0], pos.y + DIR[dir][1] };
}

class Block
{
public:
    Block(): ableToLeaveViaPortal(false), vistied(false), portalCount(-1), portalFrom(VOIDBLOCK) {}
    std::vector<coordinate> member;
    std::set<BlockID>       edge;
    bool                    ableToLeaveViaPortal;
    bool                    vistied;
    int                     portalCount;
    BlockID                 portalFrom;
};

std::vector<Block> blocks;
BlockID            theBlockGroundBelongsTo[MAX_M][MAX_N];
bool               passable[MAX_M][MAX_N];
bool               visibility[MAX_M][MAX_N];
//+--------->y/n
//|
//|
//|
//|
// v
// x/m

inline bool isUnidedGround(int m, int n)
{
    return passable[m][n] && theBlockGroundBelongsTo[m][n] == VOIDBLOCK;
}

inline int setBlockID(coordinate pos, BlockID id)
{
    return theBlockGroundBelongsTo[pos.x][pos.y] = id;
}

int getBlockID(int m, int n)
{
    if(isUnidedGround(m, n))
    {
        int currentID = blocks.size();
        blocks.push_back(Block());
        std::queue<coordinate> que;  // BFS based on queue;
        que.push({ m, n });
        while(!que.empty())
        {
            coordinate curPos = que.front();
            que.pop();
            setBlockID(curPos, currentID);
            blocks[currentID].member.push_back(curPos);
            for(size_t i = 0; i < 4; i++)
            {
                if(isUnidedGround(curPos.x + DIR[i][0], curPos.y + DIR[i][1]))
                {
                    que.push(curPos + i);
                    setBlockID(curPos + i, currentID);
                }
            }
        }
        return currentID;
    }
    else
    {
        return theBlockGroundBelongsTo[m][n];
    }
}

inline int getBlockID(coordinate pos)
{
    return getBlockID(pos.x, pos.y);
}

std::set<BlockID> &getPossiblePortal(coordinate pos, std::set<BlockID> &ans)
{
    if(visibility[pos.x][pos.y])
    {
        for(int i = 0; i < 4; i++)
        {
            int dis = 1;
            while(visibility[pos.x + dis * DIR[i][0]][pos.y + dis * DIR[i][1]])
            {
                ++dis;
            }
            --dis;
            if(passable[pos.x + dis * DIR[i][0]][pos.y + dis * DIR[i][1]])
            {
                ans.insert(getBlockID(pos.x + dis * DIR[i][0], pos.y + dis * DIR[i][1]));
            }
        }
    }
    return ans;
}

inline bool nextToWall(coordinate pos)
{
    if(passable[pos.x][pos.y])
    {
        for(int i = 0; i < 4; i++)
        {
            if(!visibility[pos.x + DIR[i][0]][pos.y + DIR[i][1]])
            {
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    long    T = 0;
    int     m, n, sx = 0, sy = 0, tx = 0, ty = 0, ans = -1;
    BlockID sBlock, tBlock;
    // std::ios::sync_with_stdio(false);
    std::cin >> T;
    // std::cout<<0<<std::endl;
    // std::cout<<T<<std::endl;
    while(T--)
    // while (std::cin >> m >> n)
    {
        // input
        {
            std::cin >> m >> n;
        }

        // ini
        {
            blocks.clear();
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    theBlockGroundBelongsTo[i][j] = VOIDBLOCK;
                    passable[i][j]                = false;
                    visibility[i][j]              = false;
                }
            }
        }

        // read map
        {
            for(int i = 0; i < m; i++)
            {
                std::string input;
                std::cin >> input;
                for(int j = 0; j < n; j++)
                {
                    switch(input[j])
                    {
                        case '.':
                            visibility[i][j] = true;
                            passable[i][j]   = false;
                            break;
                        case 'w':
                            visibility[i][j] = false;
                            passable[i][j]   = false;
                            break;
                        case 'g':
                            visibility[i][j] = true;
                            passable[i][j]   = true;
                            break;
                        case 'p':
                            visibility[i][j] = true;
                            passable[i][j]   = true;
                            sx               = i;
                            sy               = j;
                            break;
                        case 'e':
                            visibility[i][j] = true;
                            passable[i][j]   = true;
                            tx               = i;
                            ty               = j;
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        // BFS for connected Block
        {
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    getBlockID(i, j);
                }
            }
        }

        // search for edges
        {
            for(BlockID id = 0; id < (int) blocks.size(); id++)
            {
                Block &currentBlock = blocks[id];
                for(coordinate pos: currentBlock.member)
                {
                    if(nextToWall(pos))
                    {
                        currentBlock.ableToLeaveViaPortal = true;
                        break;
                    }
                }
                if(blocks[id].ableToLeaveViaPortal)
                {
                    for(coordinate pos: currentBlock.member)
                    {
                        getPossiblePortal(pos, currentBlock.edge);
                    }
                }
            }
        }

        // BFS for route
        {
            sBlock = getBlockID(sx, sy);
            tBlock = getBlockID(tx, ty);
            if(sBlock != tBlock)
            {
                if(blocks[sBlock].ableToLeaveViaPortal)
                {
                    std::queue<BlockID> que;
                    que.push(sBlock);
                    blocks[sBlock].portalCount = 1;
                    blocks[sBlock].vistied     = true;
                    while(!que.empty())
                    {
                        BlockID curBlockID = que.front();
                        Block & curBlock   = blocks[curBlockID];
                        for(BlockID id: curBlock.edge)
                        {
                            if(!blocks[id].vistied)
                            {
                                blocks[id].portalFrom  = curBlockID;
                                blocks[id].portalCount = curBlock.portalCount + 1;
                                blocks[id].vistied     = true;
                                que.push(id);
                            }
                        }
                        que.pop();
                    }
                    ans = blocks[tBlock].portalCount;
                }
                else
                {
                    ans = -1;
                }
            }
            else
            {
                ans = 0;
            }
        }

        // output result
        {
            std::cout << ans;
            // if(T)
            {
                std::cout << std::endl;
            }
        }
        // std::cout<<0<<std::endl;
        //#ifdef DEBUG

        // 		{
        // 			std::clog << "Report:" << std::endl;
        // 		}

        // 		{
        // 			std::clog << "BlockID:" << std::endl;
        // 			for (int i = 0; i < m; i++)
        // 			{
        // 				for (int j = 0; j < n; j++)
        // 				{
        // 					std::clog << std::setw(3) << getBlockID(i, j) << '
        // ';
        // 				}
        // 				std::clog << std::endl;
        // 			}
        // 		}//check connectedBlock

        // 		{
        // 			std::clog << "Edges:" << std::endl;
        // 			for (BlockID id = 0; id < (int)blocks.size(); id++)
        // 			{
        // 				std::clog << "BlockID:" << std::resetiosflags(std::ios::left
        // | std::ios::right) << std::setiosflags(std::ios::left) << std::setw(3) << id <<
        // std::setiosflags(std::ios::right); 				std::clog << "PortalCount:" <<
        // std::setw(3) <<
        // blocks[id].portalCount; 				std::clog << "From:" << std::setw(3) <<
        // blocks[id].portalFrom; 				std::clog << "Portal to:"; 				for (BlockID edge : blocks[id].edge)
        // 				{
        // 					std::clog << std::setw(3) << edge;
        // 				}
        // 				std::clog << std::endl;
        // 			}
        // 		}//check edge

        // #endif // DEBUG
    }
    return 0;
}
