#include "search.h"

// Linear search
template <typename T>
SearchResultType <T> linear_search(const std::vector<T> &list, const T &value)
{
	long n = list.size()-1;
	long i = 0;
	T results;
	for (i = 0; i <= n; i++)
		if (list[i] == value)
		{
			results = list.at(i);
			return SearchResultType<T>(true, results, i);
			//This runs through each item in a vector and checks if it is the value it is searching for
			//It then returns true and the value, as well as the point in the vector
		}
	i = i - 1;
	results = list.at(i);
	return SearchResultType<T>(false, results, i);
}

//Iterative search
template <typename T>
SearchResultType<T> iterative_binary_search(const std::vector<T> &list,const T &value)
{	
	long right = list.size() - 1;
	long left = 0;
	long middle = left + (right - left) / 2;
	T result;
	if (right == -1)
	{
		return SearchResultType<T>(true, result, middle);
	}
  while (left <= right)
  {
    middle = left + (right-left)/2;
 
    // Check if value is present at middle
	if (list[middle] == value)
	{
		result = list.at(middle);
		return SearchResultType<T>(true, result, middle);
	}
    // If value is greater, ignore left half  
	if (list[middle] < value)
		left = middle + 1;
	
 
    // If value is smaller, ignore right half 
    else
         right = middle - 1; 
  }
 
  // if we reach here, then element was not present
  result = list.at(middle);
  return SearchResultType<T>(false, result, middle);
}

//Recursive search
template <typename T>
SearchResultType<T> recursive_binary_search(const std::vector<T> &list,const T &value)
{
	//This sets the starting values of the arguments, then returns the value from the helper function
	long l = 0;
	long r = list.size()-1;
	return recursiveHelper(list, l, r, value);
}

template <typename T>
SearchResultType<T> recursiveHelper(const std::vector<T> &list, long l, long r, const T &value)
{
	
	long mid;
	mid = l + (r - l) / 2;
	T result;
	if (r > l)
	{
		mid = l + (r - l) / 2;
		// If the element is present at the middle itself
		if (list[mid] == value)
		{
			result = list.at(mid);
			return SearchResultType<T>(true, result, mid);
		}

		// If element is smaller than mid, then it can only be present
		// in left subarray
		else if (list[mid] > value)
			return recursiveHelper(list, l, mid - 1, value);


		// Else the element can only be present in right subarray
		else
			return recursiveHelper(list, mid + 1, r, value);
	}

	// We reach here when element is not present in array
	result = list.at(mid);
	if (value != result) return SearchResultType<T>(false, result, mid);
	else return SearchResultType<T>(true, result, mid);
	
}