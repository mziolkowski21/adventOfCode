#include <iostream>
#include <algorithm>
#include <vector>
 
 enum TypesOfDupas {GOWNO, KUPA, SIKI};

class Dupa1234
{
public:
    Dupa1234(int dupka, TypesOfDupas dupType)
        : amountOfDupas{dupka}, dupaType{dupType} {};
    
    bool operator<(Dupa1234 const &dupaL)
    {
        return dupaType < dupaL.dupaType;
    }

    int outputDupas()
    {
        return amountOfDupas;
    }

private:
    int amountOfDupas;
    TypesOfDupas dupaType;
};


int main()
{
    Dupa1234 dup1(2, GOWNO);
    Dupa1234 dup2(69, KUPA);
    Dupa1234 dup3(4, SIKI);
    Dupa1234 dup4(15, SIKI);
    Dupa1234 dup5(-5, GOWNO);


    std::vector<Dupa1234> listDup{};
    listDup.push_back(dup1);
    listDup.push_back(dup2);
    listDup.push_back(dup3);
    listDup.push_back(dup4);
    listDup.push_back(dup5);


    for(auto a : listDup)
    {
        std::cerr << a.outputDupas() << '\n';
    }
    std::cerr << "\n\n";
    std::sort(listDup.begin(),listDup.end());
    for(auto a : listDup)
    {
        std::cerr << a.outputDupas() << '\n';
    }

}