    //http://www.spoj.com/problems/EDIST/
	
	#include<bits/stdc++.h>
    #define ll long long 
     
    using namespace std;
     
    int main()
    {
        std::ios::sync_with_stdio(0);cin.tie(0);
        int T;cin >> T;
        while(T--)  
        {
            string a , b;cin >> a >> b;
            vector<vector<int> >dp(a.length() + 1 , vector<int>(b.length() + 1 , 0));
            for(int i = 1;i <= b.length();i++)  dp[0][i] = i;
            for(int i = 1;i <= a.length();i++)  dp[i][0] = i;
            
            int ans = 0;
            for(int i = 1;i <= a.length();i++)
            {
                for(int j = 1;j <= b.length();j++)
                {
                    if(a[j - 1] == b[i - 1])   
                    {
                        dp[i][j] = dp[i - 1][j - 1];continue;
                    }
                    dp[i][j] = min(dp[i - 1][j] , dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j] , dp[i - 1][j - 1]) + 1;
                    ans = dp[i][j];
                }
            }
            if(a == b)  ans = 0;
            /*for(int i = 1;i <= a.length();i++)
            {
                for(int j = 1;j <= b.length();j++)  cout << dp[i][j] << " ";cout << "\n";
            }*/
            cout << ans << "\n";
        }
    } 
    //tags - dynamic programming
    //complexity : O(n ^ 2)
