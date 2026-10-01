class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch:s){
            if(ch=='(' || ch=='[' || ch=='{')st.push(ch);
            else {
                if(ch==')' && (st.empty() || st.top()!='(')) return false;         
                else if(ch==']' && (st.empty() || st.top()!='[')) return false;
                else if(ch=='}' && (st.empty() || st.top()!='{')) return false;
                st.pop();
            }
        }    
        if(st.empty()) return true;
        return false;            
    }
};