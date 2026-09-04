class Solution {
public:
bool solve(vector<vector<int>>&adj,int n){
    vector<int>ind(n,0);
    for(int i=0;i<n;i++){
        for(auto j:adj[i]){
            ind[j]++;
        }
    }
    queue<int>q;
    vector<bool>visit(n,false);
    int count=0;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        count++;
        for(auto x:adj[u]){
      ind[x]--;
            if(ind[x]==0){
                q.push(x);
            }
            }
    }
    if(count==n) return true;
    else return false;
}




    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
         vector<vector<int>>edges(prerequisites.begin(),prerequisites.end());
            vector<vector<int>>adj(n);
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        adj[u].push_back(v);
    }
   if(solve(adj,n)){
   return true;
   }
  return false;

    }
};