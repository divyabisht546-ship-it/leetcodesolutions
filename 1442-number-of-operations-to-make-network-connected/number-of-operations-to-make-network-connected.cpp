class Solution {
public:
    void dfs(int start,vector<bool>&visit,vector<vector<int>>&adj){
        visit[start]=true;
        for(auto u:adj[start]){
            if(!visit[u]){
                dfs(u,visit,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
       // int s=0;
        for(auto i: connections){
            int x=i[0];
            int y=i[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int edges=connections.size();
        if(edges<n-1){
            return -1;
        }
        int count=0;
    vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count-1;
    }
};