//link:https://www.codingninjas.com/studio/problems/jump-game_3164697?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1

bool jump_search(vector<int> &jump, int n){
    // Write your code here.
    vector<int> max_reach(n,-1);
    max_reach[n-1]=n-1;
    for(int i=n-2;i>=0;i--){
        //basically if curr_index+max_jump_possible >=destination, we can reach our destination
        if(i+jump[i]>=n-1){
            max_reach[i]=n-1;
        }
        else{
            int new_max_index=i+jump[i];
            max_reach[i]=max_reach[new_max_index];
        }
    }
    if(max_reach[0]==n-1) return true;
    else return false;
}