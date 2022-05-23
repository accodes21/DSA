#include <stdio.h>
int binarysearch(int a[],int x,int low,int high){
	while(low<=high){
		int mid = low + (high-low)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]<x)
			low = mid+1;
		if(a[mid]>x)
			high = mid-1;
	}
	return -1;
}

int main(){
	int a[5], i,n,x,j;
	printf("enter elements:");
	for(i=0;i<5;i++){
		scanf("%d",&a[i]);
	}
	
	
	printf("Array is:");
	for(i=0;i<5;i++){
		printf("%d  ",a[i]);
	}
	
	
	printf("\nEnter element to be searched:");
	scanf("%d",&x);
	
	n=sizeof(a)/sizeof(a[0]);
	j = binarysearch(a,x,0,n);
	
	if(j==-1)
		printf("ELEMENT NOT FOUND");
	else
		printf("Element found at index %d",j);
	
	return 0;
}
