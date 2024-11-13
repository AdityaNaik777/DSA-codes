/*
Write a program to convert infix expression to postfix, infix expression to prefix and evaluation
of postfix and prefix expression.

*/

#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

// Check if character is an operand (number)
bool isOperand(char ch)
{
  return ch >= '0' && ch <= '9';
}

// Function to return precedence of an operator
int precedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  return 0;
}

// Function to perform arithmetic operations
int operate(int a, int b, char op)
{
  switch (op)
  {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  case '^':
    return pow(a, b);
  }
  return 0;
}

// Function to reverse a string manually
string manualReverse(string str)
{
  int n = str.size();
  for (int i = 0; i < n / 2; i++)
  {
    char temp = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = temp;
  }
  return str;
}

// Infix to Postfix Conversion
string infixToPostfix(string expression)
{
  stack<char> stack;
  string result = "";

  for (int i = 0; i < expression.size(); i++)
  {
    char ch = expression[i];

    if (isOperand(ch))
    {
      result += ch;
    }
    else if (ch == '(')
    {
      stack.push(ch);
    }
    else if (ch == ')')
    {
      while (!stack.empty() && stack.top() != '(')
      {
        result += stack.top();
        stack.pop();
      }
      stack.pop(); // Remove '(' from stack
    }
    else
    {
      while (!stack.empty() && precedence(ch) <= precedence(stack.top()))
      {
        result += stack.top();
        stack.pop();
      }
      stack.push(ch);
    }
  }

  while (!stack.empty())
  {
    result += stack.top();
    stack.pop();
  }

  return result;
}

// Infix to Prefix Conversion
string infixToPrefix(string expression)
{
  // Reverse infix expression and swap parentheses
  expression = manualReverse(expression);
  for (int i = 0; i < expression.size(); i++)
  {
    if (expression[i] == '(')
    {
      expression[i] = ')';
    }
    else if (expression[i] == ')')
    {
      expression[i] = '(';
    }
  }

  // Convert to postfix
  string postfix = infixToPostfix(expression);
  // Reverse postfix to get prefix
  return manualReverse(postfix);
}

// Evaluate Postfix Expression
int evaluatePostfix(const string &expression)
{
  stack<int> stack;

  for (int i = 0; i < expression.size(); i++)
  {
    char ch = expression[i];

    if (isOperand(ch))
    {
      // Convert character to integer and push it
      stack.push(ch - '0');
    }
    else
    {
      int b = stack.top();
      stack.pop();
      int a = stack.top();
      stack.pop();
      int result = operate(a, b, ch);
      stack.push(result);
    }
  }

  return stack.top();
}

// Evaluate Prefix Expression
int evaluatePrefix(const string &expression)
{
  stack<int> stack;

  for (int i = expression.size() - 1; i >= 0; i--)
  {
    char ch = expression[i];

    if (isOperand(ch))
    {
      // Convert character to integer and push it
      stack.push(ch - '0');
    }
    else
    {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      int result = operate(a, b, ch);
      stack.push(result);
    }
  }

  return stack.top();
}

int main()
{
  string infixExpr;
  cout << "Enter infix expression: ";
  cin >> infixExpr;

  // Convert infix to postfix and prefix
  string postfixExpr = infixToPostfix(infixExpr);
  string prefixExpr = infixToPrefix(infixExpr);

  cout << "Infix Expression: " << infixExpr << endl;
  cout << "Postfix Expression: " << postfixExpr << endl;
  cout << "Prefix Expression: " << prefixExpr << endl;

  // Evaluate postfix and prefix expressions
  cout << "Postfix Evaluation Result: " << evaluatePostfix(postfixExpr) << endl;
  cout << "Prefix Evaluation Result: " << evaluatePrefix(prefixExpr) << endl;

  return 0;
}
