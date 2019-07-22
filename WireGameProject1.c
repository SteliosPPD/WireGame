#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


/* 
	
	Stelios Papadopoulos
	AM : 2024201200082
	tst12082@uop.gr	
*/		



//SINARTISEIS

int** create_tablo(int n, int m);

void print(int** marr, int n, int m);
void fill_obst(int** marr, int n , int m, int diff);
int** chips(int** marr, int n , int m, int chip, int piste,int diff);
void move(int** marr,int** mobst, int n , int m, int piste,int diff, int chip);

//GLOBAL METABLITES

int score=0;

//MAIN

int main()
{
	//metablites main
	int m, piste,i,j;
	int n, diff, chip=49;
	int epilogh;
	int **marr=NULL, **mobst=NULL;

	
	//	Menu
	
	do{
		printf("Welcome to ~Wired~\n");
		printf("~~~~~~~Menu~~~~~~~\n\n");
		printf("1. Play\n\n");
		printf("2. Exit\n\n");
		scanf("%d", &epilogh);
		printf("\n");
	}while (epilogh != 2 && epilogh !=1);	
	
	if (epilogh == 1){
		do{
		printf("Give me the dimentions of the board\n\n***Rows must be between 6 and 20! Colummns from 2 to 9***\n\n");
		scanf("%d%d",&n,&m);
		printf("\n");
		}while (n < 6 || n > 20 );
		marr = create_tablo(n,m);
		printf ("\nSelect Difficulty:\n\n");
		printf ("1. Easy\n");
		printf ("2. Medium\n");
		printf ("3. Hard\n");
		printf("\n");
		scanf ("%d", &diff);
		printf("\n");
		piste=1;
		
		
	// Start of the Game
		printf("\n");
		printf("Game starts in \n");
		printf("..3\n");
		printf("..2\n");
		printf("..1\n");
		printf("\n");
		
		
	// Game
	
	
	if(diff==1)
	{
		do
		{
			printf("\n\n");
			marr = create_tablo(n,m);
			fill_obst(marr,n,m,diff);
			mobst = chips(marr,n,m,chip,piste,diff);
			printf("Number of Piste : %d\n\n",piste);
			print(marr,n,m);
			fseek(stdin,0,SEEK_END);
			move(marr,mobst,n,m,piste,diff,chip);
			printf("\n\n");
			
			piste++;
		}while(piste<10);
		printf("\n\n");
		printf("Your Score : %d\n",score);
		printf("Congratulations you won!!!\n\n");
	}
	else if(diff==2)
	{
		do
		{
			printf("\n\n");
			marr = create_tablo(n,m);
			fill_obst(marr,n,m,diff);
			mobst = chips(marr,n,m,chip,piste,diff);
			printf("Number of Piste : %d\n\n",piste);
			print(marr,n,m);
			fseek(stdin,0,SEEK_END);
			move(marr,mobst,n,m,piste,diff,chip);
			printf("\n\n");
			print(marr,n,m);
			piste++;
		}while(piste<10);
		printf("\n\n");
		printf("Your Score : %d\n",score);
		printf("Congratulations you won!!!\n\n");
	}
	else if(diff==3)
	{
		do
		{
			printf("\n\n");
			marr = create_tablo(n,m);
			fill_obst(marr,n,m,diff);
			mobst = chips(marr,n,m,chip,piste,diff);
			printf("Number of Piste : %d\n\n",piste);
			print(marr,n,m);
			fseek(stdin,0,SEEK_END);
			move(marr,mobst,n,m,piste,diff,chip);
			printf("\n\n");
			print(marr,n,m);
			piste++;
			printf("Next Stage!!\n\n");
		}while(piste<10);
		printf("\n\n");
		printf("Your Score : %d\n",score);
		printf("Congratulations you won!!!\n\n");
	}
	printf ("\nThank you for playing our game!\n");
	
	//Free 
	
	for(i=0; i<n+3 ;i++)
	{
		free(marr[i]);
	}
	
	for(i=0; i<(piste+piste) ;i++)
	{
		free(mobst[i]);
	}		
	}
	
	if (epilogh == 2)
	{
		printf ("\nThank you for playing our game!\n");
	}
	return 0;
	

	
}



int** create_tablo(int n, int m )
{
	
	int i, j;
	int **arr;
	int line1=49;
	int linek=65;
			
		
  	arr=(int**)malloc((n+3)*sizeof(int*));					//n+3 logw provlimatos stin sinartisi move!!!
  	for(i=0;i<(n+3);i++)
  	{
    	arr[i]=(int*)malloc((2*m+3)*sizeof(int));
    	for(j=0;j<(2*m+3);j++)
    	{
    		arr[i][j]=46;

    	}
    }		
  	
	for(i=0; i<(n+3);i++)		
	{
		for(j=0; j<(2*m+3);j++)
		{
			if(i==0 && j<4)			//PRWTI SEIRA
			{
				arr[i][j]=32;
			}
			if(i==0 && j>3 && j%2==0)
			{
				arr[i][j]=line1;
				if(line1==57)
				{
					line1=48;
				}
				line1++;
				
			}
			if(i==0 && j>3 && j%2==1)
			{
				arr[i][j]=32;
			}
			if(i==1)
			{
				arr[i][j]=45;			//DEUTERI SEIRA
			}
			if(i>1 && j==0)				//KATHETES SEIRES
			{
				arr[i][j]=linek;
				linek++;
			}
			if(i>1 && j%2==1)
			{
				arr[i][j]=32;
			}
			if(i>1 && j==2)
			{
				arr[i][j]=124;	
			}
			
		}
	}
	return arr;
}

void fill_obst(int **marr,  int n, int m, int diff)
{
	int x,y,e;
	
	
	srand(time(NULL));
	
	if(diff==1)
		e=n*m*5/100;
	if(diff==2)
		e=n*m*10/100;
	if(diff==3)		
		e=n*m*15/100;
	
	while(e>0)
	{
		x=rand() % (n+2);
		y=rand() % (2*m+3);
		if(marr[x][y]==46 && marr[x][y]!=35 && x>1 && y>3)
		{
			marr[x][y]=35;
			e--;
		}
	}
		

}

void print(int** marr, int n, int m)
{
	int i, j;
	for(i=0; i<n+2; i++)					//EKTIPWSI TABLO
		{
			for(j=0; j<2*m+3; j++)
			{
				printf("%c", marr[i][j]);
			}
			printf("\n");
		}
}
int** chips(int** marr, int n , int m, int chip, int piste,int diff)
{
	int xc,yc,counter,**mobst,i,j,b,x;
	
	i=0;
	j=0;
	x=0;
	
	mobst=(int**)malloc((piste+piste)*sizeof(int*));
  	for(b=0;b<(piste+piste);b++)
    	mobst[b]=(int*)malloc((2)*sizeof(int));
   	
	
	srand(time(NULL));
	if(diff==1)
	{
		if(piste>3 && piste<10)
		{
			piste=3;
		}
	}
	
	if(diff==2)
	{
		if(piste>6 && piste<10)
		{
			piste=6;
		}
	}
	
	
	while(piste>0)
	{
		counter=0;
			
		while(counter<2)
		{
				
			xc=rand() % (n+2);
			yc=rand() % (2*m+3);
			
		
			if(marr[xc][yc]==46 && x==0)
			{
				marr[xc][yc]=chip;
				counter++;
				mobst[i][j]=xc;
				j++;
				mobst[i][j]=yc;
				j--;
				i++;
				x++;
			}
			if(marr[xc][yc]==46 && x==1 &&	(marr[xc+1][yc] != chip && marr[xc-1][yc] != chip && marr[xc][yc+2] != chip && marr[xc][yc-2] != chip ))
			{
				marr[xc][yc]=chip;
				counter++;
				mobst[i][j]=xc;
				j++;
				mobst[i][j]=yc;
				j--;
				i++;	
			}	
					
	
		}
							
		piste--;
		chip++;	
					
	}
	
	return mobst;
}

void move(int** marr, int** mobst, int n,int m,int piste,int diff,int chip)
{
	int MAX=60,i,j,x,mx,my,fx,fy,numberof=0;
	int connect=0;
	char buf[MAX];
	
	
	
	
	
	
	if(diff==1)
	{
		if(piste>3 && piste<10)
		{
			piste=3;
		}
	}
	
	if(diff==2)
	{
		if(piste>6 && piste<10)
		{
			piste=6;
		}
	}
	
	while(connect<piste)
	{
		
		jump:
			
		printf("\n\n");	
		printf("Your score is : %d\n",score);
		printf("Wire or give command:\n\n");
		
	 
	    
	    gets(buf);										//scan gia entoles dimiourgia kalwdioy
		printf("\n");	   
	   	x=strlen(buf);
	   	
	   	
	   	
	   	
	   	if(buf[0]=='r' && buf[1]=='e' && buf[2]=='s' && buf[3]=='e' && buf[4]=='t')
	   	{
	   		printf("\n\n");
	   		numberof++;
	   		connect=0;
	   		if(diff==1)
	   			score=score-1*numberof;
	   		if(diff==2)
	   			score=score-2*numberof;
	   		if(diff==3)
	   			score=score-3*numberof;
	   		marr = create_tablo(n,m);
			fill_obst(marr,n,m,diff);
			mobst = chips(marr,n,m,chip,piste,diff);
			print(marr,n,m);
	   		fseek(stdin,0,SEEK_END);
	   		goto jump;
	   		
	   		
		}
		if(buf[0]=='e' && buf[1]=='x' && buf[2]=='i' && buf[3]=='t')
	   	{
	   		printf("\n\n");
	   		printf ("\n%cThank you for playing our game!%c\n",219,219);
	   		
	   		//Free
	   		
	   		for(i=0; i<n+3 ;i++)
			{
				free(marr[i]);
			}
	
			for(i=0; i<(piste+piste) ;i++)
			{
				free(mobst[i]);
			}
	   		exit(0);
	   		
	   		
		}
		
	    
	   	
	   	for(i=0; i<x ; i=i+2)
	   	{
	   		
			   
		   		mx=buf[i];
				my=buf[i+1];
				mx=mx-95;
	
					
				switch(my)
				{
				case(49):
					my=my-45;
					break;
				case(50):
					my=my-44;
					break;
				case(51):
					my=my-43;
					break;
				case(52):
					my=my-42;
					break;
				case(53):
					my=my-41;
					break;
				case(54):
					my=my-40;
					break;
				case(55):
					my=my-39;
					break;
				case(56):
					my=my-38;
					break;
				case(57):
					my=my-37;
					break;
				}
				
				
				
				
				// PERIPTWSI GEITONIKWN CHIPS ME ENWSI MIAS KINISIS
				
				if(i==0 && marr[mx][my]==46  && x==2 && (marr[mx+1][my]>48 && marr[mx+1][my]<58 || marr[mx-1][my]>48 && marr[mx-1][my]<58 || marr[mx][my+2]>48 && marr[mx][my+2]<58 || marr[mx][my-2]>48 && marr[mx][my-2]<58) && ((marr[mx+1][my]==marr[mx-1][my] && marr[mx+1][my]!=46 )|| (marr[mx][my+2]==marr[mx][my-2] && marr[mx][my+2]!=46 )|| (marr[mx+1][my]==marr[mx][my-2] && marr[mx+1][my]!=46 )|| (marr[mx+1][my]==marr[mx][my+2] && marr[mx+1][my]!=46)|| (marr[mx-1][my]==marr[mx][my+2] && marr[mx-1][my]!=46)|| (marr[mx-1][my]==marr[mx][my-2] && marr[mx-1][my]!=46)))
				{
					marr[mx][my]=111;
					
					
					if(diff==1)
						score=score+10+(piste*1)+1;
					if(diff==2)
						score=score+20+(piste*1)+1;
					if(diff==3)
						score=score+30+(piste*1)+1;
					
					
					connect++;
					
					
				}
				
				
				//PRWTO KALWDIO XWRIS TA DIO CHIPS NA EINAI DIPLA
				
				
				else if(i==0 && marr[mx][my]==46  && x>2 && (marr[mx+1][my]>48 && marr[mx+1][my]<58 || marr[mx-1][my]>48 && marr[mx-1][my]<58 || marr[mx][my+2]>48 && marr[mx][my+2]<58 || marr[mx][my-2]>48 && marr[mx][my-2]<58))                  
				{
					marr[mx][my]=111;
					if(piste==1 || piste==2 || piste==3 || piste==4 || piste==5 || piste==4 || piste==5 || piste==6 || piste==7 || piste==8 || piste==9)
					{
					
						if(mx+1==mobst[0][0] && my==mobst[0][1] || mx-1==mobst[0][0] && my==mobst[0][1] || mx==mobst[0][0] && my+2==mobst[0][1] || my-2==mobst[0][1] && mx==mobst[0][0] )//1
						{
							fx=mobst[1][0];
							fy=mobst[1][1];
						
						
						}
						if(mx+1==mobst[1][0] && my==mobst[1][1] || mx-1==mobst[1][0] && my==mobst[1][1] || mx==mobst[1][0] && my+2==mobst[1][1] || my-2==mobst[1][1] && mx==mobst[1][0])
						{
							fx=mobst[0][0];
							fy=mobst[0][1];
						
						}
						if(piste==2 || piste==3 || piste==4 || piste==5 || piste==4 || piste==5 || piste==6 || piste==7 || piste==8 || piste==9)
						{
							if(mx+1==mobst[2][0] && my==mobst[2][1] || mx-1==mobst[2][0] && my==mobst[2][1] || mx==mobst[2][0] && my+2==mobst[2][1] || my-2==mobst[2][1] && mx==mobst[2][0])//2
							{
								fx=mobst[3][0];
								fy=mobst[3][1];
							
							
							}
							if(mx+1==mobst[3][0] && my==mobst[3][1] || mx-1==mobst[3][0] && my==mobst[3][1] || mx==mobst[3][0] && my+2==mobst[3][1] || my-2==mobst[3][1] && mx==mobst[3][0])
							{
								fx=mobst[2][0];
								fy=mobst[2][1];
							
							
							}
							if(piste==3 || piste==4 || piste==5 || piste==4 || piste==5 || piste==6 || piste==7 || piste==8 || piste==9)
							{
								if(mx+1==mobst[4][0] && my==mobst[4][1] || mx-1==mobst[4][0] && my==mobst[4][1] || mx==mobst[4][0] && my+2==mobst[4][1] || my-2==mobst[4][1] && mx==mobst[4][0])//3
								{
									fx=mobst[5][0];
									fy=mobst[5][1];
						
						
								}
								if(mx+1==mobst[5][0] && my==mobst[5][1] || mx-1==mobst[5][0] && my==mobst[5][1] || mx==mobst[5][0] && my+2==mobst[5][1] || my-2==mobst[5][1] && mx==mobst[5][0])
								{
									fx=mobst[4][0];
									fy=mobst[4][1];
								}	
								if( piste==4 || piste==5 || piste==4 || piste==5 || piste==6 || piste==7 || piste==8 || piste==9)
								{
									if(mx+1==mobst[6][0] && my==mobst[6][0] || mx-1==mobst[6][0] && my==mobst[6][1] || mx==mobst[6][0] && my+2==mobst[6][1] || my-2==mobst[6][1] && mx==mobst[6][0])//4
									{
										fx=mobst[7][0];
										fy=mobst[7][1];
										
										
									}
									if(mx+1==mobst[7][0] && my==mobst[7][1] || mx-1==mobst[7][0] && my==mobst[7][1] || mx==mobst[7][0] && my+2==mobst[7][1] || my-2==mobst[7][1] && mx==mobst[7][0])
									{
										fx=mobst[6][0];
										fy=mobst[6][1];
										
										
									}
									if( piste==5 || piste==6 || piste==7 || piste==8 || piste==9)
									{
										if(mx+1==mobst[8][0] && my==mobst[8][1] || mx-1==mobst[8][0] && my==mobst[8][1] || mx==mobst[8][0] && my+2==mobst[8][1] || my-2==mobst[8][1] && mx==mobst[8][0])//5
										{
											fx=mobst[9][0];
											fy=mobst[9][1];
											
											
										}
										if(mx+1==mobst[9][0] && my==mobst[9][1] || mx-1==mobst[9][0] && my==mobst[9][1] || mx==mobst[9][0] && my+2==mobst[9][1] || my-2==mobst[9][1] && mx==mobst[9][0])
										{
											fx=mobst[8][0];
											fy=mobst[8][1];
										}	
										if( piste==6 || piste==7 || piste==8 || piste==9)
										{
												if(mx+1==mobst[10][0] && my==mobst[10][0] || mx-1==mobst[10][0] && my==mobst[10][1] || mx==mobst[10][0] && my+2==mobst[10][1] || my-2==mobst[10][1] && mx==mobst[10][0])//6
												{
													fx=mobst[11][0];
													fy=mobst[11][1];
													
													
												}
												if(mx+1==mobst[11][0] && my==mobst[11][1] || mx-1==mobst[11][0] && my==mobst[11][1] || mx==mobst[11][0] && my+2==mobst[11][1] || my-2==mobst[11][1] && mx==mobst[11][0])
												{
													fx=mobst[10][0];
													fy=mobst[10][1];
													
													
												}
												if(piste==7 || piste==8 || piste==9)
												{
														if(mx+1==mobst[12][0] && my==mobst[12][1] || mx-1==mobst[12][0] && my==mobst[12][1] || mx==mobst[12][0] && my+2==mobst[12][1] || my-2==mobst[12][1] && mx==mobst[12][0])//7
														{
															fx=mobst[13][0];
															fy=mobst[13][1];
															
															
														}
														if(mx+1==mobst[13][0] && my==mobst[13][1] || mx-1==mobst[13][0] && my==mobst[13][1] || mx==mobst[13][0] && my+2==mobst[13][1] || my-2==mobst[13][1] && mx==mobst[13][0])
														{
															fx=mobst[12][0];
															fy=mobst[12][1];
														}	
														if( piste==8 || piste==9)
														{
															if(mx+1==mobst[14][0] && my==mobst[14][0] || mx-1==mobst[14][0] && my==mobst[14][1] || mx==mobst[14][0] && my+2==mobst[14][1] || my-2==mobst[14][1] && mx==mobst[14][0])//8
															{
																fx=mobst[15][0];
																fy=mobst[15][1];
																
																
															}
															if(mx+1==mobst[15][0] && my==mobst[15][1] || mx-1==mobst[15][0] && my==mobst[15][1] || mx==mobst[15][0] && my+2==mobst[15][1] || my-2==mobst[15][1] && mx==mobst[15][0])
															{
																fx=mobst[16][0];
																fy=mobst[16][1];
																
																
															}	
															if(piste==9)
															{
																if(mx+1==mobst[16][0] && my==mobst[16][0] || mx-1==mobst[16][0] && my==mobst[16][1] || mx==mobst[16][0] && my+2==mobst[16][1] || my-2==mobst[16][1] && mx==mobst[16][0])//9
																{
																	fx=mobst[17][0];
																	fy=mobst[17][1];
																	
																	
																}
																if(mx+1==mobst[17][0] && my==mobst[17][1] || mx-1==mobst[17][0] && my==mobst[17][1] || mx==mobst[17][0] && my+2==mobst[17][1] || my-2==mobst[17][1] && mx==mobst[17][0])
																{
																	fx=mobst[16][0];
																	fy=mobst[16][1];
																	
																	
																}
																
																
															}
															
															
														}
													
													
												}
												
												
												
												
											
											
										}
										
										
									}
									
									
									
								}
								
								
						
							
							}							
						}
					}
				
					
						
					
				}
				
				
				//ENDIAMESA KALWDIA
				
				else if(i>1 && marr[mx][my]==46  && i<x-2  && (marr[mx+1][my]==111 || marr[mx-1][my]==111 || marr[mx][my+2]==111 || marr[mx][my-2]==111))
				{
					marr[mx][my]=111;
				}
				
				
				
				//TELEUTAIO KALWDIO
				
				else if(marr[mx][my]==46 && i==x-2 && i!=0  && (marr[mx][my+2]==111 || marr[mx][my-2]==111 || marr[mx+1][my]==111 || marr[mx-1][my]==111 ) && (mx+1==fx && my==fy || mx-1==fx && my==fy || mx==fx && my+2==fy || mx==fx && my-2==fy))
				{
					marr[mx][my]=111;
					
					
					if(diff==1)
						score=score+10+(piste*1)+1;
					if(diff==2)
						score=score+20+(piste*1)+1;
					if(diff==3)
						score=score+30+(piste*1)+1;
						
				
					connect++;
					
								
					
				}
				
				
		
			  	else 
				{
				
					printf("WRONG MOVE!!!\n\nTRY AGAIN!!\n\n");
					
					for(i=0; i<n+2; i++)					
					{
						for(j=0; j<2*m+3; j++)
						{
							if(marr[i][j]==111)
							{
								marr[i][j]=46;
							}
						}
				
					}
					
					
					fseek(stdin,0,SEEK_END);
					
					goto jump;
				}
				
				
			
			
		}
		
		printf("Chips connected!!\n\n");
		print(marr,n,m);
		printf("\n\n");
		fseek(stdin,0,SEEK_END);
		
	
		
	
   }
   printf("Good Job!! You connected all the pairs of chips!!\n\n");
   printf("Your score is : %d\n\n",score);
   fseek(stdin,0,SEEK_END);
   

	
}



