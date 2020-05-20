n, m = map(int, input().split())
cnt = [0 for i in range(m)]
for i in range(n):
    t = [int(i) for i in input().split()]
    for j in range(m - 1):
        if t[j] != t[j + 1]:
            cnt[j + 1] = 1
cnt[0]=1
for i in range(1, m):
    cnt[i] = cnt[i] + cnt[i - 1]
print(" ".join([str(i) for i in cnt]))
