class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0;
        int sum=0;
        int rsum=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        sum=lsum;
        for(int i=0;i<k;i++){
            lsum-=cardPoints[k-i-1];
            rsum+=cardPoints[n-i-1];
            sum=max(sum,lsum+rsum);
        }
        return sum;
    }
};