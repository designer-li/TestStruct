#include <stdio.h>
#include <stdlib.h>
void StudNew(void)
{
	nCount=0;
	while(1)
	{
		print("������ѧ��ѧ�ţ�");
		scanf("%d",&nStudNo[nCount]);
		if(nStudNo[nCount]<0)
			break;
		print("������ѧ��������");
		scanf("%*c%s",nStudName[nCount]);
        nCount++;
	}
}
main()
{
	int a[50],i;
	for(i=0;i<50;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
	return 0;
}
