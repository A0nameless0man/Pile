import random
MAX_N = 12
MAX_M = 10
TEST_CASE_NUM = 1000

#leaglChar = ['w']*1+['.']*5+['g']*3
leaglChar = ['w']*0+['.']*0+['g']*3

def generateOneCase(m,n):
    res = str(m) + ' ' + str(n) + '\n'
    sx  = random.randint(1,m-2)
    sy = random.randint(1,n-2)
    tx = sx
    ty = sy
    while tx==sx and ty ==sy:
        tx  = random.randint(1,m-2)
        ty = random.randint(1,n-2)
    sx = 1
    sy = 1
    tx = 8
    ty = 2
    for i in range(m):
        for j in range(n):
            if i == 0 or j == 0 or i == m - 1 or j == n - 1:
                res += 'w'
            else:
                if i == sx and j == sy or i == tx and j == ty:
                    if i == sx and j == sy:
                        res += 'p'
                    else:
                        res += 'e'
                else:
                    #res += random.sample(leaglChar,1)[0]
                    if (i%4==0)and (((i+4)%8==0 and j<MAX_N-2)or((i)%8==0)and j>1):
                        res+="w"
                    else:
                        if (i+2)%4==0:
                            res+='.'
                        else:
                            if i%4==0 or ((i+3)%8==0 or (i+5)%8==0)and (j%4!=0)or((i+1)%8==0 or (i+7)%8==0)and ((j+2)%4!=0 or j==2):
                                res+='g'
                            else:
                                res+='w'

        res+='\n'
    return res

print(TEST_CASE_NUM)
for testCaseCount in range(TEST_CASE_NUM):
    print(generateOneCase(MAX_M,MAX_N))

