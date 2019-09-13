#pragma once
#include<vector>
#include<stack>
namespace C_Tree
{
	template<class T1, class T2>
	class Node;

	template<class T1, class T2>
	class Chairman_Tree;

	template<class T1, class T2>
	using PtrNode = Node<T1,T2> *;

	template<class T1, class T2>
	class Chairman_Tree
	{
	public:
		Chairman_Tree(void);
		~Chairman_Tree(void);
		void insert(T1 key, T2 val,size_t ver);
		void dele(T1 key, size_t ver);
		T2 consalt(T1 key, size_t ver);
		void set(T1 key, T2 val, size_t ver);
		size_t newVer(size_t baseVer);
		size_t verCount(void);
	private:
		//std::vector<PtrNode<T1,T2> > allNode;
		std::vector<PtrNode<T1,T2> > allRoot;
	};

	template<class T1, class T2>
	class Node
	{
	public:
		Node(T1 key, T2 val);
		Node(const Node& copy);
		~Node(void);
		//void setChild(const Node& tar, bool left);
		//const PtrNode getChild(bool left)const;
		void ownChild(bool left);
		void insert(T1 key, T2 val);
		T2 find(T1 key)const;
		T1 getKey(void)const;
		T2 getVal(void)const;
		T2 setVal(T2 val);
		T2 setVal(T1 key, T2 Val);
		//size_t getVer(void);
	private:
		T1 myKey;
		T2 myVal;
		//size_t myVer;
		PtrNode<T1,T2> leftChild, rightChild;
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
			allRoot.push_back(new Node<T1,T2>(key, val));
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
		allRoot.push_back(new Node<T1,T2>(*allRoot[baseVer]));
		return verCount();
	}

	template<class T1, class T2>
	inline size_t Chairman_Tree<T1, T2>::verCount(void)
	{
		return allRoot.size();
	}

	template<class T1, class T2>
	inline Node<T1,T2>::Node(T1 key, T2 val):myKey(key),myVal(val),leftChild(NULL),rightChild(NULL),ownLeft(false),ownRight(false){}

	template<class T1, class T2>
	inline Node<T1, T2>::Node(const Node& copy):myKey(copy.myKey), myVal(copy.myVal), leftChild(copy.leftChild), rightChild(copy.rightChild),ownLeft(false),ownRight(false){}

	template<class T1, class T2>
	Node<T1, T2>::~Node(void)
	{
		if (ownLeft)
		{
			delete leftChild;
		}
		if (ownRight)
		{
			delete rightChild;
		}
	}

	//template<class T1, class T2>
	//inline void  Node<T1, T2>::setChild(const Node& tar, bool left)
	//{
	//	if (left)
	//	{
	//		leftChild = &tar;
	//	}
	//	else
	//	{
	//		rightChild = &tar;
	//	}
	//}

	//template<class T1, class T2>
	//inline const Chairman_Tree<T1, T2>::PtrNode  Node<T1, T2>::getChild(bool left) const
	//{
	//	return left?leftChild:rightChild;
	//}

	template<class T1, class T2>
	inline void Node<T1, T2>::ownChild(bool left)
	{
		if (left)
		{
			if (!ownLeft)
			{
				leftChild = new Node(*leftChild);
				ownLeft = true;
			}
		}
		else
		{
			if (!ownRight)
			{
				rightChild = new Node(*rightChild);
				ownRight = true;
			}
		}
		return;
	}

	template<class T1, class T2>
	inline void Node<T1, T2>::insert(T1 key, T2 val)
	{
		if (key!=myKey)
		{
			if (key<myKey)
			{
				if (leftChild==NULL)
				{
					leftChild = new Node(key, val);
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
				if (rightChild==NULL)
				{
					rightChild = new Node(key, val);
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
		if (key==myKey)
		{
			return myVal;
		}
		else
		{
			if (key<myKey&&leftChild!=NULL)
			{
				return leftChild->find(key);
			}
			else
			{
				if (myKey<key&&rightChild!=NULL)
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
		if (key==myKey)
		{
			setVal(val);
		}
		else
		{
			if (key<myKey)
			{

				if (leftChild!=NULL)
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
				if (rightChild!=NULL)
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
}