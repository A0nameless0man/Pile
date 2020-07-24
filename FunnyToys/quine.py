s = "s = %c%s%c%cprint(s%c(chr(34),s,chr(34),chr(10),chr(37)))"
print(s % (chr(34), s, chr(34), chr(10), chr(37)))

