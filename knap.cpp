// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// struct Item {
//     int weight;
//     int value;
//     double ratio;
// };

// struct Node {
//     int level;
//     int profit;
//     int weight;
//     double bound;
// };

// bool compareItems(Item a, Item b) {
//     return a.ratio > b.ratio;
// }

// double bound(Node u, int n, int W, vector<Item>& items) {
//     if (u.weight >= W)
//         return 0;
//     double profit_bound = u.profit;
//     int j = u.level + 1;
//     int totweight = u.weight;

//     while ((j < n) && (totweight + items[j].weight <= W)) {
//         totweight += items[j].weight;
//         profit_bound += items[j].value;
//         j++;
//     }

//     if (j < n)
//         profit_bound += (W - totweight) * items[j].ratio;

//     return profit_bound;
// }

// int knapsack(int W, vector<Item>& items) {
//     int n = items.size();
//     sort(items.begin(), items.end(), compareItems);

//     queue<Node> Q;
//     Node u, v;
//     u = {-1, 0, 0, 0};
//     Q.push(u);

//     int maxProfit = 0;

//     while (!Q.empty()) {
//         u = Q.front();
//         Q.pop();

//         if (u.level == n - 1)
//             continue;

//         v.level = u.level + 1;

//         v.weight = u.weight + items[v.level].weight;
//         v.profit = u.profit + items[v.level].value;

//         if (v.weight <= W && v.profit > maxProfit)
//             maxProfit = v.profit;

//         v.bound = bound(v, n, W, items);

//         if (v.bound > maxProfit)
//             Q.push(v);

//         v.weight = u.weight;
//         v.profit = u.profit;
//         v.bound = bound(v, n, W, items);

//         if (v.bound > maxProfit)
//             Q.push(v);
//     }

//     return maxProfit;
// }

// int main() {
//     int n, W;
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<Item> items(n);
//     cout << "Enter weight and value of each item:\n";
//     for (int i = 0; i < n; i++) {
//         cin >> items[i].weight >> items[i].value;
//         items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
//     }

//     cout << "Enter the maximum weight capacity of the knapsack: ";
//     cin >> W;

//     int max_value = knapsack(W, items);
//     cout << "\nMaximum value that can be obtained: " << max_value << endl;

//     return 0;
// }



///dp
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    vector<int> value = {1, 4, 5, 7};
    vector<int> weight = {1, 3, 4, 5};
    int W = 7;
    int n = value.size();

    cout << "Maximum value: " << knapsack(W, weight, value, n) << endl;
    return 0;
}
