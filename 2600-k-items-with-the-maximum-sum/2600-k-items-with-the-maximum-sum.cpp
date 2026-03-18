class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum = 0;
        while(k > 0){
            if(numOnes != 0){
                sum += 1;
                numOnes--;
                k--;
            }
            else if(numOnes == 0 && numZeros != 0){
                numZeros--;
                k--;
            }
            else if(numZeros == 0 && numOnes == 0 && numNegOnes != 0){
                sum += -1;    
                numNegOnes--;
                k--;
            }
        }
        return sum;
    }
};
