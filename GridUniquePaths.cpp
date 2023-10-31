#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
typedef long long ll;
 
const int MOD = 1e9 + 7;
const ll INF = LLONG_MAX >> 1;

int uniquePaths(int i , int j, int n, int m, vector<vector<int>>& dp){
    if(i == n-1 && j == m-1) return 1;
    if(i >= n || j >= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = uniquePaths(i+1,j,n,m,dp) + uniquePaths(i, j+1, n, m, dp);
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m,-1));
    cout << uniquePaths(0,0,n,m,dp);
    return 0;
}
