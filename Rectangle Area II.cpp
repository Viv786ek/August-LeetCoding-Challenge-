class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<vector<int>> line; 
        for (auto& rectangle : rectangles) {
            int x1 = rectangle[0], y1 = rectangle[1], x2 = rectangle[2], y2 = rectangle[3]; 
            line.push_back({y1, x1, x2, 1}); 
            line.push_back({y2, x1, x2, 0}); 
        }
        
        sort(line.begin(), line.end()); 
        
        long ans = 0, val = 0; 
        int yy = 0, prev = 0; 
        multiset<vector<int>> segments; 
        for (auto& elem : line) {
            int y = elem[0], x1 = elem[1], x2 = elem[2], tf = elem[3]; 
            ans = (ans + val * (y - yy)) % 1'000'000'007;
            yy = y; 
            if (tf) segments.insert({x1, x2}); 
            else segments.erase(segments.find({x1, x2})); 
            val = prev = 0;
            for (auto& seg : segments) {
                x1 = seg[0];
                x2 = seg[1]; 
                val += max(0, x2 - max(x1, prev)); 
                prev = max(prev, x2); 
            }
        }
        return ans;
    }
};
