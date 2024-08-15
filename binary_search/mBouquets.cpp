#include<iostream>
#include<vector>
#include<algorithm>


bool totalPossible(int K, int M, std::vector<int> &bloomDay, int day)
{
    int total = 0;
    int cnt = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay.at(i) <= day)
            cnt++;
        else
        {
            total += cnt / K;
            cnt = 0;
            if (total >= M)
                return true;
        }
    }
    total += cnt / K;
    return (total >= M);
}
int solve(int M, int K, std::vector<int> &bloomDay)
{
    // Code here{}
    if (bloomDay.size() < M * K)
        return -1;
    int low = *std::min_element(bloomDay.begin(), bloomDay.end());
    int high = *std::max_element(bloomDay.begin(), bloomDay.end());
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (totalPossible(K, M, bloomDay, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main(int argc, char const *argv[])
{
    std::vector<int> bloomDay;
    int n,temp,M,K;
    std::cin>>M>>K;
    std::cin>>n;
    for (int i = 0; i < n; i++)
    {
        std::cin>>temp;
        bloomDay.push_back(temp);
    }

    std::cout<<solve(M,K,bloomDay);
    
    return 0;
}
