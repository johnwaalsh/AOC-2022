#include <iostream>
#include <string>
using namespace std;

int main() {
    std::string line;
    int complete_overlaps = 0;
    int overlaps = 0; 

    while (std::getline(std::cin, line)) {
        int split = line.find(",");
        std::string elf_1 = line.substr(0, split);
        int elf_1_split = elf_1.find("-");
        int elf_1_start = stoi(elf_1.substr(0, elf_1_split));
        int elf_1_end = stoi(elf_1.substr(elf_1_split+1));

        std::string elf_2 = line.substr(split+1);
        int elf_2_split = elf_2.find("-");
        int elf_2_start = stoi(elf_2.substr(0, elf_2_split));
        int elf_2_end = stoi(elf_2.substr(elf_2_split+1));

        if ((elf_1_start <= elf_2_start and elf_1_end >= elf_2_end) or (elf_1_start >= elf_2_start and elf_1_end <= elf_2_end)) {
            complete_overlaps += 1;
        }

        if ((elf_1_start >= elf_2_start and elf_1_start <= elf_2_end)
         or (elf_1_end >= elf_2_start and elf_1_end <= elf_2_end)
         or (elf_2_start >= elf_1_start and elf_2_start <= elf_1_end)
         or (elf_2_end >= elf_1_start and elf_2_end <= elf_1_end)) {
            overlaps += 1;
        }
    }

    // Part 1
    std::cout << complete_overlaps << std::endl;

    // Part 2
    std::cout << overlaps << std::endl;

    return 0;
}