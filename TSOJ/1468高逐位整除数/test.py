def f(n):
    li = {0}
    for i in range(1,n+1):
        tempSet = set()
        for u in li:
            for j in range(10):
                if (i==1 or u!=0) and ((u*10+j)%i==0):
                    tempSet.add((u*10+j))
        li = tempSet
    li -={0}
    tempSet = set()
    for i in li:
        tempSet.add("\""+str(i)+"\"")
    return tempSet

for i in range(19,25):
    print(f(i))
    print(',')
