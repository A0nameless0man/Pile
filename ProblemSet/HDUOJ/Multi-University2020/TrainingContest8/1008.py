s = input()
x = 0
y = 0
dir = [(-1, 1), (0, 1), (1, 0), (1, -1), (0, -1), (-1, 0)]

points = [(0, 0)]

for c in s:
    if c == "1":
        x += -1
        y += 1
    elif c == "2":
        y += 1
    elif c == "3":
        x += 1
    elif c == "4":
        x += 1
        y += -1
    elif c == "5":
        y += -1
    else:
        x += -1
    points.append((x + 0.5 * y, 0.9 * y))

l = len(points)

for i in range(l):
    for j in range(i):
        p = points[i]
        p2=points[j]
        if (abs(p[0] - p2[0]) < 0.1 and abs(p[1] - p2[1]) < 0.1):
            print(i)
            print(j)
            print("Err")

print(points)