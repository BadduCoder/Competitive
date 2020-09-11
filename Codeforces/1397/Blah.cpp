/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string nextWord(string x)
{
    // cout<<"Got "<<x<<"\t";
    ll len = x.size();
    len--;
    while(len>=0)
    {
        if(x[len] == 'Z')
        {
            x[len] = 'A';
            len--;
        }
        else
        {
            x[len] = x[len]+1;
            break;
        }
    }

    // cout<<"Returning "<<x<<"\n";
    return x;
}

string getWord(vector <pair<string,pair<ll,ll>>> guess)
{
    string ans = "AAAA";
    bool isAns = false;

    while(!isAns)
    {
        isAns = true;
        // if(ans == "BDAA")
        //     cout<<"Trying "<<ans<<":\n";
        for(int i=0;i<guess.size();i++)
        {
            // cout<<"Guess : "<<guess.at(i).first<<"\n"; 
            ll bulls = 0, cows = 0;
            ll checked[4] = {0,0,0,0};
            // Checking number of Bulls (Correct Alphabets in Correct Places)
            for(int m=0;m<guess.at(i).first.size();m++)
            {
                if(ans[m]==guess.at(i).first.at(m))
                {
                    checked[m] = 1;
                    bulls++;
                }
            }
            // if(ans == "BDAA")
            //     cout<<"\tBulls: "<<bulls<<"\n";
            // Checking number of Bulls (Correct Alphabets in Wrong Places)
            for(int m=0;m<guess.at(i).first.size();m++)
            {
                if(checked[m]==0)
                {
                    if(ans[m]==guess.at(i).first.at((m+1)%4) && checked[(m+1)%4]==0)
                        cows++;
                    if(ans[m]==guess.at(i).first.at((m+2)%4) && checked[(m+2)%4]==0)
                        cows++;
                    if(ans[m]==guess.at(i).first.at((m+3)%4) && checked[(m+3)%4]==0)
                        cows++;
                }
            }
            // if(ans == "BDAA")
            //     cout<<"\tCows: "<<cows<<"\n";

            if(guess.at(i).second != make_pair(bulls,cows))
            {
                isAns = false;
                break;
            }
        }
        if(isAns)
            break;
        
        ans = nextWord(ans);
        if(ans=="ZZZZ")
            break;
    }
    return ans;
}

int main()
{
    ll n;
    cin>>n;
    vector <pair<string,pair<ll,ll>>> que;
    string temp;
    ll x,y;
    while(n--)
    {
        cin>>temp>>x>>y;
        que.push_back({temp,{x,y}});
        if(x==4)
        {
            cout<<temp;
            return;
        }
    }   
    
    string ans = getWord(que);
    cout<<ans;

    return 0;
}
