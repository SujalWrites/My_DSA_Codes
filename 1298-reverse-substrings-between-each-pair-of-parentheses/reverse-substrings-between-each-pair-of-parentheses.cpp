class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char ch : s){
            if(ch == ')'){
                string temp;
                while(!st.empty() && st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }

                if(!st.empty()){
                    st.pop();
                }
                for(char t : temp){
                    st.push(t);
                }
            }else{
                st.push(ch);
            }
        }
    string result;
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
       reverse(result.begin(),result.end());
       return result;
    }
};