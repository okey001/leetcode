#include "a.h"

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}


template<typename T>
int partition(T *a, int left, int right){
    if (left >= right){return left;}
    int i = left, j = right, t = a[left];
    while(i < j){
        while(a[j] > t) j--;
        if (i < j) a[i++] = a[j];
        while(a[i] < t) i++;
        if (i < j) a[j--] = a[i];
    }
    a[i] = t;
    return i;
}

template<typename T>
void qsort(T *a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int i = partition(a, left, right);
    qsort(a, left, i - 1);
    qsort(a, i + 1, right);
}

template<typename T>
void heapify(T *a, int n, int i){
    while(i< n){
        int maxIndex = i;
        int left = i * 2 + 1, right = i * 2 + 2;
        if (left < n && a[left] > a[maxIndex]){
            maxIndex = left;
        }
        if (right < n && a[right] > a[maxIndex]){
            maxIndex = right;
        }
        if (maxIndex != i){
            swap(a[i], a[maxIndex]);
            i = maxIndex;
        }
        else{
            break;
        }
    }
}

template<typename T>
void makeHeap(T *a, int n){
    for (int i = n / 2; i >= 0; i--){
        heapify(a, n, i);
    }
}

template<typename T>
void heapSort(T *a, int n){
    makeHeap(a, n);
    for (int i = n - 1; i > 0; i--){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}


template<typename T>
void mergeSort(T *a, int left, int right, T *b){
    if (left >= right) return;
    int middle = (left + right) / 2;
    mergeSort(a, left, middle, b);
    mergeSort(a, middle + 1, right, b);
    int i = left, j = middle + 1;
    for(int k = left; k <= right; k++){
        if (j > right || i <= middle && a[i] < a[j]){
            b[k] = a[i++];
        }
        else{
            b[k] = a[j++];
        }
    }
    for(int k = left; k <= right; k++){
        a[k] = b[k];
    }
}


template void qsort(int *a, int left, int right);
template void qsort(float *a, int left, int right);