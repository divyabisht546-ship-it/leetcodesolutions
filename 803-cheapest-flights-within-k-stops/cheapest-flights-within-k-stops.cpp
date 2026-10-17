class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // craete an adjacency
vector<vector<pair<int,int>>>adj(n);
for(auto i:flights){
    int u=i[0];
    int v=i[1];
    int cost=i[2];
    adj[u].push_back({v,cost});
}
// return nahii kar rahee instead hamm har ek jagah see waha tak pahuchnee kaa cost dekh rahe haii
vector<int>dist(n,INT_MAX);
dist[src]=0;
int steps=0;
queue<pair<int,int>>q; //{node,cost}
q.push({src,0});
while(!q.empty() && steps<=k){
    int size=q.size();
    while(size--){
        auto top=q.front();
        q.pop();
        int node=top.first;
        int cost=top.second;
        for(auto child:adj[node]){
            int child_node=child.first;
            int child_cost=child.second;
            if(dist[child_node]>cost+child_cost){
                dist[child_node]=cost+child_cost;
                q.push({child_node,cost+child_cost});
            }
        }
    }
    steps++; //minimum k itne hii usee kar sakte hoo
}
if(dist[dst]==INT_MAX) return -1;
return dist[dst];     
    }
};