//
// Created by faste on 12/13/2019.
//

#include<iostream>
#include <string>

void swap(std::string *xp, std::string *yp){
    std::string  temp= *xp;
    *xp= *yp;
    *yp= temp;
}

void bubbleSort(std::string arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void printArray(std::string arr[], int size){
        int i;
        for(i=0; i < size; i++)
            std::cout << arr[i] << std::endl;
        std::cout << std::endl;
}

int main(){
    std::string arr[]= {"Jon Bellion*Hand Of God*210*0","AJR*100 Bad Days*160*0", "AJR*Weak*200*0", "Jon Bellion*All Time Low*135*0", "Noah Kahan*Busyhead*180*0", "Jon Bellion*Fasion*160*0",
     "Noah Kahan*Carlo's Song*190*0","AJR*Next Up Forever*180*0", "Noah Kahan*Young Blood*170*0"};
    int n= sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    std::cout<< "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
