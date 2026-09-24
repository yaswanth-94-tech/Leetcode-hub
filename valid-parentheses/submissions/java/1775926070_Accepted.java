import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            // If opening bracket → push
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } 
            else {
                // If stack empty → invalid
                if (st.isEmpty()) {
                    return false;
                }

                char top = st.pop();

                // Check matching
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{')) {
                    continue;
                } 
                else {
                    return false;
                }
            }
        }

        // Stack should be empty
        return st.isEmpty();
    }
}