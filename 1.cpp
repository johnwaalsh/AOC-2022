#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    int curr_calories = 0;
    int cal_item;
    list<int> cals;
    list<int>::iterator it = cals.begin();

    std::string line;

    while(std::getline(std::cin, line)) {
        if(line.empty()) {
            cals.insert(it, curr_calories);
            it++;
            curr_calories = 0;
        }
        else {
            cal_item = stoi(line);
            curr_calories += cal_item;
        }
    }
    cals.insert(it, curr_calories);

    cals.sort();
    cals.reverse();

    it = cals.begin();
    int first_place = *it;
    it++;
    int second_place = *it;
    it++;
    int third_place = *it;

    // Part 1
    std::cout << first_place << endl;

    // Part 2
    int top_3_calories = first_place + second_place + third_place;
    std::cout << top_3_calories;
    return 0;
}