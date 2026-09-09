class Solution { 
public: 
// done by mee by mik bhaiya
    int dx[8]={-1,-1,0,1,1,1,0,-1}; 
    int dy[8]={0,-1,1,1,0,-1,-1,1}; 

    bool isvalid(int x,int y, vector<vector<int>>&matrix,int n){ 
        if(x<n && y<n && x>=0 && y>=0 && matrix[x][y]==0) 
            return true; 
        
        return false; 
    } 

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) { 

        vector<vector<int>> matrix(grid.begin(),grid.end()); 

        int n=matrix.size(); 

        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;

        queue<pair<int,int>> q; 

        q.push({0,0}); 

        // IMPORTANT: starting cell ko immediately visited mark karo
        matrix[0][0]=1;

        int count=1; 

        while(!q.empty()){ 

            int size=q.size(); 

            while(size--){ 

                int x=q.front().first; 
                int y=q.front().second; 
                q.pop(); 

                // Destination reached
                if(x==n-1 && y==n-1){ 
                    return count; 
                } 

                for(int k=0;k<8;k++){ 

                    int newx=dx[k]+x; 
                    int newy=dy[k]+y; 

                    if(isvalid(newx,newy,matrix,n)){ 

                        // Queue mein daalte hi visited
                        matrix[newx][newy]=1; 

                        q.push({newx,newy}); 
                    } 
                } 
            } 

            count++; 
        } 

        return -1; 
    } 
};