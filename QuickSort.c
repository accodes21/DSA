//QUICK SORT
#include <stdio.h>	
void swap(int *a,int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

int split(int a[],int low,int high){
	int pivot = a[high];
	int i = low-1;
	int j;
	
	for(j=low;j<high;j++){
		if(a[j]<=pivot){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return (i+1);
}

void quickSort(int a[],int low,int high){
	if(high>low){
		int x = split(a,low,high);
		
		//recursion for left of pivot
		quickSort(a,low,x-1);
		
		//recursion for right of pivot
		quickSort(a,x+1,high);

	}
}

void printArray(int a[], int size){
	int i;
	for( i=0;i<size;i++){
		printf("%d ",a[i]);
	}
}

int main(){
	int array[10],i,n,size;
	printf("Enter no. of elements of array:");
	scanf("%d",&n);
	
	printf("Enter elements:");
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
	
	printf("***Array Before Sorting**\n");
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
	
	quickSort(array,0,n-1);
	printf("\n**After Sorting**\n");
	printArray(array,n);
}
