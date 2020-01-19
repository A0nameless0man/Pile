#### 题目描述
[传送门系列](https://store.steampowered.com/app/620/Portal_2/)是由著名的游戏公司V社推出的一款解迷游戏.
游戏中,玩家需要利用手中的传送枪从关卡的入口出走到出口.

传送枪可以在能够看见的墙面上打开传送门,让玩家到达无法直接走到的地方.  
传送枪最多可以打开一橙一蓝两个传送门,走进橙色传送门就会走出蓝色传送门,反之亦然.  
如果需要打开新的传送门,则必须取消之前的某个传送门

玩家主要面临两种障碍:酸液池和墙壁.
- 酸液池具有腐蚀性,因此不能通行,但是不会挡住视线.  
- 墙壁是坚固的,因此也不能通行,还会挡住视线,但是你可以在它上面你看得见的位置打开传送门. 

至于地面,它可以行走也不会挡住视线,但是不能在地面上开传送门

为了简化问题,我们假设玩家只能看见在自己正东,正西,正南和正北方向的东西,只能走到相邻的路面(不能沿对角线行走).  
举例说:  
如果用`'.'`,`'g'`,`'w'`,分别代表酸液池,地面和墙壁.

$$
\begin{array}{ccccccccccccc}
w&w&w&w&w&w&W&w&w&w&w&w&w&w\\
w&.&.&.&.&.&\vdots&.&.&.&w&.&.&w\\
w&.&.&g&g&.&\vdots&.&.&.&.&.&g&w\\
W&\cdots&\cdots&G&G&\cdots&P/G&\cdots&\cdots&\cdots&\cdots&\cdots&G&W\\
w&.&.&g&g&.&\vdots&.&.&.&.&.&g&w\\
w&w&w&w&w&w&\!\!\underline{\ \ W\ \  }\!\!\!&w&w&w&w&w&w&w\\
w&.&.&.&.&.&.&.&.&.&.&.&.&w\\
w&w&w&w&w&w&w&w&w&w&w&w&w&w\\
\end{array}
$$

上图中,玩家站在`'P'`处,他能够看见的部分如图所示. 
他的视线在下方被墙挡住了,因此看不到后面的第二堵墙.  

如果玩家可以看见一堵墙,他就能在那上面开传送门.  
但是只有传送门门口是地面,才有意义.

$$
\begin{matrix}
&1&2&3&4&5&6&7&8&9&10&11&12&13&14\\
A&w&w&w&w&w&W&w&w&w&w&w&w&w&w\\
B&w&.&.&.&.&.&.&.&.&.&w&.&e&w\\
C&w&.&.&g&g&g&.&.&.&.&w&.&g&w\\
D&W&.&.&g&g&P/g&.&.&.&.&.&.&g&W\\
E&w&.&.&g&g&.&.&.&w&.&.&.&.&w\\
F&w&w&w&w&w&W&w&w&w&w&w&w&w&w\\
\end{matrix}
$$

在本场景中,玩家现在可以看见四面墙,为`A6`,`D1`,`D14`和`F6`. 他可以在其中任意一面上打开传送门. 
但是只有`D14`上的传送门可以供人通行.

在本场景中,玩家应当
1. 走到`D5`,在`F5`和`D14`上分别打开传送门
2. 走到`E5`,穿过传送门到达`D13`
3. 走到`B13`处的出口,游戏结束

- 一共打开了 $\Huge 2$个传送门

由于玩家[Nekopara](https://store.steampowered.com/app/333600/NEKOPARA_Vol_1)玩多了,现在精神不太好,请帮他计算一下需要打开多少传送门才能通过关卡.

#### 输入输出描述

##### 输入

开头是一个整数$T$,代表这个输入拥有$T$组数据.  
每组数据的第一行包括两个整数$m$,$n$代表地图的大小.  
以下$m$行,每行有$n$个字符. 为`'.'`,`'g'`,`'w'`,`'p'`,`'e'`之一,分别代表酸液池,地面,墙壁,玩家当前位置和出口位置. 玩家和出口位置相当于地面.  
保证地图由墙壁包围

数据范围:

1. 保证对于每组数据有$m,n\leq 100$
2. 保证对于每个测试点有$\sum_{}{m \cdot n}\leq 2\times 10^5$

##### 输出

请对于每组数据输出一个整数,代表玩家最少需要打开传送门的次数.  
每个整数占一行.  
如果不存在可行的方案,请输出$-1$

$$\Huge \textrm{请不要输出多余空格或者空行}$$
$$\Huge \textrm{请不要输出正数的'+'}$$

#### 输入输出样例

##### 样例$1$

$input$:

```
1
5 6
wwwwww
wpggew
w....w
wg..gw
wwwwww
```

$output$:

```
0
```

##### 样例$2$

$input$:

```
1
3 6
wwwwww
wp..ew
wwwwww
```

$output$:

```
2
```
##### 样例$3$

$input$:

```
1
5 6
wwwwww
wp.wew
w....w
wg..gw
wwwwww
```

$output$:

```
4
```

##### 样例$4$

$input$:

```
1
7 6
wwwwww
wp.wgw
w...gw
we..gw
w....w
wg..gw
wwwwww
7 6
wwwwww
wp.wgw
w...gw
we...w
w....w
wg..gw
wwwwww
```

$output$:

```
5
-1
```