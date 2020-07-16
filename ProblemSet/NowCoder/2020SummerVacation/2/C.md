1. 选非叶子节点为根

2. 对叶子节点排DFS序

$S_i \to S_{|S|/2+i}$

$[L,R]$

$R \leq |S|/2 \to  (S_R \to S_{|S|/2+R})$ 

$L \ge |S|/2 \to  (S_L \to S_{|S|/2-L})$

$L \neq 1 \lor R\neq |s|$

$L \neq 1$ $S_1 \to S_{|S|/2+1}$