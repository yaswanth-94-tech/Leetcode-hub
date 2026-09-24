class Solution:
    def isValid(self, s: str) -> bool:
        st = []

        for ch in s:
            # If opening bracket → push
            if ch in '([{':
                st.append(ch)
            else:
                # If stack empty → invalid
                if not st:
                    return False

                top = st.pop()

                # Check matching
                if (ch == ')' and top == '(') or \
                   (ch == ']' and top == '[') or \
                   (ch == '}' and top == '{'):
                    continue
                else:
                    return False

        # Stack should be empty at end
        return len(st) == 0