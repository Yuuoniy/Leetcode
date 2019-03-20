#include <stdio.h>

int main() 
{
	int c1,c2;
	scanf("%d%d",&c1,&c2);
	float d = c2 - c1+50;
	int hour = d/360000;
	d-=hour*360000;
	int mintue = d/6000;
	d -= mintue*6000;
	int second = d/100;
	printf("%02d:%02d:%02d\n",hour,mintue,second);
	return 0;
}
