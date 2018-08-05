#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

int main()
{
	char option,count=5;
	int argc,l,x,posi,first,i,success;
	char argv[50][50];
	char str[1008];
	
	
	
	
	while(count--)
	{
	printf("A. Run an internal command \nB. Run an external command  \nC. Run an external command by redirecting standard input from a file\nD.Run an external command by redirecting standard output to a file \nE.Run an external command in the background \nF.Run several external commands in the pipe mode\nG.Quit the shell ");
	scanf("%c",&option);
	getchar();
	printf("Selected %c %d\n",option,option);
	if(option=='b'||option=='B')
	{
		
		first=1;
		
		scanf ("%[^\n]s", str);
		
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
		
		
		printf("%d\n",argc);
		
		for(i=0;i<argc;i++)
		//for(j=0;)
			printf("%s====\n",argv[i]);
		
		
		
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
		
		
		if(option=='a'||option=='A')
		{/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaSS*/
			first=1;
			
			scanf ("%[^\n]s", str);
		
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
			printf("here is %s\n\n",argv[0]);
			if(strcmp(argv[0],"mkdir")==0)
			{
				mkdir(argv[1],S_IRUSR|S_IWUSR|S_IXUSR);
				getchar();
			}
			else if(strcmp(argv[0],"rmdir")==0)
			{
				rmdir(argv[1]);
				getchar();
			}
			else if(strcmp(argv[0],"chdir")==0)
			{
				chdir(argv[1]);
				getchar();
			}
			else 
			{
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
			
			
			
			
			
			
			
			
			
			
			
			
			
		/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*/	
		}
		
		if(option=='e'||option=='E')
		{
		/*eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee*/
		
		
		first=1;
		
		scanf ("%[^\n]s", str);
		
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
		
		
		printf("%d\n",argc);
		
		for(i=0;i<argc;i++)
		//for(j=0;)
			printf("%s====\n",argv[i]);
		
		argc--;
		
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
		
		printf("\nChild has terminated\n\n");
		getchar();
		}
		
		
		
		/*eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee*/
		}
		
		
		
		
		
		
		
		
		
		
		
		}
		
	
		return 0;
		}	
		
		
		
