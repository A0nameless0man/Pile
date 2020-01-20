import random as rnd

n = rnd.randint(1, 20)

G = [[rnd.randint(0,1) for i in range(n)]for j in range(n)]
m = 0

for i in G:
    for j in i:
        m=j+m

q = rnd.randint(1, 1000)



print(str(n) + " " + str(m) + " " + str(q))
for i in range(n):
    print(rnd.randint(0, 1), end=" ")
print('')


for i in range(n):
    for j in range(n):
        if (G[i][j] == 1):
            print(str(i+1) + " " + str(j+1))

for qs in range(q):
    print(str(rnd.randint(1,n))+" "+str(rnd.randint(0,100000)))