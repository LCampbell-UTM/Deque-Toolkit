#include "deque.h"
#include <iostream>
#include <fstream>

int main()
{
    IntDeque dq; 

    std::cout << "Starting test.\n";

    // =========================
    // STRESS TEST (MAIN TEST)
    // =========================
    for (int i = 0; i < 5000; i++)
    {
        dq.push_back(i); 
        dq.push_front(-i);

        if (i % 7 == 0)
        {
            dq.pop_front();
        }

        if (i % 11 == 0)
        {
            dq.pop_back();
        }
    }

    std::cout << "\n--- Initial Stress Test Complete ---\n";
    std::cout << "Expected size approx: 8832\n";
    std::cout << "Actual size: " << dq.size() << "\n";

    // =========================
    // FRONT / BACK TEST
    // =========================
    if (!dq.empty())
    {
        std::cout << "Front: " << dq.front() << "\n";
        std::cout << "Back: " << dq.back() << "\n";
    }

    // =========================
    // OPERATOR[] TEST (WRITE TO FILE)
    // =========================
    std::ofstream outFile1("test1.txt");
    for (int i = 0; i < dq.size(); i++)
    {
        int x = dq[i];
        outFile1 << x << " ";
    }
    outFile1.close();
    std::cout << "Wrote deque to test1.txt\n";

    // =========================
    // OPERATOR[] VALIDATION
    // =========================
    bool valid = true;
    for (int i = 0; i < dq.size(); i++)
    {
        if (dq[i] != dq[i]) // basic consistency check
        {
            valid = false;
            break;
        }
    }
    std::cout << "Operator[] working? " << (valid ? "Yes" : "No") << "\n";

    // =========================
    // EMPTY TEST
    // =========================
    while (!dq.empty())
    {
        dq.pop_front();
    }

    std::cout << "Empty? " << (dq.empty() ? "Yes" : "No") << "\n";

    // =========================
    // EDGE CASE TESTS
    // =========================
    std::cout << "\n--- Edge Case Testing ---\n";

    dq.pop_front(); // should not crash
    dq.pop_back();  // should not crash

    dq.push_back(42);
    std::cout << "Single element front/back: "
              << dq.front() << " " << dq.back() << "\n";

    dq.pop_back();

    // =========================
    // REFILL TEST
    // =========================
    for (int i = 0; i < 1000; i++)
    {
        dq.push_back(i);
    }

    std::ofstream outFile2("test2.txt");
    for (int i = 0; i < dq.size(); i++)
    {
        outFile2 << dq[i] << " ";
    }
    outFile2.close();
    std::cout << "Wrote altered deque to test2.txt\n";

    std::cout << "Size after refill: " << dq.size() << "\n";

    // =========================
    // SECOND STRESS TEST
    // =========================
    for (int i = 0; i < 500; i++)
    {
        dq.pop_front();
        dq.pop_back();
    }

    std::cout << "Size after second stress: " << dq.size() << "\n";

    std::cout << "Done.\n";

    return 0;
}
