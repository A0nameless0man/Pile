# D

$$
\begin{aligned}
F(x)& = \begin{bmatrix}
x^4&x^3&x^2&x^1&x^0\\
\end{bmatrix}
\cdot
\begin{bmatrix}
a\\
b\\
c\\
d\\
e\\
\end{bmatrix}
\land
\begin{aligned}
F(1)& = 1\\
F(2)&= 2\\
F(3)&= 4\\
F(4)&=8\\
F(5)&= 16\\
\end{aligned}\\
\Rightarrow &
\begin{bmatrix}
1& 1& 1& 1& 1\\
16&8&4&2&1\\
81&27&9&3&1\\
256&64&16&4&1\\
625&125&25&5&1\\
\end{bmatrix}
\cdot
\begin{bmatrix}
a\\
b\\
c\\
d\\
e\\
\end{bmatrix}=
\begin{bmatrix}
1\\
2\\
4\\
8\\
16\\
\end{bmatrix}\\
\Rightarrow &
\begin{bmatrix}
1& 1& 1& 1& 1\\
15&7&3&1&0\\
80&26&8&2&0\\
255&63&15&3&0\\
624&124&24&4&0\\
\end{bmatrix}
\cdot
\begin{bmatrix}
a\\
b\\
c\\
d\\
e\\
\end{bmatrix}=
\begin{bmatrix}
1\\
1\\
3\\
7\\
15\\
\end{bmatrix}\\
\Rightarrow &
\begin{bmatrix}
1& 1& 1& 1& 1\\
15&7&3&1&0\\
50&12&2&0&0\\
210&42&6&0&0\\
564&96&12&0&0\\
\end{bmatrix}
\cdot
\begin{bmatrix}
a\\
b\\
c\\
d\\
e\\
\end{bmatrix}=
\begin{bmatrix}
1\\
1\\
1\\
4\\
11\\
\end{bmatrix}\\
\Rightarrow &
\begin{bmatrix}
1& 1& 1& 1& 1\\
15&7&3&1&0\\
50&12&2&0&0\\
60&6&0&0&0\\
264&24&0&0&0\\
\end{bmatrix}
\cdot
\begin{bmatrix}
a\\
b\\
c\\
d\\
e\\
\end{bmatrix}=
\begin{bmatrix}
1\\
1\\
1\\
1\\
5\\
\end{bmatrix}\\
\Rightarrow &
\begin{bmatrix}
1& 1& 1& 1& 1\\
15&7&3&1&0\\
50&12&2&0&0\\
60&6&0&0&0\\
24&0&0&0&0\\
\end{bmatrix}
\cdot
\begin{bmatrix}
a\\
b\\
c\\
d\\
e\\
\end{bmatrix}=
\begin{bmatrix}
1\\
1\\
1\\
1\\
1\\
\end{bmatrix}\\
\Rightarrow &
\begin{bmatrix}
a\\\\
b\\\\
c\\\\
d\\\\
e\\
\end{bmatrix}=
\begin{bmatrix}
\frac{1}{24}\\\\
\frac{-6}{24}\\\\
\frac{23}{24}\\\\
\frac{-18}{24}\\\\
1\\
\end{bmatrix}\\
\end{aligned}
$$
