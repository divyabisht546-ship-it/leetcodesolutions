class Solution {
public:
//new thing
typedef tuple<int,int,int>T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n==1) return 0;
    vector<vector<int>>res(n,vector<int>(k+1,INT_MAX));
    vector<vector<pair<int,int>>>adj(n);
    int count=0;
    // creating adjacency
    for(auto i:edges){
int u=i[0];
int v=i[1];
int w=i[2];
adj[u].push_back({w,v});
    }
    // priority queue
    priority_queue<T,vector<T>,greater<T>>pq;
    pq.push({0,0,1}); // u v weight
    res[0][1]=0;
    while(!pq.empty()){
        auto[dist,node,count]=pq.top();
        pq.pop();
        if(dist!=res[node][count]) continue;
        if(node==n-1) return dist;
        for(auto child:adj[node]){
        int adjnode=child.second;
        int adjcost=child.first;
        int newcount=1;
        if(labels[node]==labels[adjnode]){
            newcount=1+count;
            if(newcount>k) continue;
        }
if(res[adjnode][newcount]>adjcost+dist){
res[adjnode][newcount]=adjcost+dist;
pq.push({adjcost+dist,adjnode,newcount});
}
        }
    }
return -1;
    }
};