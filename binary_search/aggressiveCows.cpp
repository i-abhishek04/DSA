#include<iostream>
#include<vector>
#include<algorithm>

bool possible(std::vector<int> &pos, const int &n, const int &k, int gap)
{
    int cntcow = 1, last = pos.at(0);

    for (int i = 1; i < n; i++)
    {
        if (pos.at(i) - last >= gap)
        {
            cntcow++;
            last = pos.at(i);
            if (cntcow == k)
                return true;
        }
    }
    return false;
}

int solve(int n, int k, std::vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = (stalls.at(n - 1) - stalls.at(0)) / (k - 1);
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (possible(stalls, n, k, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
   
}

int main(int argc, char const *argv[])
{
    std::vector<int> stalls;
    int n,k,temp;
    std::cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        std::cin>>temp;
        stalls.push_back(temp);
    }
    std::cout<<solve(n,k,stalls);
    
    return 0;
}
