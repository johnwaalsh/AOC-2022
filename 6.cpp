#include <iostream>
#include <string>
#include <set>
using namespace std;

bool unique_set(string sub) {
    set<char> sub_set;   
    for (char sub_c : sub) {
        sub_set.insert(sub_c);
    }
    return sub_set.size() == sub.length();
}

int main() {
    string line;
    int marker_index = -1;
    int start_of_message_index = -1;

    while (getline(cin, line)) {
        for (int left = 0; left < line.length()-3; left++) {
            string sub = line.substr(left, 4);
            if (unique_set(sub)) {
                if (marker_index == -1) {
                    marker_index = left + 4;
                }
            }

            if (left < line.length() - 13) {
                string p2_sub = line.substr(left, 14);
                if (unique_set(p2_sub)) {
                    if (start_of_message_index == -1) {
                        start_of_message_index = left + 14;
                    }
            }
            }
        }
    }

    // Part 1
    cout << marker_index << endl;

    // Part 2
    cout << start_of_message_index << endl;

    return 0;
}