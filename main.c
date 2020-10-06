/** AUTHOR: Lucas Viana Vilela */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "algorithms.c"

#define METHOD_LENGTH 10
typedef char* string;

int main(int argc, char **argv){
    string method; // bubble, selection, insertion, merge
    int vectorSize; // How many numbers to sort
    int *vector; // Vector to be sorted
    double elapsedTime; // Variables that'll be used to time the sorting
    int printSorted = 1;

    // If there are no command line arguments, use scanf
    if(argc == 1){
        method = (string)malloc(METHOD_LENGTH * sizeof(char));

        scanf("%s", method); // Get method
        scanf("%d", &vectorSize); // Get vector size
        
        vector = (int *)malloc(vectorSize * sizeof(int));

        // Gets unsorted numbers
        for(int i = 0; i < vectorSize; i++){
            scanf("%d", &vector[i]);
        }
    }

    // If there are only two command line arguments (method and size)
    // generate random vector
    else if(argc == 3){
        method = argv[1];
        vectorSize = atoi(argv[2]);
        printSorted = 0;
        vector = (int *)malloc((int) vectorSize * sizeof(int));

        srand(time(0));

        for(int i = 0; i < vectorSize; i++){
            vector[i] = rand();
        }

    }

    // If there are only three command line arguments (method, char and size)
    // generate random vector and print it after sorted
    else if(argc == 4 && isalpha(argv[2][0])){
        method = argv[1];
        vectorSize = atoi(argv[3]);
        vector = (int *)malloc((int) vectorSize * sizeof(int));

        srand(time(0));

        for(int i = 0; i < vectorSize; i++){
            vector[i] = rand() % (vectorSize * 100 + 1);
        }

    }

    else if(argc == 2){ return 1; }

    else{
        method = argv[1];
        printSorted = isalpha(argv[2][0]) ? 1 : 0;
        vectorSize = argc - 2 - printSorted;
        vector = (int *)malloc(vectorSize * sizeof(int));

        for(int i = 0; i < vectorSize; i++){
            vector[i] = atoi(argv[i + 2 + printSorted]);
        }
    }


    // Sets method to lowecase
    for(int i = 0; method[i]; i++){ method[i] = (char) tolower(method[i]); }

    // Sorts the input with chosen method
    if(!strcmp(method, "bubble")){
        elapsedTime = (double) clock(); 
        bubbleSort(vector, vectorSize);
        elapsedTime = ((double)clock() - elapsedTime)/CLOCKS_PER_SEC; 
    }

    else if(!strcmp(method, "selection")){
        elapsedTime = (double) clock(); 
        selectionSort(vector, vectorSize);
        elapsedTime = ((double)clock() - elapsedTime)/CLOCKS_PER_SEC; 
    }

    else if(!strcmp(method, "insertion")){
        elapsedTime = (double) clock(); 
        insertionSort(vector, vectorSize);
        elapsedTime = ((double)clock() - elapsedTime)/CLOCKS_PER_SEC; 
    }

    else if(!strcmp(method, "merge")){
        elapsedTime = (double) clock(); 
        mergeSort(vector, 0, vectorSize - 1);
        elapsedTime = ((double)clock() - elapsedTime)/CLOCKS_PER_SEC; 
    }

    else{ 
        free(vector);
        if(argc == 1){ free(method); }
        return 1; 
    }

    // Prints the sorted vector
    if(printSorted){
        printf("\n [*] Sorted vector: ");
        for(int i = 0; i < vectorSize; i++){ printf("%d ", vector[i]); }
    }

    // Prints the vector size and the elapsed time
    printf("\n [*] Sorted: %d numbers.\n", vectorSize);
    printf(" [*] The %s sort took: %lf s.\n\n", method, elapsedTime);

    free(vector);
    if(argc == 1){ free(method); }
    
    return 0;
}