#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    string bin, ans="";
    cin>>bin;

    ll k;
    cin>>k;

    for(int i=0;i<bin.size();i++)
        ans += '1';

    for(int i=0;i<bin.size();i++)
    {
        if(bin.at(i)=='0')
        {
            if(i-k>=0)
                ans[i-k] = '0';
            if(i+k<bin.size())
                ans[i+k] = '0';
        }
        if(i-k<0 && i+k>=bin.size())
            ans[i] = '0';
    }

    bool ansPoss = true;
    for(int i=0;i<bin.size();i++)
    {
        if(bin[i]=='1')
        {
            if(i-k>=0 && i+k<bin.size())
            {
                if(ans[i-k]=='0' && ans[i+k]=='0')
                {
                    ansPoss = false;
                    break;
                }
            }
            else if(i-k>=0)
            {
                if(ans[i-k]=='0')
                {
                    ansPoss = false;
                    break;
                }
            }
            else if(i+k<bin.size())
            {
                if(ans[i+k]=='0')
                {
                    ansPoss = false;
                    break;
                }
            }
            else
            {
                // cout<<"case 4\n";
                // cout<<i-k<<"\t"<<i+k<<"\n";
                ansPoss = false;
                break;
            }
        }
    }

    // cout<<ans<<"\t";
    (ansPoss)?cout<<ans<<"\n":cout<<"-1\n";

}

int main()
{
    ll t;
    cin>>t;
    while(t--)
        Solve();

    return 0;
}