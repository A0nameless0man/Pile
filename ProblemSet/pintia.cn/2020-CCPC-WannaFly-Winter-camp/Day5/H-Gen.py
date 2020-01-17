import random

n = 100000
Q = 100000
uplimit = 2**30
print(str(n) + " " + str(Q))
for i in range(n):
    print(str(random.randint(0, uplimit)), end=" ")
print('\n')
for i in range(Q):
    print(str(random.randint(0, uplimit)) + " " + str(random.randint(0, uplimit)) + " " + str(random.randint(0, uplimit)))

