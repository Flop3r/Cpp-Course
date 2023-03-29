// Franciszek Przeliorz      //
// Uniwerystet Wrocławski    //
// Kurs: Programowanie w C++ //
// Lista 3                   //

#include <iostream>
#include "Liczba.h"

int main() {

    // Test domyślnego konstruktora
    Liczba a;
    std::cout << "KONSTRUKTOR DOMYŚLNY: " << a.get() << std::endl;
    a.PrintHistory();
    std::cout << std::endl;

    // Test konstruktora z wartością początkową
    Liczba b(5.5);
    std::cout << "KONSTRUKTOR DOMYŚLNY Z POCZĄTKOWĄ WARTOŚCIĄ: " << b.get() << std::endl;
    b.PrintHistory();
    std::cout << std::endl;

    // Test kopiującego konstruktora
    Liczba c(b);
    std::cout << "KOPIUJĄCY KONSTRUKTOR: " << c.get() << std::endl;
    c.PrintHistory();
    std::cout << std::endl;

    // Test przypisania kopiującego
    a = c;
    std::cout << "PRZYPISANIE KOPIUJĄCE: " << a.get() << std::endl;
    a.PrintHistory();
    std::cout << std::endl;

    // Test przypisania przenoszącego
    Liczba d(3.2);
    a = std::move(d);
    std::cout << "PRZYPISANIE PRZENOSZĄCE: " << a.get() << std::endl;
    a.PrintHistory();
    std::cout << std::endl;

    // Test metody set()
    a.set(7.8);
    std::cout << "COFNIĘCIE DO WCZEŚNIEJSZEJ WARTOŚCI W HISTORII: " << a.get() << std::endl;
    a.PrintHistory();
    std::cout << std::endl;

    // Test metody undo()
    a.undo();
    std::cout << "COFNIĘCIE DO WCZEŚNIEJSZEJ WARTOŚCI W HISTORII: " << a.get() << std::endl;
    a.PrintHistory();
    std::cout << std::endl;

    // Test nadpisania buforu
    Liczba e;
    for(int i = 0; i <= 11; i++){
        e.set(i);
    }
    std::cout << "TEST NADPISYWANIA BUFORU LICZBA: " << std::endl;
    e.PrintHistory();
    std::cout << std::endl;

    return 0;
}
