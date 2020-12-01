#include<stdio.h>
#include <stdlib.h>
char big(int x,int m);
char small(int y,int n);

int main(void)
{
    int i=0;
    char a;
    float key=0;
    char b[800];
    while(key<=0||key==getchar()||key!=(int) key)
    {
        printf("input a key(a number):");
        fflush(stdin);
        scanf("%f",&key);
    }
    if(key>26)
        key=(int)key%26;
    printf("plaintext(origin text):");
    while(1)
    {
        scanf("%c",&a);
        if (a>=65&&a<=90)
            b[i]=big(a,(int) key);
        else if (a>=97&&a<=122)
            b[i]=small(a,(int) key);
        else if(a==10)
            break;
        else
            b[i]=a;
        i++;
    }
    printf("ciphertext(after transform):%s\n",b);
    system("pause");
    return 0;
}

char big(int x,int m)
{
    if (x+m>90)
        return x+m-26;
    else
        return x+m;
}

char small(int y,int n)
{
    if (y+n>122)
        return y+n-26;
    else
        return y+n;
}
