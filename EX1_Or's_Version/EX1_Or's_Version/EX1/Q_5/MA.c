#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int max(int a, int b);
int MaxSubN3(int *array, size_t length);
int MaxSubN2(int *array, size_t length);
int MaxSubN(int *array, size_t length);


int max(int a, int b){
    return (a > b) ? a : b;
}

int MaxSubN3(int *array,size_t length){

    int maxSum = INT_MIN;


    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = i; j < length; j++)
        {
            int currSum = 0;
            for (size_t k = i; k <= j; k++)
            {
                currSum += array[k];

                if (maxSum < currSum)
                {
                    maxSum = currSum;
                }
                
            }
            
        }
        
    }

    return maxSum;
    
}


int MaxSubN2(int *array, size_t length){

    int maxSum = INT_MIN;

    for (size_t i = 0; i < length; i++)
    {
        int currSum = 0;
        for (size_t j = i; j < length; j++)
        {
            currSum += array[j];
            if (maxSum < currSum)
            {
                maxSum = currSum;
            }
            
        }
        
    }

    return maxSum;
    
}

int MaxSubN(int *array,size_t length){
  int currSum = array[0];
  int MaxSum = array[0];


  for (size_t i = 1; i < length; i++)
  {
      currSum = max(array[i],currSum + array[i]);
      MaxSum = max(MaxSum, currSum);
  }


  return MaxSum;
  
}


void printArr(int *array,size_t length){
    printf("[");
    for (size_t i = 0; i < length; i++)
    {
        if (i != length - 1)
        {
            printf("%d ,",array[i]);
        }
        else
        printf("%d",array[i]);
        
    }
    printf("]");
    
}

int main(int argc,char *argv[]){

    if (argc < 3)
    {
    fprintf(stderr,"Usage: %s <seed> <size>\n",argv[0]);
    exit(1);
    }

    int seed = atoi(argv[1]);
    size_t size = atoi(argv[2]);


    srand(seed);


    int *nums = (int *)malloc(sizeof(int) * size);

    if (!nums)
    {
        fprintf(stderr,"Memory Allocation failed.\nExiting...");
        exit(1);
    }
    

    for (size_t i = 0; i < size; i++)
    {
        nums[i] = -25 + rand() % (75- (-25) + 1);
    }


   volatile int  n = MaxSubN(nums,size);
   volatile int n2 = MaxSubN2(nums,size);
   volatile int n3 = MaxSubN3(nums,size);

    printf("\n");
    printf("O(n) Function result of nums:%d\n",n);
    printf("O(n^2) Function result of nums:%d\n",n2);
    printf("O(n^3) Function result of nums:%d\n",n3);

    
    free(nums);
    return 0;
}