import random

T = 100
n = 10


def gen_case(n):
    res = str(n)
    res+="\n"
    # res += " ".join([str(random.randint(10**9-7, 1000000000)) for _ in range(n)])
    res += " ".join([str(random.randint(2,10**9+7)) for _ in range(n)])

    return res


if __name__ == "__main__":
    print(T)
    for _ in range(T):
        print(gen_case(n))
