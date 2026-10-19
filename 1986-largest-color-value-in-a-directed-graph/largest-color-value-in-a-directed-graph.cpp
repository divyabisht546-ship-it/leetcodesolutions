class Solution {
public:
int maxi = 0;                                   // FIX 7

// dp[node][c] = node se shuru hone wale kisi bhi path me color c ka max count
void dfs_check(vector<vector<int>>& adj, int node, string& colors,
               vector<bool>& visit, vector<array<int,26>>& dp) {
    visit[node] = true;

    for (auto child : adj[node]) {
        if (!visit[child]) {
            dfs_check(adj, child, colors, visit, dp);
        }
        for (int c = 0; c < 26; c++) {          // FIX 1 & 2: max se merge
            dp[node][c] = max(dp[node][c], dp[child][c]);
        }
    }

    dp[node][colors[node] - 'a']++;             // apna color add

    for (int c = 0; c < 26; c++) {
        maxi = max(maxi, dp[node][c]);
    }
}

bool cycle(vector<vector<int>>& adj, vector<bool>& visit,
           vector<bool>& recstack, int node) {
    visit[node] = true;
    recstack[node] = true;
    for (auto child : adj[node]) {
        if (recstack[child]) return true;
        else if (!visit[child]) {
            if (cycle(adj, visit, recstack, child)) return true;
        }
    }
    recstack[node] = false;
    return false;
}
    int largestPathValue(string colors, vector<vector<int>>& edges) {
          int n = colors.size();                      // FIX 4

    vector<vector<int>> adj(n);
    for (auto& e : edges) adj[e[0]].push_back(e[1]);

    vector<bool> visit(n, false), recstack(n, false), visit1(n, false);

    for (int i = 0; i < n; i++) {               // FIX 3 & 6
        if (!visit[i] && cycle(adj, visit, recstack, i)) {
            return -1;
        }
    }

    vector<array<int,26>> dp(n);
    for (auto& row : dp) row.fill(0);

    for (int i = 0; i < n; i++) {               // FIX 5
        if (!visit1[i]) dfs_check(adj, i, colors, visit1, dp);
    }
return maxi;
    }
};