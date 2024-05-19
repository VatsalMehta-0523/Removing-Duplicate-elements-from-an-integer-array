#include <stdio.h>
int n ;
void printArr( int arr[] , int n );               //function declaration
void remove_dupplicates( int arr[] , int *n );    // here n is passed by reference as its value should be altered in main too


int main(){
    printf("enter size of array : ");
    scanf("%d" , &n );

    int arr[n];                                 // initialising an array of size n
    for (int i = 0 ; i < n ; i++ ){
        printf("enter value%d : ", i+1);
        scanf("%d",&arr[i]);
    }
    // sorting array ...
    int temp ;
    for (int i = 0 ; i  < n ; i++){
        for (int j = i+1 ; j < n ; j++){
            if (arr[i] > arr[j]){
                temp = arr[i] ;
                arr[i] = arr[j];
                arr[j] = temp ;
            }
        }
    }

    printf("\nSorted array before removing duplicate values  : ");
    printArr(arr , n );
    remove_dupplicates(arr , &n );                                    // function is called by reference
    printf("\nupdated array after removing duplicate value   : ");    // so that size of array after removing duplicates should be altered.
    printArr(arr , n );

    return 0 ;
}

void printArr( int arr[] , int n ){  // function to print array
    for (int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
}

void remove_dupplicates(int arr[] , int *n ){  // function to remove duplicate elements from array
    int j = 0 ;
    for ( int i = 0 ; i < *n ; i++ ){
        if ( arr[i] != arr[i+1] ){
            // adding value to array only if adjacent values are not same
            arr[j++] = arr[i] ;
        }
    }
    *n = j ;   // updating size of array .
}
