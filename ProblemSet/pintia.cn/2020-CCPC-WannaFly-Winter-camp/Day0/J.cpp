#include <algorithm>
#include <array>
#include <vector>

struct Card
{
    enum Num
    {
        _2,
        _3,
        _4,
        _5,
        _6,
        _7,
        _8,
        _9,
        T,
        J,
        Q,
        K,
        A
    } num;
    enum Type
    {
        _0,
        _1,
        _2,
        _3
    } type;
};
struct Statue
{
    enum Type
    {
        flush,
        shijo,
        gourd,
        sameColor,
        junko,
        sanjo,
        doublePair,
        pair,
        else
    } type;
    std::array<Card, 5> cards;
};

Statue getStatue(std::array<Card, 7> myCard)
{
    std::array<std::vector<Card>, 4>  bucketOfCardType;
    std::array<std::vector<Card>, 13> bucketOfCardNum;

    {  // Prepare Bucket
        for(auto &c: myCard)
        {
            bucketOfCardType[c.type].push_back(c);
            bucketOfCardNum[c.num].push_back(c);
        }
        for(int i = 0; i < 4; ++i)
        {
            std::sort(bucketOfCardType[i].begin(),
                      bucketOfCardType[i].end(),
                      [](const Card &a, const Card &b) -> bool {
                          return a.num < b.num;
                      })
        }
        for(int i = 0; i < 13; ++i)
        {
            std::sort(bucketOfCardNum[i].begin(),
                      bucketOfCardNum[i].end(),
                      [](const Card &a, const Card &b) -> bool {
                          return a.type < b.typenum;
                      })
        }
    }

    {  // Judge flush
        for(int i = 0; i < 4; ++i)
        {
            if(bucketOfCardType[i].size() >= 5)
            {
                int count = 0;
                for(size_t j = 1; j < bucketOfCardType[i].size(); ++j)
                {
                    if(bucketOfCardType[i][j].num == bucketOfCardType[i][j - 1].num + 1)
                    {
                        ++count;
                        if(count == 4)
                        {
                            Statue ans;
                            ans.type = Statue::Type::flush;
                            for(size_t k = j - 4, l = 0; k <= j; ++k, ++l)
                            {
                                ans.cards[l] = bucketOfCardType[i][k];
                            }
                            return ans;
                        }
                    }
                    else
                    {
                        count = 0;
                    }
                }
            }
        }
    }

    {//Judge shijo
        for(int i = 0; i < 13;++i)
        {
            if(bucketOfCardNum[i].size()>=4)
            {
                //Get!!
            }
        }
    }

    {//Judge gourd

    }
}