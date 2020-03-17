// C++ program for coin change problem.
#include<bits/stdc++.h>

using namespace std;

int count( int S[], int n, int k )
{
    int i, j, x, y;

    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[k + 1][n];

    // Fill the enteries for 0
    // value case (n = 0)
    for (i = 0; i < n; i++)
        table[0][i] = 1;

    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < k + 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;

            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;
        }
    }
    return table[k][n - 1];
}

// Driver Code
int main()
{
    int arr[100];
    //int m = sizeof(arr)/sizeof(arr[0]);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout << count(arr, n, k);
    return 0;
}
