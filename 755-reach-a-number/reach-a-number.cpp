class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        int s = 0;
    
    
    while (s < target or (s - target) % 2 != 0)
     {
        k += 1;
        s += k;
     }  
    return k;
    }
};