class Solution {
public:
bool isvalid(int dx,int dy,int m,int n,vector<vector<char>>& maze){
    if(dx>=m || dx<0 || dy<0 ||dy>=n || maze[dx][dy]=='+') return false;
    return true;
}
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //directions
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        int count=0;
        int m=maze.size();
        int n=maze[0].size();
        queue<pair<int,int>>q; // cost {x,y}
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int x=q.front().first;
            int y=q.front().second;
            if((x!=entrance[0] || y!=entrance[1]) && (x==0||y==0||x==(m-1)||y==(n-1))) return count;
            q.pop();
            for(int k=0;k<4;k++){
                int xk=x+dx[k];
                int yk=y+dy[k];
                if(isvalid(xk,yk,m,n,maze)){
                    q.push({xk,yk});
                     maze[xk][yk]='+';
                }
            }
            }
               count++;
        }
        return -1;
    }
};