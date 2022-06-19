#include <stdio.h>
int main(){
	int a[5],i,n;
	printf("Enter numbers:\n");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	printf("Array:");
	for(i=0;i<5;i++){
		printf("%d ",a[i]);
	}
}
