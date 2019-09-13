堆是一种二叉树，但是不同于我以前所理解的二叉树：$left \le parent \le right \lor left \ge parent \ge right$

堆满足$parent \le left \land parent \le right \lor parent \ge left \land parent \ge right$

父节点大的叫最大堆，因为根节点是堆中最大元素

相反的叫最小堆。

实现上来说，通常放在数组里，并且

1. $left(i) = 2*i$
2. $right(i) = 2*i +1$
3. $parent(i) = \lfloor i/2 \rfloor$
4 记录一共有多少元素，是为$size$

堆有个关键操作叫维护堆性质，最大堆中大致步骤如下：

1. 已知$heap[i]$违反了性质，即$heap[i] < heap[left(i)] \lor heap[i] < heap[right(i)]$。**注意**，保证$heap[i]$为根节点的子树中每个元素小于$heap[parent(i)]$的父节点。
2. 将$heap[i]$与$max( heap[left(i)]  ,heap[right(i)])$交换
3. 对于子树检查性质并予以必要的维护。

向堆中加入元素时

1. 把元素放到$heap[heap.size]$处
2. $for(int \ i = parent(heap.size);i \ge 0;i- -)$，维护堆性质，直到发现堆性质已经满足
3. $heap.size++$

从数组建堆时

1. $for(int \ i = parent(heap.size);i \ge 0;i- -)$，维护堆性质

删除堆顶元素时

1. 把 $heap[0]$ 与$heap[heap.size]$ 交换
2.  $heap.size - -$
3. 对于$haep[0]$维护堆性质