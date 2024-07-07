class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;
        
        while (emptyBottles >= numExchange) {
            int newBottles = emptyBottles / numExchange;
            int remainder = emptyBottles % numExchange;
            ans += newBottles;
            emptyBottles = newBottles + remainder;
        }
        
        return ans;
    }
};
