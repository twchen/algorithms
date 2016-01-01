#include <iostream>
using namespace std;

// return the kth smallest element in the list
int quickSelect(int *list, int start, int end, int k)
{
	int pivot = partition(list, start, end);
	int index = start + k - 1; // index of the kth smallest element
	if(pivot == index)
		return list[pivot];
	if(pivot < index)
		return quickSelect(list, pivot + 1, end, index - pivot);
	return quickSelect(list, start, pivot - 1, k);
}

int partition(int *list, start, end)
{
	int pivotValue = list[end];
	int left = start, right = end - 1;
	while(left < right){
		while(list[left++] <= pivotValue);
		while(list[right--] >= pivotValue);
		if(left < right){
			int temp = list[left];
			list[left] = list[right];
			list[right] = list[left];
			left++;
			right--;
		}
		else{
			list[end] = list[left];
			list[left] = pivotValue;
			return left;
		}
	}
}