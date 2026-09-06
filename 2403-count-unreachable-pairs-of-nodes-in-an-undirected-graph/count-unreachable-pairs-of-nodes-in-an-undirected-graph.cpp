class Solution {
public:
int find(int i,vector<int>&parent){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i],parent);
}
void un(int x,int y,vector<int>&parent,vector<int>&rank){
    int x_p=find(x,parent);
    int y_p=find(y,parent);
    if(x_p==y_p) return;
if(rank[x_p]<rank[y_p]){
parent[x_p]=y_p;
}
else if(rank[x_p]>rank[y_p]){
parent[y_p]=x_p;
}
else{
parent[x_p]=y_p;
rank[y_p]++;
}
}
    long long countPairs(int n, vector<vector<int>>& edges) {
         vector<int>parent(n,0);
         long long rem=n;
   for(int i=0;i<n;i++){
    parent[i]=i;
   }
   unordered_map<int,int>mp;
    vector<int>rank(n,0);
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        un(u,v,parent,rank);
    }
    for(int i=0;i<n;i++){
        int ans=find(i,parent);
        mp[ans]++;
    }
   long long count=0;
   for(auto it=mp.begin();it!=mp.end();it++){
    long long size=it->second;
count+=size*(rem-size);
rem=rem-size;
   }
   return count;
    }
};