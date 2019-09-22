#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
struct node
{
	int sum;
	int left;
	int right;
	int toAdd;
	node *l;
	node *r;
	node *p;
};
bool isLeaf(const node &a)
{
	return a.left == a.left;
}
void pushDown(node &a)
{
	if (a.toAdd != 0)
	{
		if (a.l != NULL)
		{
			node &l = *(a.l);
			if (!isLeaf(l) && l.toAdd != 0)
			{
				pushDown(l);
			}
			l.sum += a.toAdd * (l.right - l.left + 1);
			l.toAdd = a.toAdd;
		}
		if (a.r != NULL)
		{
			node &r = *(a.r);
			if (!isLeaf(r) && r.toAdd != 0)
			{
				pushDown(r);
			}
			r.sum += a.toAdd * (r.right - r.left + 1);
			r.toAdd = a.toAdd;
		}
		a.toAdd = 0;
	}
}
void takeUp(node &a)
{
	a.sum = ((a.l == NULL) ? 0 : a.l->sum) + ((a.r == NULL) ? 0 : a.r->sum);
}
void pushUp(node &a)
{
	if (a.p != NULL)
	{
		takeUp(*(a.p));
		pushUp(*(a.p));
	}
}
int sum(int from, int to, node &a)
{
	int ans = 0;
	if (from <= a.left && to >= a.right)
	{
		ans += a.sum;
	}
	else
	{
		if (a.l != NULL)
		{
			node &l = *(a.l);
			if (l.left <= to && l.right >= to || l.left <= from && l.right >= from || from <= l.left && to >= l.right)
			{
				ans += sum(from, to, l);
			}
		}
		if (a.r != NULL)
		{
			node &r = *(a.r);
			if (r.left <= to && r.right >= to || r.left <= from && r.right >= from || from <= r.left && to >= r.right)
			{
				ans += sum(from, to, r);
			}
		}
	}
	return ans;
}

void add(int from, int to, node &a, int val)
{
	if (from <= a.left && to >= a.right)
	{
		a.sum += val * (a.right - a.left + 1);
		a.toAdd = val;
		pushUp(a);
	}
	else
	{
		if (a.l != NULL)
		{
			node &l = *(a.l);
			if (l.left <= to && l.right >= to || l.left <= from && l.right >= from || from <= l.left && to >= l.right)
			{
				add(from, to, l, val);
			}
		}
		if (a.r != NULL)
		{
			node &r = *(a.r);
			if (r.left <= to && r.right >= to || r.left <= from && r.right >= from || from <= r.left && to >= r.right)
			{
				add(from, to, r, val);
			}
		}
	}
}

void build(size_t n, node *tar)
{
	struct val
	{
		int pos;
		int left;
		int right;
	};
	std::stack<val> stack;
	//std::stack<size_t> s2;
	stack.push(val({(int)1, (int)1, (int)n}));
	while (!stack.empty())
	{
		val V = stack.top();
		stack.pop();
		tar[V.pos].left = V.left;
		tar[V.pos].right = V.right;
		tar[V.pos].sum = 0;
		tar[V.pos].toAdd = 0;
		if (V.pos == 1)
		{
			tar[V.pos].p = NULL;
		}
		else
		{
			tar[V.pos].p = tar + V.pos / 2;
		}
		if (V.left == V.right)
		{
			tar[V.pos].l = NULL;
			tar[V.pos].r = NULL;
			scanf("%d", &tar[V.pos].sum);
			pushUp(tar[V.pos]);
		}
		else
		{
			tar[V.pos].l = tar + V.pos * 2;
			tar[V.pos].r = tar + V.pos * 2 + 1;
			int mid = (V.left + V.right) / 2;
			stack.push(val({V.pos * 2 + 1, mid + 1, V.right}));
			stack.push(val({V.pos * 2, V.left, mid}));
		}
	}
	//for (size_t i = n/2; i != size_t(-1); i--)
	//{
	//	takeUp(tar[i]);
	//}
}
node no[50000 * 10];
int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case %d:\n", i + 1);
		int n;
		scanf("%d", &n);
		build(n, no);
		char s[10];
		do
		{
			//std::cin >> s;
			int a, b, c;
			scanf("%s", s);
			if (s[0] == 'E')
			{
				break;
			}
			scanf("%d%d", &a, &b);
			switch (s[0])
			{
			case 'Q':
				//std::cin >> a >> b;
				//std::cout << S_t.sum(a - 1, b - 1) << std::endl;
				printf("%d\n", sum(a, b, no[1]));
				break;
			case 'S':
				//std::cin >> a >> c;
				add(a, a, no[1], -b);
				break;
			case 'A':
				//std::cin >> a >> c;
				add(a, a, no[1], b);
				break;
			default:
				break;
			}
		} while (s[0] != 'E');
	}
	return 0;
}