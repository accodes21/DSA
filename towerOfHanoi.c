#include <stdio.h>
int towerOfHanoi(int n, char x, char y, char z){
    int c = 0;
    if (n>0){
        c = towerOfHanoi(n-1, x, z, y);
        printf("\n Move disk %d from %c to %c ",n,x,y);
        c++;
        c = c + towerOfHanoi(n-1,z,y,x);
    }
    return c;
}

int main(){
    int n;
    printf(" Enter number of plates:");
    scanf("%d",&n);
    int p = towerOfHanoi(n,'A','C','B');
    printf("\nTotal number of moves = %d", p);
    return 0;
}
