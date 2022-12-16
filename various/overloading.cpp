#include <iostream>

struct Ulamek {
    
    int licznik,mianownik;

    // Ulamek () : licznik{0},mianownik{1} {} // constructor without any parameters, constructor has to be called the same as class

    // Ulamek (int l, int m) : licznik{l},mianownik{m} {} // constructor with parameters
    /*
    {
        licznik = l;
        mianownik = m;  // another way to define constructor; without colon then
    }
    */

    // if you want to have multiple constructors they have to have different signature (diff amount of parameters or of different type)
    
    Ulamek(int l=0, int m=1) : licznik{l},mianownik{m} {} // default parameter value
    // explicit Ulamek(int l=0, int m=1) : licznik{l},mianownik{m} {} // default parameter value // will only work for the constructor types
    


    void add(const Ulamek &other);
    void mul(const Ulamek &other);


    void print();
};
void Ulamek::print()
{
    std::cout << licznik << '/' << mianownik << '\n';
}

// Ulamek add(const Ulamek &a, const Ulamek &b)
// {
//     Ulamek result;
//     result.licznik = a.licznik*b.mianownik + a.mianownik*b.licznik;
//     result.mianownik = a.mianownik * b.mianownik;

//     return result;
// }

Ulamek operator +(const Ulamek &a, const Ulamek &b) // &lhs, &rhs - operator enforces arguemnts to define what's on left hand side and rhs
{
    Ulamek result;
    result.licznik = a.licznik*b.mianownik + a.mianownik*b.licznik;
    result.mianownik = a.mianownik * b.mianownik;

    return result;
}

Ulamek operator *(const Ulamek &a, const Ulamek &b) // operator is a function
{
    // Ulamek result;
    // result.licznik = a.licznik*b.licznik;
    // result.mianownik = a.mianownik*b.mianownik;

    return Ulamek{a.licznik * b.licznik, a.mianownik * b.mianownik};
}

// std::map<int,int> mapka;
// mapka['a'] = 51
// operator []

int main()
{
    Ulamek a{1,3};
    a.print();

    Ulamek b{2,7}, c{5,9};

    // Ulamek d = add(a,mul(b,c));
    Ulamek d = a+b*c;

    d.print();

    d = a + 5; // d = a + Ulamek{5}
    return 0;
}