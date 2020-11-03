r = 10
print(r**4)
for tup in [(i,j,k,l)for i in range(r) for j in range(r) for k in range(r) for l in range(r)]:
    print(" ".join(map(str,tup)))