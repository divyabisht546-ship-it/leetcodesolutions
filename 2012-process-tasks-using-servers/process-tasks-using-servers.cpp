class Solution {
public:
    typedef tuple<long long,int,int>t;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        // freeserver
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>free_server;
       for(int i=0;i<servers.size();i++)
       {
           free_server.push({servers[i],i});
       }
        
        priority_queue<t,vector<t>,greater<t>>busy_server; 
        // anser is here
        int m=tasks.size();
vector<int>ans(m);
        for(int i=0;i<tasks.size();i++){
            int fre_w=free_server.top().first;
            int fre_i=free_server.top().second;
    
        // if(busy_server.empty()){
        //     ans[i]=fre_i;
        //     busy_server.push({i+tasks[i],fre_w,fre_i});
        //     free_server.pop();
        // }
        // move busy servers to free servers if they are free by ith time
        // get in tuple gives us first element
  while(!busy_server.empty() && get<0>(busy_server.top())<=i){
    auto[fin,wt,idx]=busy_server.top();
    busy_server.pop();
    free_server.push({wt,idx});
  }
   if(free_server.empty()){
        auto[fin_time,busy_w,busy_i]=busy_server.top();
        ans[i]=busy_i;
        busy_server.pop();
        busy_server.push({fin_time+tasks[i],busy_w,busy_i});
    }
    else{
        auto[wt,idx]=free_server.top();
        free_server.pop();
        ans[i]=idx;
        busy_server.push({i+tasks[i],wt,idx});
    }
        }
        return ans;
    }
};