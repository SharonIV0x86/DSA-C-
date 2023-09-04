#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

enum class Operator
    {
        Addition = '+',
        Subtraction = '-',
        Multiplication = '*',
        Division = '/'
    };
class Parser
{
private:
    string value;
    public:
    Parser(string val) : value(val){ }
    
    
    int calculate(int a, int b, Operator OP){ }
    void stringPos(){
        vector<char> vec;
        for (char i = 0; i <= value.length(); i++)
        {
            stck.push(value[i]);
        }
        while(!stck.empty()){
            cout << stck.top() << endl;
            stck.pop();
        }
    }


    Operator op1 = Operator::Addition;
    Operator op2 = Operator::Subtraction;
};

std::string removeWhiteSpaces(std::string &val)
{

    std::string result;
    for (char c : val)
    {
        if (!std::isspace(c))
        {
            result += c;
        }
    }
    return result;
}

int main()
{
    std::string value = "10 + 6 * 10";
    std::string valueWithoutSpaces = removeWhiteSpaces(value);
    std::cout << "Value without spaces: " << valueWithoutSpaces;
    Parser p(valueWithoutSpaces);
    p.stringPos();
    return 0;
}
