#include <fstream> // file stream
#include <iostream>
// #include <string>
#include <algorithm>
#include <iterator>


int main(){

    std::ifstream input_file("input1.txt"); // Stream class to read from files
    // how to read file again?

    int freq_change = 0;
    int result_frequency = 0;

/*
    while (!input_file.eof()) {

        std::getline(input_file,freq_change);
        result_frequency += std::stoi(freq_change); // string to int
    }
*/

    while (input_file >> freq_change){
        result_frequency += freq_change;
    }
    std::cout << result_frequency;
    input_file.close(); // closing file can be too much, no need 

}
