#include "basic_type.h"
#include <iostream>

// say what standard-library names we use
using std::cin;         using std::endl;
using std::cout;        using std::string;

S32 main()
{
    std::cout << "Please enter your first name: ";
    std::string name;
    const std::string hello = "Hello, ";
    const std::string message = hello + "world" + "!";
    std::cin >> name;
    std::cout << "Hello,  " << name << "!" << std::endl;
    std::cout << "This (\") is a quote, and this (\\) is a backlash." << std::endl;

    {
        const std::string s = "a string";
        std::cout << s << std::endl;
      {
        const std::string s = "another string";
        std::cout << s << std::endl;
      };
    };

    const string greeting = "Hello, " + name + "!";
    const S32 pad = 1;
    
    const S32 rows = pad * 2 + 3;
    string::size_type cols = greeting.size() + pad * 2 + 2;

    cout <<endl;

    for (S32 r = 0; r < rows; ++r)
    {
        string::size_type c = 0;
        while (c != cols)
        {
            if ((r == pad  || r == pad + 2) && c == pad)
            {
                string blankLine(greeting.size() + 2, ' ');
                cout << blankLine << endl;
                c += greeting.size() + 2;
            }
            else if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if (r == 0 || r == rows - 1 ||
                    c == 0 || c == cols - 1)
                {
                    cout << '*';
                }
                else
                {
                    cout << ' ';
                }
                ++c;
            }
        }
        cout <<endl;
    }
    

    return 0;
}