class Solution {
public:
long long solve(vector<int>&arr,int l,int mid,int r){
    int n1=mid-l+1;
    int n2=r-mid;
    vector<int>left(n1);
    vector<int>right(n2);
    long long p=0;
    long long count=0;
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[mid+1+j];
    }
    for(int i=0;i<n1;i++){
        while(p<n2 && left[i]>1LL*2*right[p]){
            p++;
        }
        count+=p;
    }
int i=0;
int j=0;
int k=l;
while(i<n1 && j<n2){
if(left[i]<=right[j]){
arr[k++]=left[i++];}
else{
    arr[k++]=right[j++];
}}
while(i<n1){
    arr[k++]=left[i++];
}
while(j<n2){
    arr[k++]=right[j++];
}
return count;
}
long long merge(vector<int>&nums,int l,int r){
    long long count=0;
    if(l>=r) return 0;
    int mid=l+(r-l)/2;
   count+=merge(nums,l,mid);
   count+=merge(nums,mid+1,r);
   count+=solve(nums,l,mid,r);
   return count;
}
    int reversePairs(vector<int>& nums) {
       return merge(nums,0,nums.size()-1); 
    }
};