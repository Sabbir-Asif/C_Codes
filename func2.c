#include<stdio.h>
#include<math.h>
float f(float x)
{
	return 3*sin(x*3.1416/180);
}

int main()
{
	for(float x = 0 ; x <= 1000 ; x++)
	{
		printf("%f,%f\n",x,f(x));
	}

	return 0;
	
}