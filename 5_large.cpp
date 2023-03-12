#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("TOF_large.txt", "r", stdin);
    freopen("output_large.txt", "w", stdout);
#endif

    int testcase, revenue;
    cin >> testcase;
    while (testcase--)
    {
        int n, d;
        cin >> n >> d;
        int trees = n;
        int a[5][2] = {{12000, 10},
                       {10000, 6},
                       {27500, 15},
                       {7500, 5},
                       {8000, 15}};
        vector<int> one_tree_revenue;
        for (int i = 0; i < 5; i++)
        {
            int temp = a[i][0] * (d / a[i][1]);
            one_tree_revenue.push_back(temp);
            trees--;
        }
        revenue = 0;
        for (int i = 0; i < 5; i++)
        {
            revenue = revenue + one_tree_revenue.at(i);
        }
        // cout<<revenue <<endl;
        sort(one_tree_revenue.begin(), one_tree_revenue.end(), greater<int>());

        int maximum_cap = (n * 0.4) - 1;
        int i = 0;
        while (trees > 0)
        {
            if (trees > maximum_cap)
            {
                revenue = revenue + (one_tree_revenue.at(i) * maximum_cap);
                i++;
                trees = trees - maximum_cap;
            }
            else
            {
                revenue = revenue + (one_tree_revenue.at(i) * trees);
                i++;
                trees = trees - maximum_cap;
            }
        }
        cout << revenue << endl;
    }
}
