#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

const char X = 'a';
int main()
{
    // tutaj wczytujemy wartość n upewniając się że jest liczbą dodatnią jednocyfrową
    int n=-1;
    cout << "Podaj wartosc n" << endl;
    cin >> n;
    while(n<1 || n>9){
        cout << "Wartosc n musi sie miescic w przedziale 1-9" << endl << "Podaj wartosc n" << endl;
        cin >> n;
    }

    // deklarujemy zmienne potrzebne do liczenia rzeczy podanych w poleceniu
    int wystapienia3X = 0;
    int wystapieniaParNawiasow = 0;

    bool czyOstatniZnakToOtwierajacyNawiasKwadratowy = false;
    int licznikX = 0;

    //pętla powtarza się n razy
    for(int i = 0; i<n;i++){

        // zczytujemy znak z klawiatury
        char znak;
        cout << "Podaj znak" << endl;
        cin >> znak;

        // jeżeli wczytany znak jest nawiasem zamykającym oraz poprzedni znak był nawiasem otwierającym to zapisujemy dodajemy jeden do licznika par nawiasów
        if(znak == ']' && czyOstatniZnakToOtwierajacyNawiasKwadratowy)
            wystapieniaParNawiasow++;

        // zapisujemy w zmiennej typu logicznego czy wczytany znak jest nawiasem otwierającym aby to wykorzystać w następnym wykonaniu pętli
        if(znak == '[')
            czyOstatniZnakToOtwierajacyNawiasKwadratowy = true;
        else
            czyOstatniZnakToOtwierajacyNawiasKwadratowy = false;

        //jezeli znak jest taki sam jak X to wtedy dodajemy jeden do licznika wystąpień X z rzędu, jeżeli nie to wtedy zerujemy licznik
        if(znak == X)
            licznikX++;
        else
            licznikX = 0;

        //jeżeli licznik X-ów jest większy od 2 to dadajemy jeden do licznika potrójnych wystąpień X i zerujemy licznik X-ów
        if(licznikX>2){
            wystapienia3X++;
            licznikX = 0;
        }
    }

    cout << "Para nawiasow kwadratowych wystapila tyle razy: " << wystapieniaParNawiasow << endl;
    cout << "Trzy kolejne znaki okreslone stala X wystapily tyle razy: " << wystapienia3X << endl;


    return 0;
}
