import random


def gen1(n):
    vtbs = []
    while n > 0:
        vtb = []
        while n > 0:
            beg = 0
            end = 0
            if len(vtb) == 0:
                beg = random.randint(0, 1440 - 1)
            else:
                beg = random.randint(vtb[-1][1], 1440 - 1)
            end = random.randint(beg + 1, 1800)
            vtb.append((beg, end))
            n = n - 1
            if (end >= 1440):
                break
        vtbs.append(vtb)
    return vtbs


def gen2(n):
    vtbs = [[(0, 1800)]] * n
    return vtbs

def encode(n):
    return (n // 60) * 100 + n % 60

scale = [[(10, gen1)] * 10] * 4
scale += [[(100, gen1)] * 100] * 5
scale += [[(1000, gen1)] * 10] * 3
scale += [[(1000, gen2)] * 10] * 1
scale += [[(10, gen1)] * 1000] * 3
scale += [[(10, gen2)] * 1000] * 1
scale += [[(10000, gen1)]]
scale += [[(10000, gen2)]]

for i in range(len(scale)):
    f = open("./TestData/" + str(i + 2) + ".in", mode="w+", encoding="UTF-8")
    f.write(str(len(scale[i])) + "\n")
    for case in scale[i]:
        vtbs = case[1](case[0])
        f.write(str(len(vtbs)) + '\n')
        # print("VTB"+str(len(vtbs)))
        for vtb in vtbs:
            f.write(str(len(vtb)))
            for stream in vtb:
                f.write(" " + str(encode(stream[0])).zfill(4) + " " + str(encode(stream[1])).zfill(4))
            f.write('\n')
    f.close()

