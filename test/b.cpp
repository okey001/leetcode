#include <iostream>
#include <vector>
#include <random>
#include "a.cpp"
const int n = 100000;
std::vector<int> a(n);
std::vector<int> b(n);
int main(int argc, char **argv)
{
    for (int i = 0; i < n; i++){
        a[i] = rand();
    }
    mergeSort(a.data(), 0, n-1, b.data());
    qsort(a.data(), 0, n-1);
    heapSort(a.data(), n);
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            std::cout << "Error:" << a[i - 1] << "__" << a[i] << std::endl;
        }
        else{
            //std::cout << a[i] << std::endl;
        }
    }
    return 0;
}