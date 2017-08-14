                //http://www.spoj.com/problems/ANARC09A/
				
				//https://www.quora.com/How-should-we-use-stacks-to-solve-the-Seinfeld-problem-in-SPOJ
                //see first and second answer
                #include<bits/stdc++.h>
                #define ll long long
                 
                using namespace std;
                 
                int main()
                {
                    std::ios::sync_with_stdio(0);cin.tie(0);
                    int T = 1;
                    while(T++)
                    {
                        string s;cin >> s;
                        if(s[0] == '-')     return 0;
                        int n = s.length() , c = 0 , ans = 0;
                        for(int i = 0;i < n;i++)
                        {
                            c += (s[i] == '{');
                            c -= (s[i] == '}');
                            if(c < 0)       // closing brackets are increased.so change then to opening. 
                            {
                                c += 2;ans++;
                            }
                            if(c >= n - i)  //opening backets are more than rest of the string.Change them to closing.
                            {
                                c -= 2;ans++;
                            }
                        }
                        cout << T - 1 << ". " << ans << "\n";
                    }
                }    
                
                //tags : Dynamic Programming , stacks
                //Complexity : O(n)
