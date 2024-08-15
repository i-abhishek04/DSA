#include<iostream>

#include<algorithm>
#include<numeric>

bool possible(int arr[], int n, int d, int wt)
{
    int cnt = 0;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += arr[i];
        if (tot > wt)
        {
            tot = arr[i];
            cnt++;
            if (cnt > d)
                return false;
        }
    }
    if (++cnt > d)
        return false;

    return true;
}
int leastWeightCapacity(int arr[], int n, int d)
{
    // code here  {}
    int low = *std::max_element(arr, arr + n);
    int high = std::accumulate(arr, arr + n, 0);
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (possible(arr, n, d, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main(int argc, char const *argv[])
{
    int n,d;
    std::cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cin>>d;
    std::cout<<leastWeightCapacity(arr,n,d);
    
    return 0;
}
