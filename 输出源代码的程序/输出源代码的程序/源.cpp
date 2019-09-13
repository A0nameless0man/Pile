#include<stdio.h>
const char *s = "#include<stdio.h>%cconst char s*=%c%s%c%c%cint main(void){printf(s,10,34,s,34,59,10);}";
int main(void){printf(s,10,34,s,34,59,10);}