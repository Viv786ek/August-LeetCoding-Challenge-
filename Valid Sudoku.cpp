 bool isValidSudoku(vector<vector<char>>& board) {
         int N = 9;
        unordered_set<char> rowSet[N];
        unordered_set<char> colSet[N];
        unordered_set<char> squareSet[N];
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                if (val == '.') continue;
                int sPos = (r / 3) * 3 + c / 3;
                if (rowSet[r].count(val) || colSet[c].count(val) || squareSet[sPos].count(val))
                    return false;
                rowSet[r].insert(val);
                colSet[c].insert(val);
                squareSet[sPos].insert(val);
            }
        }
        return true;
    }
