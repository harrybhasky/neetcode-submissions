class Solution {
public:
    bool isValid(string s) {
        // if its odd then return false
        //pushh awhen opening bracket, then compare top and pop

        stack <char> symb;

        for( int i=0; i<s.size(); i++){
            char c = s[i];
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            symb.push(s[i]);
            }
            else{
            if (symb.empty()) {
                    return false;
                }
            char top = symb.top();

            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                    symb.pop(); 
                }
                else{
            return false;}


        }
        }
        return symb.empty();

    }
    // if stack gets empty, everything is maytched then

};
