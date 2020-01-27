import random

charset = "a b c d e f g h i j k".split(' ')
l = 10000
len = 100000
print(' '+str(l),end=' ')
for j in range(l):
    print(str(random.randint(1,len)) + " " + str(random.randint(1,len)), end=' ')
print('')