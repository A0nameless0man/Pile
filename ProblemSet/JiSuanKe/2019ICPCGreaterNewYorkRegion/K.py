import re

line = input().strip()
if re.match("([A-Za-z ]{1,8})-([0-9a-zA-Z- ]{1,24})",line):
    print("YES")
else:
	print("NO")
    