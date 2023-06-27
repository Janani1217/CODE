class MyStack {
    Queue<Integer> q ;

    public MyStack() {
        q = new LinkedList<>();
    }
    
    public void push(int x) {
        q.add(x);
    }
    
    public int pop() {
        int count = q.size();
        if(q.size() > 0){
            while(count > 1){
                int x = q.peek();
                q.remove();
                q.add(x);
                count = count -1;
            }
            int x = q.peek();
            q.remove();
            System.out.println("pop ele = " + x);
            return x;
        }
        
        return -1;
    }
    
    public int top() {
        
        if(q.size() > 0){
            System.out.println("size = " + q.size());
            int count = q.size();
            
            while(count > 1){
                int x = q.peek();
                count = count -1;
                q.remove();
                q.add(x);
            }
            
            int ele = q.peek();
            q.remove();
            q.add(ele);
            System.out.println("top ele = " + ele);
            return ele;
            
        }
        return -1;
    }
    
    public boolean empty() {
        if(q.size() == 0)
            return true;
        return false;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */