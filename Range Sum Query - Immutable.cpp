//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3892/

class NumArray {
public:
    vector<int>& preSum; // store the reference to the original array
    
    NumArray(vector<int>& nums) : preSum(nums) {
        for (int i = 1; i < preSum.size(); ++i)
            preSum[i] += preSum[i-1]; 
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return preSum[right];
        return preSum[right] - preSum[left-1];
    }
};
