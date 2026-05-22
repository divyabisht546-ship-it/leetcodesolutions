class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>connections(n*n+1,-1);
        bool flag=true;
        int node=1;
        for(int i=n-1;i>=0;i--){
            if(flag){
                for(int j=0;j<n;j++){
                    if(board[i][j]!=-1){
                        int des=board[i][j];
                        connections[node]=des;
                    }
                    node+=1;
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    if(board[i][j]!=-1){
                        int des=board[i][j];
                        connections[node]=des;
                    }
                                    node+=1;
                }
            }
            flag=!flag; //1
        }
        unordered_map<int,vector<int>>graph;
        for(int i=1;i<n*n+1;i++){
            for(int j=1;j<=6 && i+j<=n*n;j++){ //2
                int nbr=i+j;
                if(connections[nbr]!=-1){
                    graph[i].push_back(connections[nbr]);
                }
                else{
                    graph[i].push_back(nbr);
                }
            }
        }
        // bfs traversal
        int level=0;
        vector<bool>visited(n*n+1,false);
        queue<int>q;
        q.push(1);
        visited[1]=true;
        while(!q.empty()){
            int pos=n*n;
            int size=q.size();
            while(size--){
                int f=q.front();
                visited[f]=true;
                 if(pos==f){
                return level;
            }
                q.pop();
                for(auto n:graph[f]){
                    if(!visited[n]){//3
                        visited[n]=true;
                        q.push(n);
                    }
                }
            }
            level+=1;
        }
        return -1;
    }
};