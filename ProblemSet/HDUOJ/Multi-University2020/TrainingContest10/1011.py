def p(m, t, k):
    _m = m - t
    ans = 1.0
    for i in range(k + 1):
        ans *= 1 + 1 / (_m - i)
    return ans



def E(m, t, k):
    pp = p(m, t, k)
    np = 1 - p
    