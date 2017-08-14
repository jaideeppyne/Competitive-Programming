	//http://www.spoj.com/problems/BYTESM2/
	
	    #include<bits/stdc++.h>
    #define ll long long 
     
    using namespace std;
     
    int main()
    {
        std::ios::sync_with_stdio(0);cin.tie(0);
        int T;cin >> T;
        while(T--)
        {
            int n , m;cin >> n >> m;
            int a[n][m] , dp[n][m];
            for(int i = 0;i < n;i++)
            {
                for(int j = 0;j < m;j++)    cin >> a[i][j];
            }
            for(int i = 0;i < m;i++)    dp[n - 1][i] = a[n - 1][i];
            for(int i = n - 2;i >= 0;i--)
            {
                for(int j = 1;j < m - 1;j++)
                {
                    dp[i][j] = a[i][j] + max(dp[i + 1][j] , max(dp[i + 1][j - 1] , dp[i + 1][j + 1]));
                }
                dp[i][0] = a[i][0] + max(dp[i + 1][0] , dp[i + 1][1]);
                dp[i][m - 1] = a[i][m - 1] + max(dp[i + 1][m - 1] , dp[i + 1][m - 2]);
            }
            int ans = 0;
            if(m == 1)
            {
                for(int i = 0;i < n;i++)
                {
                    for(int j = 0;j < m;j++)    ans += a[i][j];
                }
                cout << ans << "\n";continue;
            }
            for(int i = 0;i < m;i++)    ans = max(dp[0][i] , ans);
            /*for(int i = 0;i < n;i++)
            {
                for(int j = 0;j < m;j++)    cout << dp[i][j] << " ";cout << "\n";
            }*/
            cout << ans << "\n";
        }
    } 
    //tags : Dynamic Programming
    //Complexity : O(n ^ 2)
