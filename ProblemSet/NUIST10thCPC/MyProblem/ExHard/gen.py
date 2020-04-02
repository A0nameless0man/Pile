import random

rand = lambda i, j: random.randint(0, 1)


def hack1(i, j):
    if i > j:
        return i % 2
    else:
        return j % 2

def hack2(i, j):
    return (i + j) % 2

def hack3(i, j):
    return 0

def hack4(i, j):
    return 1

scale = [[(5, 10, rand)] * 20] * 2
scale += [[(10, 20, rand)] * 20] * 15
scale += [[(50, 50, rand)] * 4] * 3
scale += [[(60, 60, rand)]] * 1
scale += [[(500, 500, rand)]]*2
scale += [[(500, 500, hack1)]]
scale += [[(500, 500, hack2)]]
scale += [[(500, 500, hack3)]]
scale += [[(500, 500, hack4)]]
scale += [[(1000, 250, rand)]]
scale += [[(250, 1000, rand)]]

for i in range(len(scale)):
    f = open("./TestData/" + str(i + 2) + ".in", mode="w+", encoding="UTF-8")
    f.write(str(len(scale[i])) + "\n")
    for case in scale[i]:
        m = case[0]
        n = case[1]
        f.write(str(m) + " " + str(n) + "\n")
        for j in range(m):
            for k in range(n):
                f.write(str(case[2](j,k)))
            f.write("\n")
