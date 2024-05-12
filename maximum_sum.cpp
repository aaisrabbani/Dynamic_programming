#include <bits/stdc++.h>

using namespace std;

int max_sum(int ind, vector<int> &array,vector<int> &dp)
{

    if (ind < 0)
    {
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    if (ind == 0)
    {
        return array[ind];
    }

    int pick = array[ind] + max_sum(ind - 2,array,dp);

    int not_pick = 0 + max_sum(ind-1,array,dp);

    return dp[ind]=max(pick,not_pick);
}

int main()
{

    freopen("input.txt", "r", stdin);


    int n;
    cin >> n;
    vector<int> dp(n,-1);
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout<<max_sum(n-1,array,dp);

    return 0;
}