# 最小生成树问题

>最小生成树问题指给定一张无向连通图$G = (V,E)$,选取一个$E$的子集$T$,使得图$G = (V,T)$仍然是连通的且$\sum_{e \in T}{e.\omega}$尽可能小

显然,$T$中不能有环,不然可以简单的删去一条环边,又要保证连通,$\mid T \mid = \mid V \mid -1$

下面将论及两种MST的算法$Kruskal$和$Rrim$

## 最小生成树的形成

假定有一个连通无向图$G = (V,E)$和权重$\omega$,准备找出图$G$的一个最小生成树,本章讨论的两种方法都可以用以下过程来描述:

1. $A$是个空集

2. 当$A$还不是一个生成树时

    1. 找到一条边$e$使得将$e$加入$A$之后,$A$仍然是最小生成树的一个子集

    2. 将$e$加入$A$

3. $A$即为所求的最小生成树

这两种算法全部的奥妙都在于如何找到符合要求的边$e$,满足这种性质的边也被称作安全边.

现在来介绍一条辨认安全边的规则

## 判断安全边

首先,定义切割的概念

无向图$G = (V,E)$的一个**切割**是$V$的一个划分$(S,V-S)$

如果有一条边$(u,v) \ u \in S \ \land v \in V-S$称这条边**横跨**切割$(S,V-S)$

如果集合$A$中没有横跨$(S,V-S)$的边,称$(S,V-S)$**尊重**集合$A$

在所有横跨$(S,V-S)$的边中权重最小的边称**轻量级边**

```mermaid

graph TB
subgraph 
a
b
d
e
end
subgraph 
h
i
g
c
f
end
a-.4.-b
d--9---e
h--7---i
i--6---g
h-.1.-g
i-.2.-c
g-.2.-f
c-.4.-f
h--8---a
h--11---b
b--8---c
c--7---d
d--14---f
f--10---e
```

以上打虚线的是集合$A$

框出的是尊重集合$A$的分割$(S,V-S)$

边$(c,d)$是轻量级边
### 定理

- 假设$G = (V,E)$是一个带权无向连通图

    $A$是$E$的一个子集  
    且$A$是某最小生成树的子集
    
    $(S,V-S)$是尊重$A$的一个切割  
    $e$是横跨$(S,V-S)$的一个轻量级边

- 那么边$e$对$A$是安全的

### 证明

假设$T$是一颗包括$A$的最小生成树,且$T$不包含$e$

- $T$中必有且仅有一条简单路径$e.u \leadsto e.v$

    且这条路径横跨切割$(S,V-S)$

    - 其上必至少有一边$e'$横跨切割$(S,V-S)$

- 因为$e$是横跨$(S,V-S)$的一个轻量级边

    - 用$e$替代$e'$不会使情况变坏

- 又有$e \notin A$

    - $e$可以被加入$A$中

- $(S,V-S)$是尊重$A$的一个切割  

    - 加入$e$不会造成环

边$e$对$A$是安全的

### 推论

- 假设$G = (V,E)$是一个带权无向连通图

    $A$是$E$的一个子集  
    且$A$是某最小生成树的子集  
    $C=(V_C,E_C)$是森林$G_A = (V,A)$中的一个连通分量
    
    如果边$e$是连接了$C$和$G_A$中另一连通分量的一条轻量级边
    
- 这条边是安全的

## $Kruskal$算法

在这种算法中,考虑$A = ( V , \emptyset )$

不断地向$A$加入最小的连通两个分量的边

通过**查并集**可以快速地检查一个边是否连接了同一棵树,用`Union(u,v)`来合并两个集合

```python
def KruskalMST(G):
    A = emptySet()
    for v in G.V:
        v.father = v
    sort( G.E ,key = weight )
    for (u,v) in G.E:
        if  u.father != v.father:
            A.insert((u,v))
            Union(u,v)
    return A
```
### 时间消耗

1. 第一个`for`$\mathrm{O}(V)$

2. 排序$\mathrm{O}(E*\log{E})$

3. 第二个循环$\mathrm{O}(E)$

4. 所有的`Nuion(u,v)`$\mathrm{O}(V*\log{V})$

- 图是连通的,有$V \le E + 1$

- 又有$E < V^2$

    - 有$\mathrm{O}(E*\log{E}) \approx \mathrm{O}(E*\log{V})$

总时间$\mathrm{O}(E*\log{V})$

## $Prim$算法

在这种算法中$A$中的边永远构成一颗树

不断将连接$A$内和$A$外的轻量级边加入$A$

直到完成

为了决定下一个取哪条边

对于每个节点维护一个$key$属性,为它到$A$中的所有边的最小权重

再用$key$属性维护一个优先队列,用来决定下一个接谁

```python
def PrimMST(G):
    A = emptySet()
    for u in G.V
        u.key = INF
        u.pi = NIL
        u.done = False
    r = randomSelect(G.V)
    r.key = 0
    Q = priorityQueue({r},key = key)
    while not Q.empty():
        u = Q.top()
        if not u.done:
            for v in G.Adj[u]:
                if  not v.done and weight(u,v) < v.key:
                    v.pi = u
                    v.key = weight(u,v)
                    Q.push(v.key,v)
            u.done = True
            A.insert(u.pi,u)
        Q.pop()
```

### 时间消耗

1. 第一个初始化循环$\mathrm{O}(V)$

2. 遍历所有的`Adj[]`耗时$\mathrm{O}(E)$

3. 优先队的`push()`和`pop()`$\mathrm{O}(E*\log{E})$

总时间$\mathrm{O}(E*\log{V})$

**但是**如果使用斐波那契堆,优先队的消耗会变成$\mathrm{O}(V*\log{V})$,总时间$\mathrm{O}(E + V*\log{V})$