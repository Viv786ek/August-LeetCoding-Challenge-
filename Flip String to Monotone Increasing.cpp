class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one=0;
        int zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
                one++;
            else
                zero++;
            zero = min(zero,one);
            
        }
        return zero;
    }
};
