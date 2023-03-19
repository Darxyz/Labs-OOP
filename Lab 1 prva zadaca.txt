За програмски јазик да се употреби C.

Да се напише програма во која од стандарден влез се внесува бројот N (бројот на трансакции), а потоа N трансакциски сметки и како резултат ги печати идентификацискиот број и вкупната сума (со провизија) на сите трансакции платени со кредитна картичка. Во случај да нема трансакција платена со кредитна картичка да се испечати "No credit card transaction".

Во структурата Трансакција (Transaction) треба да се чуваат следните информации:
- Идентификациски број (int)
- Платена сума (int)
- Провизија (int)
- Дали е платено со дебитна или кредитна картичка (0 - дебитна, 1 - кредитна)


Ограничување: 0 < N < 100

Структура на влезните податоци:
N
id1 sum1 commission1 type1
...
idn sumn Commissionn typen

#include <stdio.h>
//Prvo definirame struktura potrebna za cuvanje na transakciite od lugjeto
typedef struct Transakcija
{
    int identifikaciskiBroj;
    int platenaSuma;
    int provizija;
    int nacin;
}transakcija;

int main() {
    int n;//potoa se vnesuvaat N broj na transakcii spored baranjeto od zadacata
    scanf("%d", &n);
    int id,platenaSuma,provizija;//deklarirame promenlivi sto ke gi dodelime na soodvetnite transakcii vo strukturata
    int nacin;
    transakcija transakcii[100];//kreirame soodvetna niza od transakcii sto ke gi cuva potrebnite podatoci sto se barani od zadacata
    for(int i=0;i<n;i++)
    {//pravime ciklus sto ke gi skenira i memorira soodvetnite podatoci vo nizata
        scanf("%d%d%d%d",&id,&platenaSuma,&provizija,&nacin);
        transakcii[i].identifikaciskiBroj=id;
        transakcii[i].platenaSuma=platenaSuma;
        transakcii[i].provizija=provizija;
        transakcii[i].nacin=nacin;
    }
    int flag = 0;//pravime znamence sto ke testira dali site platile so kreditna kartica, ako ne platil nikoj so kreditna kartica, znameto ostanuva na vrednost 0
for(int i=0;i<n;i++)
{
    if(transakcii[i].nacin==1)
        {
            int vkupno= transakcii[i].provizija + transakcii[i].platenaSuma;
            printf("%d %d\n",transakcii[i].identifikaciskiBroj,vkupno);
            flag = 1;//ako site platile so kreditna kartica, znameto se menuva vo vrednost 1, i moze da pecatime soodvetni vrednosti za transakciite
        }
}
if(flag==0)//ako znameto ostanalo nepromeneto, togas site platile so debitna kartica
    printf("No credit card transaction");
    return 0;
}



