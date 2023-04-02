#include <iostream>
using namespace std;

int getPivot(int arr[], int n){
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int st,int end, int key){
    int s = st;
    int e = end;
    int mid = s + (e-s)/2;
    
    while(s<=e){
        if(arr[mid] == key)
            return mid;
        
        if(arr[mid] > key)
            s = mid + 1;
        else
            e = mid - 1;
        
        mid = s + (e-s)/2;
    }
    return -1;
}

int findPosition(int arr[], int n, int k){
    int pivot = getPivot(arr, n);
    if(k >= arr[pivot] && k <= arr[n-1]){
        return binarySearch(arr, pivot, n-1, k);
    }
    else{
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main(){
    int arr[5] = {7,8,1,2,3};
    int k = 2;
    cout<<"Position of: "<<k<<" is: "<<findPosition(arr, 5, k);
}