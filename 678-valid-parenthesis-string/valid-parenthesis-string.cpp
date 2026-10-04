class Solution {
public:
    bool checkValidString(string s) {
    //left
    bool ans1=true;
    int leftopen=0;
    int leftclose=0;
    int star1=0;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='(')  leftopen++;
        if(ch==')')  leftclose++;
        if(ch=='*') star1++;
        if(leftclose>leftopen+star1) ans1=false;
    }
     bool ans2=true;
    int rightopen=0;
    int rightclose=0;
    int star2=0;
    for(int i=s.size()-1;i>=0;i--){
        char ch=s[i];
        if(ch=='(') rightopen++;
        if(ch==')')  rightclose++;
        if(ch=='*') star2++;
        if(rightopen>rightclose+star2) ans2=false;
    }
    return ans1&&ans2;
    }
};