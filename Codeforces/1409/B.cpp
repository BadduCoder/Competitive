#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll a,b,x,y,n;
    ll aa,bb,xx,yy,nn;

    cin>>a>>b>>x>>y>>n;
    aa = a;
    bb = b;
    xx = x;
    yy = y;
    nn = n;

    int decA = min(n, a-x);
    int decB = min(n, bb-y);

    nn -= decB;
    n -= decA;

    bb -= decB;
    a -= decA;

    aa -= min(aa,nn); 
    b -= min(b,n);

    aa = max(aa, xx);
    b = max(b, y);

    cout<<min(aa*bb,a*b)<<"\n";



}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}