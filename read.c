#include<stdio.h>

typedef struct
{
	char pan;//수 보여주는거 
	int dnum;//식별번호 
}board;//오목판 

board point[15][15];

void read(int,int);

main()
{
	int x,y,j,i;
	
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
	
	printf("가로\n");
	for(y=0;y<15;y++)
	{
		for(x=0;x<15;x++)
		{
			read(x,y);
			//printf("(%d,%d)",x,y);
		}
		printf("\n");
	}
	printf("\n\n");
	
	printf("세로\n");
		for(x=0;x<15;x++)
	{
		for(y=0;y<15;y++)
		{
			printf("(%d,%d)",x,y);
		}
		printf("\n");
	}
	printf("\n\n");
	
	printf("대각선 위 오른쪽\n");
	j=0;
	y=0;
	
	while(1)
	{
		x=0;
		y=j;
		
		while(1)
		{
			printf("(%d,%d)",x,y);
			
			if(x==15&&y==0)
			{
				break;
			}
			x++;
			
			
			if(y==0)
			{
				break;
			}
			y--;	
		}
		
		if(x==15&&y==0)
		{
			break;
		}
		
		j++;
		printf("\n");
	}
	
	printf("\n");
	j=1;
	while(1)
	{
		y=14;
		x=j;
		
		while(1)
		{
			printf("(%d,%d)",x,y);
			
			if(x==14&&y==14)
			{
				break;
			}
			x++;
			
			
			if(x==15)
			{
				break;
			}
			y--;	
		}
		
		if(x==14&&y==14)
		{
			break;
		}
		
		j++;
		printf("\n");
	}
	printf("\n\n");
	
	printf("대각선 아래 오른쪽\n");
	
	j=14;
	while(1)
	{
		y=j;
		x=0;
		
		while(1)
		{
			printf("(%d,%d)",x,y);
			
			if(x==15)
			{
				break;
			}
			x++;
			
			
			if(y==14)
			{
				break;
			}
			y++;	
		}
		
		if(x==15)
		{
			break;
		}
		
		j--;
		printf("\n");
	}
	printf("\n");
	
		j=1;
	while(1)
	{
		x=j;
		y=0;
		
		while(1)
		{
			printf("(%d,%d)",x,y);
			
			if(x==14&&y==0)
			{
				break;
			}
			
			
			
			if(x==14)
			{
				break;
			}
			x++;
			y++;	
		}
		
		if(x==14&&y==0)
		{
			break;
		}
		
		j++;
		printf("\n");
	}
			
}

void read(int x,int y)
{
	
}
