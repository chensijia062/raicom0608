#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    stack<int> num;
    stack<char> ops;
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            continue;
        }
        if(isdigit(s[i])){
            int x=0;
            while(i<s.length()&&isdigit(s[i])){
                x=x*10+(s[i]-'0');
                i++;
            }
            i--;
            num.push(x);
        }else if(s[i]=='('){
            ops.push(s[i]);
        }else if(s[i]==')'){
            while(ops.top()!='('){
                int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                char op=ops.top();
                ops.pop();
                if(op=='+'){
                    num.push(a+b);
                }else if(op=='-'){
                    num.push(b-a);
                }else if(op=='*'){
                    num.push(a*b);
                }else if(op=='/'){
                    num.push(b/a);
                }else if(op=='%'){
                    num.push(b%a);
                }
            }
            ops.pop();
        }else{
            if(s[i]=='='){
                while(ops.size()){
                    int a=num.top();
                num.pop();
                int b=num.top();
                num.pop();
                char op=ops.top();
                ops.pop();
                if(op=='+'){
                    num.push(a+b);
                }else if(op=='-'){
                    num.push(b-a);
                }else if(op=='*'){
                    num.push(a*b);
                }else if(op=='/'){
                    num.push(b/a);
                }else if(op=='%'){
                    num.push(b%a);
                }
                }
                break;
            }else if(s[i]=='+'||s[i]=='-'){
              if(!ops.empty() && (ops.top() == '*' || ops.top() == '/' || ops.top() == '%')) {
                    int a = num.top(); num.pop();
                    int b = num.top(); num.pop();
                    char op = ops.top(); ops.pop();   
                    if(op == '*') {
                        num.push(b * a);
                    } else if(op == '/') {
                        num.push(b / a);
                    } else if(op == '%') {
                        num.push(b % a);
                    }
                }
                else if(!ops.empty() && (ops.top() == '+' || ops.top() == '-')) {
                    int a = num.top(); num.pop();
                    int b = num.top(); num.pop();
                    char op = ops.top(); ops.pop();              
                    if(op == '+') {
                        num.push(b + a);
                    } else if(op == '-') {
                        num.push(b - a);
                    }
                }
                ops.push(s[i]);               
            }else if(s[i]=='*'||s[i]=='/'||s[i]=='%'){
                 if(!ops.empty() && (ops.top() == '*' || ops.top() == '/' || ops.top() == '%')) {
                    int a = num.top(); num.pop();
                    int b = num.top(); num.pop();
                    char op = ops.top(); ops.pop();              
                    if(op == '*') {
                        num.push(b * a);
                    } else if(op == '/') {
                        num.push(b / a);
                    } else if(op == '%') {
                        num.push(b % a);
                    }
                }
                ops.push(s[i]);
            }
        }
    }
    cout<<num.top();
    return 0;
}