
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
    fileout.write(str(int(60*float(line[3:]+"0")+0.5)))
    fileout.write(",");
fileout.write("};")