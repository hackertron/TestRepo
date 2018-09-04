#include "FindTriplet.h"
#include <algorithm>
#include <iostream>

FindTriplet::FindTriplet()
{
}

std::vector<float>  FindTriplet::find_triplet(std::vector<float> arr, int array_size, float sum)
{
	int left, right;

	/* Sort the elements */
	std::sort(arr.begin(), arr.end());

	/* Now fix the first element one by one and find the
	other two elements */
	for (int i = 0; i < array_size - 2; i++) {

		// To find the other two elements, start two index
		// variables from two corners of the array and move
		// them toward each other
		left = i + 1; // index of the first element in the
					  // remaining elements

		right = array_size - 1; // index of the last element
		while (left < right) {
			if (arr[i] + arr[left] + arr[right] == sum) {
				std::cout<<"Triplet is "<<arr[i]<<" "<<arr[left]<<" "<<arr[right];
				std::vector<float> triplet_vector{ arr[i], arr[left], arr[right] };
				return triplet_vector;
			}
			else if (arr[i] + arr[left] + arr[right] < sum)
				left++;
			else // A[i] + A[l] + A[r] > sum
				right--;
		}
	}

	// If we reach here, then no triplet was found
	std::vector<float> no_triplet;
	return no_triplet;
}



FindTriplet::~FindTriplet()
{
}
