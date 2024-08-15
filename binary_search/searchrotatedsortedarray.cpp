#include<iostream>
#include<vector>

// []{}

int searchFunc(std::vector<int> &nums, int target) {
    
    int low=0,high=nums.size()-1;
    int mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (nums[mid]==target)
        {
            return mid;
        }
        if (nums[mid] <= nums[high])
        {
            if (nums[mid] <= target && nums[high] >= target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        else
        {
            if (nums[mid] >= target && nums[low] <= target)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
    
}

int main()
{
    std::vector<int> nums;
    int n,temp,target;
    std::cin>>n;
    for (int i = 0; i < n; i++)
    {
        std::cin>>temp;
        nums.push_back(temp);
    }
    std::cin>>target;
    std::cout<<target<<" found at: "<<searchFunc(nums,target);
    
    return 0;
}
