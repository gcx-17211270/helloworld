
public class 减少复制 {
    
}
/*
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-03-05 22:50:21
 * @LastEditors: 32353
 * @LastEditTime: 2021-03-05 22:50:21
 */

class MyQueue {
    private Stack<Integer> a;// 输入栈
    private Stack<Integer> b;// 输出栈
    
    public MyQueue() {
        a = new Stack<>();
        b = new Stack<>();
    }
    
    public void push(int x) {
        a.push(x);
    }
    
    public int pop() {
        // 如果b栈为空，则将a栈全部弹出并压入b栈中，然后b.pop()
        if(b.isEmpty()){
            while(!a.isEmpty()){
                b.push(a.pop());
            }
        }
        return b.pop();
    }
    
    public int peek() {
        if(b.isEmpty()){
            while(!a.isEmpty()){
                b.push(a.pop());
            }
        }
        return b.peek();
    }
    
    public boolean empty() {
        return a.isEmpty() && b.isEmpty();
    }
}

