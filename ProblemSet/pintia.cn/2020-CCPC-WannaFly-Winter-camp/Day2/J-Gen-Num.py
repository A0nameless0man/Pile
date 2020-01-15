import random

charset = "a b c d e f g h i j k".split(' ')
l = 100000

print(' '+str(l**2),end=' ')
for j in range(l**2):
    print(str(j // l + 1) + " " + str(j % l + 1), end=' ')
print('')