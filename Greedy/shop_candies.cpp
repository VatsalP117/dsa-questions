//for every 1 candy you buy, you get any K candies free
vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        vector<int> ans;
        int i=0;
        int j=N-1;
        int minCost=0;
        while(i<=j){
            minCost+=candies[i];
            j=j-K;
            i++;
        }
        ans.push_back(minCost);
        int maxCost=0;
        reverse(candies,candies+N);
        i=0;
        j=N-1;
        while(i<=j){
            maxCost+=candies[i];
            j=j-K;
            i++;
        }
        ans.push_back(maxCost);
        return ans;
    }