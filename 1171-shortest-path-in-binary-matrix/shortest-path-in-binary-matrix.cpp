class Solution { 
public: 
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,-1,1,1,0,-1,-1,1};
bool isvalid(int x,int y,vector<vector<int>>&matrix,int n){
    if(x>=0 && y>=0 && x<n && y<n && matrix[x][y]==0) return true;
    return false;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) { 
        if(grid[0][0]==1) return -1;
        typedef pair<int,pair<int,int>>p;
         vector<vector<int>>matrix(grid.begin(),grid.end());
         int n=matrix.size();
//djikstra applied
priority_queue<p,vector<p>,greater<p>>pq;
vector<vector<int>>res(n,vector<int>(n,INT_MAX));

pq.push({1,{0,0}});
 res[0][0]=1; //here was my mistake
while(!pq.empty()){
    int dist=pq.top().first;
    int x=pq.top().second.first;
    int y=pq.top().second.second;
    pq.pop();
    for(int k=0;k<8;k++){
        int newx=dx[k]+x;
        int newy=dy[k]+y;
        if(isvalid(newx,newy,matrix,n)){
            if(res[newx][newy]>dist+1){
                res[newx][newy]=dist+1;
                pq.push({res[newx][newy],{newx,newy}});
            }
        }
    }
}
if(res[n-1][n-1]!=INT_MAX){
    return res[n-1][n-1];
}
return -1;
    } 
};