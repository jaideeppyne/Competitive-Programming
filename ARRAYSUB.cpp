//http://www.spoj.com/problems/ARRAYSUB/

#include<bits/stdc++.h>
#define ll long long
     
using namespace std;
    
int main()
{
    std::ios::sync_with_stdio(0);cin.tie(0);
    int n , k;cin >> n;
    vector<ll>a(n);
    for(int i = 0;i < n;i++)    cin >> a[i];cin >> k;
        
    deque<pair<ll , ll> >dq;                //SLIDING WINDOW TECHNIQUE - O(n)
    for(int i = 0;i < k;i++)
    {
        while(!(dq.empty()) && dq.back().first <= a[i])     dq.pop_back();
        dq.push_back({a[i] , i});     //elements arranged in decreasing order[always inside the deque]
    }
    cout << dq[0].first << " ";       //maximum element in first sliding window
    
    for(int i = k;i < n;i++)
    {
        while(!(dq.empty()) && dq.back().first <= a[i])     dq.pop_back();
        dq.push_back({a[i] , i});
        while(dq.front().second <= i - k)    dq.pop_front();//elements in range[i - k + 1 , k]inside sliding window
        
        cout << dq[0].first << " ";   //sliding window maximum for ith window 
    }
} 

//tags - sliding window , implementation
//Complexity : O(n)
