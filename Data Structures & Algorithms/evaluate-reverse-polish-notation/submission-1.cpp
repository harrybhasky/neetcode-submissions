class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;

        for (const string& x : tokens) {
            if (x.size() > 1 || (x[0] >= '0' && x[0] <= '9')) {
                num.push(stoi(x));
            }
            else {
                int b = num.top(); num.pop();
                int a = num.top(); num.pop();

                int c;
                if (x == "+") c = a + b;
                else if (x == "-") c = a - b;
                else if (x == "*") c = a * b;
                else c = a / b;

                num.push(c);
            }
        }

        return num.top();  
    }
};