#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll x[2],y[2],z[2];
    cin>>x[0]>>y[0]>>z[0];
    cin>>x[1]>>y[1]>>z[1];
    
    ll temp, ans = min(z[0],y[1]);
    z[0] -= ans;
    y[1] -= ans;
   
    for(int i=0;i<2;i++)
    {
     
        if(i==1)
        {
            temp = min(z[0],y[1]);
            ans -= 2*temp;
        }
        else
            ans *= 2;

        temp = min(y[0],x[1]);
        y[0] -= temp;
        x[1] -= temp;

        temp = min(x[0],z[1]);
        x[0] -= temp;
        z[1] -= temp;

        // cout<<x[0]<<" "<<y[0]<<" "<<z[0]<<"\n";
        // cout<<x[1]<<" "<<y[1]<<" "<<z[1]<<"\n";

        swap(x[0],x[1]);
        swap(y[0],y[1]);
        swap(z[0],z[1]);
    } 


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