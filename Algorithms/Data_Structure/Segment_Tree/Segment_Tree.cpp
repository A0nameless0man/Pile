#include"Segment_Tree.h"
namespace S_tree//闭区间
{

	//template<class T>
	Segment_Tree::Segment_Tree(size_t size, T def)/*:tree(new Node[size*4])*/
	{
		tree = new Node[size * 4];
		std::stack<std::pair<size_t, std::pair<size_t, size_t> > > stack;
		stack.push(std::pair<size_t, std::pair<size_t, size_t> >(1, std::pair<size_t, size_t>(0, size)));
		while (!stack.empty())
		{
			std::pair<size_t, std::pair<size_t, size_t> > cur = stack.top(); stack.pop();
			size_t pos = cur.first;
			size_t from = cur.second.first;
			size_t to = cur.second.second;
			size_t mid = (from + to) / 2;
			tree[pos].max = tree[pos].min = tree[pos].sum = def;
			tree[pos].low = from;
			tree[pos].up = to;
			tree[pos].mid = mid;
			tree[pos].p = &tree[pos >> 1];
			if (from != to)
			{
				tree[pos].l = &tree[pos << 1];
				stack.push(std::pair<size_t, std::pair<size_t, size_t> >(pos << 1, std::pair<size_t, size_t>(from, mid)));
				tree[pos].r = &tree[pos << 1 | 1];
				stack.push(std::pair<size_t, std::pair<size_t, size_t> >(pos << 1 | 1, std::pair<size_t, size_t>(mid + 1, to)));

			}
		}
	}


	//template<class T>
	Segment_Tree::~Segment_Tree()
	{
		delete tree;
	}

	//template<class T>
	void Segment_Tree::set(size_t from, size_t to, T val)
	{
		std::stack<Node*> stack;
		stack.push(&tree[1]);
		while (!stack.empty())
		{
			Node* cur = stack.top(); stack.pop();
			this->pushDown(cur);
			if (cur == NULL)
			{
				continue;
			}
			if (cur->low >= from && cur->up <= to)
			{
				cur->set(val);
				pushUp(cur);
			}
			else
			{
				if (cur->mid >= from)
				{
					stack.push(cur->l);
				}
				if (cur->mid < to)
				{
					stack.push(cur->r);
				}
			}
		}
		//stack.push(0);

	}

	//template<class T>
	void Segment_Tree::add(size_t from, size_t to, T val)
	{
		std::stack<Node*> stack;
		stack.push(&tree[1]);
		while (!stack.empty())
		{
			Node* cur = stack.top(); stack.pop();
			this->pushDown(cur);
			if (cur == NULL)
			{
				continue;
			}
			if (cur->low >= from && cur->up <= to)
			{
				cur->add(val);
				pushUp(cur);
			}
			else
			{
				if (cur->mid >= from)
				{
					stack.push(cur->l);
				}
				if (cur->mid < to)
				{
					stack.push(cur->r);
				}
			}
		}
	}

	//template<class T>void Segment_Tree ::mul(size_t from, size_t to, T val)
	//{
	//}

	//template<class T>
	T Segment_Tree::max(size_t from, size_t to)
	{
		std::stack<Node*> stack;
		T ans = -INF;
		stack.push(&tree[1]);
		while (!stack.empty())
		{
			Node* cur = stack.top(); stack.pop();
			this->pushDown(cur);
			if (cur == NULL)
			{
				continue;
			}
			if (cur->low >= from && cur->up <= to)
			{
				std::max(cur->max, ans);
			}
			else
			{
				if (cur->mid >= from)
				{
					stack.push(cur->l);
				}
				if (cur->mid < to)
				{
					stack.push(cur->r);
				}
			}
		}
		return ans;
	}

	//template<class T>
	T Segment_Tree::min(size_t from, size_t to)
	{
		std::stack<Node*> stack;
		T ans = INF;
		stack.push(&tree[1]);
		while (!stack.empty())
		{
			Node* cur = stack.top(); stack.pop();
			this->pushDown(cur);
			if (cur == NULL)
			{
				continue;
			}
			if (cur->low >= from && cur->up <= to)
			{
				std::min(cur->min, ans);
			}
			else
			{
				if (cur->mid >= from)
				{
					stack.push(cur->l);
				}
				if (cur->mid < to)
				{
					stack.push(cur->r);
				}
			}
		}
		return ans;

	}

	//template<class T>
	T Segment_Tree::sum(size_t from, size_t to)
	{
		std::stack<Node*> stack;
		T ans = 0;
		stack.push(&tree[1]);
		while (!stack.empty())
		{
			Node* cur = stack.top(); stack.pop();
			this->pushDown(cur);
			if (cur == NULL)
			{
				continue;
			}
			if (cur->low >= from && cur->up <= to)
			{
				ans += cur->sum;
			}
			else
			{
				if (cur->mid >= from)
				{
					stack.push(cur->l);
				}
				if (cur->mid < to)
				{
					stack.push(cur->r);
				}
			}
		}
		return ans;

	}

	void Segment_Tree::pushUp(Node * cur)
	{
		for (; cur->p != tree; cur = cur->p)
		{
			//Node& cur = tree[i];
			if (cur->low == cur->up)
			{
				continue;
			}
			cur->max = std::max(cur->l->max, cur->r->max);
			cur->min = std::min(cur->l->min, cur->r->min);
			cur->sum = cur->r->sum + cur->l->sum;
		}
	}

	void Segment_Tree::pushDown(Node * cur)
	{
		if (cur == NULL)
		{
			return;
		}
		if (cur->up==cur->low)
		{
			return;
		}
		if (cur->toadd != 0)
		{
			cur->l->add(cur->toadd);
			cur->r->add(cur->toadd);
			cur->toadd = 0;
		}
		if (cur->toset != INF)
		{
			cur->l->set(cur->toset);
			cur->r->set(cur->toset);
			cur->toset = INF;
		}
	}


	//template<class t>
	Node::Node(size_t from, size_t to) :low(from), up(to), l(NULL), r(NULL), p(NULL), toadd(0), toset(INF)
	{
	}


	//template<class t>
	//Node::~Node()
	//{
	//	;
	//}
	void Node::set(T val)
	{
		sum = val * (up - low + 1);
		max = min = val;
		toadd = val;
	}
	void Node::add(T val)
	{
		sum += val * (up - low + 1);
		max += val;
		min += val;
		toset = val;
	}
	////template<class T>
	//Node & Node ::left()
	//{
	//	// TODO: 在此处插入 return 语句
	//}
	////template<class T>
	//Node & Node ::right()
	//{
	//	// TODO: 在此处插入 return 语句
	//}
	////template<class T>
	//Node & Node ::parent()
	//{
	//	// TODO: 在此处插入 return 语句
	//}
}