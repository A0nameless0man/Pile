#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>

template<class T1, class T2>
class Node;

template<class T1, class T2>
class Chairman_Tree;

template<class T1, class T2>
using PtrNode = Node<T1, T2>*;

template<class T1, class T2>
class Chairman_Tree
{
public:
	Chairman_Tree(void);
	~Chairman_Tree(void);
	void insert(T1 key, T2 val, size_t ver);
	void dele(T1 key, size_t ver);
	T2 consalt(T1 key, size_t ver);
	void set(T1 key, T2 val, size_t ver);
	size_t newVer(size_t baseVer);
	size_t verCount(void);
private:
	//std::vector<PtrNode<T1,T2> > allNode;
	std::vector<PtrNode<T1, T2> > allRoot;
};


PtrNode<int, int > newNode(const Node<int, int >& copy);

//template<class T1, class T2>
PtrNode<int, int > newNode(int  key, int  val);

template<class T1, class T2>
class Node
{
public:
	Node(T1 key = T1(), T2 val = T2());
	//Node(const Node& copy);
	//~Node(void);
	//void setChild(const Node& tar, bool left);
	//const PtrNode getChild(bool left)const;
	void ownChild(bool left);
	void insert(T1 key, T2 val);
	T2 find(T1 key)const;
	T1 getKey(void)const;
	T2 getVal(void)const;
	T2 setVal(T2 val);
	T2 setVal(T1 key, T2 Val);
	friend	PtrNode<int, int > newNode(const Node<int, int >& copy);
	friend	PtrNode<int, int > newNode(int  key, int  val);
	//size_t getVer(void);
	T1 myKey;
	T2 myVal;
	//size_t myVer;
	PtrNode<T1, T2> leftChild, rightChild;
	bool ownLeft, ownRight;
};

template<class T1, class T2>
inline Chairman_Tree<T1, T2>::Chairman_Tree(void)
{

}

template<class T1, class T2>
inline Chairman_Tree<T1, T2>::~Chairman_Tree(void)
{

}

template<class T1, class T2>
inline void Chairman_Tree<T1, T2>::insert(T1 key, T2 val, size_t ver)
{
	if (allRoot.empty())
	{
		allRoot.push_back(newNode(key, val));
	}
	else
	{
		allRoot[ver]->insert(key, val);
	}
}

template<class T1, class T2>
inline void Chairman_Tree<T1, T2>::dele(T1 key, size_t ver)
{
	throw std::exception();
}

template<class T1, class T2>
inline T2 Chairman_Tree<T1, T2>::consalt(T1 key, size_t ver)
{
	return allRoot[ver]->find(key);
}

template<class T1, class T2>
inline void Chairman_Tree<T1, T2>::set(T1 key, T2 val, size_t ver)
{
	allRoot[ver]->setVal(key, val);
}

template<class T1, class T2>
inline size_t Chairman_Tree<T1, T2>::newVer(size_t baseVer)
{
	allRoot.push_back(newNode(*allRoot[baseVer]));
	return verCount();
}

template<class T1, class T2>
inline size_t Chairman_Tree<T1, T2>::verCount(void)
{
	return allRoot.size();
}

template<class T1, class T2>
inline Node<T1, T2>::Node(T1 key, T2 val) :myKey(key), myVal(val), leftChild(NULL), rightChild(NULL), ownLeft(false), ownRight(false) {}
//
//template<class T1, class T2>
//inline Node<T1, T2>::Node(const Node& copy) : myKey(copy.myKey), myVal(copy.myVal), leftChild(copy.leftChild), rightChild(copy.rightChild), ownLeft(false), ownRight(false) {}



template<class T1, class T2>
inline void Node<T1, T2>::ownChild(bool left)
{
	if (left)
	{
		if (!ownLeft)
		{
			leftChild = newNode(*leftChild);
			ownLeft = true;
		}
	}
	else
	{
		if (!ownRight)
		{
			rightChild = newNode(*rightChild);
			ownRight = true;
		}
	}
	return;
}

template<class T1, class T2>
inline void Node<T1, T2>::insert(T1 key, T2 val)
{
	if (key != myKey)
	{
		if (key < myKey)
		{
			if (leftChild == NULL)
			{
				leftChild = newNode(key, val);
				ownLeft = true;
			}
			else
			{
				if (!ownLeft)
				{
					ownChild(true);
				}
				leftChild->insert(key, val);
			}
		}
		else
		{
			if (rightChild == NULL)
			{
				rightChild = newNode(key, val);
			}
			else
			{
				if (!ownRight)
				{
					ownChild(false);
				}
				rightChild->insert(key, val);
			}
		}
	}
	else
	{
		throw std::exception();
	}
}

template<class T1, class T2>
inline T2 Node<T1, T2>::find(T1 key) const
{
	if (key == myKey)
	{
		return myVal;
	}
	else
	{
		if (key < myKey && leftChild != NULL)
		{
			return leftChild->find(key);
		}
		else
		{
			if (myKey < key && rightChild != NULL)
			{
				return rightChild->find(key);
			}
			else
			{
				return T2();
				//throw std::exception();
			}
		}
	}
}

template<class T1, class T2>
inline T1  Node<T1, T2>::getKey(void) const
{
	return myKey;
}

template<class T1, class T2>
inline T2  Node<T1, T2>::getVal(void) const
{
	return myVal;
}

template<class T1, class T2>
inline T2  Node<T1, T2>::setVal(T2 val)
{
	return myVal = val;
}

template<class T1, class T2>
inline T2  Node<T1, T2>::setVal(T1 key, T2 val)
{
	if (key == myKey)
	{
		setVal(val);
	}
	else
	{
		if (key < myKey)
		{

			if (leftChild != NULL)
			{
				if (!ownLeft)
				{
					ownChild(true);
				}
				leftChild->setVal(key, val);
			}
			else
			{
				insert(key, val);
			}
		}
		else
		{
			if (rightChild != NULL)
			{
				if (!ownLeft)
				{
					ownChild(false);
				}
				rightChild->setVal(key, val);
			}
		}
	}
	return myVal;
}
//inline size_t  Node<T1, T2>::getVer(void)
//{
//	return myVer;
//}
Node<int, int  > pool[13000007];
int  poolSize = 0;
int main()
{
	int n, m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		Chairman_Tree<int, int > C_T;
		using pair = std::pair<int, int >;
		std::vector< pair> vec;
		for (int i = 1; i <= n; i++)
		{
			int  k;
			//std::cin >> k;
			scanf("%d", &k);
			vec.push_back(pair(i, k));
		}
		//std::random_shuffle(vec.begin(), vec.end());
		std::stack<pair> sta;
		sta.push(pair(0, n - 1));
		while (!sta.empty())
		{
			pair p = sta.top();
			sta.pop();
			if (p.first == p.second)
			{
				C_T.insert(vec[p.first].first, vec[p.first].second, 0);
			}
			else
			{
				int  mid = (p.first + p.second) / 2;
				C_T.insert(vec[mid].first, vec[mid].second, 0);
				if (p.first <= mid - 1)
				{
					sta.push(pair(p.first, mid - 1));
				}
				if (mid + 1 <= p.second)
				{
					sta.push(pair(mid + 1, p.second));
				}
			}
		}
		//for (size_t i = 0; i < n; i++)
		//{
		//	C_T.insert(vec[i].first, vec[i].second, 0);
		//}
		for (size_t i = 0; i < m; i++)
		{
			int ver;
			int op;
			//std::cin >> ver >> op;
			scanf("%d%d", &ver, &op);
			if (op == 1)
			{
				int key, val;
				//std::cin >> key >> val;
				scanf("%d%d", &key, &val);
				C_T.newVer(ver);
				C_T.set(key, val, i + 1);
			}
			else
			{
				int key;
				//std::cin >> key;
				scanf("%d", &key);
				C_T.newVer(ver);
				printf("%d\n", C_T.consalt(key, i + 1)) ;
			}
		}
	}
	return 0;
	//newNode()
}

inline PtrNode<int, int > newNode(const Node<int, int > & copy)
{
	pool[poolSize].myKey = copy.myKey;
	pool[poolSize].myVal = copy.myVal;
	pool[poolSize].leftChild = copy.leftChild;
	pool[poolSize].rightChild = copy.rightChild;
	pool[poolSize].ownLeft = false;
	pool[poolSize].ownRight = false;
	return pool + (poolSize++);
}

inline PtrNode<int, int > newNode(int   key, int  val)
{
	pool[poolSize].myKey = key;
	pool[poolSize].myVal = val;
	pool[poolSize].leftChild = NULL;
	pool[poolSize].rightChild = NULL;
	pool[poolSize].ownLeft = false;
	pool[poolSize].ownRight = false;
	return pool + (poolSize++);
}
