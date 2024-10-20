class Solution {
public:
    int minBitFlips(int s, int g) {
        int cnt=0;
        for(int i=0 ; i<32 ; i++) {
            if( ((s>>i) & 1) != ((g>>i) & 1) ) 
                cnt++;
        }
        return cnt;
    }
};