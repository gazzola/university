/*EightQueens Program using two Stacks , Stacks are implemented using arrays */

 # include <stdio.h>
 # include <stdlib.h>
 # include <time.h>

 typedef struct  { int x,y;
		    } position ;
 void SolveProblem(int n);
 int N=0;
 void main()
 {printf("\nENTER THE SIZE OF CHESSBOARD ( N ) FOR NxN CHESSBOARD :");
  scanf("%d",&N);
  printf("\nIn Each of the solutions the Coordinates of the N-Queens are given (Row,Col) .");
  printf("\nNote that the Rows and Colums are numbered between 1 - N :\n");
  SolveProblem(N);
  getchar();
 }
 void SolveProblem(int n)
 {
 int counter1,counter2=-1,counter3=-1;
 static int counter=0,choice;
 int d[100][3]={0};
 int *stack2;
 position Position1,Position2,Position3;
 position *head1=(position *)malloc(n*n*sizeof(position));
  stack2=(int *)malloc(n*sizeof(int));
 for(counter1=n-1;counter1>=0;counter1--)
	{ Position1.x=0;
	  Position1.y=counter1;
	  head1[++counter2]=Position1;
	 };
  while(counter2>=0){ Position1=head1[counter2--];
		  while(counter3>=0 && Position1.x<=counter3){
		  Position2.x=counter3;
		  Position2.y=stack2[counter3--];
		  d[Position2.y][0]=0;
		  d[Position2.x+Position2.y][1]=0;
		  d[Position2.x-Position2.y+n][2]=0;};
		  stack2[++counter3]=Position1.y;
		  d[Position1.y][0]=1;
		  d[Position1.x+Position1.y][1]=1;
		  d[Position1.x-Position1.y+n][2]=1;


		if(counter3==n-1)
		  {
		   counter++;
		   printf("\nSOLUTION # %d:",counter);
		   for(counter1=0;counter1<=counter3;counter1++)
		    printf("(%d,%d) " ,counter1+1, stack2[counter1]+1);
		   if(counter%10==0){printf("\nEnter 1 to Continue , 0 to end.");
				     scanf("%d",&choice);
				     if(choice==0)
				     exit(0);
				     };
			 Position2.x=counter3;
		   Position2.y=stack2[counter3--];
		   d[Position2.y][0]=0;
		   d[Position2.x+Position2.y][1]=0;
		   d[Position2.x-Position2.y+n][2]=0;}
	   else{for(counter1=n-1;counter1>=0;counter1--)
	       if(d[counter1][0]==0 && d[Position1.x+1+counter1][1]==0 && 			d[n+Position1.x+1-counter1][2]==0)
		{Position3.x=Position1.x+1;
		 Position3.y=counter1;
		 head1[++counter2]=Position3;
		 };
		   }
	}

  }
