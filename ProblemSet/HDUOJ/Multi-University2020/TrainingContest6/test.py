s = "1145141919" * 20
l = [int(c) for c in s]
# WARNNG This Program Takes Over 20GiB of memory,Makesure that you have enough RAM!
# 警告 这个程序消耗超过 20GiB 的内存，请确定你有足够的内存
rang = 10000000

mem = {}

def get(left: int, right: int):
    if mem.__contains__((left, right)):
        return mem[(left,right)]
    elif left + 1 == right:
        return {l[left]:str(l[left])}
    else:
        ans = {}
        sum = int(s[left:right])
        if(sum <= rang):
            ans[sum]=s[left:right]
        for i in range(left + 1, right):
            leftset = get(left, i)
            rightset = get(i, right)
            for a,expra in leftset.items():
                for b,exprb in rightset.items():
                    mul = a*b
                    add = a+b
                    if(mul <= rang and not ans.__contains__(mul)):
                        # ans[mul]=" ".join([expra,exprb,'*'])
                        ans[mul]="".join(["(",expra,')*(',exprb,")"])
                    if(add <= rang and not ans.__contains__(add)):
                        # ans[add] = " ".join([ expra,exprb, '+'])
                        ans[add] = "".join(["(",expra,')+(',exprb,")"])
        mem[(left,right)]=ans
        return ans


ans = [-1 for i in range(1, rang + 2)]
expr = ["" for i in range(1, rang + 2)]
limit = 1
cnt = rang
f2 = open("out2.txt","w")

while cnt != 0:
    var = get(0, limit)
    for possible in var:
        if possible <= rang and ans[possible] == -1:
            ans[possible] = limit
            expr[possible] = var[possible]
            f2.write(str(possible)+" : "+str(ans[possible])+" : "+expr[possible]+"\n")
    cnt = 0
    for pos in range(1, rang+1):
        if ans[pos] == -1:
            cnt += 1
    print("limit: " + str(limit) + " cnt: " + str(cnt))
    if cnt <= 2:
        for pos in range(1, rang+1):
            if ans[pos] == -1:
                print(str(pos) + " ", end="")
        print("")
        break
    limit += 1
f = open("out.txt","w")
for i in range(1, rang + 1):
    # print(str(ans[i])+" : "+expr[i])
    f.write(str(i)+" : "+str(ans[i])+" : "+expr[i]+"\n")
