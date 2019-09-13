#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include<stdio.h>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<set>
//#include<stack>
#include<algorithm>
using namespace std;
const long long INF = 0x3f3f3f3f;
//stack<char> ansbuf;
unordered_set<long long> servierL, servierR, conflictR;//存在冲突的距离
unordered_map<long long, long long> r, l;//当空投在特定x的右侧一格时从左边和右边来的生还人数
class Player
{
public:
	long long x;
	set<long long> y;
	//bool center = false;
	bool operator<(const Player &b)const { return x < b.x; }
	Player(long long x, long long y) :x(x)
	{
		this->y.insert(y);
	}
	Player(void) { ; }
};
map<long long, Player> players;
long long T, n, _y, x, y;
long long Max, Min, ser;
int main()
{
	//ios::sync_with_stdio(false);
	//cin >> T;//读入T，也就是数据组数
	scanf("%d", &T);
	while (T--)//对于每一组数据
	{
		//cin >> n >> _y;//读入玩家数和y0
		scanf("%d%d", &n, &_y);
		Max = 0;
		Min = INF;
		ser = 0;
		players.clear();
		//conflictL.clear();
		conflictR.clear();
		servierL.clear();
		servierR.clear();
		r.clear();
		l.clear();//初始化
		for (long long i = 0; i < n; i++)
		{
			//cin >> x >> y;
			scanf("%d%d", &x, &y);
			y -= _y;
			if (players.count(x) == 0)
			{
				players[x] = Player(x, y);
			}
			else
			{
				players[x].y.insert(y);
			}
			//players[i].center = (players[i].y == 0);
		}//读入玩家的坐标
		long long currentSER = 0;
		for (auto x : players)//创建map left
		{
			l[x.first] = currentSER;
			for (auto y : x.second.y)
			{
				long long disl = -x.first + abs(y);
				if (y != 0 && x.second.y.count(-y) != 0)//如果是天生冲突的两人
				{
					if (servierL.count(disl)!=0)
					{
						currentSER -= 1;//如果有死斗的，会拦住同方向的人的路
						servierL.erase(disl);
					}
				}
				else//如果不是天生冲突的人//与其他生还者战死//陷入死斗//成为生还者
				{
					if ((servierL.count(disl) != 0))//有潜在的冲突
					{

						//如果与生还者冲突
						//servierL[disl].erase(servierL[disl].upper_bound(x.first));
						servierL.erase(disl);
						currentSER--;
					}
					else//活着真好//等会还可能死掉
					{
						servierL.insert(disl);
						currentSER++;
					}
				}
			}
			//cout <<u.first<<" "<< u.second.x << " " << u.second.y.size() << endl;
		}
		l[INF] = currentSER;
		currentSER = 0;
		//DONE:从右向左再来一次
		for (auto x = players.rbegin(); x != players.rend(); x++)
		{
			//cout << x->first << endl;
			for (auto y : x->second.y)
			{
				long long disr = x->first + abs(y);
				if (y != 0 && x->second.y.count(-y) != 0)//如果是天生冲突的两人
				{
					//if (conflictR[disr].count(x->first) == 0)
					//{
					//	conflictR[disr].insert(x->first);//记录他们的dis，防止有冲突
					//}
					if (servierR.count(disr)!=0)
					{
						currentSER -= 1;//如果有死斗的，会拦住同方向的人的路
						conflictR.insert(disr);
						servierR.erase(disr);
					}
				}
				else//如果不是天生冲突的人//与其他生还者战死//陷入死斗//成为生还者
				{
					if (( servierR.count(disr) != 0))//有潜在的冲突
					{
						//如果与生还者冲突
						//servierR[disr].erase(servierR[disr].lower_bound(x->first));
						servierR.erase(disr);
						currentSER--;
					}
					else//活着真好//等会还可能死掉
					{
						servierR.insert(disr);
						currentSER++;
					}
				}
			}
			r[x->first] = currentSER;
		}
		r[INF] = 0;
		//DOING:结合left，right和players[x].y.size计算x0取不同值时的生还者人数
		for (auto x = players.begin(); x != players.end(); x++)
		{
			ser = l[x->first] + r[x->first];
			Min = min(ser, Min);
			for (auto y : x->second.y)
			{
				if (y > 0 && x->second.y.count(-y) != 0)
				{
					ser += 2;
					if (conflictR.count(x->first+abs(y))!=0)
					{
						ser++;
					}
				}
			}
			Max = max(ser, Max);
			//	cout << "x:" << x->first << "ls:" << l[x->first] << "rs" << r[x->first] << endl;
		}
		ser = l[INF] + r[INF];
		//Max = max(ser, Max);
		Min = min(ser, Min);
		//cout << /*"ans:" << */Min << " " << Max << endl;
		printf("%lld %lld\n", Min, Max);
		//ansbuf.push('\n');
		//if (Max == 0)
		//	ansbuf.push('0');
		//else
		//	while (Max!=0)
		//	{
		//		ansbuf.push(Max % 10 + '0');
		//		Max /= 10;
		//	}
		//ansbuf.push(' ');
		//if (Min == 0)
		//	ansbuf.push('0');
		//else
		//	while (Min != 0)
		//	{
		//		ansbuf.push(Min % 10 + '0');
		//		Min /= 10;
		//	}
		//while (!ansbuf.empty())
		//{
		//	putchar(ansbuf.top());
		//	ansbuf.pop();
		//}
	}

	return 0;
}
//TODO:对于面对的两个玩家要特判