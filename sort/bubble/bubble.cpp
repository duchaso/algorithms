#include <iostream>
#include <utility>

using namespace std;

template<typename T>
void print_array(T arr[], int n);

template<typename T>
void bubble_sort(T arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        bool swapped = false;
        for(int j = 0; j < n-i-1; ++j)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
	    print_array(arr, n);
        }
        if(swapped) return;
    }
}

template<typename T>
void print_array(T arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    int arr[] = {5,4,3,2,1};
    int n = 5;

    char arr1[] = {'b', 'a', 'd', 'c', 'e'};
    int n1 = 5;

    bubble_sort(arr, n);
    print_array(arr, n);

    bubble_sort(arr1, n1);
    print_array(arr1, n1);
}
