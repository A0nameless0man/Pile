import random


def gen1(n):
    vtbs = []
    while n > 0:
        vtb = []
        while n > 0:
            beg = 0
            end = 0
            if len(vtb) == 0:
                beg = random.randint(0, 43200 - 1)
            else:
                beg = random.randint(decode(vtb[-1][1]), 43199)
            end = random.randint(beg + 1, 43200 + 60 * 6)
            if end % 1440 - beg % 1440 == 1 and end % 1440 <= 360:
                end = (end // 1440 - 1) * 10000 + encode(end % 1440 + 1440)
            else:
                end = (end // 1440) * 10000 + encode(end % 1440)
            beg = (beg // 1440) * 10000 + encode(beg % 1440)
            vtb.append((beg, end))
            n = n - 1
            if decode(end) >= 43200:
                break
        vtbs.append(vtb)
    return vtbs


def gen2(n):
    vtbs = [[(0, 302400)]] * n
    return vtbs


def encode(n):
    return (n // 60) * 100 + n % 60


def decode(i):
    return (i // 10000) * 1440 + 60 * (i % 10000 // 100) + i % 60


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
        f.write(str(len(vtbs)) + "\n")
        # print("VTB"+str(len(vtbs)))
        for vtb in vtbs:
            f.write(str(len(vtb)))
            for stream in vtb:
                f.write(
                    " " + str((stream[0])).zfill(6) + " " + str((stream[1])).zfill(6)
                )
            f.write("\n")
    f.close()
