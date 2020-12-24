#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x,i,*a=NULL;
    printf("请输入数组长度：");
    scanf("%d",&x);
    a=(int*)malloc(x*sizeof (int));
    printf("请输入：");
    for(i=0;i<x;i++)
    {
        scanf("%d",a+i);
        a[i]*=2;
        a[i]%=3;
        a[i]+=4;
        if (i==0)
            printf("经过一系列运算之后的结果：");
        printf("%d ",*(a+i));
    }
    return 0;
}
