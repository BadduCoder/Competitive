#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    string substr = "";

    for(int i=0;i<k;i++)
        substr += '?';

    for(int i=0;i<n;i++)
    {
        if(str[i]!='?')
        {
            if(substr[i%k]=='?' || substr[i%k]==str[i])
                substr[i%k] = str[i];
            else
            {
                cout<<"NO\n";
                return;
            }
        }
    }

    ll zCount=0, oCount=0;
    for(int i=0;i<k;i++)
    {
        if(substr[i]=='0')
            zCount++;
        else if(substr[i]=='1')
            oCount++;
    }

    // cout<<zCount<<":"<<oCount<<"\t"<<k<<"|"<<"\t";
    if(zCount>(k/2) || oCount>(k/2))
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    return;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}