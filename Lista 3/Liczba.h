// Franciszek Przeliorz      //
// Uniwerystet Wrocławski    //
// Kurs: Programowanie w C++ //
// Lista 3                   //

#ifndef UNTITLED_LICZBA_H
#define UNTITLED_LICZBA_H

#include <iostream>
#include <iostream>

class Liczba {
private:
    static const int MAX_HIST = 10; // Stała określająca długość zapisanej historii liczb

    double value;
    double* history;
    int histSize;
    int histId;

public:
    // Konstrukotr domyślny bez wartości
    Liczba();

    // Konstrukotr domyślny z wartością początkową
    explicit Liczba(double val);

    // Konstrukotr kopiujący
    Liczba(const Liczba& other);

    // Konstrukotr przepisujący
    Liczba(Liczba&& other);

    // Destruktor przenoszący
    ~Liczba();

    // Operatory przypisywania
    Liczba& operator=(const Liczba& other);
    Liczba& operator=(Liczba&& other);

    // Metoda ustawiająca nową wartość liczby
    void set(double val);

    // Metoda zwracająca aktualną wartość liczby
    double get() const;

    // Metoda cofająca wartość liczby do poprzedniej wartości
    void undo();

    // Metoda drukująca na wyjściu standardowym bufor historii liczby
    void PrintHistory();

};


#endif //UNTITLED_LICZBA_H
