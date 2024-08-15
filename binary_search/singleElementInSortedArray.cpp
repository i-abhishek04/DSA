#include<iostream>
#include<vector>

int singleNonDuplicate(std::vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    int low = 0, high = nums.size() - 1;
    int mid;
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[high] != nums[high - 1])
        return nums[high];
    low++, high--;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];
        if (mid % 2 == 0)
        {
            if (nums[mid] == nums[mid - 1])
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
    }
    return nums[mid];
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums;
    int n, temp;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        nums.push_back(temp);
    }
    std::cout << singleNonDuplicate(nums); // returns the single element in array

    return 0;
}