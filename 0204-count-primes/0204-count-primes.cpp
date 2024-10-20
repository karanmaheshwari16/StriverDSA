class Solution {
public:
    int countPrimes(int n) {
        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        if(n <= 1) return 0;
        int count = 0;
        vector<bool> v(n+1,1);
        v[0] = v[1] = 0;

        for(int i=2 ; i<n ; i++) {
            if(v[i] == true) {
                for(int j=2*i ; j<=n ; j+=i) {
                    v[j] = false;
                }
            }
        }
        
        for(int i=0 ; i<n ; i++) {
            if(v[i] == 1) count++;
        }

        return count;
    }
};