#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct
{
	int mxrange_x[20];//x좌표 최대범위 
	int mnrange_x[20];//x좌표 최소범위 
	
	int mxrange_y[20];//y좌표 최대범위 
	int mnrange_y[20];//y좌표 최소범위 
}chromosome;//개체 

void create_population(int *x,int *y);//개체들에게 범위를 집어 넣는다. 

main()
{
	srand((unsigned)time(NULL));
	chromosome crms[100];//각각의 개체 
	int i,j;
	int sum_x,sum_y;//20개의 범위에서 뽑은 수들의 합 
	int randnum_x[20],randnum_y[20];//20개의 범위에서 뽑은 수 
	int x,y;//한 수 
	
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
		printf("유전자%d\n",i);
		for(j=0;j<20;j++)
		{
			printf("%d~%d  ",crms[i].mnrange[j],crms[i].mxrange[j]);
		}
		printf("\n----------\n");
	}확인용*/
	
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
