#include <iostream>
#include <fstream>


/*
rock - 1, paper - 2, scissors - 3
1 is beaten by 2 | 1 -> 2
2 is beaten by 3 | 2 -> 3
3 is beaten by 1 | 3 -> 1


*/
int main()
{
    std::ifstream input("input2.txt");
    char enemyChoice, playerChoice;
    int enemy, player;
    int score = 0;

    while(input >> enemyChoice)
    {
        input >> playerChoice;
        enemy = int(enemyChoice - 'A') + 1;

        if(playerChoice == 'X') player = enemy - 1 + 3*(enemy == 1);        
        if(playerChoice == 'Y') 
        {
            player = enemy;
            score += 3;
        }
        if(playerChoice == 'Z') 
        {
            player = enemy + 1 - 3*(enemy == 3);
            score += 6;
        }

        score += player;

    }

    std::cout << "score: " << score;
}