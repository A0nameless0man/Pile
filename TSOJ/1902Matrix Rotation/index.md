题目描述:

>Give you a $n*n$ matrix, if you rotate it $90^{\circ}$(clockwise$\circlearrowright$), we call it $Matrix_1$, if you rotate it $180^\circ$ degrees, we call it $Matrix_2$, etc … This is said if you rotate the Matrix $k*90^\circ$ degrees, then we call it $Matrix_k$. Now, your task is to calculate $\sum_{i = 0}^{k
}{Matrix_i}$.

输入描述：

>There multiple test cases. Each test case begins with one integer $n$$( 1 \le n \le 10 )$, following n lines, each line contains n integers, describe the original matrix, then a single line contains a$k$$( 1 \le k \le 10^8 )$described above. Process to end of file.

输出描述：

>For each case, output $\sum_{i = 0}^{k
}{Matrix_i}$ in n lines. Each line there are $n$ integers separated by one space. **Note** that there is **No** extra space at the end of each line.

>Attention：for the largest date，you‘d better use the type of long long to ouput your answer。

样例输入:

```
3

1 2 3

2 3 4

3 4 5

10
```

样例输出:

```
33 32 31

34 33 32

35 34 33
```