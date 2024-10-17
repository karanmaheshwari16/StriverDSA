class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt = 0;
        int j = 0 , i = 0;

        if(s.size() == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin() , s.end());

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                cnt++;
                j++; i++;
            }
            else {
                j++;
            }
        }
        return cnt;
    }
};