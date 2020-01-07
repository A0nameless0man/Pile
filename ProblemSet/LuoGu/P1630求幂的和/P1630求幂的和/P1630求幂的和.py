NumberOfInput = int(input())
for i in range(NumberOfInput):
    InputGet=str(input()).split()
    a=int(InputGet[0])
    b=int(InputGet[1])
    sum=0;
    for j in range(1,a+1):
        sum+=j**b
    print(sum%10000)
    #print((a**b+(b-1)*a)/b)#failed