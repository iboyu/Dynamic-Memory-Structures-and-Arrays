#include<stdio.h>
#include<stdlib.h>
#define size 40

int comp(const void* p1, const void* p2){
    int element1 = *(const int*)p1;
    int element2 = *(const int*)p2;

    if(element1 > element2) return 1;
    if(element1 < element2) return -1;
    return 0;
}


int main(){

    char inbuf[size];
    int numOfElements, *p, i;

    printf("How many numbers would you like to create? \n");
    fgets(inbuf, size, stdin);
    sscanf(inbuf, "%d", &numOfElements);

    p = (int *)malloc(numOfElements * sizeof(int));

if(p == NULL){
    exit(-1);
}
    for(i = 0; i < numOfElements; i++){
        printf("Please enter the number %d\n", i+1);
        fgets(inbuf, size, stdin);
        sscanf(inbuf, "%d", &p[i]);
    }
    

    printf("Original array: \n");
    for(i = 0; i < numOfElements; i++){
        printf("%d\t",p[i]);
    }
    printf("\n");

    qsort(p, numOfElements, sizeof(int), comp);

    printf("Sorted array: \n");
    for(i = 0; i < numOfElements; i++){
        printf("%d\t",p[i]);
    }
    printf("\n");

    free(p);
    return 0;
}