import java.util.ArrayList;

/*
 * Stack : FILO :
 * 
 * All operations in O(1)
 * operations : push , pop , getMin , top
 * 
 * .............................................................................
 * 
 * To implement the getMin() :
 * 
 * 1. we have to maintain a variable which will store the min value
 * during we perform the push() operation.
 * 
 * 2. once we receive the next min value, first push the curr min val
 * into the stack and then update the min_val variable.
 * 
 * 3. this would help in the situation where pop() is called and
 * the min_val is present on the top of the stack. So on pop() this
 * will get removed and we wont be having the next min value present.
 * 
 * 4. so when pop() is called and the top == min_val, first we will pop()
 * then we will update the var min_val = top ,which is the next ele
 * present after it. And after the update , pop that ele also.
 * 
 * .............................................................................
 * 
 *  Initialize the stack with some value ~ infinity / INT_MAX ; 
 * 
 * .............................................................................
 * 
 * 
 */

class MinStack {
    int min_val = Integer.MAX_VALUE;
    ArrayList<Integer> arr = null;

    public MinStack() {
        arr = new ArrayList<>();
    }

    public void push(int val) {
        if (val <= min_val) {
            arr.add(min_val);
            arr.add(val);
            min_val = val;
        } else {
            arr.add(val);
        }
    }

    public void pop() {
        if (arr.size() > 0) {
            int topval = top();
            System.out.println("top = " + topval);
            if (top() == min_val) {
                arr.remove(arr.size() - 1);
                min_val = top();
                arr.remove(arr.size() - 1);
            } else {
                arr.remove(arr.size() - 1);
            }
        }
    }

    public int top() {
        if (arr.size() > 0) {
            return arr.get(arr.size() - 1);
        }
        return -1;
    }

    public int getMin() {
        return min_val;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */