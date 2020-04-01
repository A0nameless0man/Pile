import random
scale = [[(5, 10)] * 20]*5+[[(10, 20)] * 20]*15+ [[(50, 50)] * 4]*3+ [[(60, 60)]]*3+[[(100, 100)]]+[[(200,50)]]+[[(50,200)]]

for i in range(len(scale)):
    f = open("./TestData/" + str(i + 2) + ".in", mode="w+", encoding="UTF-8")
    f.write(str(len(scale[i]))+"\n")
    for case in (scale[i]):
        m = case[0]
        n = case[1]
        f.write(str(m) + " " + str(n) + "\n")
        for j in range(m):
            for k in range(n):
                f.write(str(random.randint(0, 1)))
            f.write("\n")