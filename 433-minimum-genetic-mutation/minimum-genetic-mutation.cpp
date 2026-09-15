class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
    string start=startGene;
    string end=endGene;
    set<string>b(bank.begin(),bank.end());
    unordered_map<string,bool>visit;
    queue<string>q;
    q.push(start);
    int level=0;
    visit[start]=true;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            string temp=q.front();
            q.pop();
visit[temp]=true;
            if(temp==end) {
                return level;
            }
    
            for(char c:string("ACTG")){
                for(int i=0;i<temp.size();i++){
                    string s=temp;
                    if(s[i]!=c){
                        s[i]=c;
                        if(!visit[s] && b.find(s)!=b.end()){
                            q.push(s);
                            visit[s]=true;
                        }
                    }
                }
            }
        }
        level++;
    }
    return -1;
    }
};