#include <stdio.h>
#include <stdlib.h>
#define ROW 4
#define COL 5
int upperCaseFirstLetterList(char** words,int numWords);
void createArrFromInput(double * arr, int n);
void printBackwards(double * arr, int n);
int main(){
    
        userArr();
    return 0;
}

int upperCaseFirstLetterList(char** words,int numWords){
    int i;
    char *word;
    for(i = 0;i < numWords; i++){
        word = *(words+1);
        if(*word >= 'a' && *word <= 'z'){
            *word -= 'a'-'A';
        }
    }
    return 0;
}   

void createArrFromInput(double * arr, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Enter element %d: \n", i+1);
        scanf("%lf", arr+i);
    }
}
void printBackwards(double * arr, int n){
    int i;
    for(i = n-1; i >= 0; i--){
        printf("%.2lf ", arr[i]);
    }
}

void userArr(){
    int n, randN;
    int *arr , *randArr;
    printf("enter Array size: \n");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: \n", i+1);
        scanf("%d", arr+i);
    }
    randN = rand()%9;
    randArr = (int*)malloc(randN*sizeof(int));
    for (int i = 0; i < randN; i++)
    {
        if(*(arr+i) == rand()%9)
        *(randArr+i) = rand()%9;
        
    }
    printf("Your array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr+i));
    }
    printf("\nRandom array is: \n");
    for (int i = 0; i < randN; i++)
    {
        printf("%d ", *(randArr+i));
    }
    free(arr);
    free(randArr);

    
}
void howMuchCharInString(char *str, char ch){
    int count = 0;
    while (*str!= '\0'){
        if (*str == ch){
            count++;
        }
        str++;
    }
    printf("The character '%c' appears %d times in the string\n", ch, count);
}

int* arrMerge(int* arr1,int* arr2){
    int size1 = sizeof(arr1)/sizeof(int) ,size2 = sizeof(arr2)/sizeof(int) , n = 0;
    int *newArr;
    for (size_t i = 0; i < size1+size2; i++)
    {
        if(*arr1>*arr2 && arr2 != NULL && *newArr!= *arr1 && *newArr!=*arr2){
            newArr = realloc(newArr, (n+1)*sizeof(int));
            *(newArr+n) = *arr2;
            arr2++;
            n++;

        }else if(*arr1<*arr2 &&arr2 != NULL && *newArr!= *arr1 && *newArr!=*arr2){
            newArr = realloc(newArr, (n+1)*sizeof(int));
            *(newArr+n) = *arr2;
            arr1++;
            n++;
        }else{
            arr1++;
            arr2++;
        }
    }
    


}