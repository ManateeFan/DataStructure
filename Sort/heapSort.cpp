#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void maxHeapify(vector<T>& A, int i)
{
    int left = i * 2;
    int right = left + 1;
    int lagest = 0;
    if (A.size() > left && A[left] > A[i])
    {
        lagest = left;
    }
    else
    {
        lagest = i;
    }
    if (A.size() > right && A[right] > A[lagest])
    {
        lagest = right;
    }

    if (lagest != i)
    {
        swap(A[i], A[lagest]);
        maxHeapify(A, lagest);
    }

}

template<typename T>
void buildMaxHeap(vector<T>& A)
{
    for (int i = (A.size() + 1) / 2; i >= 1; i--)
    {
        maxHeapify(A, i);
    }
}
int main()
{
    vector<int> nums = { 0, 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
    maxHeapify(nums, 2);
    buildMaxHeap(nums);
    for (auto n : nums)
    {
        cout << n << std::endl;
    }
}