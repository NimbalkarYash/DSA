class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
    unordered_map<char, int> mp;
    int answer = INT_MAX;

    for(int i =0; i<n;i++)
    {
        if(mp.find(s[i]) != mp.end()) //already found
        {
            mp[s[i]] = -1;
        }
        else
        {
            mp[s[i]] = i;
        }
    }

    for(auto i: mp)
        {
           if(i.second == -1) continue;

            answer = min(i.second, answer);
        }
    if(answer == INT_MAX) return -1;
    else return answer;
    }
};