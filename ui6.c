#include<stdio.h>
#include<stdlib.h>
#include<time.h>


typedef struct
{
	char pan;
	int dol;
	int number;
}board;//오목판 

typedef struct
{
	int mxrange_x[20];//x좌표 최대범위 
	int mnrange_x[20];//x좌표 최소범위 
	
	int mxrange_y[20];//y좌표 최대범위 
	int mnrange_y[20];//y좌표 최소범위 
	int score;
}chromosome;//개체 

void create_population(int *x,int *y);//염색체 생성 
int output(int*,int*,int);//좌표 출력 
void omok();//오목 수를 뽑아냄 
int read(int*,int*);
void game(void);//오목 하는거 보는거 
void cross(void);//교배 
void menu(void);
int av(int);//절댓값 

chromosome crms[100];//각각의 개체
board point[15][15];//바둑판 생성

main()
{
	srand((unsigned)time(NULL));
	omok();
	menu();

}

void menu(void)
{
	int ii;
	printf("어디로 가시겠습니까?\n");
	printf("오목게임(1),교배(2)\n:");
	scanf("%d",&ii);
	
	if(ii==1)
	{
		game();
	}
	
	else if(ii==2)
	{
		cross();	
	}
}
void game(void)
{ 
	int i,j;
	int sq;//순서 
	int sq_number=0;//순서 
	int opt_x=NULL,opt_y=NULL;//상대 수 좌표
	int opt_sq=0,com_sq=0;//각 돌들 순서 
	int com_x,com_y;//컴 수 좌표 
	int delta_x,delta_y;//증분 
	int re;//다시 
	int number;//싸우는 컴번호 
	int back;//백스텝 
	
	number=rand()%100;
	
	for(i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			point[i][j].pan='-';
		}
	}
	for(i=0;i<15;i++)
	{
		printf("  %2d",i);
	}
	printf("\n");
	for(i=0;i<15;i++)
	{
		printf("%2d ",i);
		for(j=0;j<15;j++)
		{
			printf("%c   ",point[i][j].pan);
		}
		printf("\n\n");
	}
	
	sq=rand()%((1-0)+1)+0;
	
	while(1)
	{
		if(sq==0)//상대 먼저시작 
		{
			while(1)
			{
				printf("상대\n");
				printf("x:");
				scanf("%d",&opt_x);
				
				if(opt_x==100)
				{
					menu();
				}
				
				printf("y:");
				scanf("%d",&opt_y);
				
				if(point[opt_y][opt_x].pan=='-'&&opt_x<15&&opt_y<15)
				{
					point[opt_y][opt_x].pan='@';
					point[opt_y][opt_x].dol=0;
					point[opt_y][opt_x].number=opt_sq;
					opt_sq++; 
					break;
				}
			}
		}
		
		else if(sq==1)//프로그램 부터 시작 
		{
			while(1)
			{
				if(opt_x==NULL)
				{
					opt_x=7;
					opt_y=7;
				}
				output(&delta_x,&delta_y,number);
				
				read(&delta_x,&opt_x);
				read(&delta_y,&opt_y);
				
				com_x=read(&delta_x,&opt_x);
				com_y=read(&delta_y,&opt_y);
				
				if(point[com_y][com_x].pan=='-')
				{
					printf("-------------4-----------\n");
					point[com_y][com_x].pan='O';
					point[com_y][com_x].dol=0;
					point[com_y][com_x].number=com_sq;
					com_sq++; 
					break;
				}
				
			}
		}
		
		//system("cls");
		for(i=0;i<15;i++)
		{
			printf("  %2d",i);
		}
		
		printf("\n");
		for(i=0;i<15;i++)
		{
			printf("%2d ",i);
			for(j=0;j<15;j++)
			{
				printf("%c   ",point[i][j].pan);
			}
			printf("\n\n");
		}
		
		if(sq==0)
		{
			sq=1;	
		} 
		
		else if(sq==1)
		{
			sq=0;
		}
		sq_number++;
	}
}

void omok()
{
	int i,j;
	
	for(i=0;i<100;i++)
	{
		crms[i].score=0;
	}
	
	for(i=0;i<100;i++)
	{	
		for(j=0;j<20;j++)
		{
			create_population(&crms[i].mxrange_x[j],&crms[i].mnrange_x[j]);
			create_population(&crms[i].mxrange_y[j],&crms[i].mnrange_y[j]);
		}
		//printf("적합도(%d) : %d\n",i,crms[i].score);
	}
	
	for(i=0;i<10;i++)
	{
		printf("유전자%d\n",i);
		for(j=0;j<20;j++)
		{
			printf("x:%d~%d  ",crms[i].mnrange_x[j],crms[i].mxrange_x[j]);
			printf("y:%d~%d  ",crms[i].mnrange_y[j],crms[i].mxrange_y[j]);
		}
		printf("\n----------\n");
	}	
} 

int output(int *x,int *y,int num)
{
	int i,j;
	int sum_x,sum_y;//20개의 범위에서 뽑은 수들의 합 
	int randnum_x[20],randnum_y[20];//20개의 범위에서 뽑은 수 
	//sum_x=0;
	//sum_y=0;
	 
	for(i=0;i<20;i++)
	{
		randnum_x[i]=rand()%((crms[num].mxrange_x[i]-crms[num].mnrange_x[i])+1)+crms[num].mnrange_x[i];
		printf("x=%d\n",randnum_x[i]);
		//sum_x=sum_x+randnum_x[i];
		
		randnum_y[i]=rand()%((crms[num].mxrange_y[i]-crms[num].mnrange_y[i])+1)+crms[num].mnrange_y[i];
		printf("y=%d\n\n",randnum_y[i]);
		//sum_y=sum_y+randnum_y[i];
	}
	i=rand()%19;
	printf("i=%d\nrandnum_x[%d]=%d\n",i,i,randnum_x[i]);
	*x=randnum_x[i];
	
	j=rand()%19;
	printf("j=%d\nrandnum_y[%d]=%d\n",j,j,randnum_y[j]);
	*y=randnum_y[j];
	
	return num;	
}

void create_population(int *x,int *y)
{
	int i;
	
	while(1)
	{
		*x=rand()%((15-(-15))+1)+(-15);
		*y=rand()%((15-(-15))+1)+(-15);
		
		if(*x>0&&*y<0)
		{
			break;
		}
	}	
}

int read(int *delta,int *opt)
{
	 int sum;
	 int com;
	 int gap;
	 
	 sum=*delta+*opt;
	 
	 if(sum>14)
	 {
	 	gap=sum-14;
	 	com=14-gap;
	 }
	 
	 else if(sum<0)
	 {
	 	com=sum*(-1);
	 }
	 
	 else if(sum>0&&sum<15)
	 {
	 	com=sum;
	 }
	 return com;
}

void cross(void)
{
	chromosome tmp[100],tmp2[50];//옮길거
	chromosome parent[25];//
	
	int a,num; 			  	
	int i,j,k,m,n;
	int randnum;
	int rd;
	printf("반복횟수:");
	scanf("%d",&num);
	printf("--------1------\n");
	
	for(a=0;a<num;a++)
	{
		for(i=0;i<100;i++)
		{
			crms[i].score=0;
		}
		
		for(i=0;i<100;i++)
		{
			tmp[i]=crms[i];	
		}
		
		for(i=0;i<100;i++)
		{
			for(j=0;j<20;j++)
			{
				tmp[i].score=tmp[i].score+av(tmp[i].mxrange_x[j])-1;
				tmp[i].score=tmp[i].score+av(tmp[i].mnrange_x[j])-1;
				tmp[i].score=tmp[i].score+av(tmp[i].mxrange_y[j])-1;
				tmp[i].score=tmp[i].score+av(tmp[i].mnrange_y[j])-1;
			}
		}
		
		j=0;	
		for(i=0;i<100;i=i+2)
		{
			if(tmp[i].score>=tmp[i+1].score)
			{
				tmp2[j]=tmp[i];	
			}
			
			else if(tmp[i].score<tmp[i+1].score)
			{
				tmp2[j]=tmp[i+1];	
			}
			j++;		
		}
		
		j=0;
		for(i=0;i<50;i=i+2)
		{
			if(tmp2[i].score>=tmp2[i+1].score)
			{
				parent[j]=tmp2[i];	
			}
			
			else if(tmp2[i].score<tmp2[i+1].score)
			{
				parent[j]=tmp2[i];
			}
			j++;
		}
		j=0;
		for(k=0;k<10;k++)
		{
			for(i=0;i<20;i=i+2)
			{
				for(m=0;m<20;m++)
				{				
					crms[j].mxrange_x[m]=rand()%((parent[i+1].mxrange_x[m]-1)+1)+1;
					crms[j].mnrange_x[m]=rand()%(((-1)-parent[i].mnrange_x[m])+1)+parent[i].mnrange_x[m];
					crms[j].mxrange_y[m]=rand()%((parent[i].mxrange_y[m]-1)+1)+1;
					crms[j].mnrange_y[m]=rand()%(((-1)-parent[i+1].mnrange_y[m])+1)+parent[i+1].mnrange_y[m];
				}
				j++;
			}
		}
	}
	for(i=0;i<10;i++)
	{
		printf("유전자%d\n",i);
		for(j=0;j<20;j++)
		{
			printf("x:%d~%d  ",crms[i].mnrange_x[j],crms[i].mxrange_x[j]);
			printf("y:%d~%d  ",crms[i].mnrange_y[j],crms[i].mxrange_y[j]);
		}
		printf("\n----------\n");
	}	
	menu();
}

int av(int x)
{
	if(x<0)
	{
		x=x*(-1);	
	}
	
	return x; 
} 
