// Including Libraries
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const std::vector<std::string> kGrammarRules= { "E->2E2", "E->3E3", "E->4" };
static const char kAction[] = "REDUCE E -> ";
struct ShiftReduceParserDemo {
    std::vector<char> stack;

    void printState(const std::string& input, int offset=0) {
        std::cout << std::endl << "$";
        for (int cnt = 0; cnt < stack.size(); cnt++) {
            std::cout << stack[cnt];
        }
        std::cout << "\t" << input.substr(offset) << "$\t";
    }

    static void print_rules() {
        std::cout << "GRAMMAR is" << std::endl;
        for (const std::string& rule : kGrammarRules) {
            std::cout << rule << std::endl;
        }
    }

    // This Function will check whether the stack contains a production rule which is to be reduced.
    // Rules can be E->2E2 , E->3E3 , E->4
    bool check()
    {
        // checking for producing rule E->4
        if(stack.back() == '4')
        {
            std::cout << kAction << "4";
            stack.pop_back();
            stack.push_back('E');
            return true;
        }

        // checking for another production
        if(*(stack.end()-3) == '2' && *(stack.end()-2) == 'E' &&
                stack.back() == '2')
        {
            std::cout << kAction << "2E2";
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            stack.push_back('E');

            return true;
        }

        //checking for E->3E3
        if(*(stack.end()-3) == '3' && *(stack.end()-2) == 'E' &&
                stack.back() == '3')
        {
            std::cout << kAction << "3E3";
            stack.pop_back();
            stack.pop_back();
            stack.pop_back();
            stack.push_back('E');
            return true;
        }
        return false; // return to main
    }
};

// Driver Function
int main(int argc, char*argv[])
{
    if (argc != 2) {
        std::cerr << "Wrong number of arguments." << std::endl;
        std::cerr << "Usage: ./shift_reduce_parser <expression>" << std::endl;

        return -1;
    }
    const std::string input(argv[1]);

    ShiftReduceParserDemo demo;
    ShiftReduceParserDemo::print_rules();

    std::cout << std::endl << "stack \tinput \taction";

    // This will print the initial values of the stack and input
    std::cout << std::endl << "$\t" << input << "$\t";

    for(int i = 0; i < input.length() ; i++)
    {
        std::cout << "SHIFT";

        // Pushing into the stack
        demo.stack.push_back(input[i]);
        demo.printState(input, i+1);

        // Call the check function which will check the stack whether it contains any production or not
        if (demo.check()) {
            demo.printState(input, i+1);
        }
    }

    // Rechecking last time if it contains any valid production
    if (demo.check()) {
        demo.printState(input);
    }

    // If the top of the stack is E(starting symbol) then it will accept the input
    if(demo.stack[0] == 'E' && demo.stack.size() == 1)
        std::cout << "Accept" << std::endl;
    else  // reject
        std::cout << "Reject" << std::endl;
}
