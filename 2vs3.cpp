//Problem link - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3/
//2 vs 3
//Code Monk(Segment tree , RMQ , Lazy propagation)
//Author - Jaideep Pyne
//https://www.hackerearth.com/@jaideep16

#include <bits/stdc++.h>
#define ll long long 

using namespace std;
 
void construct_segment_tree(vector<pair<int , int> >& segtree , int n)
{
    for(int i = n - 1;i >= 1;i--)   
    {
        segtree[i].first = (segtree[2 * i].first + segtree[2 * i + 1].first) % 3;
        segtree[i].second = (segtree[2 * i].second + segtree[2 * i + 1].second) % 3;
    }
}
void update(vector<pair<int , int> >& segtree , int pos , int n)
{
	//range sum query
    pos += n;
    if(segtree[pos].first == 0 && segtree[pos].second == 0)
    {
        segtree[pos].first = (pos) & 1;
        segtree[pos].second = !((pos) & 1);
    }
    else    return;
    while(pos > 1)
    {
        pos >>= 1;
        segtree[pos].first = (segtree[2 * pos].first + segtree[2 * pos + 1].first) % 3;
        segtree[pos].second = (segtree[2 * pos].second + segtree[2 * pos + 1].second) % 3;
    }
}
int range_query(vector<pair<int , int> >& segtree , int left , int right , int n)
{
    int r = right;
    left += n;right += n;
    int sumodd = 0 , sumeven = 0;
    while(left < right)
    {
        if(left & 1)            
        {   
            sumodd += segtree[left].first;sumodd %= 3;
            sumeven += segtree[left].second;sumeven %= 3;
            left++;
        }
        if(right & 1)           
        {   
            right--;
            sumodd += segtree[right].first;sumodd %= 3;
            sumeven += segtree[right].second;sumeven %= 3;
        }  
        left >>= 1;right >>= 1;
    }
    r--;
    if(!(r & 1))	//this is the tricky part
    return (sumeven - sumodd + 3);
    else    return (sumodd - sumeven + 3);
    // when the right bound is odd the bounds get 
    //shifted by one place.When the right bound is
    //even there is no problem.Draw the original string 
    //and mark the odd and even indices on top of each character.
    //now take an interval with odd right bound and do the above 
    //step.Ypu will fin dthe trick.
}
int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
	int n;string a;cin >> n >> a;
	vector<pair<int , int> >segtree(2 * n);
	//To check divisibility by 3 -
	//the number of 1's in even position 
	//and the number of 1's in the odd
	//position should be equal when taken 
	//under mod 3.
	for(int i = 0;i < n;i++)
	{
	    if(a[i] == '1')
	    {
	        segtree[n + i].first  = i & 1;
	        segtree[n + i].second = !(i & 1);
	    }
	    else
	    {
	        segtree[n + i].first  = 0;
	        segtree[n + i].second = 0;
	    }
	}
	construct_segment_tree(segtree , n);
	int q;cin >> q;
	//If you have a binary number (b4,b3,b2,b1,b0)2                        
	//then the value of the number is b4*16 + b3*8 + b2*4 + b1*2 + b0.                        
	//And the value % 3 == b4*1 + b3*(-1) + b2*1 + b1*(-1) + b0                        
	//== b4 - b3 + b2 - b1 + b0
	while(q--)
	{
	    int type , left , right , pos;
	    cin >> type;
	    if(type == 1)
	    {
	        cin >> pos;
	        if(a[pos] == '0')   a[pos] = '1';
	        update(segtree , pos , n);
	    }
	    else
	    {
	        cin >> left >> right;
	        int ans = range_query(segtree , left , right + 1, n);
	        cout << ans % 3 << "\n";
	    }
	}
	return 0;
}

//Overall Complexity : O(n * log n)
//tags : math , modular arithmetic , segment tree
