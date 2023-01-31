// Mehmet Feyyaz Küçük 22003550

#include <string>
#include <iostream>
#include <sstream>
#include "AlgebraicExpression.h"
using namespace std;

string infix2prefix(const string exp) {
    string prefixExp = "";
    Stack stack;

    string top = "";
    string cur = "";
    for (int i = exp.length() - 1; i >= 0; i--) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                stack.getTop(top);
                while (!stack.isEmpty() && top != ")" && precedence(cur) <= precedence(top)) {
                    prefixExp = top + " " + prefixExp;
                    stack.pop();
                }
                stack.push(cur);
            }
            else if (cur == ")") {
                stack.push(cur);
            }
            else if (cur == "(") {
                stack.getTop(top);

                while (top != ")") {
                    prefixExp = top + " " + prefixExp;
                    stack.pop();
                    stack.getTop(top);
                }
                stack.pop();
            }
            else {
                prefixExp = reverse(cur) + " " + prefixExp;
            }

            cur = "";
        }
    }

    if (isOperator(cur)) {
        stack.getTop(top);
        while (!stack.isEmpty() && top != ")" && precedence(cur) <= precedence(top)) {
            prefixExp = top + " " + prefixExp;
            stack.pop();
            stack.getTop(top);
        }
        stack.push(cur);
    }
    else if (cur == ")") {
        stack.push(cur);
    }
    else if (cur == "(") {
        stack.getTop(top);

        while (top != ")") {
            prefixExp = top + " " + prefixExp;
            stack.pop();
            stack.getTop(top);
        }
        stack.pop();
    }
    else {
        prefixExp = reverse(cur) + " " + prefixExp;
    }

    cur = "";

    while (!stack.isEmpty()) {
        stack.pop(top);
        prefixExp = top + " " + prefixExp;
    }

    return prefixExp;
}

string infix2postfix(const string exp) {
    string postfixExp = "";
    Stack stack;

    string top = "";
    string cur = "";
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                stack.getTop(top);
                while (!stack.isEmpty() && top != "(" && precedence(cur) <= precedence(top)) {
                    postfixExp += top + " ";
                    stack.pop();
                    stack.getTop(top);
                }
                stack.push(cur);
            }
            else if (cur == "(") {
                stack.push(cur);
            }
            else if (cur == ")") {
                stack.getTop(top);

                while (top != "(") {
                    postfixExp += top + " ";
                    stack.pop();
                    stack.getTop(top);
                }
                stack.pop();
            }
            else {
                postfixExp += cur + " ";
            }

            cur = "";
        }
    }

    if (isOperator(cur)) {
        stack.getTop(top);
        while (!stack.isEmpty() && top != "(" && precedence(cur) <= precedence(top)) {
            postfixExp += top + " ";
            stack.pop();
        }
        stack.push(cur);
    }
    else if (cur == "(") {
        stack.push(cur);
    }
    else if (cur == ")") {
        stack.getTop(top);

        while (top != "(") {
            postfixExp += top + " ";
            stack.pop();
            stack.getTop(top);
        }
        stack.pop();
    }
    else {
        postfixExp += cur + " ";
    }

    cur = "";

    while (!stack.isEmpty()) {
        stack.pop(top);
        postfixExp += top;
        postfixExp += " ";
    }

    return postfixExp;
}

string prefix2infix(const string exp) {
    string infixExp;
    Stack stack;

    string cur = "";
    string operand1, operand2;
    for (int i = exp.length() - 1; i >= 0; i--) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                stack.pop(operand1);
                stack.pop(operand2);

                stack.push("( " + operand1 + " " + cur + " " + operand2 + " )");
            }
            else {
                stack.push(reverse(cur));
            }

            cur = "";
        }
    }

    if (isOperator(cur)) {
        stack.pop(operand1);
        stack.pop(operand2);

        stack.push("( " + operand1 + " " + cur + " " + operand2 + " )");
    }
    else {
        stack.push(reverse(cur));
    }

    stack.getTop(infixExp);

    return infixExp;
}

string prefix2postfix(const string exp) {
    string postfixExp = "";
    Stack stack;

    string cur = "";
    string operand1, operand2;
    for (int i = exp.length() - 1; i >= 0; i--) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                stack.pop(operand1);
                stack.pop(operand2);

                stack.push(operand1 + " " + operand2 + " " + cur);
            }
            else {
                stack.push(reverse(cur));
            }

            cur = "";
        }
    }

    if (isOperator(cur)) {
        stack.pop(operand1);
        stack.pop(operand2);

        stack.push(operand1 + " " + operand2 + " " + cur);
    }
    else {
        stack.push(reverse(cur));
    }

    stack.getTop(postfixExp);

    return postfixExp;
}

string postfix2infix(const string exp) {
    string infixExp;
    Stack stack;

    string cur = "";
    string operand1, operand2;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                stack.pop(operand1);
                stack.pop(operand2);

                stack.push("( " + operand2 + " " + cur + " " + operand1 + " )");
            }
            else {
                stack.push(cur);
            }

            cur = "";
        }
    }

    if (isOperator(cur)) {
        stack.pop(operand1);
        stack.pop(operand2);

        stack.push("( " + operand2 + " " + cur + " " + operand1 + " )");
    }
    else {
        stack.push(cur);
    }

    stack.getTop(infixExp);

    return infixExp;
}

string postfix2prefix(const string exp) {
    string prefixExp = "";
    Stack stack;

    string cur = "";
    string operand1, operand2;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                stack.pop(operand1);
                stack.pop(operand2);

                stack.push(cur + " " + operand2 + " " + operand1);
            }
            else {
                stack.push(cur);
            }

            cur = "";
        }
    }

    if (isOperator(cur)) {
        stack.pop(operand1);
        stack.pop(operand2);

        stack.push(cur + " " + operand2 + " " + operand1);
    }
    else {
        stack.push(cur);
    }

    stack.getTop(prefixExp);

    return prefixExp;
}

double evaluateInfix(const string exp) {
    Stack numbers;
    Stack operators;
    double result;

    string topOperator = "";
    string cur = "";
    string operand1, operand2;
    double num1, num2;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                operators.getTop(topOperator);

                while (!operators.isEmpty() && topOperator != "(" && precedence(cur) <= precedence(topOperator)) {
                    operators.pop();
                    numbers.pop(operand1);
                    numbers.pop(operand2);

                    stringstream ss1(operand1);
                    stringstream ss2(operand2);
                    ss1 >> num1;
                    ss2 >> num2;

                    stringstream ss_result;
                    if (topOperator == "+") {
                        ss_result << (num2 + num1);
                        numbers.push(ss_result.str());
                    }
                    else if (topOperator == "-") {
                        ss_result << (num2 - num1);
                        numbers.push(ss_result.str());
                    }
                    else if (topOperator == "*") {
                        ss_result << (num2 * num1);
                        numbers.push(ss_result.str());
                    }
                    else if (topOperator == "/") {
                        ss_result << (num2 / num1);
                        numbers.push(ss_result.str());
                    }

                    operators.getTop(topOperator);
                }
                operators.push(cur);
            }
            else if (cur == "(") {
                operators.push(cur);
            }
            else if (cur == ")") {
                operators.getTop(topOperator);

                while (topOperator != "(") {
                    operators.pop();
                    numbers.pop(operand1);
                    numbers.pop(operand2);

                    stringstream ss1(operand1);
                    stringstream ss2(operand2);
                    ss1 >> num1;
                    ss2 >> num2;

                    stringstream ss_result;
                    if (topOperator == "+") {
                        ss_result << (num2 + num1);
                        numbers.push(ss_result.str());
                    }
                    else if (topOperator == "-") {
                        ss_result << (num2 - num1);
                        numbers.push(ss_result.str());
                    }
                    else if (topOperator == "*") {
                        ss_result << (num2 * num1);
                        numbers.push(ss_result.str());
                    }
                    else if (topOperator == "/") {
                        ss_result << (num2 / num1);
                        numbers.push(ss_result.str());
                    }
                    
                    operators.getTop(topOperator);
                }
                operators.pop();
            }
            else {
                numbers.push(cur);
            }

            cur = "";
        }
    }

     if (isOperator(cur)) {
        operators.getTop(topOperator);

        while (!operators.isEmpty() && topOperator != "(" && precedence(cur) <= precedence(topOperator)) {
            operators.pop();
            numbers.pop(operand1);
            numbers.pop(operand2);

            stringstream ss1(operand1);
            stringstream ss2(operand2);
            ss1 >> num1;
            ss2 >> num2;

            stringstream ss_result;
            if (topOperator == "+") {
                ss_result << (num2 + num1);
                numbers.push(ss_result.str());
            }
            else if (topOperator == "-") {
                ss_result << (num2 - num1);
                numbers.push(ss_result.str());
            }
            else if (topOperator == "*") {
                ss_result << (num2 * num1);
                numbers.push(ss_result.str());
            }
            else if (topOperator == "/") {
                ss_result << (num2 / num1);
                numbers.push(ss_result.str());
            }

            operators.getTop(topOperator);
        }
        operators.push(cur);
    }
    else if (cur == "(") {
        operators.push(cur);
    }
    else if (cur == ")") {
        operators.getTop(topOperator);

        while (topOperator != "(") {
            operators.pop();
            numbers.pop(operand1);
            numbers.pop(operand2);

            stringstream ss1(operand1);
            stringstream ss2(operand2);
            ss1 >> num1;
            ss2 >> num2;

            stringstream ss_result;
            if (topOperator == "+") {
                ss_result << (num2 + num1);
                numbers.push(ss_result.str());
            }
            else if (topOperator == "-") {
                ss_result << (num2 - num1);
                numbers.push(ss_result.str());
            }
            else if (topOperator == "*") {
                ss_result << (num2 * num1);
                numbers.push(ss_result.str());
            }
            else if (topOperator == "/") {
                ss_result << (num2 / num1);
                numbers.push(ss_result.str());
            }
            operators.getTop(topOperator);
        }
        operators.pop();
    }
    else {
        numbers.push(cur);
    }

    cur = "";

    while (!operators.isEmpty()) {
        operators.getTop(topOperator);
        numbers.pop(operand1);
        numbers.pop(operand2);

        stringstream ss1(operand1);
        stringstream ss2(operand2);
        ss1 >> num1;
        ss2 >> num2;

        stringstream ss_result;
        if (topOperator == "+") {
            ss_result << (num2 + num1);
            numbers.push(ss_result.str());
        }
        else if (topOperator == "-") {
            ss_result << (num2 - num1);
            numbers.push(ss_result.str());
        }
        else if (topOperator == "*") {
            ss_result << (num2 * num1);
            numbers.push(ss_result.str());
        }
        else if (topOperator == "/") {
            ss_result << (num2 / num1);
            numbers.push(ss_result.str());
        }
        operators.pop();
    }

    numbers.getTop(cur);
    stringstream ss_result(cur);
    ss_result >> result;
    return result;
}

double evaluatePrefix(const string exp) {
    Stack stack;
    double result;

    string cur = "";
    string operand1, operand2;
    double num1, num2;
    for (int i = exp.length() - 1; i >= 0; i--) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                stack.pop(operand1);
                stack.pop(operand2);

                stringstream ss1(operand1);
                stringstream ss2(operand2);
                ss1 >> num1;
                ss2 >> num2;

                stringstream ss_result;
                if (cur == "+") {
                    ss_result << (num1 + num2);
                    stack.push(ss_result.str());
                }
                else if (cur == "-") {
                    ss_result << (num1 - num2);
                    stack.push(ss_result.str());
                }
                else if (cur == "*") {
                    ss_result << (num1 * num2);
                    stack.push(ss_result.str());
                }
                else if (cur == "/") {
                    ss_result << (num1 / num2);
                    stack.push(ss_result.str());
                }
            }
            else {               
                stack.push(reverse(cur));
            }

            cur = "";
        }
    }

    if (isOperator(cur)) {
        stack.pop(operand1);
        stack.pop(operand2);

        stringstream ss1(operand1);
        stringstream ss2(operand2);
        ss1 >> num1;
        ss2 >> num2;

        stringstream ss_result;
        if (cur == "+") {
            ss_result << (num1 + num2);
            stack.push(ss_result.str());
        }
        else if (cur == "-") {
            ss_result << (num1 - num2);
            stack.push(ss_result.str());
        }
        else if (cur == "*") {
            ss_result << (num1 * num2);
            stack.push(ss_result.str());
        }
        else if (cur == "/") {
            ss_result << (num1 / num2);
            stack.push(ss_result.str());
        }
    }
    else {
        stack.push(cur);
    }

    stack.getTop(cur);
    stringstream ss_result(cur);
    ss_result >> result;
    return result;
}

double evaluatePostfix(const string exp) {
    Stack stack;
    double result;

    string cur = "";
    string operand1, operand2;
    double num1, num2;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != ' ') {
            cur += exp[i];
        }
        else {
            if (isOperator(cur)) {
                stack.pop(operand1);
                stack.pop(operand2);

                stringstream ss1(operand1);
                stringstream ss2(operand2);
                ss1 >> num1;
                ss2 >> num2;

                stringstream ss_result;
                if (cur == "+") {
                    ss_result << (num2 + num1);
                    stack.push(ss_result.str());
                }
                else if (cur == "-") {
                    ss_result << (num2 - num1);
                    stack.push(ss_result.str());
                }
                else if (cur == "*") {
                    ss_result << (num2 * num1);
                    stack.push(ss_result.str());
                }
                else if (cur == "/") {
                    ss_result << (num2 / num1);
                    stack.push(ss_result.str());
                }
            }
            else {
                stack.push(cur);
            }

            cur = "";
        }
    }

    if (isOperator(cur)) {
        stack.pop(operand1);
        stack.pop(operand2);

        stringstream ss1(operand1);
        stringstream ss2(operand2);
        ss1 >> num1;
        ss2 >> num2;

        stringstream ss_result;
        if (cur == "+") {
            ss_result << (num2 + num1);
            stack.push(ss_result.str());
        }
        else if (cur == "-") {
            ss_result << (num2 - num1);
            stack.push(ss_result.str());
        }
        else if (cur == "*") {
            ss_result << (num2 * num1);
            stack.push(ss_result.str());
        }
        else if (cur == "/") {
            ss_result << (num2 / num1);
            stack.push(ss_result.str());
        }
    }
    else {
        stack.push(cur);
    }

    stack.getTop(cur);
    stringstream ss_result(cur);
    ss_result >> result;
    return result;
}

bool isOperator(string c) {
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

int precedence(string c) {
    return (c == "*" || c == "/");
}

string reverse(string s) {
    string reverse = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        reverse += s[i];
    }
    return reverse;
}