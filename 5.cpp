#include <iostream>
#include <string>
#include <list>
#include <sstream>
using namespace std;

// Helper method for debugging
int print_containers(list<list<char>> containers) {
    for (const auto &container: containers) {
        for (auto const &item: container) {
            cout << item << endl;
        }
        cout << " " << endl;
    }
    return 0;
}

int perform_move(list<list<char>>& containers, list<list<char>>& p2_containers, string line) {
    istringstream iss(line);
    string temp_buff;
    int index = 0;
    int num_to_move;
    int from;
    int to;
    while (getline(iss, temp_buff, ' ')) {
        if (index == 1) {
            num_to_move = stoi(temp_buff);
        } else if (index == 3) {
            from = stoi(temp_buff);
        } else if (index == 5) {
            to = stoi(temp_buff);
        }
        index++;
    }

    // Part 1
    auto container_iterator = containers.begin();
    advance(container_iterator, from-1);
    list<char>& from_container = *container_iterator;

    auto second_container_iterator = containers.begin();
    advance(second_container_iterator, to-1);
    list<char>& to_container = *second_container_iterator;

    for (int i = 0; i < num_to_move; i++) {
        auto from_container_iterator = from_container.begin();
        advance(from_container_iterator, 1);
        to_container.splice(to_container.begin(), from_container, from_container.begin(), from_container_iterator);
    }

    // Part 2
    auto p2_container_iterator = p2_containers.begin();
    advance(p2_container_iterator, from-1);
    list<char>& p2_from_container = *p2_container_iterator;

    auto p2_second_container_iterator = p2_containers.begin();
    advance(p2_second_container_iterator, to-1);
    list<char>& p2_to_container = *p2_second_container_iterator;

    auto p2_iterator = p2_from_container.begin();
    advance(p2_iterator, num_to_move);
    to_container.splice(p2_to_container.begin(), p2_from_container, p2_from_container.begin(), p2_iterator);

    return 0;
}

int print_top(list<list<char>> containers) {
    for (const auto &container: containers) {
        cout << container.front();
    }
    return 0;
}

int main() {
   string line;

    bool prep = true;
    list<list<char>> containers;
    list<list<char>> p2_containers;
    while (getline(cin, line)) {
        if (line.empty()) {
            prep = false;
            p2_containers.assign(containers.begin(), containers.end());
            continue;
        }

        if (prep) {
            for (int i = 1; i < line.length(); i += 4) {
                char rel_char = line[i];
                int container_index = (i - 1) / 4;
                if (isdigit(rel_char)) {
                    continue;
                } else {
                    if (container_index >= containers.size()) {
                        list<char> new_container;
                        containers.push_back(new_container);
                    }
                    if (!isspace(rel_char)) {
                        auto container_iterator = containers.begin();
                        advance(container_iterator, container_index);
                        list<char>& rel_container = *container_iterator;
                        rel_container.push_back(rel_char);
                    }
                }
            }
        } else {
            perform_move(containers, p2_containers, line);
        }
    }

    // Part 1
    print_top(containers);

    cout << endl;

    // Part 2
    print_top(p2_containers);
    return 0;
}