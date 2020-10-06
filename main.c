/** AUTHOR: Lucas Viana Vilela */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithms.c"

#define METHOD_LENGTH 10

int main(){
    char method[METHOD_LENGTH]; // bubble, selection, insertion, merge
    int vectorSize; // How many numbers to sort

    scanf("%s", method); // Get method
    scanf("%d", &vectorSize); // Get vector size
    
    int *vector = (int *)malloc(vectorSize * sizeof(int));

    // Gets unsorted numbers
    for(int i = 0; i < vectorSize; i++){
        scanf("%d", &vector[i]);
    }

    // Sorts the input with chosen method
    if(!strcmp(method, "bubble")){
        bubbleSort(vector, vectorSize);
    }

    else if(!strcmp(method, "selection")){
        selectionSort(vector, vectorSize);
    }

    else if(!strcmp(method, "insertion")){
        insertionSort(vector, vectorSize);
    }

    else if(!strcmp(method, "merge")){
        mergeSort(vector, 0, vectorSize - 1);
    }

    else{ return 1; }

    // Prints the sorted vector
    for(int i = 0; i < vectorSize; i++){ printf("%d ", vector[i]); }
    printf("\n");

    free(vector);

    return 0;
}