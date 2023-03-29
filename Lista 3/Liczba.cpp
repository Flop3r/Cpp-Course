// Franciszek Przeliorz      //
// Uniwerystet Wrocławski    //
// Kurs: Programowanie w C++ //
// Lista 3                   //

#include <iostream>
#include "Liczba.h"

Liczba::Liczba() : value(0), history(new double[MAX_HIST]), histSize(1), histId(0) {
    history[0] = value;
}

 Liczba::Liczba(double val) : value(val), history(new double[MAX_HIST]), histSize(1), histId(0) {
    history[0] = value;
}

Liczba::Liczba(const Liczba& other) : value(other.value), history(new double[MAX_HIST]), histSize(1), histId(0) {
    history[0] = value;
}

Liczba::Liczba(Liczba&& other) : value(other.value), history(other.history), histSize(other.histSize), histId(other.histId) {
    other.history = nullptr;
}

Liczba::~Liczba() {
    delete[] history;
}

Liczba& Liczba::operator=(const Liczba& other) {
    if (this == &other) {
        return *this;
    }
    value = other.value;
    history[0] = value;
    histSize = 1;
    histId = 0;
    return *this;
}

Liczba& Liczba::operator=(Liczba&& other) {
    if (this == &other) {
        return *this;
    }
    value = other.value;
    history = other.history;
    histSize = other.histSize;
    histId = other.histId;
    other.history = nullptr;
    return *this;
}

void Liczba::set(double val) {
    if (histSize < MAX_HIST) {
        histSize++;
    }
    for (int i = histSize - 1; i > 0; i--) {
        history[i] = history[i-1];
    }

    history[0] = val;
    value = val;
}


double Liczba::get() const {
    return value;
}

void Liczba::undo() {
    if (histSize == 1) {
        return;
    }
    for (int i = 0; i < histSize; i++) {
        history[i] = history[i + 1];
    }
    histSize--;
    value = history[0];
}

void Liczba::PrintHistory(){
    std::cout << "Historia liczba:" << std::endl;
    for(int i = 0; i < histSize; i++){
        std::cout << history[i] << ", ";
    }

    std::cout << std::endl;
}

