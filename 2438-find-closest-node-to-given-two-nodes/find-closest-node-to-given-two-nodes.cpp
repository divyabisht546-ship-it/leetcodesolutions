class Solution {
public:
void dfs1(int node, vector<vector<int>>& adj,
          vector<bool>& visit1,
          vector<pair<int,int>>& arr1, int total) {

    visit1[node] = true;
    arr1[node].first = node;
    arr1[node].second = total;

    for(auto child : adj[node]) {
        if(!visit1[child]) {
            dfs1(child, adj, visit1, arr1, total + 1);
        }
    }
}

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
          int n = edges.size();
    vector<vector<int>> adj(n);

    for(int i = 0; i < n; i++) {
        if(edges[i] != -1) {
            adj[i].push_back(edges[i]);
        }
    }

    vector<bool> visit1(n, false);
    vector<pair<int,int>> arr1(n, {-1, -1});

    dfs1(node1, adj, visit1, arr1, 0);

    vector<bool> visit2(n, false);
    vector<pair<int,int>> arr2(n, {-1, -1});

    dfs1(node2, adj, visit2, arr2, 0);

    int mini = INT_MAX;
    int ans = -1;

    for(int j = 0; j < n; j++) {
        if(arr1[j].second != -1 &&
           arr2[j].second != -1) {

            int maxi = max(arr1[j].second, arr2[j].second);

            if(maxi < mini) {
                mini = maxi;
                ans = j;
            }
        }
    }
return ans;
    }
};