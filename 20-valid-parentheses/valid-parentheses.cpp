class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return "true";
			stack<char> st;
			
			for(char it: s)
			{
				
				if(it == '(' || it == '[' || it == '{')
				{
					st.push(it);
				}
				else
				{
					if(st.empty()) return false;
					char p = st.top();
					
					if(it == ')')
					{
						if(p == '(') st.pop();
						else 
						{
							return false;
						}
					}
					else if(it == ']')
					{
						if(p == '[') st.pop();
						else 
						{
							return false;
						}
					}
					else if(it == '}')
					{
						if(p == '{') st.pop();
						else 
						{
							return false;
						}
					}
					else continue;
				}

			}
			if(st.empty())
			{
				return true;
			}
			else
			{
				return false;
			}
    }
};