#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum  Card {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
enum  HandType {Null, HighCard, OnePair, TwoPair, ThreeKind, Full, FourKind, FiveKind};


class Hand
{
public:
    Hand() 
        : hand{""}, bid{0}
    {
        convertStrToHand();
    }
    Hand(std::string hand_val, int bid_val) 
        : hand{hand_val}, bid{bid_val}
    {
        convertStrToHand();
    }
    Hand& operator=(const Hand& obj_source)
    {
       hand = obj_source.hand;
       bid = obj_source.bid;
       cards_in_hand = obj_source.cards_in_hand;
       return *this;
    }
    bool operator<(Hand &h2) const
    {
        // returns true if h2 is of greater power than h1
        std::cerr << hand_type << " < "  << h2.hand_type << " = " << (hand_type < h2.hand_type) << '\n';
        return hand_type < h2.hand_type;
        // if(hand_type != h2.get_hand_type())
        // {
        //     std::cerr << "DUPA KURWA" << '\n';
        //     return hand_type < h2.get_hand_type();
        // }
        // else
        // {
        //     for(unsigned int i {0}; i < 5; ++i)
        //     {
        //         if(cards_in_hand[i] != h2.cards_in_hand[i])
        //             return cards_in_hand[i] < h2.cards_in_hand[i];
        //     }
        //     return false;
        // }
    }
    
    HandType get_hand_type()
    {
        return hand_type;
    }
    std::vector <Card> cards_in_hand {};

    int get_bid() const
    {
        return bid;
    }
    
private:

    std::string hand {};
    int bid {};
    HandType  hand_type {HandType::Null};

    void convertStrToHand ();
};

void Hand::convertStrToHand ()
{
    char repeated_card {' '};
    int count_array [13] = {0};
    for(char c : hand)
        {
            switch (c)
            {
                case 'T':
                        cards_in_hand.push_back(Card::Ten);
                        count_array[10-2]++;
                        break;
                case 'J':
                        cards_in_hand.push_back(Card::Jack);
                        count_array[11-2]++;
                        break;
                case 'Q':
                        cards_in_hand.push_back(Card::Queen);
                        count_array[12-2]++;
                        break;
                case 'K':
                        cards_in_hand.push_back(Card::King);
                        count_array[13-2]++;
                        break;
                case 'A':
                        cards_in_hand.push_back(Card::Ace);
                        count_array[14-2]++;
                        break;
                default:
                        cards_in_hand.push_back(Card(c-'0'));
                        count_array[(c-'0')-2]++;
            }
        }
    bool possible_full {false};
    bool theres_three {false};
    int how_many_pairs {0};
    for(unsigned int i {0}; i < 13; ++i)
    {
        if (count_array[i] == 5)
        {
            hand_type = HandType::FiveKind;
            break;
        }
        else if (count_array[i] == 4)
        {
            hand_type = HandType::FourKind;
            break;
        }
        else if (count_array[i] == 3)
            theres_three = true;
        else if (count_array[i] == 2)
        {
            how_many_pairs++;
        }
    }
    if (theres_three)
    {
        if (how_many_pairs == 1)
            hand_type = HandType::Full;
        else
            hand_type = HandType::ThreeKind;
    }
    else if(how_many_pairs == 2)
        hand_type = HandType::TwoPair;
    else if (how_many_pairs == 1)
        hand_type = HandType::OnePair;
    else if (hand_type == HandType::Null)
        hand_type = HandType::HighCard;
}

// bool operator <(Hand &h1, Hand &h2)
// {
//     // returns true if h2 is of greater power than h1
//     if(h1.get_hand_type() != h2.get_hand_type())
//     {
//         std::cerr << "DUPA KURWA" << '\n';
//         return h1.get_hand_type() < h2.get_hand_type();
//     }
//     else
//     {
//         for(unsigned int i {0}; i < 5; ++i)
//         {
//             if(h1.cards_in_hand[i] != h2.cards_in_hand[i])
//                 return h1.cards_in_hand[i] < h2.cards_in_hand[i];
//         }
//         return false;
//     }
// }
 
// bool operator <(Hand const &h1, Hand const &h2)
// {
//     return (h1.get_bid() < h2.get_bid());
// }

int main()
{
    std::vector <Hand> hands {};

    std::string hand {};
    int bid {0};
    while(std::cin >> hand >> bid)
    {
        Hand temp_hand(hand,bid);
        hands.push_back(temp_hand);
    }

    for(int i = 0; i<5;++i)
    {
        std::cout << hands[i].get_hand_type() << '\n';
    }
    std::cerr << '\n';

    std::sort(hands.begin(),hands.end());
    
    for(int i = 0; i<5;++i)
    {
        std::cout << hands[i].get_hand_type() << '\n';
    }

}