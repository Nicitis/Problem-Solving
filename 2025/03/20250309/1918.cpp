#include <iostream>
#include <string>
#include <stack>

#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3
#define PARENTHESIS_START 4
#define PARENTHESIS_END 5
#define EOS 6

using namespace std;

int priority[] = { 2, 2, 1, 1, 9, 0, 10 };

bool IsOperand(char c, int& operand)
{
    if (c >= 'A' && c <= 'Z')
        return false;

    switch (c)
    {
        case '+':
            operand = PLUS;
            break;
        case '-':
            operand = MINUS;
            break;
        case '*':
            operand = MUL;
            break;
        case '/':
            operand = DIV;
            break;
        case '(':
            operand = PARENTHESIS_START;
            break;
        case ')':
            operand = PARENTHESIS_END;
            break;
        case '\0':
            operand = EOS;
    }
    return true;
}

char GetChar(int opcode)
{
    switch (opcode)
    {
        case PLUS:
            return '+';
        case MINUS:
            return '-';
        case MUL:
            return '*';
        case DIV:
            return '/';
        case PARENTHESIS_START:
            return '(';
        case PARENTHESIS_END:
            return ')';
    }
    return ' ';
}

int main()
{
    string expression;

    cin >> expression;

    stack<int> opStack;
    stack<string> expStack;

    int length = expression.size();
    for (int i = 0; i < length + 1; i++)
    {
        char c = i < length ? expression[i] : '\0';
        int opcode;
        
        // cout << i << ": " << c << "\n";

        if (IsOperand(c, opcode))
        {
            if (opcode == PARENTHESIS_START)
            {
                opStack.push(opcode);
                continue;
            }
            // 우선순위가 낮거나 같으면 식을 계산
            bool existParenthesis = false;
            while (!opStack.empty() && 
                (priority[opcode] >= priority[opStack.top()] || 
                 existParenthesis))
            {
                // cout << "op : " << GetChar(opStack.top()) << "\n";
                int operand;
                do
                {
                    operand = opStack.top();
                    opStack.pop();
                    if (operand == PARENTHESIS_END)
                        existParenthesis = true;
                }
                while (!opStack.empty() && operand == PARENTHESIS_END);

                if (operand == PARENTHESIS_START)
                {
                    existParenthesis = false;
                    continue;
                }

                string val2 = expStack.top();
                expStack.pop();
                string val1 = expStack.top();
                expStack.pop();

                // ( 제거
                if (existParenthesis && opStack.top() == PARENTHESIS_START)
                {
                    opStack.pop();
                    existParenthesis = false;
                }

                // 계산
                string newExpression = val1 + val2 + GetChar(operand);
                expStack.push(newExpression);
                // cout << "new exp : " << newExpression << " ";
                // if (opStack.empty()) cout << "\n";
                // else cout << "(op : " << opStack.top() << "(" << (opStack.size()) << "))\n";
            }
            
            // 우선순위가 더 높을 때
            opStack.push(opcode);
        }
        else
        {
            string newExp(1, c);
            expStack.push(newExp);
        }
    }
    cout << expStack.top() << '\n';

    return 0;
}