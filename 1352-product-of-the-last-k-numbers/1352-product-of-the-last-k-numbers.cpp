class ProductOfNumbers {
public:
    vector<int>products;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        products.push_back(num);
    }
    
    int getProduct(int k) {
         int n=products.size();
         int product=1;
         for(int i=n-1;i>=n-k;i--){
            product*=products[i];
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