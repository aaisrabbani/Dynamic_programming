#include <bits/stdc++.h>

using namespace std;

int minimum_weight(int index, vector<int> &weight)
{
    if (index == 0)
    {
        return 0;
    }

    int one_jump = abs(weight[index] - weight[index - 1]) + minimum_weight(index - 1, weight);
    int two_jump = INT_MAX;
    if (index > 1)
    {
        two_jump = minimum_weight(index - 2, weight) + abs(weight[index] - weight[index - 2]);
    }

    return min(one_jump, two_jump);
}

int main()
{

    freopen("input.txt", "r", stdin);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }

        cout << minimum_weight(n - 1, array)<<endl;
    }

    return 0;
}