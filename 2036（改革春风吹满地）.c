/*没有AC
   辣鸡判定程序，劳资明明是对的
   功能：若干个直角系坐标计算围成图形的面积
   先输入边数，再分别输入顶点坐标，用空格隔开*/
#include<stdio.h>
#include<math.h>

double Mianji(int a1,int a2,int b1,int b2,int c1,int c2);

int main(void)
{
    int n,a[100][2],i,j;
    double s,sum=0;
    scanf("%d",&n);
    while (n!=0)
    {
        for (i=0;i<n;i++)
        {
            scanf("%d %d",&a[i][0],&a[i][1]);
        }
        for (j=1;j<n-1;j++)
        {
            s=Mianji(a[0][0],a[0][1],a[j][0],a[j][1],a[j+1][0],a[j+1][1]);
            sum+=s;
        }
        printf("%.1lf\n",sum);
        sum=0;
        scanf("%d",&n);
    }
    return 0;
}

double Mianji(int a1,int a2,int b1,int b2,int c1,int c2)
{
    double p,S,l1,l2,l3;
    l1=sqrt((double) (a1-b1)*(a1-b1)+(a2-b2)*(a2-b2));
    l2=sqrt((double) (b1-c1)*(b1-c1)+(b2-c2)*(b2-c2));
    l3=sqrt((double) (c1-a1)*(c1-a1)+(c2-a2)*(c2-a2));
    p=(l1+l2+l3)/2;
    S=sqrt(p*(p-l1)*(p-l2)*(p-l3));
    return S;
}
