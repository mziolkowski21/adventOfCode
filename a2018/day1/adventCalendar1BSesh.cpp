#include <iostream>
#include <vector>
#include <set>


bool alreadyExists(int value, const std::vector <int> &sequence) // const jest dodatkowym zabezpieczeniem przed popsuciem referenced value przed zmiana
{ // do funkcji dla nie fundamentalnych typów nie chcemy przekazywać parametrów jako kopie, tylko fizycznie przekazać ten sam (&) z powodów wydajnościowych
// by default: pass-by-value (pass-by-copy)
// preferred: pass-by-reference (&)
// really preferred: pass-by-const-reference (const and &)
    for(int elem : sequence) // - range-based for (for-each)
    {
        if(value == elem)
        {
            return true;
        }
    }
    return false;
}

bool alreadyExists(int value, const std::set <int> &elemSet)
{
    // elemSet.find(value) - zwraca "uchwyt"/"handle"
    // elemSet.end() - specjalna wartość symbolizujący brak elementu
    return elemSet.find(value) != elemSet.end();
}


int main()
{
    
    std::vector <int> input;
    {
        int tmp;
        while(std::cin >> tmp)
        {
            input.push_back(tmp);
        }
    }

    // dla indeksów w for loopach lepiej dawać typ unsigned niż int
    
    // std::vector <int> prevSum; 
    int sum = 0;
    prevSum.push_back(sum);

    /*
    BST - Binary-Search Tree
    AVL - tpye of BST
    Red-Black Tree - also type of BST
    */
    std::set <int> prevSum; 
    /*
    - nie ma push_back() i pop_back()
    - vector jest sekwencją, set kolekcją, nie są w kolejności w której się je wrzuciło
    - insert(element), erase(element) - 0(log n)
    - zakłada się zazwyczaj log_2, e.g. log_2(1024) = 10, zajmie około 10 droższych operacji, przy 0(n) zajmie 1024 tanich operacji
    - find(element) - 0(log n)
    */

    // std::unordered_set, insert, erase - 0(1), hashing structure


    /*
        O(n^2) - złożońość obliczeniowa/algorithmic complexity - im więcej danych tym wykładniczo zwiększa się liczba kroków

        std::vector:
        - .push_back() - O(1) "zamortyzowany"
        - .pop_back() - O(1) - tanie
        - [idx], .at(idx) (at also checks if index is in range) - działa w czasie stałym O(1)
        - .insert(idx, element), .erase() - 0(n), kosztowniejsze, trzeba przekopiowac całą tablicę
        - n - zazwyczaj ilość danych wejściowych
    */

    while(true){
        // // czas: O(n)
        // for (int v : input)
        // {
        //     sum += v;

        //     // czas: O(n)
        //     if (alreadyExists(sum, prevSum)) 
        //     {
        //         std::cout << sum << '\n';
        //         return 0;
        //     }
        //     prevSum.push_back(sum);
        // }
    }
}