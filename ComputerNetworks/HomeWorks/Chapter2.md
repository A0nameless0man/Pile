# 计算机网络作业

## 2019年9月16日

|姓名|学号|学院|班级|
|---|---|---|---|
|胡广|201883290072|计算机与软件学院|计算机类2018级2班|

### $2-4$

|名词|解释|
|---|---|
|数据|是要传送的消息的逻辑实体|
|信号|是数据物理形式上的表现|
|模拟数据|数据是连续取值的|
|模拟信号|代表信号的物理量是连续取值的|
|基带信号|来着原始数据源的信号|
|带通信号|经过调制,适于在信道上发送的信号|
|数字数据|数据的取值是离散的|
|数字信号|代表信号的物理量具有离散的值|
|码元|一定长度的信号是一个码元,是特定传输方法传递信息的最小单位|
|单工通信|只有一边发送,一边接收|
|半双工通信|任意时刻只有一边发送一边接收|
|全双工通信|双方可以同时发送和接收|
|串行传输|一次发送一个码元|
|并行传输|一次同步地发送多个码元|

### $2-8$

#### 香农公式

$$
C = W \cdot \log_{2}{(1+\frac{S}{N})}
$$

#### 答

其应当具有的信噪比为:

$$
\huge 2^{\frac{64kbit/s\times 1.6}{3000Hz}}-1 \approx 2.64\times 10^{6}\\
\approx 64dB
$$

想要提高传输速率,还是提高带宽比较有效.

### $2-9$

#### 香农公式

$$
C = W \cdot \log_{2}{(1+\frac{S}{N})}
$$

#### 答

$$
\huge \frac{S}{N} = 2^{\frac{C}{W}}-1
$$

其应当具有的信噪比为:

$$
\huge 2^{\frac{35kbit/s\times 1.6}{3100Hz}}-1 \approx 2.5\times 10^{3}\\
\approx 34dB
$$

 $C$ 增加 $60\%$ 时, $S/N$ 的增加为:

$$
\Huge
\begin{array}{l}
\frac{2^{\frac{35kbit/s\times 1.6}{3100Hz}}-1}{2^{\frac{35kbit/s}{3100Hz}}-1} \\
{\approx 2^{0.6\times \frac{35kbit/s}{3100Hz}}}\\
\approx 109.5
\end{array}
$$

此时的 $S/N$ 大约为 $2.7\times 10^5$ ,在增加到十倍约为 $2.7\times 10^6$  
此时的 $C$ 为

$$
3100Hz\times \log_{2}{(1+2.7\times 10^6)}\\
\approx 66.3kbit/s
$$

增加了

$$
(\frac{66.3kbit/s}{35kbit/s\times 1.6}-1)\times 100\%\\
\approx 18\%
$$

不能再增加$20\%$

### $2-16$

码片序列

$$
\begin{array}{r|cccccccc}
\hline
A&-1&-1&-1&+1&+1&-1&+1&+1\\
\hline
B&-1&-1&+1&-1&+1&+1&+1&-1\\
\hline
C&-1&+1&-1&+1&+1&+1&-1&-1\\
\hline
D&-1&+1&-1&-1&-1&-1&+1&-1\\
\hline
\end{array} 
$$

收到了

$$
\begin{array}{r|cccccccc}
\hline
Rec&-1&+1&-3&+1&-1&-3&+1&+1\\
\hline
\end{array}
$$

取向量内积

$$
\begin{array}{r|c}
\hline
A&8\\
\hline
B&-8\\
\hline
C&0\\
\hline
D&8\\
\hline
\end{array}
$$

归一化

$$
\begin{array}{r|c}
\hline
A&1\\
\hline
B&-1\\
\hline
C&0\\
\hline
D&1\\
\hline
\end{array}
$$

收到的数据为

$$
\begin{array}{r|c}
\hline
A&1\\
\hline
B&0\\
\hline
D&1\\
\hline
\end{array}
$$