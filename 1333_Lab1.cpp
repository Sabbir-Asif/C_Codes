#include<stdio.h>
#define max 100

int main()
{
	char str[max];
	char path[max];
	char f = 'a';
	int head = -1;

	printf("Enter your string : ");
	scanf("%s",str);

	for(int i = 0 ; str[i] != '\0' ; i++)
	{
		switch(f)
		{
		case 'a' : if(str[i] == '0') 
			{
				f = 'a';
				head++;
				path[head] = 'a';
			}
			else if(str[i] == '1')
			{
				f = 'b';
				head++;
				path[head] = 'b';
			}
		break;
	    case 'b' : if(str[i] == '0')
	    	{
	    		f = 'a';
	    		head++;
	    		path[head] = 'a';
	    	}
	    	else if(str[i] == '1')
	    	{
	    		f = 'c';
	    		head++;
	    		path[head] = 'c';
	    	}
	    break;
	    case 'c' : if(str[i] == '0')
	    	{
	    		f = 'a';
	    		head++;
	    		path[head] = 'a';
	    	}
	    	else if(str[i] == '1')
	    	{
	    		f = 'd';
	    		head++;
	    		path[head] = 'd';
	    	}
	    break;
	    case 'd' : if(str[i] == '0')
	    	{
	    		f = 'd';
	    		head++;
	    		path[head] = 'd';
	    	}
	    	else if(str[i] == '1')
	    	{
	    		f = 'd';
	    		head++;
	    		path[head] = 'd';
	    	}
	    break;

		}
	}

	if(f == 'd')
	{
		printf("Your string is accepted!\n");
		printf("path : ");
		for(int j = 0 ; j <=head ; j++) printf("%c -> ",path[j]);
			printf("\n");
	}
	else printf("Your String is not accepted!\n");

	return 0;
}