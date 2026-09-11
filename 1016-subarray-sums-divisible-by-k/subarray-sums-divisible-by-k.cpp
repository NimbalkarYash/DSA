class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;

        for(auto num: nums)
        {
            sum += num;

            int remainder = sum % k;

            if(remainder < 0 ) remainder += k;
            if(mp.count(remainder)){
                count += mp[remainder];
            } 

            mp[remainder] += 1;
        }

        return count;
    }
};