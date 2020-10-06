/** AUTHOR: Lucas Viana Vilela */

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
typedef int boolean;

// Returns a copy of the received vector
int *copyVector(int *vector, int vectorSize){
    int *outputVector = (int *)malloc(vectorSize * sizeof(int));

    for(int i = 0; i < vectorSize; i++){
        outputVector[i] = vector[i];
    }

    return outputVector;
}

// Swaps vector[i] and vector[j]
void swapElements(int *vector, int i, int j){
   if(i != j){
        int tmp; // Auxiliar variable

        tmp = vector[i];
        vector[i] = vector[j];
        vector[j] = tmp;
   }
    
    return;
}

// Receives a vector and the position of two sorted subvectors inside it - merges both of them into a fully sorted one
void mergeSubvectors(int *vector, int firstLeftIndex, int firstRightIndex, int secondLeftIndex, int secondRightIndex){
    int vectorSize = (firstRightIndex - firstLeftIndex + 1) + (secondRightIndex - secondLeftIndex + 1);

    int *tmp = (int*)malloc(vectorSize * sizeof(int)); // Temporary vector in which the interpolation will occur
    
    int i, j, k = 0; // Auxiliar variables that'll index the for-loops

    // Loops through both subvectors, merging them
    for(i = firstLeftIndex, j = secondLeftIndex; k < vectorSize; k++){

        // If there are still elements in both subvector
        if(i <= firstRightIndex && j <= secondRightIndex){ 
            // Compares them and copies the lowest one to tmp
            if(vector[i] < vector[j]){ tmp[k] = vector[i++]; }
            else{ tmp[k] = vector[j++]; }
        }

        // If not, copies the remaining element to tmp
        else if(i <= firstRightIndex){ tmp[k] = vector[i++]; }
        else if(j <= secondRightIndex){ tmp[k] = vector[j++]; }

    }

    // Copies the sorted vector in tmp to the original one, replacing the subvectors
    for(i = firstLeftIndex, j = secondLeftIndex, k = 0; k < vectorSize; k++){
        if(i <= firstRightIndex){ vector[i++] = tmp[k]; }
        else{ vector[j++] = tmp[k]; }

    }

    free(tmp); tmp = NULL;

    return;
}



// SELECTION SORT
void selectionSort(int *vector, int vectorSize){
    int unsortedSubvector; // First element in the unsorted subvector's index
    int lowestValueIndex;  // Lowest value element in the unsorted subvector's index

    // Loops through the whole vector (each iteration grows the sorted subvector by 1)
    for (unsortedSubvector = 0; unsortedSubvector < vectorSize; unsortedSubvector++){

        // A new iteration starts with it's unsorted subvector's first element as the lowest value
        lowestValueIndex = unsortedSubvector;

        // Loops through the unsorted subvector and selects the lowest element
        for (int i = unsortedSubvector + 1; i < vectorSize; i++){

            // If the current element is greater than the lowest value, set it as the lowest value
            if (vector[i] < vector[lowestValueIndex]){ lowestValueIndex = i; }

        }

        swapElements(vector, unsortedSubvector, lowestValueIndex);
    }

    return;
}

// BUBBLE SORT
void bubbleSort(int *vector, int vectorSize){
    boolean hasSwapped; // Has a swap occurred in the last iteration?
    int lastSwapped; // Last swapped element in this iteration's index
    int sentinella = vectorSize; // Last unsorted element's index

    do{
        hasSwapped = False; // A new iteration starts with no swaps

        // Loops through the vector
        for(int i = 1; i < sentinella; i++){ 
            if(vector[i-1] > vector[i]){ // If an element is greater than it's subsequent, swap'em
                swapElements(vector,i-1,i);

                hasSwapped = True; // A swap just occurred 
                lastSwapped = i;
            }
        }

        // Sentinella is moved to the last swapped element in this iteration
        sentinella = lastSwapped; 

    } while(hasSwapped == True); // Once a iteration with no swaps occur, the vector is sorted

    return;
}

// INSERTION SORT
void insertionSort(int *vector, int vectorSize){

    // Loops through the whole vector
    for(int i = 1; i < vectorSize; i++){
        int aux = 0; // Auxiliar variable in order to index the "current" element

        // Goes through the already passed part of the vector
        for(int j = i - 1; j >= 0; j--){

            // And takes the "current" element as far left as needed
            if(vector[i-aux] < vector[j]){
                swapElements(vector, j, i-aux);
                aux++;

            }
            
            else{ break; }
        }
    }

    return;
}

// MERGE SORT
void mergeSort(int *vector, int leftIndex, int rightIndex){
    int vectorSize = rightIndex - leftIndex + 1;

    if (vectorSize > 1){
        int middleIndex = (rightIndex + leftIndex) / 2;

        mergeSort(vector, leftIndex, middleIndex);
        mergeSort(vector, middleIndex + 1, rightIndex);
        mergeSubvectors(vector, leftIndex, middleIndex, middleIndex + 1, rightIndex);
    }

    return;
}
