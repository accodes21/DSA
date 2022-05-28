#include <stdio.h>
int main(){
	int a[50],freq[50];
	int n,i,j,count;
	printf("Enter no. of elements:");
	scanf("%d",&n);
	
	printf("Enter elements in array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        freq[i] = -1;
    }
    
    for(i=0;i<n;i++){
    	count = 1;
    	for(j=i+1;j<n;j++){
    		if(a[i]==a[j]){
    			count++;
    			freq[j]=0;
			}
		}
		
		if(freq[i]!=0){
			freq[i]=count;
		}
	}
	
	 printf("\nFrequency elements of array : \n");
    for(i=0; i<n; i++)
    {
        if(freq[i] != 0)
        {
            printf("%d occurs %d times\n", a[i], freq[i]);
        }
    }

    return 0;
}
