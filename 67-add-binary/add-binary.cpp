class Solution {
public:
    string addBinary(string a, string b) {
        string temp;
        int i=a.size()-1;
        int carry=0;
        int j=b.size()-1;
        while(i>=0 || j>=0 ||carry==1){
            if(i>=0){
                carry+=(a[i]-'0');
                i--;
            }
            if(j>=0){
                carry+=(b[j]-'0');
                j--;
            }
            temp.push_back((carry % 2)+'0');
            carry=carry/2;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};