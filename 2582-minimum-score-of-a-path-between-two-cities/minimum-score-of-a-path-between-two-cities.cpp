class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>>adj(n+1);
    for(auto i:roads){
        int u=i[0];
        int v=i[1];
        int cost=i[2];
        // stored=>[node,distance]
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
    }
    queue<pair<int,int>>q;
    q.push({1,INT_MAX});
    vector<bool>visit(n+1,false);
    int mini=INT_MAX;
    while(!q.empty()){
int size=q.size();
while(size--){
   auto top=q.front();
    int node=top.first;
    int cost=top.second;
        q.pop();
    mini=min(mini,cost);
    visit[node]=true;
    for(auto child:adj[node]){
        int child_node=child.first;
        int child_cost=child.second;
        if(!visit[child_node]){
            q.push({child_node,child_cost});
        }
    }
}
    }
    for(auto i:roads){
        int u=i[0];
        int v=i[1];
        int cost=i[2];
        if(visit[u]==true && visit[v]==true){
            mini=min(mini,cost);
        }
    }
    return mini;
    }
};