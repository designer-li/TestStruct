#include <stdio.h>
#include <stdlib.h>
void StudNew(void)
{
	nCount=0;
	while(1)
	{
		print("请输入学生学号：");
		scanf("%d",&nStudNo[nCount]);
		if(nStudNo[nCount]<0)
			break;
		print("请输入学生姓名：");
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
