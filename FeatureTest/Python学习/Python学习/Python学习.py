#n = int(input("Imbput the N:"))
#sum =0
#for i in range(1,n+1):
#    #print(i)
#    sum+=n//i
#print(sum)//所有小于n的整数有多少因数

#for i in range(1,10):
#    for j in range(1,i+1):
#        print((str(i)+'X'+str(j)+'='+str(i*j)).ljust(10),end='')
#    print('\n')#九九乘法表

#for i in range(200):
#    for j in range(10):
#        print((str(i)+'^'+str(j)+'='+str(i**j)).ljust(15),end='')
#    print('\n')

#import os
#outfile = open("out.txt",'w')
#for i in range(200):
#    for j in range(100):
#        outfile.write((str(i)+'^'+str(j)+'='+str(i**j)).ljust(15))
#        outfile.write(" ")
#    outfile.write('\n')

#from tkinter import *
#from math import *
#import time
#clickTime=0
#def changeColor():
#    global clickTime
#    #for x in range(20):
#    # btnCaculate.grid(padx=75+30*sin(x*3.14),pady=45+30*cos(x*3.14))
#    # #time.sleep(0.1)
#    clickTime+=1
#    btnCaculate.grid(padx=75+30*sin(clickTime),pady=45+30*cos(clickTime))
#    if btnCaculate["bg"]=="midnight blue":
#        btnCaculate["bg"]="pink"
#        btnCaculate["fg"]="gray"
#    else:
#        btnCaculate["bg"]="midnight blue"
#        btnCaculate["fg"]="dark gray"
#mainWindow = Tk()
#mainWindow.title("MAIN_TEST")
#btnCaculate=Button(mainWindow,text="Caculate")
#btnCaculate["bg"]="light blue"
#btnCaculate["command"]=changeColor
#btnCaculate.grid(padx=75,pady=15)
#mainWindow.mainloop()

import os
file = open("testin.txt",mode = "r")
fileout = open("out.txt",'w')
FailCount = 0
f = float("+1.5")
fileout.write('{')
#for line in file:
#    print(line)
#    line=line.split()
#    line=line[0]
#    fileout.write("\"");
#    fileout.write(line)
#    fileout.write("\",");
#fileout.write("};\n{")
#file.close()
#file = open("testin.txt",mode = "r")
for line in file:
    line=line.split()
    line=line[-2]
    fileout.write(str(int(60*eval("0"+line[3:]))))
    fileout.write(",");
fileout.write("};")
#print(FailCount)
#import random
#import os
#filetest = open("testin.txt","w")
#fileans = open("testout.txt","w")
#for i in range(20):
#    out = ""
#    k = random.randint(1,5)
#    k=k*2+1
#    for j in range(k):
#        if j%2==0:
#            out+=str(random.randint(0,50))
#        else:
#            if random.randint(0,1)==0:
#                out+="+"
#            else:
#                out+="-"
#    print(out)
#    filetest.write(out+"\n")
#    fileans.write(str(eval(out))+"\n")
#fileans.close()
#filetest.close()
