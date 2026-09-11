#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& profit, int n) {

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] + dp[i - 1][w - wt[i - 1]]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {

    // Profit of each item
    vector<int> profit = {1, 2, 5, 6};

    // Weight of each item
    vector<int> wt = {2, 3, 4, 5};

    int n = 4;

    // Knapsack capacity
    int W = 8;

    int result = knapsack(W, wt, profit, n);

    cout << "Maximum Profit = " << result << endl;

    return 0;
}
