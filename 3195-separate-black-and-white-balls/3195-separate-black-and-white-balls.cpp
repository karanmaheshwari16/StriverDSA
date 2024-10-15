class Solution {
public:
    long long minimumSteps(string s) {

        long long ans = 0;
        long long zero_right = 0;
        
        for(int i=s.size()-1 ; i>=0 ; i--) {
            if(s[i] == '0') zero_right++;
            else ans += zero_right;
        }

        // cout<<s.size();
        return ans;
    }
};