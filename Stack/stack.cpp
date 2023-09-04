#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s;

    // Push elements on the stack:
    s.push(3);
    s.push(5);
    s.push(7);
    
    // Empty the whole stack:
    while(!s.empty()){
        // Print info:
        cout << "top() -> " << s.top() << endl
        << "size() -> " << s.size() << endl << endl;
        
        // Pop out the top element:
        s.pop(); // Can be stored in a variable
    }
}
//LIFO pronciple