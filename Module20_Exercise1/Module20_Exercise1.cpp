// Jan 13 2025
// Module20_Exercise1.cpp
// Swap a Stack: using C++ Standard Template Library's built-in stack container, this program reverses the order of a series of numbers;
// It obtains a series of numbers from the user, displays them back, and then displays the list in reverse order.  

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    stack<int> reversed_nums;
    vector<int> original_nums;
    int num;
    cout << " Enter your list of numbers: (Type -1 to stop)" << endl;
    
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }
        original_nums.push_back(num); // Stores copy of num to end of vector
        reversed_nums.push(num); // Push into stack
    }
    cout << "Original: ";
    for (int i : original_nums) {
        cout << i << " ";
    }

    cout << endl;

    cout << "Reversed: ";
    while (!reversed_nums.empty()) {
        cout << reversed_nums.top() << " ";
        reversed_nums.pop();
    }
    cout << endl;

    return 0;
    
}

