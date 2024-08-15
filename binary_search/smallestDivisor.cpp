#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


bool solve(std::vector<int> &nums, int k, int div)
{
    int tot = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // cout<<(int)ceil(nums.at(i)/(float)div)<<'\n';
        tot += (int)ceil(nums.at(i) / (double)div);
        if (tot > k)
            return false;
    }
    return true;
}
int smallestDivisor(std::vector<int> &nums, int K)
{

    // Write your code here. {}
    if (nums.size() == 1)
        return (int)ceil(nums.at(0) / (double)K);
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (solve(nums, K, mid))
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}

int main(int argc, char const *argv[])
{
    std::vector<int> nums;
    int n, temp, M, K;
    std::cin >> n >> K;    
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        nums.push_back(temp);
    }

    std::cout << smallestDivisor(nums,K);

    return 0;
}