// Including Libraries
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Global Variables
int z = 0, i = 0, j = 0, c = 0;

// Modify array size to increase
// length of string to be parsed
char a[16], ac[20], act[10];

std::vector<char> stk;

// This Function will check whether
// the stk contain a production rule
// which is to be Reduce.
// Rules can be E->2E2 , E->3E3 , E->4
void check()
{
    // Coping string to be printed as action
    strcpy(ac,"REDUCE TO E -> ");

    // c=length of input string
    for(z = 0; z < c; z++)
    {
        // checking for producing rule E->4
        if(stk[z] == '4')
        {
            printf("%s4", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';

            //printing action
            std::cout << "\n$";
	    for (int cnt = 0; cnt < stk.size(); cnt++) {
		    std::cout << stk[cnt];
	    }
	    std::cout << "\t" << a << "$\t";
        }
    }

    for(z = 0; z < c - 2; z++)
    {
        // checking for another production
        if(stk[z] == '2' && stk[z + 1] == 'E' &&
                stk[z + 2] == '2')
        {
            printf("%s2E2", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
	    std::cout << "\n$";
	    for (int cnt = 0; cnt < stk.size(); cnt++) {
		    std::cout << stk[cnt];
	    }
	    std::cout << "\t" << a << "$\t";
            i = i - 2;
        }

    }

    for(z = 0; z < c - 2; z++)
    {
        //checking for E->3E3
        if(stk[z] == '3' && stk[z + 1] == 'E' &&
                stk[z + 2] == '3')
        {
            printf("%s3E3", ac);
            stk[z]='E';
            stk[z + 1]='\0';
            stk[z + 1]='\0';
	    std::cout << "\n$";
	    for (int cnt=0; cnt < stk.size(); cnt++) {
		    std::cout << stk[cnt];
	    }
	    std::cout << "\t" << a << "$\t";
            i = i - 2;
        }
    }
    return ; // return to main
}

// Driver Function
int main()
{
    std::cout << "GRAMMAR is -\nE->2E2 \nE->3E3 \nE->4\n";

    // a is input string
    std::string a("32423");

    // strlen(a) will return the length of a to c
    c = a.length();

    // "SHIFT" is copied to act to be printed
    strcpy(act,"SHIFT");

    // This will print Lables (column name)
    std::cout << "\nstk \t input \t action";

    // This will print the initial
    // values of stk and input
    std::cout << "\n$\t" << a << "$\t";

    // This will Run upto length of input string
    for(i = 0; j < c; i++, j++)
    {
        // Printing action
        std::cout << act;

        // Pushing into stk
        stk.push_back(a[j]);
        stk.push_back('\0');

        // Moving the pointer
        a[j]=' ';

        // Printing action
        std::cout << "\n$";
        for (int cnt = 0; cnt < stk.size(); cnt++) {
            std::cout << stk[cnt];
        }
        std::cout << "\t" << a << "$\t";

        // Call check function ..which will
        // check the stk whether its contain
        // any production or not
        check();
    }

    // Rechecking last time if contain
    // any valid production then it will
    // replace otherwise invalid
    check();

    // if top of the stk is E(starting symbol)
    // then it will accept the input
    if(stk[0] == 'E' && stk[1] == '\0')
        printf("Accept\n");
    else //else reject
        printf("Reject\n");
}
// This code is contributed by Shubhamsingh10
