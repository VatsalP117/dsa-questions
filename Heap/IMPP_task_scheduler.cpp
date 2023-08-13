//link:https://leetcode.com/problems/task-scheduler/submissions/

//greedy: always do the mist frequently occuring task first

//easy to understand ,intuitive solution
//easy to understand situation
class Solution {
public:
    struct Pair{
        int frequency;
        int availableTime; //the time at which this task will be available to add
        Pair(int f,int t){
            frequency=f;
            availableTime=t;
        }
    };
    int leastInterval(vector<char>& tasks, int n) {
        //n is the cooldown period here
        vector<int> char_freq(26,0);
        for(char ch:tasks){
            char_freq[ch-'A']++;
        }
        priority_queue<int> pq; //max heap to store all the frequencies of tasks
        for(int i=0;i<26;i++){
            int count=char_freq[i];
            if(count>=1) {
                pq.push(count);
            }
        }
        //pq now has all the frequencies of tasks we have
        queue<Pair> waitingQueue;
        int currTime=1;
        //pq only has those elements which can be executed whenever we want, unpe koi cooldown restrictions nahi h
        //restrictions wale waiting queue mai hai
        while(!pq.empty() || !waitingQueue.empty()){
            //see if someone from waiting just got ready
            while(waitingQueue.empty()==false){
                if(waitingQueue.front().availableTime==currTime){
                    pq.push(waitingQueue.front().frequency);
                    waitingQueue.pop();
                }
                else break;
            }
            if(pq.empty()==false){
                int max_freq=pq.top();
            pq.pop();
            if(max_freq>1){
                waitingQueue.push(Pair(max_freq-1,currTime+n+1));
            }
            }
            
            currTime++;
        }
        return currTime-1;
    }
};

//approach 2
class Solution {
public:
    int leastInterval(vector<char>& tasks, int c) {
        int n=tasks.size();
        vector<int> f(26,0);
        for(char ch:tasks){
            f[ch-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(f[i]>0){
                pq.push(f[i]);
            }
        }
        //now ready
        int time=0;
        while(!pq.empty()){
            int cycle=c+1;
            vector<int> remain;
            while(cycle>0 && pq.empty()==false){
                int task_freq=pq.top();
                pq.pop();
                if(task_freq>1){
                    //to abhi bhi khatam nahi hua hai
                    remain.push_back(task_freq-1);
                }
                cycle--;
                time++;

            }
            for(int it:remain) pq.push(it);
            if(pq.empty())break;
            time+=cycle;
        }
        return time;
    }
};

