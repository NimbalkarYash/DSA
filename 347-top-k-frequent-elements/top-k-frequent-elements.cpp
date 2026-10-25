class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        for( auto i: nums)
        {
            mapp[i]++;
        }
        priority_queue<pair<int,int>> pq;

        for( auto &it: mapp)
        {
            pq.push({it.second, it.first});

        }

        vector<int> result;
        int count = 0;
        while(!pq.empty() && count<k)
        {
            result.push_back(pq.top().second);
            pq.pop();
            count+=1;
        }
        return result;
    }
};