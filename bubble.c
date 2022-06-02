#include <stdio.h>
//BUBBLE SORT
int bubble(int a[], int n){
	int i,j,t;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[j]>a[j+1]){
					t = a[j];
					a[j] = a[j+1];
					a[j+1] = t;
			}
		}
	}
}

int main(){
	int b[10],i,n;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	
	printf("Enter elements:");
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	
	printf("array is:");
	for(i=0;i<n;i++){
		printf("%d",b[i]);
	}
	
	int size = sizeof(b)/sizeof(b[0]);
	
	bubble(b,size);
	
	printf("Sorted array is :");
	for(i=0;i<n;i++){
		printf("%d",b[i]);
	}
}
