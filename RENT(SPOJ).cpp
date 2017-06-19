//http://www.spoj.com/problems/RENT/
//Rent your Airplanes and make money 
//https://www.commonlounge.com/discussion/67af185dc42d44bfbd12983c46677c34/all/cc4141e92a454ff581bff2415afeec37
// ^The above link provides a good editorial by Himanshu Jaju with stepwise hints 

#include <bits/stdc++.h>
#define ll long long 

using namespace std;

struct yo
{
    ll start , end , profit;
};
int compare(yo a , yo b)
{
    if(a.start == b.start)      return a.end < b.end;
    return a.start < b.start;
}
int bsearch(struct yo a[] , int i , int n)
{
    //binary search to find the next index whose
    //start value is greater than the end value 
    //of the ith interval
    int low = i + 1 , high = n - 1;
    int ans = high , mid;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        if(a[mid].start > a[i].end)
        {
            ans = min(ans , mid);
            high = mid - 1;
        }
        else    low = mid + 1;
    }
    if(a[ans].start < a[i].end)  return -1;
    return ans;
}
int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
    int T;cin >> T;
    while(T--)
    {
        int n;cin >> n;
        struct yo a[n];
        for(int i = 0;i < n;i++)
        {
            cin >> a[i].start >> a[i].end >> a[i].profit;
            a[i].end = a[i].start + a[i].end - 1;
        }
        sort(a , a + n , compare);
        vector<ll>dp(n);
        fill(dp.begin() , dp.end() , 0);
        dp[n - 1] = a[n - 1].profit;
        for(int i = n - 2;i >= 0;i--)
        {
            int next = bsearch(a , i , n);
            //searching for next disjoint interval
            if(next == -1)  dp[i] = max(dp[i + 1] , a[i].profit);
            // ^ no next disjoint interval present
            else            dp[i] = max(dp[i + 1] , a[i].profit + dp[next]);
        }
        cout << dp[0] << "\n";
    }
}
//tags - weighted job scheduling , binary search , dynamic programming
//Overall Complexity - O(n * log n)
