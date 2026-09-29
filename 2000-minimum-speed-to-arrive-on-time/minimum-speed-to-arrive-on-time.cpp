class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1, e = 10000000;
        int ans = -1;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            double hrs = 0;

            for (int i = 0; i < dist.size() - 1; i++) {
                // Removed the extra parenthesis at the end of this line
                hrs += (dist[i] + mid - 1) / mid; 
            }

            hrs += (double) dist[dist.size() - 1] / mid;

            if (hrs <= hour) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};