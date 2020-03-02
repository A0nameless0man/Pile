raw = input()
raw = raw.split()
a = int(raw[0])
b = int(raw[1])
k = int(raw[2])
c = int(raw[3])
MOD = 1000000007
if (k == 0):
    print("0")
elif (a == b and b == c):
    print(str(k))
elif (a != b and (a == c or b == c)):
    print(str(((2 ** (k - 1)) * k) % MOD))
else:
    print("0")