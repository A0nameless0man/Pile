# 所有节点对的最短路径问题

## 概述

最短路径问题在对应的文章里已有阐述,但是,现实中,为了应对大量的查询,有时候需要提前计算出关于某张图的最短路径问题的所有答案.  
我们当然可以对于每一个节点运行Dijkstra之类的算法,但是这样子$O(V\cdot(V+E)\cdot Log(V))$的复杂度是比较高的,尤其是考虑到最短路问题具有最优子结构的特性这一点,应当有许多重复的工作是可以省去的.

另外,在这一节中,也会看到图的最短路问题与矩阵乘法的密切关系

## 算法的输入

简单来说,需要输入一张图.  
但是图也是有许多记录形式的,由于后面会说明的原因,我们这里采用邻接矩阵$W$来保存这张图.

## 算法的输出

这个算法的结果无疑不能用一个简单的数字代表,我们需要一个$V\times V$矩阵$D$.

$$
D = 
\begin{bmatrix}
d_{1\ 1}&d_{1\ 2}&\cdots & d_{1 \ n}\\
d_{2\ 1}&d_{2\ 2}&\cdots & d_{2 \ n}\\
\vdots&\vdots&\ddots&\vdots\\
d_{n\ 1}&d_{n\ 2}&\cdots & d_{n \ n}\\
\end{bmatrix}
$$

其中,$d_{i \ j}$满足

$$
d_{i \ j} = 
\begin{cases}
0&i=j\\
\delta(i,j)&i\neq j \land \textrm{Ther is path form }V_i\textrm{ to }V_j\\
\infty&\textrm{Ther isn't path form }V_i\textrm{ to }V_j\\
\end{cases}
$$

另外,由于需要解决最短路径是哪一条的问题,我们还需要前驱节点矩阵$P$

$$
P =
\begin{bmatrix}
\pi_{1\ 1}&\pi_{1\ 2}&\cdots&\pi_{1\ n}\\
\pi_{2\ 1}&\pi_{2\ 2}&\cdots&\pi_{2\ n}\\
\vdots&\vdots&\ddots&\vdots\\
\pi_{n\ 1}&\pi_{n\ 2}&\cdots&\pi_{n\ n}\\
\end{bmatrix}
$$

其中,$\pi_{i\ j}$满足

$$
\pi_{i\ j} = 
\begin{cases}
\textrm{NULL}&\textrm{Ther isn't path form }V_i\textrm{ to }V_j \lor i=j\\
\textrm{The predecessor vertex of } V_j \textrm{ when sourced from } V_i&\textrm{Ther is path form }V_i\textrm{ to }V_j \land i \neq j\\
\end{cases}
$$

## 计算

### 概述

1. 基于矩阵乘法解决本问题,复杂度为$O(V^3 \cdot Log_{2}{V})$
2. 给出一种动态规划算法,即为$Floyed\!-\!Warshell$算法
    - 同时,也讨论了在有向图中寻找传递闭包的算法,这与解决本问题有关
3. 介绍$Johnson$算法,其能够在$O(V^2\cdot Log_{2}{V}+V\cdot E)$的时间内完成,如果是稀疏图的话,这是个相当好的算法

### 基于矩阵乘法的最短路算法

#### 约定

首先声明,这里是基于矩阵乘法,而不是使用矩阵乘法,所以有必要做出一些约定

1. 以下提及的任意矩阵都具有$\mid V \mid$的边长

2. 矩阵用大写字母表示,矩阵元素用小写字母表示

3. $v_{i \ j}$为矩阵$V$的第$i$行第$j$列的元素

4. 带括号的上标代表对矩阵的迭代,比如说如果$V$是原始矩阵,$V^{(1)}$就是它迭代的第一次,$v^{(1)}_{i \ j}$就是它迭代第一次时的对应矩阵

#### 迭代

之前的内容已经让我知道,任何最短路径的子路径都是最短路径.  
因此,假定用一个邻接矩阵$W$来存储输入的图.  
考虑一个在节点$i$,$j$之间的路径$p^{(m)}_{i \ j}$,它最多包含$m$条边.  
假定没有权重为负的环.

如果$i=j$,则$p^{(m)}_{i \ j}=0$  
如果$i\neq j$,则有$\exist k \in V , p^{(m)}_{i \ j}=p^{(m-1)}_{i \ k}+w_{k \ j}$  

特别的,$m=0$和$m=1$时,矩阵$P$具有一些有趣的性质  
比如说

$$
p^{(0)}_{i \ j} = 
\begin{cases}
0&i=j\\
\infty &i\neq j\\
\end{cases}
$$

还有

$$
P^{(1)}=W
$$

当$m \geq 2$时,有

$$
\huge
p^{(m)}_{i \ j} = 
\min_{k \in V , (k,j)\in E}{(\ p^{(m-1)}_{i\ k}+w_{k\ j})}
$$

#### 实现

基于这个递归的定义,我们很容易写出一种$O(V^{4})$的写法

```python
from numpy import *

def iterate(P,W):
    assert(P.size() == W.size())
    n = P.size()
    newP = mat(zeros((n,n)))
    for i in range(n):
        for j in range(n):
            knowMin = INF
            for k in range(n):
                knowMin = min(knowMin,P[i,k]+W[k,j])
            newP[i,j] = knowMin
    return newP

def plainMatrixAlgorithm(W):
    n = W.size()
    P = mat(full((n,n),INF))
    for i in range(n):
        P[i,i] = 0
    for times in range(n):
        P = iterate(P,W)
    return P
```

明显的,这个算法具有一个相当高的复杂度.  
但这只是一个起点.

注意到,最短路径的拆分是任意的,其结合也是符合结合律的.也就是说,$P^{(2*m)}=iterate(P^{(m)},P^{(m)})$  
多么美妙的性质,现在可以请出我们的快速幂算法

```python

def quickPowMatrixAlgorithm(W):
    n = W.size()
    P = mat(full((n,n),INF))
    for i in range(n):
        P[i,i] = 0
    while n:
        if n % 2:
            P = iterate(P,W)
        W = iterate(W,W)
        n = n//2
    return P    

```

快速幂这个巧妙的算法将我们的复杂度降低至$O(V^3 \cdot Log_{2}{V})$.这确实相当快.  
但是,在每次独立的迭代中,许多根本不存在的边占用了大量的时间.  
要进一步优化,我们需要从矩阵乘法中脱离出来,寻找更高效的方案.

### $Floyed\!-\!Warshell$算法

#### 原理

>在这种算法中我们仍然需要用到最短路径可以任意拆分的特性.  
但不是考虑从$i$到$j$的最短路径可以如何拆分,而是考虑考虑这个路径是否经过点$k$.  

假定$V^{(k)}$是$V$的一个子集:

$$
V^{(k)} = \bigcup_{i = 1}^{k}{ \{ V_{i} \} }
$$

假设$p^{(k)}_{i \ j}$代表$i$与$j$之间,只经过$V^{(k)}$中的点的一条最短路径.

我们有:

- 如果$k \notin p^{(k)}_{i \ j}$

    $$p^{(k)}_{i \ j} = p^{(k-1)}_{i \ j}$$

- 如果$k \in p^{(k)}_{i \ j}$

    $$p^{(k)}_{i \ j} = p^{(k-1)}_{i \ k}+p^{(k-1)}_{k \ j}$$

#### 计算

由以上知识,我们定义$D^{(k)}$为只能经过$V^{(k)}$中节点时的路径权重矩阵

由上面的原理可知

$$
\huge
d^{(k)}_{i\ j} = 
\begin{cases}
w_{i \ j}&k=0\\
\min(d^{(k-1)}_{i \ j},d^{(k-1)}_{i \ k}+d^{(k-1)}_{k \ j})&k > 0\\
\end{cases}
$$

通过一个也没有那么麻烦的三重循环,我们可以得到

```python
def Floyed_WarshallAlgorithm(W):
    n = W.size()
    D = [matrix(W),matrix(W)]
    for k in range(n):
        for i in range(n):
            for j in range(n):
                D[k%2][i][j]=min(D[(k-1)%2][i][j],D[(k-1)%2][i][k]+D[(k-1)%2][k][j])
    return D[n%2]
```

无需多言,这是个$O(V^3)$的算法,而且具有稳定的运行时间期望,对于稠密图,这是个相当好的算法了

### $Johnson$算法

该算法可以在$O(V^2\cdot Log_{2}{V}+V\cdot E)$的时间内完成,在稀疏图的情况下,要比前面介绍的算法都要快,但是如果是稠密图乃至完全图则有可能跑不过$Floyed\!-\!Warshell$

不过现实当中,让$Johnson$算法发挥其优势的情况比较多

$Johnson$算法的本质就是通过某种方法,修改图的权重,使得不存在任何负权边.

但是,既然基于优先队的spfa可以应对负权边的情况,实际上只需要反复套用spfa就可以了,当然,这需要图比较稀疏才能跑过$Floyed\!-\!Warshell$算法