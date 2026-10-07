class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size()-1;
        char tar = tolower(target);
        char ans = letters[0];
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(letters[mid] > tar)
            {
                ans = letters[mid];
                r = mid-1;
            }
            else if(letters[mid] == tar)
            {
                l = mid+1;
            }
            else
            {
                l = mid+1;
            }

        }
        return ans;

    }
};