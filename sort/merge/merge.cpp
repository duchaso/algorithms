#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

template<typename T>
void print_vector(vector<T>& v)
{
    for(const auto& i : v)
        cout << i << '\n';
    cout << '\n';
}

template<typename T>
void merge(vector<T>& array, int left, int mid, int right)
{
    auto const size_of_fisrt_subarray = mid - left + 1;
    auto const size_of_second_subarray = right - mid;
    
    vector<T> first_temp_array;
    vector<T> second_temp_array;

    for(int i = 0; i < size_of_fisrt_subarray; ++i)
    {
        first_temp_array.push_back(array[left+i]);
        second_temp_array.push_back(array[mid+1+i]);
    }

    int index_of_first_subarray{0};
    int index_of_second_subarray{0};
    int index_of_merge{left};

    while(index_of_first_subarray < size_of_fisrt_subarray && index_of_second_subarray < size_of_second_subarray)
    {
        if(first_temp_array[index_of_first_subarray]<second_temp_array[index_of_second_subarray])
        {
            array[index_of_merge] = first_temp_array[index_of_first_subarray];
            ++index_of_first_subarray;
        } else {
            array[index_of_merge] = second_temp_array[index_of_second_subarray];
            ++index_of_second_subarray;
        }
        ++index_of_merge;
    }

    while(index_of_first_subarray < size_of_fisrt_subarray)
    {
        array[index_of_merge++] = first_temp_array[index_of_first_subarray++];
    }
    while(index_of_second_subarray < size_of_second_subarray)
    {
        array[index_of_merge++] = second_temp_array[index_of_second_subarray++];
    }
}

template<typename T>
void merge_sort(vector<T>& v, int begin, int end)
{
    if(begin >= end) return;
    
    auto mid = begin + (end-begin)/2;

    merge_sort(v, begin, mid);
    merge_sort(v, mid+1, end);
    
    merge(v, begin, mid, end);
}

int main()
{
    srand(unsigned(std::time(nullptr)));
    vector<int> v(10000);
    generate(v.begin(), v.end(), std::rand);

    auto start = high_resolution_clock::now();
    merge_sort(v, 0, v.size()-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << '\n';
    
}