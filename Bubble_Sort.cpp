//Bubble Sort

//Bubble sort is one of the simplest sorting algorithms. It is a stable sort algorithm. </br>
//The program for bubble sort is C++ is as follows :

#include <iostream>
using namespace std;

int main() 
{
    //Enter number of elements in the array
	int n;
	cin>>n;
	int nums[n];
	//Enter the numbers to be sorted
	for(int i=0;i<n;i++)
	    cin>>nums[i];
	//Bubble Sort
	for(int i=0;i<n-1;i++)
	{
	    for(int j=0;j<n-i-1;j++)
	    {
	        if(nums[j] > nums[j+1])
	        {
	            int temp = nums[j];
	            nums[j] = nums[j+1];
	            nums[j+1] = temp;
	        }
	    }
	}
	cout<<"Sorted numbers are :\n";
	for(int i=0;i<n;i++)
	    cout<<nums[i]<<" ";
	return 0;
}

//Time Complexity: O(n^2)
//Auxiliary Space: O(1)

//Example:
//Input: n=5 , nums[] = {2, 7, 4, 10, 1}
//Output: nums[] = {1, 2, 4, 7, 10}