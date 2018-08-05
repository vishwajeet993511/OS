#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void sort1(int a[],int n);

int main()
{
   int arr1[100];
   int arr2[100];
   int arr3[100];
   int arr4[300];
   int pipe1[2];  // Used to store two ends of first pipe
   int pipe2[2];  // Used to store two ends of second pipe
   int pipe3[2];  // Used to store two ends of third pipe
   pipe(pipe1);
   pipe(pipe2);
   pipe(pipe3);
   //int pipe4[2];  // Used to store two ends of fourth pipe
   int i,j;
   /*
   for(i=0;i<100;i++)
		   arr1[i] = rand() % 10000 +1;
   for(i=0;i<100;i++)
		   printf("%d   ",arr1[i]);
   */
   int pid1 = fork();
   
   if(pid1 < 0 )
        printf("unable to create fork 1 \n");
   if(pid1 ==0 )
    {
        
		close(pipe1[0]);  // close the reading end of the pipe
		srand((unsigned)time(0));
		for(i=0;i<100;i++)
		   arr1[i] = rand() % 10000 +1;
		//for(i=0;i<100;i++)
		 //  printf("%d   ",arr1[i]);
		sort1(arr1,100);
		write(pipe1[1], arr1, 100*sizeof(int));
		close(pipe1[1]);
    
    }
   else
    {
		int pid2 = fork();
		if(pid2 < 0 )
		 		printf("unable to create fork 2 \n");
		if(pid2 ==0 )
		 {
				close(pipe2[0]);  // close the reading end of the pipe
				srand(10);
				for(i=0;i<100;i++)
				   arr2[i] = rand() % 10000 +1;
				sort1(arr2,100);
				write(pipe2[1], arr2, 100*sizeof(int));
				close(pipe2[1]);
		}
		 else
		{
		 		int pid3 = fork();
	            if(pid3 < 0 )
		 			printf("unable to create fork 3 \n");
				if(pid3 ==0 )
				 {
					close(pipe3[0]);  // close the reading end of the pipe
					srand(20);
					for(i=0;i<100;i++)
					   arr3[i] = rand() % 10000 +1;
					sort1(arr3,100);
					write(pipe3[1], arr3, 100*sizeof(int));
				    close(pipe3[1]);
				 }
				 else
				 {
					close(pipe1[1]);
					read(pipe1[0], &arr1, 100*sizeof(int));
					close(pipe1[0]);
					printf("arr1 elements \n");
					for(i=0;i< 100;i++)
					{
			           printf("%d   ",arr1[i]);
		            }
		            printf("\n");
					
					close(pipe2[1]);
					read(pipe2[0], &arr2, 100*sizeof(int));
					close(pipe2[0]);
					
					printf("arr2 elements \n");
					for(i=0;i< 100;i++)
					{
			           printf("%d   ",arr2[i]);
		            }
		            printf("\n"); 
					close(pipe3[1]);
					read(pipe3[0], &arr3, 100*sizeof(int));
					close(pipe3[0]);
					printf("arr3 elements \n");
					for(i=0;i< 100;i++)
					{
			           printf("%d   ",arr3[i]);
		            }
		            printf("\n");
					
					//printf("hello/n");
					for(i=0;i<100;i++)
					 {
					   arr4[i] = arr1[i];
					   //if(i <10) {printf("%d  \n",arr4[i]);}
					   
					 }
					 for(i=0;i<100;i++)
					 {
					   arr4[100+i] = arr2[i];
					   //if(i <10) {printf("%d  \n",arr4[i]);}
					 }
					 for(i=0;i<100;i++)
					 {
					   arr4[200+i] = arr3[i];
					   //if(i <10) {printf("%d  \n",arr4[i]);}
					 }
					sort1(arr4,300);
					printf("arr4 elements \n");
					for(i=0;i< 5;i++)
					{
			           printf("%d   ",arr4[i]);
		            }
		            printf("\n");
					//for(i=0 ; i< 10;i++)
					//   printf("  %d ", arr4[i]);
		

				}
		

		}
	  

    }
   


}






void sort1(int a[],int n)
{
  int i,temp,j;
  for(i=0;i<n;i++)
    for(j=0;j<i;j++)
     {

       if( a[i] < a[j] )
        {

           temp = a[i];
           a[i] = a[j];
           a[j] = temp;
        }

    }

}








