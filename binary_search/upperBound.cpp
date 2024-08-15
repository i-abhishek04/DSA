#include <iostream>
#include <vector>

// []{}

int upperbound(std::vector<int> &arr, int target)
{
    int low = 0, ans = arr.size(), high = ans - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    std::vector<int> arr;
    int n, temp, target;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        arr.push_back(temp);
    }
    std::cin >> target;
    std::cout << (upperbound(arr, target)) << "\n";
    return 0;
}