class Solution {
public:
set<string>setter;
void check(int i,int open,int close,int n,string cur,string &s){
    if(open>close) return;
    if(i>=n){
        if(open==0 && close==0){
            setter.insert(cur);
        }
                 return;
    }
        if(s[i]=='('){
            if(open>0)
            check(i+1,open-1,close,n,cur+'(',s);
            check(i+1,open,close,n,cur,s);
    }
    else if(s[i]==')'){
        if(close>open)
         check(i+1,open,close-1,n,cur+')',s);
        check(i+1,open,close,n,cur,s);
    }
    else{
           check(i+1,open,close,n,cur+s[i],s); 
    }
}
    vector<string> removeInvalidParentheses(string s) {
        int n=s.size();
        int pairs=0;
        stack<char>st;
        for(char ch:s){
            if(ch=='(') st.push(ch);
            else{
                if(ch==')'){
                    if( !st.empty()&&st.top()=='('){
     pairs++;
                    st.pop();
                    }
                }
            }
        }
        check(0,pairs,pairs,n,"",s);
        vector<string>ans(setter.begin(),setter.end());
        return ans;
    }
};