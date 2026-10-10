class Solution {
public:
long long root_sum=0;
int dfs_base(vector<vector<int>>&adj,int src,vector<bool>&visited,int depth,vector<int>&count){
    int totalnode=1;
    visited[src]=true;
    root_sum+=depth;
    for(auto child:adj[src]){
if(visited[child]) continue;
totalnode+=dfs_base(adj,child,visited,depth+1,count);
    }
    count[src]=totalnode;
    return totalnode;
}
void dfs(vector<vector<int>>&adj,int curr,vector<bool>&visit,vector<int>&result,int n,vector<int>&count){
    visit[curr]=true;
   for(auto child:adj[curr]){
    if(visit[child]) continue;
    result[child]=result[curr]-count[child]+(n-count[child]);
    dfs(adj,child,visit,result,n,count);
   }
}
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
     vector<vector<int>>adj(n);
     for(auto i:edges){
        int u=i[0];
        int v=i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     vector<int>count(n,0);
     vector<bool>visited(n,false);
     int ans=dfs_base(adj,0,visited,0,count);
     //  count nikaal diyaa + distance nikaal diya
     vector<int>result(n,0);
     vector<bool>visited2(n,false);
     result[0]=root_sum;

     dfs(adj,0,visited2,result,n,count); //parent value
     return result;
    }
};