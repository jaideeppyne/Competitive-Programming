//http://www.spoj.com/problems/YODANESS/
//Yodaness Level

	#include <bits/stdc++.h>
    #define ll long long 
     
    using namespace std;
     
    /*void construct_segment_tree(vector<int>& segtree , int n)
    {
        for(int i = n - 1;i >= 1;i--)   segtree[i] = segtree[2 * i] ^ segtree[2 * i + 1];
    }*/
    void update(vector<int>& segtree , int pos , int value , int n)
    {
        pos += n;
        segtree[pos] += 1;
        while(pos > 1)
        {
            pos >>= 1;
            segtree[pos] = segtree[2 * pos] + segtree[2 * pos + 1];
        }
    }
    int range_query(vector<int>& segtree , int left , int right , int n)
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
        std::ios::sync_with_stdio(0);cin.tie(0);
    	int T;cin >> T;
    	while(T--)
    	{
    	    int n;cin >> n;
    	    map<string , int>mm;string s;
    	    vector<int>v(n);
    	    for(int i = 0;i < n;i++)
    	    {
    	        cin >> s;
    	        mm.insert({s , i});
    	    }
    	    for(int i = 0;i < n;i++)
    	    {
    	        cin >> s;
    	        v[i] = mm[s];
    	    }
    	    int inversion = 0;
    	    vector<int>segtree(2 * n , 0);
    	    for(int i = 0;i < n;i++)
    	    {
    	        inversion += range_query(segtree , v[i] + 1 , n , n);
    	        update(segtree , v[i] , v[i] , n);
    	    }
    	    cout << inversion << "\n";
    	}
    } 
//tags - Segment tree , STL
//Overall Complexity - O(|s| * log |s|)
//Related Problems - Inversion Count(http://www.spoj.com/problems/INVCNT/)
