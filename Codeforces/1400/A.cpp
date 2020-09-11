#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n;
    cin>>n;
    string binary;
    cin>>binary;

    bool z=false, o=false;

    string ans = "";
    for(int i=0;i<n;i++)
        ans += binary[n-1];

    cout<<ans<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}