import random

charset = "a b c d e f g h i j k".split(' ')
l = 100000

for j in range(l):
    print(charset[random.randint(0, len(charset) - 1)], end='')