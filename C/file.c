#include <stdio.h>
#define N 6

void merge(int arr[], int first, int last);
void mergeSort(int arr[], int start, int end);
void quickSort(int arr[], int low , int high);
int partition(int arr[], int low, int high);

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}

void merge(int arr[], int first, int last) {
    int temp[N]; 
    int i, j, k;
    int mid = (first + last) / 2;
    for (i = first; i <= last; i++)
        temp[i] = arr[i];
    k = first;
    i = first;
    j = mid + 1;
    while (i <= mid && j <= last) {
        if (temp[i] < temp[j])
            arr[k++] = temp[i++];
        else
            arr[k++] = temp[j++];
    }
    while (i <= mid)
        arr[k++] = temp[i++];
    while (j <= last)
        arr[k++] = temp[j++];
}

void quickSort(int arr[], int low , int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(int arr[], int low, int high) {
    
    int pivot = arr[high];
    int i = low - 1;
    int tmp;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
        tmp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = tmp;
    return (i + 1);

}
