//http://www.spoj.com/problems/INVCNT/
//Inversion Count
	#include <bits/stdc++.h>
    #define ll long long 
     
    using namespace std;
     
    struct yo
    {
        int val , index;
    };
    int compare(yo a , yo b)
    {
        if(a.val == b.val)  return a.index < b.index;
        return (a.val < b.val);
    }
    void update(vector<ll>& segtree , int pos , int value , int n)
    {
        pos += n;
        segtree[pos] += 1;
        while(pos > 1)
        {
            pos >>= 1;
            segtree[pos] = segtree[pos<<1] + segtree[pos<<1 | 1];
        }
    }
    int range_query(vector<ll>& segtree , int left , int right , int n)
    {
        left += n;right += n;
        int sum = 0;
        while(left < right)
        {
            if(left & 1)            {   sum = sum + segtree[left];left++;}
            if(right & 1)           {   right--;sum = sum + segtree[right];}  
            left >>= 1;right >>= 1;
        }
        return sum;
    }
    int main() 
    {
        // std::ios::sync_with_stdio(0);cin.tie(0);
    	int T;cin >> T;
    	while(T--)
    	{
    	    int n , i;
            scanf("%d" , &n);
            vector<int> v(n);
            for (int i = 0; i < n; i++) {
                cin >> v[i];
            }
     
            set<int> s(v.begin(), v.end());
            vector<int> sorted(s.begin(), s.end());
            
            for (int i = 0; i < n; i++) {
                v[i] = lower_bound(sorted.begin(), sorted.end(), v[i]) - sorted.begin();
            }
            ll inversion = 0;
    	    vector<ll>segtree(2 * n , 0);
    	    for(i = 0;i < 2 * n;i++)	segtree[i] = 0;
    	    for(i = 0;i < n;i++)
    	    {
    	        inversion += range_query(segtree , v[i] + 1 , n , n);
    	        //how many elements are greater than v[i]
    	        update(segtree , v[i] , v[i] , n);
    	        //those are in the range 0 to i - 1 
    	    }
    	    cout << inversion << "\n";
    	}
    } 
//tags - Segment tree , implementation
//Overall Complexity - O(n * log n)
//Related Problems - YODANESS LEVEL(http://www.spoj.com/problems/YODANESS/)
