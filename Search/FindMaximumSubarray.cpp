#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

auto findMaximuxCrossingSubarray(const vector<int>& nums, int left, int mid, int right)
{
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left;

    for (int i = mid; i >= left; i--)
    {
        sum += nums[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right;

    for (int i = mid + 1; i <= right; i++)
    {
        sum += nums[i];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }

    return make_tuple(max_left, max_right, left_sum + right_sum);
}

auto findMaximumSubarray(const vector<int>& nums, int left, int right)
{
    if (left == right)
    {
        return make_tuple(left, left, nums[left]);
    }
    auto mid = left + (right - left) / 2;
    auto [left_low, left_high, left_sum] = findMaximumSubarray(nums, left, mid);
    auto [right_low, right_high, right_sum] = findMaximumSubarray(nums, mid + 1, right);
    auto [cross_low, cross_high, cross_sum] = findMaximuxCrossingSubarray(nums, left, mid, right);

    if (left_sum >= right_sum && left_sum >= cross_sum)
    {
        return make_tuple(left_low, left_high, left_sum);
    }
    else if (right_sum >= left_sum && right_sum >= cross_sum)
    {
        return make_tuple(right_low, right_high, right_sum);
    }
    else
    {
        return make_tuple(cross_low, cross_high, cross_sum);
    }
}

int main()
{
    vector<int> nums{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -4, -22, 15, -4, 7 };
    //18 20 -7 12
    auto [a, b, c] = findMaximumSubarray(nums, 0, 15);
}