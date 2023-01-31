// Mehmet Feyyaz Küçük 22003550

#include <string>
using namespace std;

#include "Stack.h"

#ifndef ALGEBRAICEXPRESSION_H
#define ALGEBRAICEXPRESSION_H

string infix2prefix(const string exp);
string infix2postfix(const string exp);   
string prefix2infix(const string exp);
string prefix2postfix(const string exp);
string postfix2infix(const string exp);
string postfix2prefix(const string exp);

double evaluateInfix(const string exp);
double evaluatePrefix(const string exp);
double evaluatePostfix(const string exp); 

bool isOperator(string c);
int precedence(string c);
string reverse(string s);

#endif