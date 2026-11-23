class ProductOfNumbers {
private:
  
    vector<int> prefixProduct;
    int size = 0;

public:
    ProductOfNumbers() {
        
        prefixProduct.push_back(1);
        size = 0;
    }

    void add(int num) {
        if (num == 0) {
         
            prefixProduct = {1};
            size = 0;
        } else {
            
            prefixProduct.push_back(prefixProduct[size] * num);
            size++;
        }
    }

    int getProduct(int k) {
       
        if (k > size) return 0;
        return prefixProduct[size] / prefixProduct[size - k];
    }
};
/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */