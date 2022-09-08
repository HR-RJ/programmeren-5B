// Copyright: GEATEC engineering, 2020
// License: Apache 2

#include <iostream>
#include <stack>
#include <cmath>

namespace st = std;

int main() {
    auto stack = st::stack <long double>();
    auto input = st::string (); // Explitly use constructor if you want variable of type string!
    
    do {
        st::cout << "? ";
        st::cin >> input;
        try {
            stack.push (st::stold (input));
        }
        catch (st::invalid_argument) {
            
            // Provide 0 for missing operands
            
            while (stack.size () < 2) {
                stack.push (0);
            }
            
            // Unary operators
            
            auto operand0 = stack.top ();
            stack.pop ();
            
            if (input == "chs") {    // Change sign of current operand
                stack.push (-1 * operand0);
            }
            else if (input == "sqrt") {
                stack.push (sqrt (operand0));
            }
            else if (input == "exp") {
                stack.push (exp (operand0));
            }
            else if (input == "ln") {
                stack.push (log (operand0));
            }
            else if (input == "sin") {
                stack.push (sin (operand0));
            }
            else if (input == "cos") {
                stack.push (cos (operand0));
            }
            else if (input == "tan") {
                stack.push (tan (operand0));
            }
            else if (input == "asin") {
                stack.push (asin (operand0));
            }
            else if (input == "acos") {
                stack.push (acos (operand0));
            }
            else if (input == "atan") {
                stack.push (atan (operand0));
            }
            
            // Binary operators
            
            else {
                
                auto operand1 = stack.top ();
                stack.pop ();
                
                if (input == "+") {
                    stack.push (operand1 + operand0);
                }
                else if (input == "-") {
                    stack.push (operand1 - operand0);
                }
                else if (input == "*") {
                    stack.push (operand1 * operand0);
                }
                else if (input == "/") {
                    stack.push (operand1 / operand0);
                }
                else if (input == "pow") {
                    stack.push (st::pow (operand1, operand0));
                }
                else {  // Restore stack
                    stack.push (operand1);
                    stack.push (operand0);
                }
            }
            st::cout << "! " << stack.top () << '\n';
        }
    } while (input != "quit");
    
    return 0;
} 