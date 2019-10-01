import random
table = \
    ["あ", "い", "う", "え", "お",
    "か", "き", "く", "け", "こ",
    "さ", "し", "す", "せ", "そ",
    "た", "ち", "つ", "て", "と",
    "な", "に", "ぬ", "ね", "の",
    "ア", "イ", "ウ", "エ", "オ",
    "カ", "キ", "ク", "ケ", "コ",
    "サ", "シ", "ス", "セ", "ソ",
    "タ", "チ", "ツ", "テ", "ト",
    "ナ", "ニ", "ヌ", "ネ", "ノ"]
rom = ("a i u e o ka ki ku ke ko sa si su se so ta chi tsu te to na ni nu ne no").split()
m = {}
m2 = {}
#print(table)
#print(rom)
for i in range(len(rom)):
    m[rom[i]] = table[i]
for i in range(len(rom)):
    m2[rom[i]] = table[i + len(rom)]
count = 0
while True:
    print("Round ", count, " start!")
    count = count + 1
    wrong = 0
    miss = set()
    giveUp = set()
    random.shuffle(table)
    #print(table)
    for c in table:
        while True:
            print("Q:",c)
            i = input()
            if i in m:
                print(m[i])
                print(m2[i])
                if c == m[i] or c == m2[i]:
                    break
                else:
                    wrong = wrong + 1
                    miss.add(c)
            elif '?' in i:
                wrong = wrong + 1
                giveUp.add(c)
                break
    print(wrong, " wrong try!")
    print("miss = ",miss)
    print("giveUp = ",giveUp)
