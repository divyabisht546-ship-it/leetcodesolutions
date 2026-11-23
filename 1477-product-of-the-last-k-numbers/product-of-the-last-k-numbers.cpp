class ProductOfNumbers {
public:
//
  vector<int>arr;
    ProductOfNumbers() {
    }
    
    void add(int num) {
    arr.push_back(num);
    }
    
    int getProduct(int k) {
// [3],[0],[2],[5],[4]
        int n=arr.size();
        int product=1;
        int back=n-1;
        while(k--){
            product*=arr[back];
            back--;
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */