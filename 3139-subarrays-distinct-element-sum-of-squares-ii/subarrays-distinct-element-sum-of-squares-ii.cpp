class Solution {
public:
typedef long long ll;
int n;
const int mod=1e9+7;
vector<ll>lazytree;
vector<ll>sumsegmenttree;
vector<ll>sqsegmenttree;
void  lazyaddition(int i,int l,int r,int val){
    int len=r-l+1;
    ll old=sumsegmenttree[i];
   sqsegmenttree[i]+=2LL*val*old+1LL*len*val*val;
sumsegmenttree[i]+=(1LL*len*val);

}
void  updaterange(int start,int end,int i,int l,int r,int val){
    if(lazytree[i]!=0){
        lazyaddition(i,l,r,lazytree[i]);
    //it means the node is not a leafnode
if(l!=r){
lazytree[2*i+1]+=lazytree[i];
lazytree[2*i+2]+=lazytree[i];
}
lazytree[i]=0;
    }
    // out of range
    if(l>end||r<start||l>r) return;
    //completely within thee range
    if(l>=start && r<=end){
          lazyaddition(i,l,r,val);
          if(l!=r){
    lazytree[2*i+1]+=val;
     lazytree[2*i+2]+=val;          
          }
          return;
    }
    //not within the range
    int mid=l+(r-l)/2;
updaterange(start,end,2*i+1,l,mid,val);
updaterange(start,end,2*i+2,mid+1,r,val);
        sumsegmenttree[i] =
            sumsegmenttree[2 * i + 1] +
            sumsegmenttree[2 * i + 2];

        sqsegmenttree[i] =
            sqsegmenttree[2 * i + 1] +
            sqsegmenttree[2 * i + 2];
}
    int sumCounts(vector<int>& nums) {
        long long result=0;
        n=nums.size();
lazytree.assign(4*n,0);
sumsegmenttree.assign(4*n,0);
sqsegmenttree.assign(4*n,0);
vector<int>lastindex(100001,-1);
for(int i=0;i<n;i++){
    int start=lastindex[nums[i]]+1;
    int end=i;
    updaterange(start,end,0,0,n-1,1);
    result=(result+sqsegmenttree[0])%mod;
    lastindex[nums[i]]=i;
    }
    return result;
    }
};