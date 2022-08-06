#include <iostream>
#include <string>

using namespace std;

void printAge() {
    int year;
    cout << "Podaj rok urodzenia: ";
    cin >> year;

    cout << "Masz " << 2020 - year << " lat" << endl;
}

void changeAgeToHours() {
    int year;
    cout << "Podaj rok urodzenia: ";
    cin >> year;

    cout << "Zyjesz juz godzin: " << (2020 - year) * 360 * (24) << endl; 
}

void registerUser() {
    string name;
    string surname;
    string bithdate;
    string classNumber;

    cout << "Podaj imie: " << endl;
    cin >> name;
    cout << "Podaj nazwisko: " << endl;
    cin >> surname;
    cout << "Podaj date urodzenia: " << endl;
    cin >> bithdate;
    cout << "Podaj klasę: " << endl;
    cin >> classNumber;

    //Dane Wejściowe Imie - Jan Nazwisko - Kowalski - Data Urodzenia 1994 Klasa - 7G
    cout << name << " " << surname << endl;
    cout << "Data urodzenia: " << bithdate << endl;
    cout << "Klasa " << classNumber << endl;
}

int main() {
    registerUser();
    changeAgeToHours();
    printAge();
}