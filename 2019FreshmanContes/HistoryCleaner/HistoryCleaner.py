import json
# import urllib

def DealOldShit(str):
    print(str)
    return str

def latex(str):
    str.replace('>='," \geq ")
    str.replace('<='," \leq ")
    str = '$'+ str+'$'
    return str

def main():
    # inPutFile = open("./Data/problems.json","r",encoding = "UTF-8")
    # inPutData = inPutFile.read()
    # decodedData = json.loads(inPutData)
    # for p in decodedData:
    #     p["content"] = DealOldShit(p["content"])
    inputFile = open("./temp.txt",'r',encoding = "UTF-8")
    inputStr = inputFile.read()
    inputStr = latex(inputStr)
    inputFile.close()
    inputFile = open("./temp.txt",'w',encoding = "UTF-8")
    inputFile.write(inputStr)
    return 


if __name__ == "__main__":
    main()