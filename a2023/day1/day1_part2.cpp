#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

const std::map<std::string, char> strToCharMap {{"zero",'0'},{"one",'1'},{"two",'2'},{"three",'3'},{"four",'4'},{"five",'5'},{"six",'6'},{"seven",'7'},{"eight",'8'},{"nine",'9'}};

bool is_there_a_digit(char &digit_to_find, const std::string &input_substring, bool is_reversed);

int main()
{
    unsigned int sum {0}; 
    std::string input_line {};
    while(std::getline(std::cin, input_line))
    {
        std::string sub_string {};
        char digit_to_find {};
        std::string line_number {};
        for(unsigned int i=0; i<input_line.length(); i++)
        {
            sub_string.push_back(input_line[i]);
            if(is_there_a_digit(digit_to_find, sub_string, false))
            {
                line_number = digit_to_find;
                break;
            }
        }
        sub_string = "";
        for(unsigned int i=input_line.length()-1; i > 0; i--)
        {
            sub_string.push_back(input_line[i]);
            if(is_there_a_digit(digit_to_find, sub_string, true))
            {
                
                line_number = line_number + digit_to_find;
                break;
               
            }
        }
        if (line_number.length() == 1)
            line_number.push_back(line_number.back());
        sum += stoi(line_number);
        std::cerr << line_number << '\n';
    }
     std::cout << sum << '\n';

}

bool is_there_a_digit(char &digit_to_find, const std::string &input_substring, bool is_reversed)
{
    // std::cerr << input_substring << '\n';
    for(const auto &kv : strToCharMap)
    {
        size_t found {};
        if (!is_reversed)
             found = input_substring.find(kv.first);
        else
        {
            std::string temp_string {};
            for(int i = input_substring.length() - 1; i >= 0; i--)
            {
                temp_string.push_back(input_substring[i]);
            }
            found = temp_string.find(kv.first);
        }
             
        if (found!=std::string::npos) 
        {

            digit_to_find = kv.second;
            return true;
        }
    }

    if (isdigit(input_substring.back()))
    {
        digit_to_find = input_substring.back();
        return true;
    }

    return false;
}