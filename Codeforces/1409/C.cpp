#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll x,y,n;
    cin>>n>>x>>y;

    ll a = 1, d = 1;
    ll aa = 1, dd = 1, maxxEle = 1000000007;
    bool found = false;
    for(;a<=x;a++)
    {
        // cout<<"For a = "<<a<<"\n";
        for(d=1;d<=y-x;d++)
        {
            // cout<<d<<"\t";
            ll yy = y, xx = x; 
            yy -= a;
            xx -= a;

            if(xx%d==0 && yy%d==0)
            {
                xx/=d;
                yy/=d;

                xx++;
                yy++;

                if(yy <= n)
                {
                    ll maxxx = a+((n-1)*d);
                    if(maxxEle > maxxx)
                    {
                        maxxEle = maxxx;
                        aa = a;
                        dd = d;
                    }
                    // cout<<"\n"<<yy<<"\n";
                    // cout<<"\n"<<d<<" worked\n";
                    // found = true;
                    // break;    
                }
            }
        }
        // if(found) break;
    }

    for(int i=0;i<n;i++)
        cout<<aa+(i*dd)<<" ";
    cout<<"\n";
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}