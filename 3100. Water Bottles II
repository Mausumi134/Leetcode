class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int a = 1;
        int b = 2 * numExchange - 3;
        int c = -2 * numBottles;
        double delta = (double)b * b - 4.0 * a * c;
        int t = (int)ceil((-b + sqrt(delta)) / (2.0 * a));
        return numBottles + t - 1;
    }
};