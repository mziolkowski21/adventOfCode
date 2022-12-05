#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


int main()
{
    using std::vector;

    int result_frequency = 0;
    bool keep_looping = true;
    vector <int> input_vector;
    vector <int> freq_deviation = {0};

    std::ifstream input_file("input1.txt");

    {
        int freq_change = 0;
        while(input_file >> freq_change) // (std::cin >> freq_change) - can enter whole text file with standard input (./a.exe < input1.txt) przekierowanie wejścia
        {
            input_vector.push_back(freq_change);
                std::cout << freq_change << '\n';
        }
    } 

    while (keep_looping)
    {
        for (auto num:input_vector)
        {
            result_frequency += num;
            std::cout << result_frequency << '\n';
            if(std::find(freq_deviation.begin(), freq_deviation.end(), result_frequency) != freq_deviation.end())
            {
                std::cout << "Result: " << result_frequency; 
                keep_looping = false;
                break;
            }
            freq_deviation.push_back(result_frequency);
        }
    }

}