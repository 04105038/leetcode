#include <iostream>  
#include<vector>
#include <string>  
#include<queue>
#include<set>
#include<stack>
using namespace std;
class Solution {
public:
    bool isvalidparentheses(string s){
        if (s.empty()) return true;
        stack<char> stk;
        int i = 0;
        while (i<s.length()){
            if (s[i] == ')')    return false;
            if (s[i] == '('){
                stk.push(s[i]);
                i++;
                break;
            }
            i++;
        }
        for (; i<s.length(); i++){
            if (s[i] == '(')  stk.push(s[i]);
            if (s[i] == ')'){
                if (stk.empty())
                    return false;
                stk.pop();
            }
        }
        if (stk.empty()) return true;
        return false;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        queue<string> q;
        q.push(s);
        while (!q.empty()){
            set<string> foundstring;
            bool flag = false;
            int n = q.size();
            for (int i = 0; i<n; i++){
                string tmp = q.front();
                q.pop();
                if (isvalidparentheses(tmp)){
                    result.push_back(tmp);
                    flag = true;
                }
                if (!flag){
                    for (int j = 0; j<tmp.length(); j++){
                        if (tmp[j] == '(' || tmp[j] == ')'){
                            string wantadd = tmp.substr(0, j) + tmp.substr(j + 1);
                            if (foundstring.find(wantadd) == foundstring.end()){
                                q.push(wantadd);
                                foundstring.insert(wantadd);
                            }
                        }
                    }
                }
            }
            if (flag)
                return result;
        }
    }
};

int main(){
    Solution eg;
    string s = "()())()";
    vector<string> result = eg.removeInvalidParentheses(s);
    cout << eg.isvalidparentheses(s) << " hepan"<<endl;
    cout << result[0]<< " "<<result[1]<<" hepan" << endl;
    return 0;
}