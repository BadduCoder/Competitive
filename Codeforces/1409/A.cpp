#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll x,y;
    cin>>x>>y;
    ll diff = abs(x-y);

    ll rem = diff%10;
    diff -= rem;
    diff /= 10;
    if(rem!=0)
        diff++;

    cout<<diff<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}