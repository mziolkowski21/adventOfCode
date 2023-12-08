#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>


/* 
v = d/t
d = v*t where v(t) = 1*t_hold and t = t_max-t_hold
d = t_hold(t_max-t_hold)
d(t_hold) = t_hold*t_max - t_hold^2

d(7) = 7t-t^2

d(7)t(1) = 6
t(2) = 14-4 = 10
t(3) = 21-9 = 12
*/

int calculate_distance_traveled(unsigned int t_held, unsigned int t_max);
void parse_and_solve_part1();
void parse_and_solve_part2();
// solve_quadratic_equation();


int main(int argc, char *argv[])
{

    if(*argv[1] == '1')
        parse_and_solve_part1();
    else
        parse_and_solve_part2();
    return 0;
}


int calculate_distance_traveled(unsigned int t_held, unsigned int t_max)
{
    return t_max*t_held - t_held*t_held;
}


void parse_and_solve_part1()
{
    std::vector <unsigned int> times {};
    std::vector <int> distances {};

    int how_many_times_able_to_beat_record {0};
    int solution {1};
    std::string str {};
    int temp_num {0};

    getline(std::cin, str);
    std::stringstream ss {str};
    ss >> str; // "Time:""
    while(ss >> temp_num)
    {
        times.push_back(temp_num);
    }

    // empty ss
    ss.str("");
    ss.clear();

    getline(std::cin, str);
    ss << str;
    ss >> str; // "Distance:"

    while (ss >> temp_num)
    {
        distances.push_back(temp_num);
    }

    // solution (assumming times.size() == distances.size())
    for(unsigned int i {0}; i < times.size(); ++i)
    {
        for(unsigned int j {0}; j < times[i]; ++j)
        {            
            if(calculate_distance_traveled(j, times[i]) > distances[i])
                how_many_times_able_to_beat_record++;            
        }
        solution *= how_many_times_able_to_beat_record;
        how_many_times_able_to_beat_record = 0;
    }
    std::cout << solution << '\n';

}

void parse_and_solve_part2()
{

    // solve inequality
    // d(t_hold) > d_record ---> t_hold*t_max - t_hold^2 > d_record
    // t_hold^2 - t_hold*t_max + d_record < 0
    // ---> (t_max-sqrt(t_max^2-4dm_record))/2 < t_hold < (t_max+sqrt(t_max^2-4dm_record))/2
    
    std::string str {};
    std::string temp_num {};

    long long time {0};
    long long distance {0};


    getline(std::cin, str);
    std::stringstream ss {str};
    ss >> str; // "Time:""
    str = "";
    while(ss >> temp_num)
    {
        str.append(temp_num);
    }
    time = std::stoll(str);

    // empty ss
    ss.str("");
    ss.clear();

    getline(std::cin, str);
    ss << str;
    ss >> str; // "Distance:"
    str = "";

    while (ss >> temp_num)
    {
        str.append(temp_num);
    }

    distance = std::stoll(str);
    long double distanceF = static_cast<long double> (distance);
    long double timeF = static_cast<long double> (time);

    // std::cerr << distanceF << '\n';

    long long solution1 = std::floor((timeF + std::sqrt( timeF*timeF - 4*distanceF ))/2);
    long long solution2 = std::ceil((timeF - std::sqrt( timeF*timeF - 4*distanceF ))/2);

    std::cerr << solution1 << " " << solution2 << '\n';

    long long solution = solution1 - solution2;
    std::cout << solution+1 << '\n';

}