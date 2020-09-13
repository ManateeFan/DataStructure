#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& nums, int left, int right, int target)
{
	while (left <= right)
	{
		auto mid = left + (right - left) / 2;
		if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else if (nums[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{

}