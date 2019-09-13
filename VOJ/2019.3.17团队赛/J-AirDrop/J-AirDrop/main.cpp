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
unordered_set<long long> servierL, servierR, conflictR;//���ڳ�ͻ�ľ���
unordered_map<long long, long long> r, l;//����Ͷ���ض�x���Ҳ�һ��ʱ����ߺ��ұ�������������
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
	//cin >> T;//����T��Ҳ������������
	scanf("%d", &T);
	while (T--)//����ÿһ������
	{
		//cin >> n >> _y;//�����������y0
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
		l.clear();//��ʼ��
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
		}//������ҵ�����
		long long currentSER = 0;
		for (auto x : players)//����map left
		{
			l[x.first] = currentSER;
			for (auto y : x.second.y)
			{
				long long disl = -x.first + abs(y);
				if (y != 0 && x.second.y.count(-y) != 0)//�����������ͻ������
				{
					if (servierL.count(disl)!=0)
					{
						currentSER -= 1;//����������ģ�����סͬ������˵�·
						servierL.erase(disl);
					}
				}
				else//�������������ͻ����//������������ս��//��������//��Ϊ������
				{
					if ((servierL.count(disl) != 0))//��Ǳ�ڵĳ�ͻ
					{

						//����������߳�ͻ
						//servierL[disl].erase(servierL[disl].upper_bound(x.first));
						servierL.erase(disl);
						currentSER--;
					}
					else//�������//�Ȼỹ��������
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
		//DONE:������������һ��
		for (auto x = players.rbegin(); x != players.rend(); x++)
		{
			//cout << x->first << endl;
			for (auto y : x->second.y)
			{
				long long disr = x->first + abs(y);
				if (y != 0 && x->second.y.count(-y) != 0)//�����������ͻ������
				{
					//if (conflictR[disr].count(x->first) == 0)
					//{
					//	conflictR[disr].insert(x->first);//��¼���ǵ�dis����ֹ�г�ͻ
					//}
					if (servierR.count(disr)!=0)
					{
						currentSER -= 1;//����������ģ�����סͬ������˵�·
						conflictR.insert(disr);
						servierR.erase(disr);
					}
				}
				else//�������������ͻ����//������������ս��//��������//��Ϊ������
				{
					if (( servierR.count(disr) != 0))//��Ǳ�ڵĳ�ͻ
					{
						//����������߳�ͻ
						//servierR[disr].erase(servierR[disr].lower_bound(x->first));
						servierR.erase(disr);
						currentSER--;
					}
					else//�������//�Ȼỹ��������
					{
						servierR.insert(disr);
						currentSER++;
					}
				}
			}
			r[x->first] = currentSER;
		}
		r[INF] = 0;
		//DOING:���left��right��players[x].y.size����x0ȡ��ֵͬʱ������������
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
//TODO:������Ե��������Ҫ����