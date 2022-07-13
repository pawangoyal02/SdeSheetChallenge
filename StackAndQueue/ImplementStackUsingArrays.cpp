// Stack class.
class Stack {
    int topp;
    int arr[10000];
    int size;
public: 
    Stack(int capacity) {
        topp = -1;
        size = capacity;
    }

    void push(int num) {
        if(topp>=size)
        {
            return;
        }
        arr[++topp]= num;
    }

    int pop() {
        if(topp!=-1)
         return arr[topp--];
        else 
         return -1;
    }
    
    int top() {
        if(topp!=-1 && topp<size)
            return arr[topp];
        else
            return -1;
    }
    
    int isEmpty() {
        if(topp==-1)
            return 1;
        else
            return 0;
    }
    
    int isFull() {
        if(topp>=size)
            return 1;
        else
            return 0;
    }
};