#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    list<int> nums;
    int n;
    while (cin >> n) {
        nums.push_back(n);
        nums.sort();
        int size = nums.size();
        if (size % 2 == 0) {
            auto it1 = nums.begin();
            advance(it1, size/2 - 1);
            auto it2 = it1;
            advance(it2, 1);
            double median = (*it1 + *it2) / 2.0;
            cout << "[";
            for (auto it = nums.begin(); it != nums.end(); ++it) {
                cout << *it;
                if (it != prev(nums.end())) cout << ", ";
            }
            cout << "] " << fixed << setprecision(1) << median << endl;
        } else {
            auto it = nums.begin();
            advance(it, size/2);
            double median = *it;
            cout << "[";
            for (auto it = nums.begin(); it != nums.end(); ++it) {
                cout << *it;
                if (it != prev(nums.end())) cout << ", ";
            }
            cout << "] " << fixed << setprecision(1) << median << endl;
        }
    }
    return 0;
}
