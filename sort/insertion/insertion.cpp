#include <iostream>
#include <utility>
#include <chrono>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::chrono;

template<typename T>
void insertion_sort(vector<T>& arr)
{
    for(int i = 1; i < arr.size(); ++i)
    {
        for(int j = i; j > 0; --j)
        {
            if(arr[j]<arr[j-1])
                swap(arr[j], arr[j-1]);
        }
    }
}

template<typename T>
void print_array(vector<T>& arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main()
{
	srand(unsigned(std::time(nullptr)));
    vector<int> v(10000);  
    generate(v.begin(), v.end(), std::rand);

    auto start = high_resolution_clock::now();
    insertion_sort(v);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << '\n';
}
