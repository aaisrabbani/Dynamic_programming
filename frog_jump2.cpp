#include <bits/stdc++.h>

using namespace std;

int minimum_weight(int index, vector<int> &weight, int k, vector<int> &dp)
{
    if (dp[index] != -1)
    {
        return dp[index];
    }
    if (index == 0)
    {
        return 0;
    }

    int min_step = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        {
            int jump = minimum_weight(index - i, weight, k, dp) + abs(weight[index] - weight[index - i]);
            min_step = min(min_step, jump);
        }
    }

    return dp[index] = min_step;
}

int main()
{
     //freopen("input.txt", "r", stdin);

    int n, k;
    cin >> n >> k;
    vector<int> dp(n, -1); // Corrected size here
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << minimum_weight(n - 1, array, k, dp) << endl; // Corrected function call

    return 0;
}
