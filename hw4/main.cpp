// Mehmet Feyyaz Küçük 22003550

#include <iostream>
using namespace std;

#include "AlgebraicExpression.h"

int main() {
    
    cout << evaluateInfix("( 9 - 2 ) * 5 + 3") << endl;
    cout << infix2prefix("( 9 - 2 ) * 5 + 3") << endl;
    cout << infix2postfix("( 9 - 2 ) * 5 + 3") << endl;
    cout << evaluatePrefix("* + 9 / 20 5 - 14 3") << endl;
    cout << prefix2infix("* + 9 / 20 5 - 14 3") << endl;
    cout << prefix2postfix("* + 9 / 20 5 - 14 3") << endl;
    cout << evaluatePostfix("5 100 2 * + 4 * 7 -") << endl;
    cout << postfix2infix("5 100 2 * + 4 * 7 -") << endl;
    cout << postfix2prefix("5 100 2 * + 4 * 7 -") << endl;

    return 0;
}