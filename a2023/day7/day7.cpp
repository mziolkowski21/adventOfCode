#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

enum  HandType {Nan, HighCard, OnePair, TwoPair, ThreeKind, Full, FourKind, FiveKind};

std::map<char, int> convert_to_relative_strength
{
    {'2', 1},
    {'3', 2},
    {'4', 3},
    {'5', 4},
    {'6', 5},
    {'7', 6},
    {'8', 7},
    {'9', 8},
    {'T', 9},
    {'J', 10},
    {'Q', 11},
    {'K', 12},
    {'A', 13}
};

class Hand
{
public:
    Hand(std::string hand_val, int bid_val)
        : hand_str{hand_val}, bid{bid_val}, hand_type{Nan}
        {
            hand_type = determine_hand_type();
        };
    Hand(const Hand &src_obj)
        :Hand(src_obj.hand_str, src_obj.bid) {};

    int get_bid() const
    {
        return bid;
    }

    std::string get_hand() const
    {
        return hand_str;
    }

    HandType what_hand_type() const
    {
        return hand_type;
    }

    bool operator<(const Hand &h2) const
    {
        if(hand_type != h2.hand_type)
        {
            return hand_type < h2.hand_type;
        }
        else
        {
            for(unsigned int i{0}; i < hand_str.length(); ++i)
            {
                if(hand_str[i] != h2.hand_str[i])
                    return convert_to_relative_strength[hand_str[i]] < convert_to_relative_strength[h2.hand_str[i]];
            }
            return false;
        }
    }
    void operator=(const Hand &h2)
    {
        hand_str = h2.hand_str;
        bid = h2.bid;
        hand_type = h2.hand_type;
    }
    
private:
    std::string hand_str;
    int bid;
    HandType hand_type;

    HandType determine_hand_type() const;
    
};

HandType Hand::determine_hand_type() const
{
    bool there_is_three {false};
    int how_many_pairs {0};

    std::map <char, int> how_many_in_hand {};
    for(char c : hand_str)
    {
        ++how_many_in_hand[c];
    }
    for(std::pair <char,int> p : how_many_in_hand)
    {
        if (p.second == 5)
            return FiveKind;    
        else if (p.second == 4)
            return FourKind;
        else if (p.second == 3)
            there_is_three = true;
        else if (p.second == 2)
            ++ how_many_pairs;
        else
            continue;
    }
    if (there_is_three)
    {
        if (how_many_pairs == 1)
            return Full;
        else
            return ThreeKind;
    }
    else if (how_many_pairs == 2)
        return TwoPair;
    else if (how_many_pairs == 1)
        return OnePair;
    else
        return HighCard;
}


int main ()
{
    std::vector <Hand> hands {};
    std::string temp_str {};
    int bid {};
    while(std::cin >> temp_str >> bid)
    {
        Hand temp_hand(temp_str,bid);
        hands.push_back(temp_hand);
    }

    std::sort(hands.begin(),hands.end());

    int solution {0};
    for(int i {0}; i < hands.size(); i++)
    {
        solution += (i+1) * hands[i].get_bid();
    }
    std::cout << solution << '\n';
    return 0;
}