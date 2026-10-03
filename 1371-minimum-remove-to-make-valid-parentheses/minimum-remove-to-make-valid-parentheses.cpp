class Solution {
public:
    string minRemoveToMakeValid(string s) {
          stack<pair<int,int>>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push({'(',i});
        }
        else if(s[i]==')'){
            if(!st.empty() && st.top().first=='('){
                  st.pop();
            }
            else st.push({')',i});
        }
    }
    unordered_set<int>setty;
  while(!st.empty()){
      setty.insert(st.top().second);
      st.pop();
  }
  string temp="";
  for(int i=0;i<s.size();i++){
      if(setty.find(i)!=setty.end()) continue;
      else temp+=s[i];
  }
  return temp;
    }
};