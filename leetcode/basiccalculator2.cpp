class Solution {
public:
    int calculate_help(int left, char symbol, int right)
    {
	    switch(symbol)
	    {
		    case '*':
			    return left * right;
		    case '/':
			    return left / right;
		    default:
			    return 0;
	    }
    }
    
    int calculate(string s) {
        int n = s.length();
	    if (n < 1)
	    {
		    return 0;
	    }

	    int result = 0;
	    stack<int> value;
	    stack<char> symbol;
	    symbol.push('+');
	    for (int i = 0; i < n;)
	    {
		    if (s[i] == '+' || s[i] == '-'
			    || s[i] == '*' || s[i] == '/')
		    {
			    symbol.push(s[i]);
			    i++;
		    }
		    else if (s[i] == ' ')
		    {
		        i++;
		    }
		    else
		    {
			    int right = 0;
			    while (i < n && s[i] <= '9' && s[i] >= '0')
			    {
				    right = right*10 + s[i]-'0';
				    i++;
			    }
			    if (!symbol.empty() && (symbol.top() == '*' || symbol.top() == '/'))
			    {
				    right = calculate_help(value.top(), symbol.top(), right);
				    value.pop();
				    symbol.pop();
			    }

			    value.push(right);
		    }
	    }

	    while (!symbol.empty())
	    {
		    int temp = value.top();
		    if (symbol.top() == '-')
		    {
			    temp = -temp;
		    }
		    result += temp;
		    value.pop();
		    symbol.pop();
	    }

	    return result;
    }
};