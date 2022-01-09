#include <stdio.h>

void insertion_sort(int s[], int n);
void swap(int *a, int *b);
void print_arr(int arr[], int arr_sz);

int main()
{
	int arr[] = {4,1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	print_arr(arr, n);
	insertion_sort(arr, n);
	print_arr(arr, n);
	return 0;
}

void insertion_sort(int s[], int n)
{
	int j = 0;	
	for(int i = 1; i < n; i++)
	{
		j = i;
		while((j > 0) && (s[j] < s[j-1]))
		{
			swap(&s[j], &s[j-1]);		
			--j;
		}
	}
}
void swap(int *a, int *b)
{
	int buf = *a;
	*a = *b;
	*b = buf;
}
void print_arr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
