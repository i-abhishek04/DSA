#include<vector>
#include<iostream>

int findPeakElement(std::vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    int low = 0, high = nums.size() - 1;
    if (nums.at(low) > nums.at(low + 1))
        return low;
    if (nums.at(high) > nums.at(high - 1))
        return high;
    low++, high--;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        if (nums[mid] <= nums[mid - 1])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums;
    int n,temp;
    std::cin>>n;
    for (int i = 0; i < n; i++)
    {
        std::cin>>temp;
        nums.push_back(temp);
    }
    std::cout<<findPeakElement(nums);//returns index of peak element
    
    return 0;
}
