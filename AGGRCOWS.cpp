    //http://www.spoj.com/problems/AGGRCOW/
	
	#include <bits/stdc++.h>
    #define ll long long 
     
    using namespace std;
     
    bool check(vector<ll int>a , ll int m ,ll int n , ll int COWS)
    {
        ll int cows = 1 , prev = a[0];
        for(int i = 1;i < n;i++) 
        {
            if(a[i] - prev >= m)
            {
                prev = a[i];
                cows++;
            }
        }
        return (cows >= COWS); 
    }
    int main() 
    {
        std::ios::sync_with_stdio(0);
       int T;cin  >> T;
       while(T--)
       {
           ll int n , c;
           cin >> n >> c;
           vector<ll int>a(n);
           for(int i = 0;i < n;i++)     cin >> a[i];
           sort(a.begin() , a.end());
           
           ll int low = 1 , high = a[n - 1] , mid , ans = 0;
           while(low <= high)
           {
               mid = (low + high) / 2;//cout << mid << "\n";
               bool ok = check(a , mid , n , c);
               if(ok)
               {
                   ans = max(ans , mid);
                   low = mid + 1;
               }
               else     high = mid - 1;
           }
           cout << ans << "\n";
       }
    } 
    //tags : Binary Search , Implementation
    //Complexity : O(n * log n)
