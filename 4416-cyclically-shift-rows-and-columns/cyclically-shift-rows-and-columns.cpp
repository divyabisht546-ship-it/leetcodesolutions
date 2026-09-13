class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
vector<vector<int>>matrix(n,vector<int>(n,0));
vector<vector<int>>matrix2(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int apply=rowShift[i];
          for(int j=0;j<n;j++){
              matrix[i][j]=grid[i][(j+apply+n)%n];
          }
        }
        for(int i=0;i<n;i++){
            int apply=colShift[i];
          for(int j=0;j<n;j++){
              matrix2[j][i]=matrix[(j+apply+n)%n][i];
          }
        }
        return matrix2;
        }
};