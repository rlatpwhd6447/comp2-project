#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct
{
	int mxrange_x[20];//x��ǥ �ִ���� 
	int mnrange_x[20];//x��ǥ �ּҹ��� 
	
	int mxrange_y[20];//y��ǥ �ִ���� 
	int mnrange_y[20];//y��ǥ �ּҹ��� 
}chromosome;//��ü 

void create_population(int *x,int *y);//��ü�鿡�� ������ ���� �ִ´�. 

main()
{
	srand((unsigned)time(NULL));
	chromosome crms[100];//������ ��ü 
	int i,j;
	int sum_x,sum_y;//20���� �������� ���� ������ �� 
	int randnum_x[20],randnum_y[20];//20���� �������� ���� �� 
	int x,y;//�� �� 
	
	for(i=0;i<100;i++)
	{
		for(j=0;j<20;j++)
		{
			create_population(&crms[i].mxrange_x[j],&crms[i].mnrange_x[j]);
			create_population(&crms[i].mxrange_y[j],&crms[i].mnrange_y[j]);
		}
	}
	
	/*for(i=0;i<100;i++)
	{
		printf("������%d\n",i);
		for(j=0;j<20;j++)
		{
			printf("%d~%d  ",crms[i].mnrange[j],crms[i].mxrange[j]);
		}
		printf("\n----------\n");
	}Ȯ�ο�*/
	
	//
	sum_x=0;
	sum_y=0;
	for(i=0;i<20;i++)
	{
		randnum_x[i]=rand()%((crms[0].mxrange_x[i]-crms[0].mnrange_x[i])+1)+crms[0].mnrange_x[i];
		sum_x=sum_x+randnum_x[i];
		
		randnum_y[i]=rand()%((crms[0].mxrange_y[i]-crms[0].mnrange_y[i])+1)+crms[0].mnrange_y[i];
		sum_y=sum_y+randnum_y[i];
	}
	x=sum_x/20;
	y=sum_y/20;
	printf("(%d,%d)\n",x,y);
	//
}

void create_population(int *x,int *y)
{
	int i;
	srand((unsigned)time(NULL));
	
	while(1)
	{
		*x=rand()%((15-0)+1)+0;
		*y=rand()%((15-0)+1)+0;
		
		if(*x-*y>0)
		{
			break;
		}
	}	
}
