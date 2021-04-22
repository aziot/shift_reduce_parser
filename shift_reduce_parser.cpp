// Including Libraries
#include <bits/stdc++.h>
#include <vector>

using namespace std;

const std::vector<std::string> kGrammarRules= { "E->2E2", "E->3E3", "E->4" };
static const char kAction[] = "REDUCE TO E -> ";
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

    // This Function will check whether
    // the stk contain a production rule
    // which is to be Reduce.
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
int main()
{
    ShiftReduceParserDemo::print_rules();

    ShiftReduceParserDemo demo;

    const std::string input("32423");

    // This will print Labels (column name)
    std::cout << std::endl << "stack \t input \t action";

    // This will print the initial
    // values of stk and input
    std::cout << "\n$\t" << input << "$\t";

    // This will Run upto length of input string
    for(int i = 0; i < input.length() ; i++)
    {
        // Printing action
        std::cout << "SHIFT";

        // Pushing into stk
        demo.stack.push_back(input[i]);
        demo.printState(input, i+1);

        // Call check function ..which will
        // check the stk whether its contain
        // any production or not
        if (demo.check()) {
            demo.printState(input, i+1);
        }
    }

    // Rechecking last time if contain
    // any valid production then it will
    // replace otherwise invalid
    if (demo.check()) {
        demo.printState(input);
    }

    // if top of the stk is E(starting symbol)
    // then it will accept the input
    if(demo.stack[0] == 'E' && demo.stack.size() == 1)
        std::cout << "Accept" << std::endl;
    else //else reject
        std::cout << "Reject" << std::endl;
}
// This code is contributed by Shubhamsingh10
