//INSERTION AT END
/*#include<stdio.h>
int main()
{
	int arr[10]={10,11,3,6,15};
	int len=5;
	int i,n;
	
	printf("Original Array :");
	for(i=0;i<len;i++){
		printf("%d	",arr[i]);
	}
	printf("\nEnter Number to be inserted at end :");
	scanf("%d",&n);
	
	arr[len]=n;
	
	printf("\nAfter Insertion :");
	for(i=0;i<len+1;i++){
		printf("%d	",arr[i]);
	}
	return 0;
}
*/

#include <stdio.h>
int main()
{
	int arr[10],i,pos,n,x;
	printf("Enter numbers of elemnets for the array :");
	scanf("%d",&n);
	
	printf("Enter %d numbers:\n",n);
	for(i=0;i<n;i++){
		
		scanf("%d",&arr[i]);
	}
	
	
	printf("Enter location to insert number :");
	scanf("%d",&pos);
	
	printf("Enter x to insert :");
	scanf("%d",&x);
	
	for(i=n-1;i>=pos-1;i--){
		arr[i+1]=arr[i];
	}
	arr[pos-1]=x;
	
	printf("Final Array is:\n");
	for(i=0;i<=n;i++){
		printf("%d	",arr[i]);
	}
	return 0;
}


