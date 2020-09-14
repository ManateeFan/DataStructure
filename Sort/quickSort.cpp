#include <iostream>
#include <vector>

using namespace std;


int partital(vector<int>& nums, int left, int right)
{
    int key = nums[left];
    int i = left;
    for(int j = left+1;  j <= right; j++)
    {
        if(nums[j] <= key)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i], nums[left]);
    return i;
}

void quickSort(vector<int>& nums, int left, int right)
{
    if(left < right)
    {
        auto mid = partital(nums, left, right);
        quickSort(nums, left, mid);
        quickSort(nums, mid+1, right);
    }
}
int main()
{
    std::vector<int> v{ 5, 4, 3, 2, 1 };

    quickSort(v, 0, v.size()-1);

    for (auto num : v)
        std::cout << num << " ";
}