#include <stdlib.h>
#include <stdio.h>
typedef enum{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
} Directions;


typedef struct{
    int x;
    int y;
    Directions direction;
}Partical;

Partical* createPartical(int x, int y, Directions direction){
    Partical* p = (Partical*)malloc(sizeof(Partical));
    p->x = x;
    p->y = y;
    p->direction = direction;
    return p;
}
void addParticalToVector(Partical** particals, Partical* p){
    ++particals;
    particals = (Partical**) realloc(particals, sizeof(Partical*)+1);
    particals = p;

}



void insertionSort(Partical **arr, int n)
{
    for (int i = 1; i < n; ++i) {
        Partical* key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j]->x > key->x || (arr[j]->x == key->x && arr[j]->y > key->y)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void movePartical(Partical* p){
    if(p->direction==UP){
        p->y--;
    } else if (p->direction==DOWN)
    {
        p->y++;
    }
    else if (p->direction==LEFT){
        p->x--;
    }
    else if (p->direction==RIGHT){
        p->x++;
    }
}
void removeDuplicates(Partical **arr, int n) {
    if (n <= 1)
        return n;
    
    int idx = 1;
    int newParticalCount = 0;
    Partical **newParticals= (Partical **)malloc(sizeof( Partical *));
    for (int i = 1; i < n; i++) {
        if (arr[i]->x == arr[i - 1]->x && arr[i]->y == arr[i - 1]->y) {
            arr[idx] = arr[i];
            if(arr[idx]->direction==NONE){
                newParticalCount = (Partical **)realloc(newParticals, sizeof(Partical *)+4);
                newParticals[newParticalCount++] = createPartical(arr[i]->x, arr[i]->y, UP);
                newParticals[newParticalCount++] = createPartical(arr[i]->x, arr[i]->y, DOWN);
                newParticals[newParticalCount++] = createPartical(arr[i]->x, arr[i]->y, LEFT);
                newParticals[newParticalCount++] = createPartical(arr[i]->x, arr[i]->y, RIGHT);
                newParticalCount+=4;
            }
            idx++;
        }
    }
    arr = realloc(arr, n * sizeof(Partical)-idx+newParticalCount);
    for (int i = idx,j = 0; j < newParticalCount; i++,j++){
        arr[i] = newParticals[j];
    }

}

void frameUpdate(Partical** particals,int n){
    for (int i = 0; i < n; i++)
    {
        movePartical(particals[i]);
    }
    insertionSort(particals, n); 
    removeDuplicates(particals, n);
    
}


int main(){
    int a = 1;
    long b;
    b = (long) a;
    printf("%lo",b);

    return 0;
}

