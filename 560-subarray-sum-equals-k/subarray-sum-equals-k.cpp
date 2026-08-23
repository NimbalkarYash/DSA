class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; 
        
        int currentSum = 0;
        int count = 0;

        for (int x : nums) {
            currentSum += x;

            if (prefixCount.count(currentSum - k)) {
                count += prefixCount[currentSum - k];
            }

            prefixCount[currentSum]++;
        }

        return count;
    }
};