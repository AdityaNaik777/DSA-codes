
#include <iostream>
#include <string>
using namespace std;

int stack[100];
int top = -1;

// Returns the precedence of operators
int priority(char c)
{
  if (c == '*' || c == '/')
    return 3;
  if (c == '+' || c == '-')
    return 2;
  return 1;
}

void infix_to_postfix(string input)
{
  string postfix = "", ans = "";

  for (int i = 0; i < input.size(); i++)
  {
    char c = input[i];

    if (isalnum(c))
    {
      postfix += c; // Append operand to postfix
    }
    else if (c == '(')
    {
      stack[++top] = c; // Push '(' to stack
    }
    else if (c == ')')
    {
      // Pop and append until '(' is found
      while (top != -1 && stack[top] != '(')
      {
        postfix += stack[top--];
      }
      top--; // Pop '(' from stack
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
      int precedence = priority(c);
      // Pop operators of higher or equal precedence
      while (top != -1 && stack[top] != '(' && priority(stack[top]) > precedence)
      {
        postfix += stack[top--];
      }
      stack[++top] = c; // Push current operator to stack
    }
  }

  // Pop remaining operators from the stack
  while (top != -1)
  {
    postfix += stack[top--];
  }

  for (int i = postfix.length(); i >= 0; i--)
  {
    if (postfix[i] == '(')
    {
      ans += ')';
    }
    else if (postfix[i] == ')')
    {
      ans += '(';
    }
    else
    {
      ans += postfix[i];
    }
  }
  cout << "Prefix expression : " << ans;
}
int main()
{
  string input;
  string rev_input, ans;
  cout << "Enter the expression: ";
  cin >> input;
  for (int i = input.length(); i >= 0; i--)
  {
    if (input[i] == '(')
    {
      rev_input += ')';
    }
    else if (input[i] == ')')
    {
      rev_input += '(';
    }
    else
    {
      rev_input += input[i];
    }
  }
  infix_to_postfix(rev_input);
  return 0;
}