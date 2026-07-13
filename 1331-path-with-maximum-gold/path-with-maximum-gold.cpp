class Solution {
public:
int maximum=0;
bool isvalid(int i,int j,int m,int n,vector<vector<int>>&grid){
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
        return false;
    }
    return true;
}
void solve(int m,int n,int i,int j,vector<vector<int>>&grid,int sum){
    sum+=grid[i][j];
    int temp=grid[i][j];
    grid[i][j]=0;
    maximum=max(maximum,sum);
    if(isvalid(i+1,j,m,n,grid)){
solve(m,n,i+1,j,grid,sum);
    }
   if(isvalid(i-1,j,m,n,grid)){
solve(m,n,i-1,j,grid,sum);
    }
if(isvalid(i,j+1,m,n,grid)){
solve(m,n,i,j+1,grid,sum);
    }
if(isvalid(i,j-1,m,n,grid)){
solve(m,n,i,j-1,grid,sum);
    }
    grid[i][j]=temp;
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
solve(m,n,i,j,grid,0);
                }
            }
        }
        return maximum;
    }
};