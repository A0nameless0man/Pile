#ifndef NULL
#    include <stdio.h>
#endif  // !NULL
using LengthOfChainTable = unsigned long long int;
template <class T>
using ptr = T *;
namespace
{
template <class T>
class C_Table_Node
{
public:
    C_Table_Node(T);
    ~C_Table_Node();
    ptr<C_Table_Node<T>> findFirst(T target);
    LengthOfChainTable   count(T target);
    T                    get(void);
    void                 change(T result);
    void                 setNext(ptr<C_Table_Node<T>>);
    ptr<C_Table_Node<T>> getNext(void);
    void                 setLast(ptr<C_Table_Node<T>>);
    ptr<C_Table_Node<T>> getLast(void);

private:
    T                    Data;
    ptr<C_Table_Node<T>> next, last;
};
template <class T>
C_Table_Node<T>::C_Table_Node(T input): Data(input), next(NULL), last(NULL)
{
}
template <class T>
C_Table_Node<T>::~C_Table_Node(void)
{
}
template <class T>
ptr<C_Table_Node<T>> C_Table_Node<T>::findFirst(T target)
{
    if(Data == target)
    {
        return this;
    }
    else
    {
        if(next != NULL)
        {
            return next->findFirst(target);
        }
        else
        {
            return NULL;
        }
    }
}
template <class T>
LengthOfChainTable C_Table_Node<T>::count(T target)
{
    return (next == NULL ? 0 : next->count(target)) + (Data == target ? 1 : 0);
}
template <class T>
T C_Table_Node<T>::get(void)
{
    return Data;
}
template <class T>
void C_Table_Node<T>::change(T result)
{
    Data = result;
}
template <class T>
void C_Table_Node<T>::setNext(ptr<C_Table_Node<T>> toBeNext)
{
    next = toBeNext;
}
template <class T>
ptr<C_Table_Node<T>> C_Table_Node<T>::getNext(void)
{
    if(this != NULL)
    {
        return next;
    }
    else
    {
        return NULL;
    }
}
template <class T>
void C_Table_Node<T>::setLast(ptr<C_Table_Node<T>> toBeLast)
{
    last = toBeLast;
}
template <class T>
ptr<C_Table_Node<T>> C_Table_Node<T>::getLast(void)
{
    if(this != NULL)
    {
        return last;
    }
    else
    {
        return NULL;
    }
}
}  // namespace
template <class T>
using iterator = ptr<C_Table_Node<T>>;
template <class T>
class ChainTable
{
private:
public:
    ChainTable(void);
    ~ChainTable(void);
    void               push(T input);
    LengthOfChainTable count(T target);
    bool               remove(T target);
    void               change(T target, T result);
    LengthOfChainTable Length(void);
    bool               empty(void);

private:
    LengthOfChainTable length;
    iterator<T>        Data;
};
// template<class T> iterator<T>& operator++(iterator<T>& a)
//{
//	return a = a!=NULL?a->getNext():NULL;
//}
// template<class T> iterator<T>& operator--(iterator<T>& a)
//{
//	return a = a!=NULL?a->getLast():NULL;
//}
template <class T>
ChainTable<T>::ChainTable(void): length(0)
{
    delete Data;
    Data = NULL;
}
template <class T>
ChainTable<T>::~ChainTable(void)
{
    iterator<T> tempPtr = Data;
    while(tempPtr != NULL)
    {
        Data = tempPtr->getNext();
        delete tempPtr;
        tempPtr = Data;
    }
}
template <class T>
void ChainTable<T>::push(T input)
{
    if(Data == NULL)
    {
        Data = new C_Table_Node<T>(input);
    }
    else
    {
        iterator<T> tempPtrNext = Data;
        Data                    = new C_Table_Node<T>(input);
        Data->setNext(tempPtrNext);
        tempPtrNext->setLast(Data);
    }
    length++;
}
template <class T>
LengthOfChainTable ChainTable<T>::count(T target)
{
    if(!empty())
        return Data->count(target);
    else
        return 0;
}
template <class T>
bool ChainTable<T>::remove(T target)
{
    if(!empty())
    {
        iterator<T> removeTarget = Data->findFirst(target);
        if(removeTarget != NULL)
        {
            iterator<T> tempPtrNext = removeTarget->getNext(),
                        tempPtrLast = removeTarget->getLast();
            if(tempPtrLast != NULL)
            {
                tempPtrLast->setNext(tempPtrNext);
            }
            if(tempPtrNext != NULL)
            {
                tempPtrNext->setLast(tempPtrLast);
            }
            delete removeTarget;
            length--;
            if(length == 0)
            {
                Data = NULL;
            }
            return true;
        }
        else
        {
            return false;  // Not Find
        }
    }
    else
    {
        return false;  // NO Data At All
    }
}
template <class T>
void ChainTable<T>::change(T target, T result)
{
    if(!empty())
    {
        iterator<T> tempPtr = Data->findFirst(target);
        if(tempPtr != NULL)
        {
            tempPtr->change(result);
        }
    }
}
template <class T>
LengthOfChainTable ChainTable<T>::Length(void)
{
    return length;
}
template <class T>
bool ChainTable<T>::empty(void)
{
    if(length == 0 || Data == NULL)
        return true;
    else
        return false;
}