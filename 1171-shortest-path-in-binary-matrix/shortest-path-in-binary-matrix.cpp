class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        int count=1;
        queue<pair<int,int>>q;
        if(grid[0][0]==1){
            return -1;
        }
        q.push({0,0});
        visited[0][0]=true;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
            auto[x,y]=q.front();
            q.pop();
          if(x==n-1 && y==n-1){
                return count;
            }
            int dx[8]={-1,1,0,0,-1,-1,1,1};
            int dy[8]={0,0,-1,1,1,-1,-1,1};
            for(int k=0;k<8;k++){
int nx=dx[k]+x;
int ny=dy[k]+y;
if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && !visited[nx][ny]){
    q.push({nx,ny});
    visited[nx][ny]=true;
}
            }}
            count++;
        }
        return -1;
    }
};