/**
 * a4.cpp
 * Assignment 4, CMPT-225
 *
 * Matthew Marinets
 * 301311930
 * mmarinet@sfu.ca
 *
 * Reads a sequence of integers (in the range of int's) from standard in;
 * It is interpreted as two lists, separated by a single 0
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // print student info
    cout << "301311930 mmarinet Matthew Marinets" << endl;

    // get input file name
    std::string inputFileName;
    cin >> inputFileName;

    // declare collections to hold the two lists
    std::vector<int> list1;
    std::set<int> list2;
    auto input = std::ifstream(inputFileName);

    // load values into list 1
    int x;
    while (input) {
        input >> x;
        if (x) {
            list1.push_back(x);
            std::push_heap(list1.begin(), list1.end());
        } else {
            break;
        }
    }

    // load values into list 2
    while (input) {
        input >> x;
        if (x) {
            list2.insert(x);
        }
    }

    // repeatedly take the max element of list1, and return it if it is not in list 2.
    int retval;
    while (true) {
        if (list1.empty()) {
            retval = 0;
            break;
        }
        retval = list1.front();
        std::pop_heap(list1.begin(), list1.end());
        list1.pop_back();
        if (list2.find(retval) == list2.end()) {
            break;
        }
    }

    // print the result
    if (retval) {
        cout << retval << endl;
    } else {
        cout << "NONE" << endl;
    }

    return 0;
}
