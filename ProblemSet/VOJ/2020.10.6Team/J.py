from functools import reduce


def cap(sets):
    return reduce(lambda x, y: x.intersection(y), sets)


def capl(sets):
    return len(cap(sets))


def mul(sets):
    return reduce(lambda x, y: x * y, [len(s) for s in sets])


# S = [set([i for i in range(1,16) if (i & (2**j))!= 0])for j in range(4)]

S = [{1, 2, 3, 4, 5}, {3, 4, 5, 6, 7, 8}, {3, 4, 7, 8, 9, 10, 11}, {8, 9, 12, 13}]
print(S)

print(mul(S))

for i in range(len(S)):
    print(capl([S[g] for g in range(len(S)) if not g in [i]]) * mul([S[i]]))

for i in range(len(S)):
    for j in range(i + 1, len(S)):
        print(
            capl([S[g] for g in range(len(S)) if not g in [i, j]]) * mul([S[i], S[j]])
        )

