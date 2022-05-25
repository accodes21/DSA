#include <stdio.h>
int main()
{
	int a[10],i,n,cp=0,cn=0,ce=0,co=0;
	for(i=0;i<10;i++){
		printf("Enter %d element:",i);
		scanf("%d",&n);
	}
	for(i=0;i<10;i++){
		if(i>0){
			cp++;
			if(i%2==0)
				ce++;
			else
				co++;
		}
		else
			cn++;
		
	}
	printf("Count of positive numbers is %d\n",cp);
	printf("Count of neagative numbers is %d\n",cn);
	printf("Count of odd numbers is %d\n",co);
	printf("Count of even numbers is %d",ce);
	return 0;
}
