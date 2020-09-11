#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

void Solve()
{
    ll n,k,y,temp, miny=LONG_LONG_MAX, ans = 0;
    cin>>n>>k;
    vector<ll> xCor(n);
    vector<pair<ll,ll>> values;
    unordered_map<ll,ll> countX;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        countX[temp]++;
        if(countX[temp]==1)
            xCor.push_back(temp);
    }
    for(int i=0;i<n;i++)
        cin>>y;

    sort(xCor.begin(),xCor.end());

    ll prevInd = 0, sum = 0;
    for(int i=0;i<xCor.size();i++)
    {
        if(xCor.at(i) - xCor.at(prevInd) <= k)
            sum += countX[xCor.at(i)];
        else
        {
            values.push_back({sum,prevInd});
            while(xCor.at(i)-xCor.at(prevInd) > k)
            {
                sum -= countX[xCor.at(prevInd)];
                prevInd++;
            }
            i--;
        }
        
    }
    sort(values.begin(), values.end());
    ans += values.at(values.size()-1).first;
    cout<<values.at(values.size()-1).first<<":";
    prevInd = values.at(values.size()-1).second;

    values.clear();

    vector<ll> tempArr = xCor;
    xCor.clear();
    for(int i=0;i<tempArr.size();i++)
    {
        if(tempArr.at(i)>=tempArr.at(prevInd) && tempArr.at(i)<=tempArr.at(prevInd+k))
            countX[tempArr.at(i)] = 0;
        else
            xCor.push_back(tempArr.at(i));
    }
    for(int i=0;i<xCor.size();i++)
        cout<<xCor.at(i)<<" ";
    cout<<"\n";
    sum = 0;
    for(int i=0;i<xCor.size();i++)
    {
        if(xCor.at(i) - xCor.at(prevInd) <= k)
            sum += countX[xCor.at(i)];
        else
        {
            values.push_back({sum,prevInd});
            while(xCor.at(i)-xCor.at(prevInd) > k)
            {
                sum -= countX[xCor.at(prevInd)];
                prevInd++;
            }
            i--;
        }
        
    }
    sort(values.begin(), values.end());
    ans += values.at(values.size()-1).first;
    
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