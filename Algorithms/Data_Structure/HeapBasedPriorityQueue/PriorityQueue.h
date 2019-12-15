#pragma once
#ifndef PQh
#include<algorithm>
namespace P_Queue
{
	template<class T>
	class P_Queue
	{
	public:
		//P_Queue(sizt_t);
		P_Queue(size_t minCompacity = 10);
		~P_Queue(void);
		void insert(const T&);
		T top(void)const;
		void pop(void);
		size_t size(void)const;
		bool empty(void)const;
	private:
		void matainHeap(size_t);
		size_t changeSizeTo(size_t);
		void moreCompacity(void);
		size_t left(size_t)const;
		size_t right(size_t)const;
		size_t parent(size_t)const;
		T* Heap;
		size_t compacity;
		size_t compacityUsed;
	};
	template<class T>P_Queue<T>::P_Queue(size_t minCompacity)
	{
		Heap = NULL;
		compacity = 0;
		compacityUsed = 0;
		changeSizeTo(minCompacity);
	}
	template<class T>P_Queue<T>::~P_Queue(void)
	{
		delete Heap;
	}
	template<class T>void P_Queue<T>::insert(const T& target)
	{
		if (compacity == compacityUsed)
		{
			moreCompacity();
		}
		Heap[compacityUsed++] = target;
		for (size_t i = parent(compacityUsed); i != size_t(-1); i--)
		{
			matainHeap(i);
		}
	}
	template<class T>T P_Queue<T>::top(void) const
	{
		return Heap[0];
	}
	template<class T>void P_Queue<T>::pop(void)
	{
		std::swap(Heap[0], Heap[compacityUsed - 1]);
		--compacityUsed;
		matainHeap(0);
	}
	template<class T>size_t P_Queue<T>::size(void)const
	{
		return compacityUsed;
	}
	template<class T>bool P_Queue<T>::empty(void) const
	{
		return size() == 0;
	}
	template<class T>void P_Queue<T>::matainHeap(size_t target)
	{
		size_t next = target;
		while (true)
		{

			if (Heap[target] < Heap[left(target)])
			{next = left(target);}
			else if (Heap[next] < Heap[right(target)])
			{next = right(target);}//找到父节点和子节点中比较大的那个
			if (next != target)//如果不是父节点就交换
			{
				std::swap(Heap[next], Heap[target]);
				target = next;
			}
			else{return;}//是则说明这个节点满足性质，可以收工了
		}//继续维护性质
	}
	template<class T>size_t P_Queue<T>::changeSizeTo(size_t target)
	{
		if (target < compacityUsed)
		{
			throw std::exception();
		}
		else
		{
			T* newHeap = new T[target];
			memcpy(newHeap, Heap, compacityUsed);
			compacity = target;
			Heap = newHeap;
		}
		return target;
	}
	template<class T>inline void P_Queue<T>::moreCompacity(void)
	{
		changeSizeTo(2 * compacity);
	}
	template<class T>inline size_t P_Queue<T>::left(size_t i)const
	{
		size_t ans = i * 2;
		if (ans < compacityUsed)
		{
			return ans;
		}
		else
		{
			return i;
		}
	}
	template<class T>inline size_t P_Queue<T>::right(size_t i)const
	{
		size_t ans = i * 2 + 1;
		if (ans < compacityUsed)
		{
			return ans;
		}
		else
		{
			return i;
		}
	}
	template<class T>inline size_t P_Queue<T>::parent(size_t i)const
	{
		return i / 2;
	}
}
#endif
#define PQh