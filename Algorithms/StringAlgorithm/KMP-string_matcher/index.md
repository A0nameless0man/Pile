# 字符串的匹配

>就像多数的计算机问题一样，字符串匹配的描述是极其易懂的。
>
>给定两个字符串$key$和$target$
>
>寻找所有的整数$s$满足$\forall{i}\in\lbrace x \mid x \in N, 0 \leq x < key.length()\rbrace  key[i]==taarget[i+s]$

---

## 朴素字符串匹配

很容易想到对于每一个$s < target.length() - key.length()$检查是否满足性质。

```cpp
vector<int check(const string& key,const string& target)
{
	vector<int ans;
	for(int s = 0;s<target.length() - key.length();s++)
	{
		for(int i = 0;i<key.length();i++)
		{
			if(key[i]==target[s+i])
			{
				if(i==key.length()-1)
				{
					ans.push_back(s);
				}
			}
			else
			{
				break;
			}
		}
	}
	return ans;
}
```

复杂度是$O(key.length()*target.length())$

当$key$和$target$比较小的时候，这样子当然没有什么问题

但是如果有一天，你需要在一个256MB的文本文件中寻找一个长为1000的字符串

比如在$10^9$以内的素数表中查找有没有出现$\pi$的前一千位。这个算法就会消耗好几分钟的时间才能得到结果。

---

## KMP字符串匹配

为了更快地匹配大量字符串（也可以是好多数字或者二进制码）需要找到一种节省时间的方法。
考虑以下情况:

- 对于某个$s$,我们已经匹配了其后的$i-1$个字符，但是第$i$个不能配对，我们称这是一次失败的配对
	但是这样的失败是有价值的，让我们知道$target$中$s$开始的$i-1$个字符是匹配的
	匹配失败后直接`i = 0;`然后`s++;`的方法直接抛弃了这样的信息
  - 假设$key$中所有字符各不相同，一次匹配失败就能让我们知道
	$key[0]\notin target[s+1:s+i]$
	因此可以`s += i;i = 0;`然后开始下一轮匹配
- 假设$key[0:2]==key[i-2:i]$
	尽管匹配失败了，但是知道了$target[s+i-2:s+i]==key[i-2:i]$
	那么也就知道了$target[s+i-2:s+i]==key[0:2]$
	这样子,我们可以`i = 2;`然后继续尝试匹配

所以,要是能事先对于所有的$i$计算出最大的$k$使得$key[0:k]==key[i-k:i]$

就可以在$O(target.length())$的时间内完成匹配~~岂不美哉~~

确实,可以花费$O(key.length())$的时间内求得这个数组

让我们称之为$next$,因为它指示了每次匹配失败时下一步应当匹配哪个字符.

方法其实是对于部分的$key$使用部分的$next$

```cpp
vector<size_t>& caculateNext(const string& key, vector<size_t>& next)
{
	//vector<int next;
	next.clear();
	next.resize(key.length());
	next[0] = 0;
	size_t j = 0;
	for (size_t i = 1; i < key.length(); i++)
	{
		while (j!=0&&key[j]!=key[i])
		{
			j = next[j-1];
		}
		if (key[j]==key[i])
		{
			++j;
		}
		next[i] = j;
	}
	return next;
}
```

- 假设$next[i]=j$,$next[j]=k$
    有$key[0:j]==key[i-j+1:i+1]$又有$key[0:k]==key[j-k+1:j+1]$
    故有$key[0:k]==key[i-k+1:i+1]$

- 假设$j=next[i-1]$且$k=next[j]$
    即$key[0:j]==key[i-j:i]$
  - 如果$key[i]==key[j]$
    $key[0:j+1]==key[i-j+1:i+1]$
    $next[i]=j+1$
  - 否则
    有$key[0:k]=key[i-k:i]$
    相当于$k=next[i-1]$
    再做上面的判断

求出$next$后应用以下代码

```cpp
vector<size_t> KMP_string_matcher(const string& target, const string& key, const vector<size_t>& next)
{
	vector<size_t> ans;
	size_t j = 0;
	for (size_t i = 0; i < target.length(); i++)
	{
		while (j != 0 && target[i] != key[j])
		{
			j = next[j-1];
		}
		if (target[i]==key[j])
		{
			j++;
		}
		if (j==key.length())
		{
			ans.push_back(i - j + 1);
			j = next[j-1];
		}
	}
	return ans;
}
```

总的时间消耗为$O(key.length()+target.length())$

~~这里好想插个gif~~
