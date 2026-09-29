class Solution {
public:
bool bfs(int node,vector<int>&color,vector<vector<int>>&adj){
    queue<int>q;
color[node]=1;
q.push(node);
   while(!q.empty()){
       int node=q.front();
       q.pop();
       for(auto i:adj[node]){
           if(color[i]==-1){
               color[i]=1-color[node];
               q.push(i);
           }
           else if(color[i]==color[node]) return false;
       }
   }
   return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int num=n+1;
    vector<vector<int>>adj(num);
    for(auto i:dislikes){
        int x=i[0];
        int y=i[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int flag=1;
    vector<int>color(num,-1);
    for(int i=1;i<num;i++){
        if(color[i]==-1){
            if(!bfs(i,color,adj)){
                return false;
            }
        }
    }
   return true;
    }
};