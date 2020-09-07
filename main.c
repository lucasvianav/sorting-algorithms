/** AUTHORS:
 * Felipe Moura Madureira - 10748646
 * Lucas Viana Vilela - 10748409
 * Lucas Henrique Sant'Anna - 10748521
*/

#include <stdio.h>
#include <string.h>

/* Copies inputVector to outputVector */
void copyVector(int vectorSize, int inputVector[], int outputVector[]){
    for(int i = 0; i < vectorSize; i++){
        outputVector[i] = inputVector[i];
    }

    return;
}

/* Swaps vector[index1] with vector[index2] */
void swapElements(int vector[], int index1, int index2){

    /** To use or not to use 'if(index1 != index2){}'?
     * PRO: Using it would be a more optimized version of the algorithms; 
     * PRO: The provided test-case files's 1.out indicates that it should be used;
     * CON: The version presented in class doesn't use it;
     * 
     * As the output it must exactly match what is expected (and it should also 
     * match the provided test-case files), it probably is best to use it.
    */

   if(index1 != index2){
        int tmp; /* Auxiliar variable */

        printf("T %d %d\n", index1, index2); /* T = Troca */

        tmp = vector[index1];
        vector[index1] = vector[index2];
        vector[index2] = tmp;
   }
    

    return;
}

void bubbleSort(int vectorSize, int vector[], int output[]){
    int hasSwapped; /* Has a swap occurred in the last pass? 1 = yes / 0 = no */
    int lastSwapped; /* Last swapped element in this pass' index */
    int sentinella = vectorSize; /* Last unsorted element's index */

    copyVector(vectorSize, vector, output);

    do{
        hasSwapped = 0; /* A new pass starts with no swaps */

        for(int i = 1; i < sentinella; i++){ /* Loops through the vector */
            printf("C %d %d\n", i-1, i); /* C = Comparação */

            if(output[i-1] > output[i]){ /* If an element is greater than it's subsequent, swap'em */
                swapElements(output,i-1,i);

                hasSwapped = 1; /* A swap just occurred */
                lastSwapped = i;
            }
        }

        sentinella = lastSwapped; /* Sentinella is moved to the last swapped element in this pass */
    }while(hasSwapped == 1); /* Once a pass with no swaps occur, the vector is sorted */

    return;
}

void selectionSort(int vectorSize, int vector[], int output[]){
    int unsortedSubvector; /* Índice do primeiro elemento do vetor não ordenado */
    int lowestValueIndex; /* Índice do elemento de menor valor do vetor não ordenado */

    copyVector(vectorSize, vector, output);

    /* Loop por todo o vetor (cada final do loop incrementa unsortedSubvector em 1) */
    for(unsortedSubvector = 0; unsortedSubvector < vectorSize; unsortedSubvector++){
        /* No início do loop o elemento atual é usado como referência para o menor valor */
        lowestValueIndex = unsortedSubvector; 

        for(int i = unsortedSubvector+1; i < vectorSize; i++){ /* Loop pelo vetor não ordenado */
            printf("C %d %d\n", lowestValueIndex, i); /* C = Comparação */

            /* Se o elemento de referência é maior que o elemento atual, então lowestValueIndex recebe o índice do elemento de menor valor */
            if(output[i] < output[lowestValueIndex]){
                lowestValueIndex = i;
            }
        }

        swapElements(output, unsortedSubvector, lowestValueIndex);
    }
}

int main(){
    char method[7]; /* "bolha" or "selecao" */
    int vectorSize; /* Tamanho do vetor */

    scanf("%s",method); /* Lê o método de ordenação do usuário */
    scanf("%d",&vectorSize); /* Lê o número de valores a ser digitado pelo usuário */
    
    int input[vectorSize]; /* Vetor não ordenado de números */
    int output[vectorSize]; /* Vetor ordenado de números */

    /* Lê os valores do usuário */
    for(int i = 0; i < vectorSize; i++){
        scanf("%d", &input[i]);
    }

    /* Se method == "bolha", o método de ordenação utilizado é o bubbleSort */
    if(strcmp(method,"bolha") == 0){
        bubbleSort(vectorSize,input,output);
    }

    /* Se method == "selecao", o método de ordenação utilizado é o selectionSort */
    else if(strcmp(method,"selecao") == 0){
        selectionSort(vectorSize,input,output);
    }

    /* Se o usuário não digitou nenhum dos métodos acima relatados, o programa é fechado com erro */
    else{
        return 1;
    }

    /* Imprime o vetor com os valores ordenados (output) */
    for(int i = 0; i < vectorSize; i++){
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}
