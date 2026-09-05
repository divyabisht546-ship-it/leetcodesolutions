class Solution {
public:
bool solve(vector<int>&color, vector<vector<int>>&adj,int node,int clr){
queue<int>q;
q.push(node);
  color[node]=clr;
while(!q.empty()){
    int u=q.front();
    q.pop();
    for(auto v:adj[u]){
        if(color[v]==-1){
            q.push(v);
            color[v]=1-color[u];
        }
        else if(color[v]==color[u]) return false;
    }

}
return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        // using bfs
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int u:graph[i]){
                adj[i].push_back(u);
                adj[u].push_back(i);
            }
        }
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
            if(!solve(color,adj,i,1)) return false;
            }
        }
        return true;

    }
};