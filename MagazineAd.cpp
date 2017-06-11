//http://codeforces.com/contest/803/problem/D
//Magazine Ad

#include <bits/stdc++.h>
#define ll long long 
     
using namespace std;

bool check(int width , vector<int>& token , int k)  //check validity of width
{
    int sum = 0 , ctr = 0 , current = 0;
    for(int i = 0;i < token.size();i++)
    {
        sum += token[i];            //max possible width in a line which is less than mid
        if(sum > width)
        {
            sum -= token[i];i--;
            current = max(current , sum);   //finding max width in any line 
            if(sum <= 0 || sum > width)    return false;
            sum = 0;
            ctr++;  //count number of lines.target is to minimize this.
        }
    }
    if(sum > 0)     //IMPORTANT STEP
    {
        if(sum > width)     return false;
        else                {ctr++;current = max(current , sum);}
    }
    return (ctr <= k);//number of words formed should be less than k
}
int main() 
{
    std::ios::sync_with_stdio(0);cin.tie(0);
    int k;cin >> k;
    string s;
    cin.ignore();       //special type of string input
    getline(cin , s);
    vector<int>token;   //to store length of each word
    int c = 0;
    for(int i = 0;i < s.length();i++)   
    {
        c++;
        if(s[i] == '-' || s[i] == ' ')
        {
            token.push_back(c);//store length of each word separately
            c = 0;
        }
    }
    token.push_back(c);//length of last word - caution step - DONT MISS
    int low = 1 , high = s.length() , mid , width = (int)1e6;
    while(low <= high)
    {
        mid = (low + high) >> 1;    //binary search for the answer
        if(check(mid , token , k)){         high = mid - 1;width = min(width , mid);}
                                                                //minimum possible answer
        else                                low = mid + 1;      //go for higher widths
    }
    cout << width;
} 
//Time complexity : O(|s| * (log |s|))
//tags : binary search , greedy
