# Problem

>Give two fraction$\frac{x}{a}$ and $\frac{y}{b}$ where $0 \le x,y \le {10}^{18}$ and $0 < a,b \le {10}^{9}$.  
Compare them and output =,< or >.

>The input will be ordered as `x a y b` .

>For each case print a line contains given operator.

# Tip

As we know

$$\frac{x}{a}=\frac{y}{b}$$

equals

$$x\cdot b = y\cdot a$$

However we can only store integers no more than $2^{64}-1$ or about $1.8 \times {10}^{19}$ in `unsigned long long int` witch is the biggest integer type given by C++.  
This is a dead end.

However, it's too early to pull out BigInteger as $\frac{x}{a}=\lfloor\frac{x}{a}\rfloor +\frac{x \mod a}{a}$.  
This gives us the sweety fact that $\lfloor\frac{x}{a}\rfloor$,$x\mod a$ and $a$ are all less than $10^9$.