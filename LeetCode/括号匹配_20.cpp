/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
 */
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (st.empty() && (s[i] == '}' || s[i] == ')' || s[i] == ']')) //若栈为空，并且输入为右括号
                return false;
            if (s[i] == '}' || s[i] == ')' || s[i] == ']')
            {
                if (s[i] - st.top() == 1 || s[i] - st.top() == 2) //左右括号值差1或2
                    st.pop();                                   //若匹配，则出栈
                else 
                    return false;
            }
            else
            {
                st.push(s[i]);  //左括号进栈
            }
        }
        return st.empty();
    }
};
