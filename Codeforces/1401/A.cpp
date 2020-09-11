#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll a,k,ans=0;
    cin>>a>>k;
    if(a<k)
    {
        ans += k-a;
        a = k;
    }
    if((a+k)%2!=0)
        ans++;
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