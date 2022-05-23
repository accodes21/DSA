//Linear Search

#include <stdio.h>
int main(){
	int a[10],i,x,n;
	printf("No. of elements to enter:\n");
	scanf("%d",&n);
	
	printf("Enter elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("Array is :");
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
	
	printf("\nElement to be searched:");
	scanf("%d",&x);
	
	for(i=0;i<n;i++){
		if(a[i]==x)
			break;
			//printf("element found");
	}
	
	if(a[i]==x){
		printf("Element found at %d",i+1);
	}
	
	else{
		printf("Element not found");
	}
	
	return 0;
	
}
