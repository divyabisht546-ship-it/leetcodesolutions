class Solution {
public:
vector<int>path;
void dfs(int node,   unordered_map<int,vector<int>>&adj){
    while(!adj[node].empty()){
        int next=adj[node].back();
        adj[node].pop_back();
        dfs(next,adj);
    }
    path.push_back(node);
}
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n=pairs.size();
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indegree,outdegree;
        for(auto i:pairs){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        int start=pairs[0][0];
        for(auto it:adj){
            int node=it.first;
            if(outdegree[node]-indegree[node]==1){start=node;
            break;}
        }
        dfs(start,adj);
        vector<vector<int>>ans;
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size()-1;i++){
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};