class Solution {
public:
void dfs(int node,vector<bool>&visit,vector<vector<int>>& rooms){
    visit[node]=true;
    for(auto i:rooms[node]){
        if(!visit[i]){
            dfs(i,visit,rooms);
        }
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n=rooms.size();
       vector<bool>visit(n,false);
dfs(0,visit, rooms);
for(int i=0;i<n;i++){
    if(visit[i]==false) return false;
}
return true;
    }
};