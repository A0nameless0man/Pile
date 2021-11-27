import matplotlib.pyplot as plt


def f(n):
    sum = 0
    p = 1
    for x in range(1, n + 1):
        sum += x * (x / n) * p
        p *= 1 - x / n
    return sum


def p(n):
    prob = 1
    res = []
    for x in range(1, n+1):
        res.append(prob*x/n)
        prob *= 1-x/n
    return [x for x in range(1, n+1)], res


def p_normal(n):
    prob = 1
    res = []
    for x in range(1, 20):
        res.append(prob/n)
        prob *= 1-x/n
    return [x for x in range(1, 20)], res


def main():
    x_sacle = plt.MultipleLocator(1)
    y_scale = plt.MultipleLocator(0.1)
    plt.figure(dpi=2000)
    tar = [5, 10, 15, 20]
    for n in tar:
        x, y = p(n)
        plt.plot(x, y)
    plt.ylabel('prob-prd')
    plt.xlabel("n")
    ax = plt.gca()
    ax.xaxis.set_major_locator(x_sacle)
    ax.yaxis.set_major_locator(y_scale)
    plt.xlim(1, 20)
    plt.show()

    plt.figure(dpi=2000)
    for n in tar:
        x, y = p_normal(n)
        plt.plot(x, y)
    plt.ylabel('prob-normal')
    plt.xlabel("n")
    ax = plt.gca()
    ax.xaxis.set_major_locator(x_sacle)
    ax.yaxis.set_major_locator(y_scale)
    plt.xlim(1, 20)
    plt.show()

    plt.figure(dpi=2000)
    plt.plot([f(n) for n in range(1, 41)])
    plt.ylabel("interval")
    plt.xlabel("n")
    plt.show()


if __name__ == "__main__":
    main()
