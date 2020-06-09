import sys
sys.setrecursionlimit(2**31-1)
def f(n):
    print(n)
    f(n+1)

f(0)