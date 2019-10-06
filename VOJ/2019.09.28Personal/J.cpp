#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
struct S_tree;
const int INF = 0x7fffffff;
const int MOD = 998244353;
// S_tree *getS(size_t size, size_t from = 0, S_tree *parent = NULL);
// struct S_tree
// {
// 	S_tree *p;
// 	S_tree *lSon;
// 	S_tree *rSon;
// 	size_t l, r, mid;
// 	int lazy;															 //0 or 2 or 3//if range is bigger than my range than lazy and just mul the best with i
// 	int best;															 //best is the smallest rec in (l,r)
// 	inline void ini(size_t size, size_t from = 0, S_tree *parent = NULL) //:l(from),r(from+size),p(parent),lazy(0),best(0)
// 	{
// 		struct V
// 		{
// 			S_tree *t;
// 			size_t size;
// 			size_t from;
// 			S_tree *parent;
// 			V(S_tree *t,
// 			  size_t size,
// 			  size_t from,
// 			  S_tree *parent) : t(t), size(size), from(from), parent(parent) {}
// 		};
// 		std::stack<V> stack;
// 		stack.push(V(this, size, from, parent));
// 		while (!stack.empty())
// 		{
// 			V v = stack.top();
// 			stack.pop();
// 			v.t->l = v.from;
// 			v.t->r = v.from + v.size;
// 			v.t->p = v.parent;
// 			v.t->lazy = 0;
// 			v.t->best = 0;
// 			if (v.size != 1)
// 			{
// 				size_t half = v.size / 2;
// 				v.t->lSon = getS(half, v.from, v.t);
// 				v.t->rSon = getS(v.size - half, v.from + half, v.t);
// 				stack.push(V(v.t->lSon, half, v.from, v.t));
// 				stack.push(V(v.t->rSon, v.size - half, v.from + half, v.t));
// 				v.t->mid = v.from + half;
// 			}
// 			else
// 			{
// 				v.t->lSon = v.t->rSon = NULL;
// 				v.t->mid = 0;
// 			}
// 		}
// 		return;
// 	}
// 	inline bool leaf() { return lSon == NULL && rSon == NULL; }
// 	inline bool theLeaf(size_t tl, size_t tr) { return leaf() && l >= tl && l < tr; }
// 	inline void unlazy()
// 	{
// 		if (lSon != NULL)
// 			lSon->op(l, r, lazy);
// 		if (rSon != NULL)
// 			rSon->op(l, r, lazy);
// 	}
// 	inline int consult(size_t tl, size_t tr)
// 	{
// 		if (tl <= l && tr >= r || theLeaf(tl, tr))
// 			return best;
// 		else
// 		{
// 			if (lazy)
// 			{
// 				unlazy();
// 			}
// 			int ans = INF;
// 			if (lSon != NULL && tl < mid)
// 			{
// 				ans = std::min(ans, lSon->consult(tl, tr));
// 			}
// 			if (rSon != NULL && tr > mid)
// 			{
// 				ans = std::min(ans, rSon->consult(tl, tr));
// 			}
// 			return ans;
// 		}
// 	}
// 	//inline void op(size_t tl,size_t tr,int i)
// 	//{
// 	//	struct V
// 	//	{
// 	//		S_tree* t;
// 	//		size_t tl;
// 	//		size_t tr;
// 	//		int i;
// 	//		V(
// 	//			S_tree* t,
// 	//			size_t tl,
// 	//			size_t tr,
// 	//			int i
// 	//			):t(t),tl(tl),tr(tr),i(i)
// 	//		{}
// 	//	};
// 	//	std::stack<V> stack;
// 	//	stack.push(V(this,tl,tr,i));
// 	//	while (!stack.empty())
// 	//	{
// 	//		V v = stack.top();
// 	//		stack.pop();
// 	//		if(v.t->lazy)
// 	//		{
// 	//			v.t->unlazy();
// 	//		}
// 	//		if(v.tl<=v.t->l&&v.tr>=v.t->r||v.t->theLeaf(v.tl,v.tr))
// 	//		//return best;
// 	//		{
// 	//			v.t->best += v.i;
// 	//			v.t->lazy =v.i;
// 	//		}
// 	//		else
// 	//		{
// 	//			int ans =INF;
// 	//			if(v.t->lSon!=NULL&&tl<v.t->mid)
// 	//			{
// 	//				//v.t->lSon->op(v.tl,v.tr,v.i);
// 	//				stack.push(V(v.t->lSon,v.tl,v.tr,i));
// 	//				ans = std::min(ans,v.t->lSon->consult(l,r));
// 	//			}
// 	//			if(v.t->rSon!=NULL && v.tr>v.t->mid)
// 	//			{
// 	//				//v.t->rSon->op(v.tl,v.tr,v.i);
// 	//				stack.push(V(v.t->rSon,v.tl,v.tr,i));
// 	//				ans = std::min(ans,v.t->rSon->consult(l,r));
// 	//			}
// 	//			v.t->best = ans;//std::min(ans,best);
// 	//			//return;// ans;
// 	//		}
// 	//
// 	//	}
// 	void op(size_t tl, size_t tr, int i)
// 	{

// 		if (tl <= l && tr >= r || theLeaf(tl, tr))
// 		//return best;
// 		{
// 			best += i;
// 			lazy += i;
// 		}
// 		else
// 		{
// 			if (lazy)
// 			{
// 				unlazy();
// 			}
// 			//int ans =INF;
// 			if (lSon != NULL && tl < mid)
// 			{
// 				lSon->op(tl, tr, i);
// 				//ans = std::min(ans,lSon->consult(l,r));
// 			}
// 			if (rSon != NULL && tr > mid)
// 			{
// 				rSon->op(tl, tr, i);
// 				//ans = std::min(ans,rSon->consult(l,r));
// 			}
// 			//best = ans;//std::min(ans,best);
// 			int ans = INF;
// 			if (lSon != NULL)
// 				ans = std::min(ans, lSon->best);
// 			if (rSon != NULL)
// 				ans = std::min(ans, rSon->best);
// 			best = ans;
// 			return; // ans;
// 		}
// 	}
// };
// S_tree vec[4 * 100007];
// size_t count = 0;
// inline S_tree *getS(size_t size, size_t from, S_tree *parent)
// {
// 	int c = count++;
// 	//vec[c].ini(size,from,parent);
// 	return &vec[c];
// }

inline long long qpow(long long base, long long p)
{
	long long ans = 1;
	while (p)
	{
		if (p & 1)
		{
			ans *= base;
			ans %= MOD;
		}
		base *= base;
		base %= MOD;
		p >>= 1;
	}
	return ans;
}
// int main(void)
// {
// 	int t;
// 	int l, r;
// 	int j;
// 	std::ios::sync_with_stdio(false);
// 	//std::cin>>t;
// 	scanf("%d", &t);
// 	while (t--)
// 	{
// 		int n, m;
// 		count = 0;
// 		//std::cin>>n>>m;
// 		scanf("%d%d", &n, &m);
// 		S_tree tr[2];
// 		tr[0].ini(n, 1);
// 		tr[1].ini(n, 1);
// 		for (int i = 0; i < m; i++)
// 		{
// 			//std::cin>>l>>r>>j;
// 			scanf("%d%d%d", &l, &r, &j);
// 			//l--;
// 			//r--;
// 			tr[j - 2].op(l, r + 1, 1);
// 		}
// 		long long ans = qpow(2, tr[0].consult(1, n + 1)) * qpow(3, tr[1].consult(1, n + 1));
// 		ans %= MOD;
// 		//std::cout<<ans<<std::endl;
// 		printf("%lld\n", ans);
// 	}
// 	return 0;
// }
/*
3
5 3
1 3 2
3 5 2
1 5 3
6 3
1 2 2
5 6 2
1 6 2

*/
int main(void)
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int n, m;
		std::cin >> n >> m;
		std::vector<int> vec[2];
		vec[0].resize(n + 1);
		vec[1].resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			int l, r, j;
			scanf("%d%d%d", &l, &r, &j);
			vec[j - 2][l - 1]++;
			vec[j - 2][r]--;
		}
		int a = INF, b = INF;
		int sa = 0, sb = 0;
		for (int i = 0; i < n; i++)
		{
			sa += vec[0][i];
			sb += vec[1][i];
			a = std::min(a, sa);
			b = std::min(b, sb);
		}
		long long ans = qpow(2, a) * qpow(3, b);
		printf("%lld\n", ans);
	}
}