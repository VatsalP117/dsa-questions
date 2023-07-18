// Stack class.
class Stack {
    
public:
    vector<int> arr;
    int ptr;
    int cap;
    Stack(int capacity) {
        // Write your code here.
        arr.resize(capacity);
        ptr=0;
        //can also try with initalizing ptr=-1 basically index of last pushed element
        cap=capacity;
    }

    void push(int num) {
        // Write your code here.
        if(ptr==cap) return;
        arr[ptr]=num;
        ptr++;
    }

    int pop() {
        // Write your code here.
        if(ptr==0) return -1;
        else{
            ptr--;
            return arr[ptr];
        }
    }
    
    int top() {
        // Write your code here.
        if(ptr==0) return -1;
        else return arr[ptr-1];
    }
    
    int isEmpty() {
        // Write your code here.
        if(ptr==0) return 1;
        else return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(ptr==cap) return 1;
        else return 0;
    }
    
};
