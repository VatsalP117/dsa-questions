vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1);
        row[0] = row[i] = 1;
        for (int j = 1; j < i; j++) {
            vector<int> prev_row = ans[i - 1];
            row[j] = prev_row[j - 1] + prev_row[j];
        }
        ans[i] = row;
    }
    return ans;
}