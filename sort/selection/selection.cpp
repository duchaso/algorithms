#include <iostream>
#include <utility>

using namespace std;

/* BRIEF EXPLANATION
We itarate through array and find min element, swap this element with first
then we iterate through subarray without first min element we already swap

Example( | <- this is our i in iteration and numbers we iterate through j in second iteration ):
    | 3 2 4 1
    1 | 2 4 3
    1 2 | 4 3
    1 2 3 | 4
    1 2 3 4 |

Time complexity for this sort is ___N^2___ cause we have two loops

Also i make it with template so u can use whatever type u want that can be compare

*/

template<typename T>
void selection_sort(T arr[], int n)
{
    int min_index{0};

    for(int i = 0; i < n; i++)
    {
        min_index = i;
        for(int j = i; j < n; j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

template<typename T>
void print_array(T arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main()
{
    int arr[] = {5,4,3,2,1};
    int n = 5;

    double arr1[] = {1.4, 51.2, -2, 0};
    int n1 = 4;

    char arr2[] = {'d', 'c', 'b', 'a'};
    int n2 = 4;


    selection_sort(arr, n);
    print_array(arr, n);

    selection_sort(arr1, n1);
    print_array(arr1, n1);

    selection_sort(arr2, n2);
    print_array(arr2, n2);
}