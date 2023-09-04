#include <iostream>
#include <string>
#include <stack>
#include <cctype>

// Node class representing a node in the expression tree
class Node
{
public:
    virtual int evaluate() const = 0;
};

// OperandNode class representing an operand node in the expression tree
class OperandNode : public Node
{
private:
    int value;

public:
    OperandNode(int value) : value(value) {}

    int evaluate() const
    {
        return value;
    }
};

// OperatorNode class representing an operator node in the expression tree
class OperatorNode : public Node
{
private:
    char op;
    Node *left;
    Node *right;

public:
    OperatorNode(char op, Node *left, Node *right) : op(op), left(left), right(right) {}

    int evaluate() const
    {
        int leftValue = left->evaluate();
        int rightValue = right->evaluate();

        switch (op)
        {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0; // Invalid operator
        }
    }
};

// Lexer class
class Lexer
{
private:
    std::string text;
    size_t pos;
    char currentChar;

public:
    Lexer(const std::string &text) : text(text), pos(0), currentChar(text[0]) {}

    void advance()
    {
        pos++;
        if (pos < text.length())
        {
            currentChar = text[pos];
        }
        else
        {
            currentChar = '\0';
        }
    }

    void skipWhitespace()
    {
        while (currentChar != '\0' && std::isspace(currentChar))
        {
            advance();
        }
    }

    int integer()
    {
        std::string result;
        while (currentChar != '\0' && std::isdigit(currentChar))
        {
            result += currentChar;
            advance();
        }
        return std::stoi(result);
    }

    char getCurrentChar() const
    {
        return currentChar;
    }
};

// Parser class
class Parser
{
private:
    Lexer lexer;
    std::stack<Node *> nodeStack;

public:
    Parser(const std::string &text) : lexer(text) {}

    Node *parse()
    {
        lexer.advance();
        parseExpression();
        return nodeStack.top();
    }

private:
    void parseExpression()
    {
        parseTerm();

        while (lexer.getCurrentChar() == '+' || lexer.getCurrentChar() == '-')
        {
            char op = lexer.getCurrentChar();
            lexer.advance();

            parseTerm();

            Node *right = nodeStack.top();
            nodeStack.pop();
            Node *left = nodeStack.top();
            nodeStack.pop();

            nodeStack.push(new OperatorNode(op, left, right));
        }
    }

    void parseTerm()
    {
        parseFactor();

        while (lexer.getCurrentChar() == '*' || lexer.getCurrentChar() == '/')
        {
            char op = lexer.getCurrentChar();
            lexer.advance();

            parseFactor();

            Node *right = nodeStack.top();
            nodeStack.pop();
            Node *left = nodeStack.top();
            nodeStack.pop();

            nodeStack.push(new OperatorNode(op, left, right));
        }
    }

    void parseFactor()
    {
        if (std::isdigit(lexer.getCurrentChar()))
        {
            int value = lexer.integer();
            nodeStack.push(new OperandNode(value));
        }
        else if (lexer.getCurrentChar() == '(')
        {
            lexer.advance();
            parseExpression();
            if (lexer.getCurrentChar() == ')')
            {
                lexer.advance();
            }
            else
            {
                std::cerr << "Error: Missing closing parenthesis" << std::endl;
                exit(1);
            }
        }
        else
        {
            std::cerr << "Error: Invalid character" << std::endl;
            exit(1);
        }
    }
};

// Main program
int main()
{
    std::string expression = "3 + 4 * 2 - (10 / 5)";
    Parser parser(expression);
    Node *rootNode = parser.parse();

    int result = rootNode->evaluate();
    std::cout << "Result: " << result << std::endl;

    // Clean up the expression tree
    delete rootNode;

    return 0;
}
