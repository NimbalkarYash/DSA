class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int count = 0;
        int sum = 0;
        mp[0] = 1;

        for(auto num: nums)
        {
            sum += num;

            int remaining = sum - k;
            //if(remaining < 0) continue;
            if(mp.count(remaining))
            {
                count += mp[remaining];
            }

            mp[sum] += 1;
        }

        return count;

    }
};