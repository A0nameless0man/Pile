s = "1145141919" * 20
l = [int(c) for c in s]


def get(left: int, right: int):
    if left + 1 == right:
        return set([l[left]])
    else:
        ans = set()
        sum = int(s[left:right])
        ans.add(sum)
        for i in range(left + 1, right):
            leftset = get(left, i)
            rightset = get(i, right)
            for a in leftset:
                for b in rightset:
                    ans.add(a * b)
                    ans.add(a + b)
        return ans


rng = 5000
ans = [-1 for i in range(1, rng + 2)]
limit = 1
cnt = rng
while cnt != 0:
    for possible in get(0, limit):
        if possible < rng + 1 and ans[possible] == -1:
            ans[possible] = limit
    cnt = 0
    for pos in range(1, rng + 1):
        if ans[pos] == -1:
            cnt += 1
    print("limit: " + str(limit) + " cnt: " + str(cnt))
    if cnt < 10:
        for pos in range(1, rng + 1):
            if ans[pos] == -1:
                print(str(pos) + " ", end="")
        print("")
        if cnt < 3:
            break
    limit += 1
print(ans)

