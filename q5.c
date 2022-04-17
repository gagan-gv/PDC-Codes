#include<stdio.h>
#include<limits.h>
#include<omp.h>

int main(){
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int arr[n];
    int max = INT_MIN;
    int min = INT_MAX;

    for(int ii = 0; ii < n; ii++){
        scanf("%d", &arr[ii]);
    }

    #pragma omp parallel for reduction(min : min)
    for(int ii = 0; ii < n; ii++){
        if(arr[ii] < min){
            min = arr[ii];
        }
    }
    #pragma omp parallel for reduction(max : max)
    for(int ii = 0; ii < n; ii++){
        if(arr[ii] > max){
            max = arr[ii];
        }
    }
    
    printf("Max Value in the array = %d\n", max);
    printf("Min Value in the array = %d\n", min);

    return 0;
}