#define True 1
#define False 0
typedef int boolean;

// Returns the highest number in the vector
int maxValue(int *vector, int vectorSize){
    int max = vector[0];

    for(int i = 0; i < vectorSize; i++){
        if(max < vector[i]){
            max = vector[i];
        }
    }

    return max;
}

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

// Prints inline
void printVector(int *vector, int vectorSize, boolean newline){
    for(int i = 0; i < vectorSize; i++){
        printf("%d ", vector[i]);
    }
    if(newline == True){ printf("\n"); }

    return;
}