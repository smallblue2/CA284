#include<stdio.h>
#include<stdlib.h>

void findDuplicate(int *a, int length, int* result, int *lengthResult);
void printArray(int *a, int length);
void swap(int *a, int *b);
void bsort(int *a, int length);

int main(int argc, char*argv[])
{
    int capacity = 5;
    int* data = (int*)calloc(capacity, sizeof(int));
    int *temp;
    int count = 0;

    while(count < capacity){
        if(count + 1 == capacity){
            if(capacity < argc - 1){
                capacity += 1;
                temp = (int*)realloc(data, capacity*sizeof(int));
                data = temp;
            }
        }
        *(data + count) = atoi(argv[count+1]);
        ++count;
    }
    int *foundDuplicate = (int*)calloc(1, sizeof(int));
    int length = 0;

    findDuplicate(data, count, foundDuplicate, &length);
    bsort(foundDuplicate, length);
    printArray(foundDuplicate, length);

    return 0;
}

void findDuplicate(int *a, int length, int* result, int *lengthResult){

    int *temp;
    int countDuplicateElement;
    int countFoundNumber = 0;

    for(int i = 0; i < length; ++i){
        countDuplicateElement = 1;
        for(int j = 0; j < length; ++j){
            if(i != j){
                if(*(a + i) == *(a + j)){
                    countDuplicateElement++;
                }
            }
        }

        if(countDuplicateElement > 3){
            countFoundNumber++;
            result = (int*)realloc(result, countFoundNumber*sizeof(int));
            *(result + countFoundNumber - 1) = *(a+i);
        }
    }
    *lengthResult = countFoundNumber;
}

void printArray(int *a, int length){
    for(int i = 0; i < length; ++i){
        printf("%d\n", *(a + i));
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bsort(int *a, int length){
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
}
