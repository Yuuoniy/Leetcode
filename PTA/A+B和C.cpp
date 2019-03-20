#include <stdio.h>

int main()
{
	int tim = 0;
	long unsigned int a = 0,b = 0,c = 0,sum = 0;
	scanf("%d",&tim);

	int re = tim+1;
	while(tim)
	{
		scanf("%lu%lu%lu",&a,&b,&c); 
		sum = a+b;
		if(sum<=c)
			printf("Case #%d: false\n",re-tim--);
		else
			printf("Case #%d: true\n",re-tim--);
	
	}
	return 0;
	 
 } 
