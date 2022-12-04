#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int getValue(char c) {
    int c_val = int(c);
    if (isupper(c_val)) {
        return c_val - 38;
    } else {
        return c_val - 96;
    }
}

int getGroupValue(std::string member_1, std::string member_2, std::string member_3) {
    unordered_map<char, int> m_1;
    unordered_map<char, int> m_2;

    for (int i = 0; i < member_1.length(); i++) {
        m_1[member_1[i]] = 1;
    }

    for (int i = 0; i < member_2.length(); i++) {
        char rel_char = member_2[i];
        if (m_1.count(rel_char) == 1) {
            m_2[rel_char] = 1;
        }
    }

    for (int i = 0; i < member_3.length(); i++) {
        char rel_char = member_3[i];
        if (m_2.count(rel_char) == 1) {
            return getValue(rel_char);
        }
    }

    return 0;
}

int main() {

    std::string line;
    int total = 0;
    int badge_total = 0;

    int group_member = 0;
    std::string member_1;
    std::string member_2;
    std::string member_3;
    while(std::getline(std::cin, line)) {
        int line_length = line.length();
        int halfway = line_length / 2;
        unordered_map<char, int> compartment_1;
        unordered_map<char, int> compartment_2;

        std::string comp_1 = line.substr(0, halfway);
        std::string comp_2 = line.substr(halfway);
        
        for (int i = 0; i < comp_1.length(); i++) {
            compartment_1[comp_1[i]] = 1;
        }

        for (int i = 0; i < comp_2.length(); i++) {
            char rel_char = comp_2[i];
            if (compartment_1.count(rel_char) == 1 and compartment_2.count(rel_char) == 0) {
                total += getValue(rel_char);
                compartment_2[rel_char] = 1;
            }
        }

        if (group_member == 0) {
            member_1 = line;
            group_member++;
        } else if (group_member == 1) {
            member_2 = line;
            group_member++;
        } else {
            member_3 = line;
            badge_total += getGroupValue(member_1, member_2, member_3);
            group_member = 0;
        }
    }

    // Part 1
    std::cout << total << std::endl;

    // Part 2
    std::cout << badge_total << std::endl;

    return 0;
}