// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
#include "alg.h"
std::string infx2pstfx(std::string inf) {
  // добавьте код
  TStack<char, 100> stack;
    std::string postfix = "";

    for (char c : inf) {
        if (std::isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                postfix += " ";
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!stack.isEmpty() && 
                   (stack.top() == '*' || stack.top() == '/' || 
                    (c == '+' || c == '-') && (stack.top() == '+' || stack.top() == '-'))) {
                postfix += " ";
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
            postfix += " ";
        }
    }

    while (!stack.isEmpty()) {
        postfix += " ";
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
  return std::string("");
}

int eval(std::string pref) {
  // добавьте код
  TStack<int, 100> stack;
    std::stringstream ss(post);
    std::string token;
    while (ss >> token) {
        if (std::isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();
            if (token[0] == '+') {
                stack.push(operand1 + operand2);
            } else if (token[0] == '-') {
                stack.push(operand1 - operand2);
            } else if (token[0] == '*') {
                stack.push(operand1 * operand2);
            } else if (token[0] == '/') {
                stack.push(operand1 / operand2);
            }
        }
    }
    return stack.top();
  return 0;
}
