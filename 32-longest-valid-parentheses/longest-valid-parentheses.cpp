class Solution {
public:
    int longestValidParentheses(string s) {
        //left to right
        int leftclose=0;
        int leftopen=0;
        int ans1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') leftopen++;
            if(s[i]==')') leftclose++;
            if(leftopen==leftclose){
            int result=leftopen+leftclose;
            ans1=max(ans1,result);
            }
            else if(leftclose>leftopen){
                leftopen=0;
                leftclose=0;
            }
        }
        //right to left
         int rightclose=0;
        int rightopen=0;
        int ans2=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') rightopen++;
            if(s[i]==')') rightclose++;
            if(rightopen==rightclose){
            int result=rightopen+rightclose;
            ans1=max(ans1,result);
            }
            else if(rightclose<rightopen){
                rightopen=0;
rightclose=0;
            }
        }
        return max(ans1,ans2);
        //max(right toleft,left to right)
    }
};