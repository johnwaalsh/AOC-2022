#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    int sum = 0;
    int new_strategy_sum = 0;

    unordered_map<char, string> opp_letter_to_rps;
    opp_letter_to_rps['A'] = "rock";
    opp_letter_to_rps['B'] = "paper";
    opp_letter_to_rps['C'] = "scissors";

    unordered_map<char, string> self_letter_to_rps;
    self_letter_to_rps['X'] = "rock";
    self_letter_to_rps['Y'] = "paper";
    self_letter_to_rps['Z'] = "scissors";

    unordered_map<string, int> letter_to_score;
    letter_to_score["rock"] = 1;
    letter_to_score["paper"] = 2;
    letter_to_score["scissors"] = 3;

    unordered_map<string, string> defeats;
    defeats["rock"] = "scissors";
    defeats["paper"] = "rock";
    defeats["scissors"] = "paper";

    unordered_map<string, string> loses;
    loses["rock"] = "paper";
    loses["paper"] = "scissors";
    loses["scissors"] = "rock";

    std::string line;

    while(std::getline(std::cin, line)) {
        char opp_move_char = line[0];
        std::string opp_move = opp_letter_to_rps[opp_move_char];
        char self_move_char = line[2];
        std::string self_move = self_letter_to_rps[self_move_char];
        int move_score = letter_to_score[self_move];

        // Part 1
        int outcome_score;
        if(opp_move == self_move) {
            outcome_score = 3;
        } else if(defeats[opp_move] == self_move) {
            outcome_score = 0;
        } else {
            outcome_score = 6;
        }

        sum += move_score + outcome_score;

        // Part 2
        int new_strategy_move_score;
        int new_strategy_outcome_score = 0;
        if(self_move_char == 'X') {
            new_strategy_move_score = letter_to_score[defeats[opp_move]];
            new_strategy_outcome_score = 0;
        } else if(self_move_char == 'Y') {
            new_strategy_move_score = letter_to_score[opp_move];
            new_strategy_outcome_score = 3;
        } else if(self_move_char == 'Z') {
            new_strategy_move_score = letter_to_score[loses[opp_move]];
            new_strategy_outcome_score = 6;
        }

        new_strategy_sum += new_strategy_move_score + new_strategy_outcome_score;
    }

    // Part 1
    std::cout << sum << std::endl;

    // Part 2
    std::cout << new_strategy_sum << std::endl;

    return 0;
}