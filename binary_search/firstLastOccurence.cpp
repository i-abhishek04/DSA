#include <iostream>
#include <vector>

// []{}

int lowerbound(std::vector<int> &arr, int target)
{
    int low = 0, ans = arr.size(), high = ans - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

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
    int ub = upperbound(arr, target);
    int lb = lowerbound(arr, target);
    if (ub == lb)
        std::cout << "element not present\n";
    else
    {
        std::cout << "first occurence: " << lb << "\n";
        std::cout << "last occurence: " << ub - 1 << "\n";
    }

    std::cout << "total occurences: " << ub - lb << "\n";
    return 0;
}