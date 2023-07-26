//linK:https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1
//https://www.youtube.com/watch?v=yNLu2kJUjjU (good explaination)

    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
           vector<int> ans;
    ans.resize(K); // Preallocate memory for the 'ans' vector
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> s; // To keep track of which indexes we have already used
    pq.push({A[N-1] + B[N-1], {N-1, N-1}});
    s.insert({N-1, N-1});
    int index = 0;
    for (int c = 0; c < K; c++) {
        auto it = pq.top();
        pq.pop();
        int val = it.first;
        int i = it.second.first;
        int j = it.second.second;
        ans[index] = val;
        index++;
        if (i > 0 && j >= 0 && s.find({i - 1, j}) == s.end()) {
            pq.push({A[i - 1] + B[j], {i - 1, j}});
            s.insert({i - 1, j});
        }
        if (i >= 0 && j > 0 && s.find({i, j - 1}) == s.end()) {
            pq.push({A[i] + B[j - 1], {i, j - 1}});
            s.insert({i, j - 1});
        }
    }
    return ans;
        
    }