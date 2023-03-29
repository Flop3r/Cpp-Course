// Franciszek Przeliorz      //
// Uniwerystet Wrocławski    //
// Kurs: Programowanie w C++ //
// Lista 1                   //


#include <iostream>
#include <vector>
#include <string>

using namespace std;


string dec2rom(int x); // Funckja konwertującą liczbę dziesiętną na odpowiadający jej zapis w postaci rzymskiej

int main(int argc, char *argv[]){

    if(argc > 1){
        for (int i = 1; i < argc; i++) {
            int x;
            bool errorFlag = false;

            string str(argv[i]);

            try {
                x = stoi(str);
            }
            catch (const invalid_argument &e) {
                errorFlag = true;
            }
            catch (const out_of_range &e) {
                errorFlag = true;
            }

            if (!errorFlag && x >= 1)
                cout << dec2rom(x) << endl;

        }
    }else{
        int x = 1;

        while(x > 0) {
            cout << "Podaj liczbę w systemie dziesiętnym którą chcesz zamienić na liczbę w systemie rzymskim:" << endl;
            cin >> x;
            if(x > 0)
                cout << "Liczba w systmie rzymskim: " + dec2rom(x) << endl << endl;
        }
    }
    return 0;
}

string dec2rom(int x) {
    vector<pair<int, string> > rzym;
    rzym.push_back(make_pair(1000, "M"));
    rzym.push_back(make_pair(900, "CM"));
    rzym.push_back(make_pair(500, "D"));
    rzym.push_back(make_pair(400, "CD"));
    rzym.push_back(make_pair(100, "C"));
    rzym.push_back(make_pair(90, "XC"));
    rzym.push_back(make_pair(50, "L"));
    rzym.push_back(make_pair(40, "XL"));
    rzym.push_back(make_pair(10, "X"));
    rzym.push_back(make_pair(9, "IX"));
    rzym.push_back(make_pair(5, "V"));
    rzym.push_back(make_pair(4, "IV"));
    rzym.push_back(make_pair(1, "I"));

    string wynik;

    for (int i = 0; i < rzym.size(); i++) {
        int value = rzym[i].first;
        string symbol = rzym[i].second;

        while (x >= value) {
            wynik += symbol;
            x -= value;
        }
    }

    return wynik;
}
