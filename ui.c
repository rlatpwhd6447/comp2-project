#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct
{
	char pan;
		int dol;
			int number;
			}board;

			void read(int*,int*);
			void game(void);

			main()
			{
				srand((unsigned)time(NULL));
					game();
						
						}

						void game(void)
						{
							board point[15][15];//바둑판 생성 
								int i,j;
									int sq;//순서 
										int opt_x,opt_y;//상대 수 좌표
											int opt_sq=0,com_sq=0;//각 돌들 순서 
												int com_x,com_y;//컴 수 좌표 
													int re;//다시 
														
															for(i=0;i<15;i++)
																{
																		for(j=0;j<15;j++)
																				{
																							point[i][j].pan='*';
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
																																																																															printf("y:");
																																																																																			scanf("%d",&opt_y);
																																																																																							
																																																																																											if(point[opt_x][opt_y].pan=='*'&&opt_x<15&&opt_y<15)
																																																																																															{
																																																																																																				point[opt_x][opt_y].pan='X';
																																																																																																									point[opt_x][opt_y].dol=0;
																																																																																																														point[opt_x][opt_y].number=opt_sq;
																																																																																																																			opt_sq++; 
																																																																																																																								break;
																																																																																																																												}
																																																																																																																															}
																																																																																																																																	}
																																																																																																																																			
																																																																																																																																					else if(sq==1)//프로그램 부터 시작 
																																																																																																																																							{
																																																																																																																																										while(1)
																																																																																																																																													{
																																																																																																																																																	printf("컴\n");
																																																																																																																																																					printf("x:");
																																																																																																																																																									scanf("%d",&com_x);
																																																																																																																																																													printf("y:");
																																																																																																																																																																	scanf("%d",&com_y);
																																																																																																																																																																					
																																																																																																																																																																									if(point[com_x][com_y].pan=='*'&&com_x<15&&com_y<15)
																																																																																																																																																																													{
																																																																																																																																																																																		printf("com\n");
																																																																																																																																																																																							point[com_x][com_y].pan='O';
																																																																																																																																																																																												point[com_x][com_y].dol=0;
																																																																																																																																																																																																	point[com_x][com_y].number=com_sq;
																																																																																																																																																																																																						com_sq++; 
																																																																																																																																																																																																											break;
																																																																																																																																																																																																															}
																																																																																																																																																																																																																		}
																																																																																																																																																																																																																				}
																																																																																																																																																																																																																						
																																																																																																																																																																																																																								system("cls");
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
																																																																																																																																																																																																																																																																																					}
																																																																																																																																																																																																																																																																																					}
