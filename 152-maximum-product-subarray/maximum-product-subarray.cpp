class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lproduct = 1;
        int rproduct = 1;
        int result = INT_MIN;

        for(int i=0; i<nums.size();i++)
        {
            if(lproduct == 0) lproduct = 1;
            if(rproduct == 0) rproduct = 1;

            lproduct *= nums[i];
            rproduct *= nums[nums.size()-i-1];
            result = max(result, max(lproduct, rproduct));
        }

        return result;
    }
};