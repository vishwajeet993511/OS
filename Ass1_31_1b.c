#include<stdio.h>
#include<string.h>
#include<unistd.h>




/* DON'T  PRESS  STRAY ENTER BUTTON  WHILE THE SHELL IS RUNNING   */




void treat(char* str)
{
	int l,i;
	if(str[0]=='.'&&str[1]==(char)(47)) return;
	else 
	{
		l=strlen(str);
		for(i=l;i>=0;i--)
		{
			str[i+2]=str[i];
		}
		str[0]='.';
		str[1]=(char)(47);
	}
	return;
}
int main()
{	int success;
	int count=1;
	int i,posi,l,first=1;
	int argc;
	char argv[50][50];
	char str[1008];
	int x;
	while(1)
	{
		first=1;
		//printf("enetering while %d\n",getpid());
		
		
		scanf ("%[^\n]s", str);
		
		
		if(strcmp("quit",str)==0) { printf("thanks\n"); return 0; }
		//printf("completed comparing\n");
		
		treat(str);
		l=strlen(str);
		
		
		
		
		argc=0;
		
		
		posi=0;
		for(i=0;i<l;i++)
		{
			if(str[i]!=' ') 
			{	
				first=1;
				argv[argc][posi]=str[i];
				posi++;
				continue;
			}
			else
			{
				if(first==0) continue;
				else
				{
					argv[argc][posi]='\0';
					posi=0;
					first=0;
					argc++;
				}
			}
		}
		argv[argc][posi]='\0';
		argc++;
		
		
		/*printf("%d\n",argc);
		
		for(i=0;i<argc;i++)
		//for(j=0;)
			printf("%s====\n",argv[i]);
		*/
		x=fork();
		
		if(x==0)
		{
			//printf("inside child %d\n",getpid());
			switch(argc)
			{
				case 1:  {/*printf("switvhing to %d\n",argc);*/ success=execlp(argv[0], argv[0], (char*)NULL);}
				break;
				
				case 2:{/*printf("switvhing to %d\n",argc);*/ success=execlp(argv[0], argv[0],argv[1], NULL);}
				break;
				
				case 3: {/*printf("switvhing to %d\n",argc);*/ success=execlp(argv[0], argv[0],argv[1],argv[2], NULL);}
				break;
				
				case 4: {/*printf("switvhing to %d\n",argc);*/ success=execlp(argv[0], argv[0],argv[1],argv[2],argv[3],NULL);}
				break;
				
				case 5: {/*printf("switvhing to %d\n",argc);*/ success=execlp(argv[0], argv[0],argv[1],argv[2],argv[3],argv[4], NULL);}
				break;
				
				case 6: {/*printf("switvhing to %d\n",argc);*/ success=execlp(argv[0], argv[0],argv[1],argv[2],argv[3],argv[4],argv[5], NULL);}
				break;
				
				case 7: {/*printf("switvhing to %d\n",argc);*/ success=execlp(argv[0], argv[0],argv[1],argv[2],argv[3],argv[4],argv[5],argv[6], NULL);}
				break;
				
				default: {  printf("Too many arguments !!!]\n");  return 0;}
			}
			printf("execlp() has failed !!!!\n");
		}
		else
		{
		wait(0); 
		printf("\nChild has terminated\n\n");
		getchar();
		}
					
				
		
		
	}

return 0;

}
	
