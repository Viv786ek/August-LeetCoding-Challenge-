class Solution {
public:
    
    int dp[100][100][100];
    int solve(vector<int>& boxes, int i, int j, int k)
    {
        if(i>j) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int res = (k+1)*(k+1)+solve(boxes,i+1,j,0);
        for(int it=i+1; it<=j; it++)
            if(boxes[it]==boxes[i]) 
                res = max(res,solve(boxes,i+1,it-1,0)+solve(boxes,it,j,k+1));
        return dp[i][j][k]=res;
    }
    int removeBoxes(vector<int>& boxes) {
         memset(dp,-1,sizeof dp);
        return solve(boxes, 0, boxes.size()-1, 0);   
    }
};
