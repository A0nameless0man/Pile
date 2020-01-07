#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const int MAX_N = 300007;
struct list
{
    int Rec;
    int next;
};
int  TotalRec, n, uj, ui;
list Record[2 * MAX_N];
int  BanksList[MAX_N];
int  BankStren[MAX_N];
void addRec(int Banka, int Bankb)
{
    if(BanksList[Banka] == -1)
    {
        BanksList[Banka]             = TotalRec++;
        Record[BanksList[Banka]].Rec = Bankb;
    }
    else
    {
        int tag = BanksList[Banka];
        while(Record[tag].next != -1)
        {
            tag = Record[tag].next;
        }
        Record[tag].next     = TotalRec;
        Record[TotalRec].Rec = Bankb;
        TotalRec++;
    }
}
int main(void)
{
    while(scanf("%d", &n) != EOF)
    {
        TotalRec = 0;
        for(size_t i = 0; i < n; i++)
        {
            scanf("%d", &BankStren[i]);
            BanksList[i]   = -1;
            Record[i].next = Record[i + n].next = -1;
        }
        for(size_t i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &uj, &ui);
            addRec(ui, uj);
            addRec(uj, ui);
        }
    }
}