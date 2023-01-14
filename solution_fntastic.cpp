#include <iostream>
#include <string>
#include <unordered_map>
// for tolower
#include <algorithm> // to avoid remaking existing bicycle with ascii table
#include <cctype> 


void convert2brackest(std::string& input) {
    std::transform(input.begin(), input.end(), input.begin(),
                    [](unsigned char c){ return std::tolower(c); });
    std::unordered_map<char, size_t> charMap;
    // possible update: change charMap to C array
    for (size_t i = 0; i < input.size(); ++i) {
        ++charMap[input[i]];
    }
    for (size_t i = 0; i < input.size(); ++i) {
        if (charMap[input[i]] == 1)
            input[i] = '(';
        else
            input[i] = ')';
    }
}

void test(const std::string& input, const std::string& result) {
    std::string temp = input;
    convert2brackest(temp);
    if (temp == result) {
        std::cout << "passed" << std::endl;
        return;
    }
    std::cout << "test failed: in \"" << input << " out: \"" << temp << "\"" << std::endl;
}

int main () {
    test("din", "(((");
    test("recede", "()()()");
    test("Success", ")())())");
    test("(( @", "))((");
}