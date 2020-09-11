#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n;
    cin>>n;
    string str[n];
    
    ll count[26];
    memset(count, 0, sizeof count);
    

    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        for(int j=0;j<str[i].size();j++)
            count[str[i][j]-'a']++;
    }

    bool can=true;
    for(int i=0;i<26;i++)
    {
        if(count[i]%n!=0)
        {
            can = false;
            break;
        }
    }

    can?cout<<"YES\n":cout<<"NO\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}