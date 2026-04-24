#include "deque.h"
#include <iostream>
#include <fstream>

int main()
{
    IntDeque dq; 

    std::cout << "Starting test.\n";

    for (int i = 0; i < 5000; i++) // tests push_back, push_front, pop_back, and pop_front
    {
        // increases size by 2 each loop
        dq.push_back(i); 
        dq.push_front(-i);

        // decreases size by 1 every 7 loops
        if (i % 7 == 0)
        {
            dq.pop_front();
        }

        // decreases size by 1 every 11 loops
        if (i % 11 == 0)
        {
            dq.pop_back();
        }

        // math for size = (2 * 5000) - (5000 / 7) - (5000 / 11) 
        // so size = 10000 - 714 - 454 = 8832
        // 714 and 454 lose their decimal points. integers and all that.
    }

    std::cout << "Size: " << dq.size() << "\n"; // tests size


    std::ofstream outFile1("test1.txt");
    for (int i = 0; i < dq.size(); i++) // tests operator[]
    {
        int x = dq[i];
    
        outFile1 << x << " "; // writes entire deque to file
    }
    outFile1.close();
    std::cout << "\nWrote deque to test1.txt\n";


    while (!dq.empty()) // tests empty
    {
        dq.pop_front(); // empties the deque by popping it all
    }


    std::string answer; // tests empty
    if(dq.empty())
    {
        answer = "Yes";
    }
    else
    {
        answer = "No";
    }
    std::cout << "Empty? " << answer << "\n"; // tells if empty worked or not


    for (int i = 0; i < 1000; i++)
    {
        dq.push_back(i); // refills the deque
    }

    std::ofstream outFile2("test2.txt");
    for (int i = 0; i < dq.size(); i++)
    {
        outFile2 << dq[i] << " "; // prints the newly refilled deque to test2.txt
    }
    outFile2.close();
    std::cout << "\nWrote altered deque to test2.txt\n";

    std::cout << "Final size: " << dq.size() << "\n"; // should be 1000

    std::cout << "Done.\n";

    return 0;
}
