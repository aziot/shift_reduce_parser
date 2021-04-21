// Including Libraries
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Global Variables
int z = 0, i = 0, j = 0, c = 0;

const std::vector<std::string> kGrammarRules= { "E->2E2", "E->3E3", "E->4" };
static const char kAction[] = "REDUCE TO E -> ";
struct ShiftReduceParserDemo {
    std::vector<char> stack;

    void printStack() {
        for (int cnt = 0; cnt < stack.size(); cnt++) {
            std::cout << stack[cnt];
        }
    }

    static void print_rules() {
        std::cout << "GRAMMAR is" << std::endl;
        for (const std::string& rule : kGrammarRules) {
            std::cout << rule << std::endl;
        }
    }
};


// This Function will check whether
// the stk contain a production rule
// which is to be Reduce.
// Rules can be E->2E2 , E->3E3 , E->4
void check(const std::string& input, std::vector<char>* stack)
{
    // c=length of input string
    for(z = 0; z < c; z++)
    {
        // checking for producing rule E->4
        if((*stack)[z] == '4')
        {
            std::cout << kAction << "4";
            (*stack)[z] = 'E';
            (*stack)[z + 1] = '\0';

            //printing action
            std::cout << "\n$";
            for (int cnt = 0; cnt < stack->size(); cnt++) {
                std::cout << (*stack)[cnt];
            }
            std::cout << "\t" << input << "$\t";
        }
    }

    for(z = 0; z < c - 2; z++)
    {
        // checking for another production
        if((*stack)[z] == '2' && (*stack)[z + 1] == 'E' &&
                (*stack)[z + 2] == '2')
        {
            std::cout << kAction << "2E2";
            (*stack)[z] = 'E';
            (*stack)[z + 1] = '\0';
            (*stack)[z + 2] = '\0';
            std::cout << "\n$";
            for (int cnt = 0; cnt < stack->size(); cnt++) {
                std::cout << (*stack)[cnt];
            }
            std::cout << "\t" << input << "$\t";
            i = i - 2;
        }

    }

    for(z = 0; z < c - 2; z++)
    {
        //checking for E->3E3
        if((*stack)[z] == '3' && (*stack)[z + 1] == 'E' &&
                (*stack)[z + 2] == '3')
        {
            std::cout << kAction << "3E3";
            (*stack)[z]='E';
            (*stack)[z + 1]='\0';
            (*stack)[z + 1]='\0';
            std::cout << "\n$";
            for (int cnt=0; cnt < stack->size(); cnt++) {
                std::cout << (*stack)[cnt];
            }
            std::cout << "\t" << input << "$\t";
            i = i - 2;
        }
    }
    return ; // return to main
}

// Driver Function
int main()
{
    ShiftReduceParserDemo::print_rules();

    ShiftReduceParserDemo demo;

    std::string input("32423");

    // strlen(a) will return the length of a to c
    c = input.length();

    // This will print Labels (column name)
    std::cout << std::endl << "stack \t input \t action";

    // This will print the initial
    // values of stk and input
    std::cout << "\n$\t" << input << "$\t";

    // This will Run upto length of input string
    for(i = 0; j < input.length() ; i++, j++)
    {
        // Printing action
        std::cout << "SHIFT";

        // Pushing into stk
        demo.stack.push_back(input[j]);
        demo.stack.push_back('\0');

        // Moving the pointer
        input[j]=' ';

        // Printing action
        std::cout << std::endl << "$";
        demo.printStack();
        std::cout << "\t" << input << "$\t";

        // Call check function ..which will
        // check the stk whether its contain
        // any production or not
        check(input, &demo.stack);
    }

    // Rechecking last time if contain
    // any valid production then it will
    // replace otherwise invalid
    check(input, &demo.stack);

    // if top of the stk is E(starting symbol)
    // then it will accept the input
    if(demo.stack[0] == 'E' && demo.stack[1] == '\0')
        printf("Accept\n");
    else //else reject
        printf("Reject\n");
}
// This code is contributed by Shubhamsingh10
