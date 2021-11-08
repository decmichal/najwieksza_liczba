#include <iostream>
#include <fstream>

using namespace std;

int ROZMIAR_TABLICY=0;

int *tablica_danych;

// deklaracje funkcji
int czy_druga_liczba_jest_bardziej_znaczaca(int pierwsza_liczba, int druga_liczba);

void wczytanie_danych_wejsciowych(void);

void zapis_wyniku(void);

int main()
{
    cout<<"Wczytanie danych wejsciowych: "<<endl;
    wczytanie_danych_wejsciowych();
    cout<<endl;

    int i;
    int powtorz=1;

    cout<<"POCZATEK SORTOWANIA"<<endl;

        for(i=0;i<ROZMIAR_TABLICY;i++)
        {
            cout<<tablica_danych[i];
        }

    cout<<endl;

    while(powtorz==1) //Petla sluzaca do przeprowadzenia potrzebnych ilosci przebiegow. Jesli jakas liczba w tablicy ma wartosc wieksza niz na pierwszym polu to wystepuje dodatkowy obieg aby dodatkowo posortowac liczby
    {
        powtorz=0;

        for(i=0;i<(ROZMIAR_TABLICY-1);i++)
        {
            int wynik = czy_druga_liczba_jest_bardziej_znaczaca(tablica_danych[i], tablica_danych[i+1]); //Wywolanie funkcji ktora za argumenty przyjmuje wartosci spod pol indeksow w tablicy

                if(wynik==1)
                {
                    int tymczasowa = tablica_danych[i]; //Poczatek srotowania liczb w tablicy. Do pomocniczej zmiennej przypisywana jest wartosc spod aktualnego pola
                    tablica_danych[i]=tablica_danych[i+1]; //Jesli kolejna liczba w tablicy jest wieksza to nastepuja zamiana
                    tablica_danych[i+1]=tymczasowa; //Liczba mniejsza wraca do pozycji tymczasowej podczas sortowania babelkowego
                    powtorz=1;
                }

        }

    }

    cout<<endl<<"KONIEC SORTOWANIA"<<endl;

        for(i=0;i<ROZMIAR_TABLICY;i++)
        {
            cout<<tablica_danych[i];

        }

    cout<<endl;

    zapis_wyniku();

    system("PAUSE");
    return 0;
}

/*
 * Funkcja sprawdza jaka pozycja dwoch podanych liczb pozwoli na stworzenie wiekszej
 * liczby poprzez ich polaczenie wedlug schematu:
 *        - pozycja 1: <pierwsza_liczba><druga_liczba>
 *        - pozycja 2: <druga_liczba><pierwsza_liczba>
 * Jezeli nowa licza utworzona z pozycji 2 daje wieksza wartosc niz z pozycji 1, to
 * funkcja zwraca wartosc 1, w przeciwnym przypadku zwraca wartosc 0.
*/
int czy_druga_liczba_jest_bardziej_znaczaca(int pierwsza_liczba, int druga_liczba)
{

    /*Zmienna okresla czy druga liczba jest bardziej znaczaca, czy liczba z pozycji
    drugiej jest wieksza od liczby z pozycji pierwszej, jesli jest to zmienna zwraca przez funkcje*/

    int druga_liczba_jest_bardziej_znaczaca=0;

    //Wyswietl mozliwe pozycje

    cout<<endl;
    cout<<"Pozycja 1 <pierwszaliczba> <drugaliczba> "<<pierwsza_liczba<<druga_liczba<<endl;
    cout<<"Pozycja 2 <drugaliczba> <pierwszaliczba> "<<druga_liczba<<pierwsza_liczba<<endl;

    //Sprawdza typowe przypadki

    if(pierwsza_liczba==druga_liczba)
    {
        //Jesli obie liczby maja te sama wartosc to druga liczba nie jest bardziej znaczaca
        druga_liczba_jest_bardziej_znaczaca=0;
    }

    else if(pierwsza_liczba>0&&druga_liczba==0)
    {
        //Jesli pierwsza liczba jest wieksza od 0, a druga liczba jest rowna 0, to druga liczba nie jest bardziej znaczaca
        druga_liczba_jest_bardziej_znaczaca=0;
    }

    else if(pierwsza_liczba==0&&druga_liczba>0)
    {
        //Jesli pierwsza liczba jest rowna 0, a druga liczba jest wieksza od 0, to druga liczba jest bardziej znaczaca
        druga_liczba_jest_bardziej_znaczaca=1;
    }

    else
    {
        int licznik_cyfr_pierwszej_liczby=0;
        int licznik_cyfr_drugiej_liczby=0;
        int kopia_pierwsza_liczba=pierwsza_liczba;
        int kopia_druga_liczba=druga_liczba;

        //Liczy ile cyfr ma pierwsza liczba

        while(kopia_pierwsza_liczba>0)
        {
            kopia_pierwsza_liczba /=10;
            licznik_cyfr_pierwszej_liczby++;
        }

        //Liczby ile cyfr ma druga liczba

        while(kopia_druga_liczba>0)
        {
            kopia_druga_liczba /=10;
            licznik_cyfr_drugiej_liczby++;
        }

        //Wczytuje pierwsza i druga liczbe do kopii po przeliczeniu cyfr

        kopia_pierwsza_liczba=pierwsza_liczba;
        kopia_druga_liczba=druga_liczba;

        //Przesuwa pierwsza liczbe o tyle pozycji ile cyfr ma druga liczba

        for(int i=0; i<licznik_cyfr_drugiej_liczby; i++)
        {
            kopia_pierwsza_liczba *=10;
        }

        //Przesuwa druga liczbe o tyle pozycji ile cyfr ma pierwsza liczba

        for(int i=0; i<licznik_cyfr_pierwszej_liczby; i++)
        {
            kopia_druga_liczba *=10;
        }

        //Wylicza pozycje z liczby pierwszej

        kopia_pierwsza_liczba+=druga_liczba;

        //Wylicz pozycje liczby drugiej

        kopia_druga_liczba+=pierwsza_liczba;

        //Jesli liczba z pozycji pierwszej jest wieksza od liczby z pozycji drugiej

        if(kopia_pierwsza_liczba>kopia_druga_liczba)
        {
            //To druga liczba nie jest bardziej znaczaca
            druga_liczba_jest_bardziej_znaczaca=0;
        }
        else
        {
            //Druga liczba jest bardziej znaczaca
            druga_liczba_jest_bardziej_znaczaca=1;
        }

        //Wyswietla wynik

        cout<<"Druga liczba jest bardziej znaczaca: "<<druga_liczba_jest_bardziej_znaczaca<<endl;

        //Zwraca wynik

    }

    return druga_liczba_jest_bardziej_znaczaca;
}

void wczytanie_danych_wejsciowych(void)
{
    int liczba;
    int licznik_liczb;
    ifstream dane_wejsciowe;

    dane_wejsciowe.open("dane_wejsciowe.txt");

    if (!dane_wejsciowe)
    {
        cout << "Nie mozna odczytac pliku";
        exit(1);
    }

    while (dane_wejsciowe >> liczba)
    {
        cout<<"Liczba z danych wejsciowych: "<<liczba<<endl;
        licznik_liczb++;
    }

    cout<<"Ilosc liczb w danych wejsciowych: "<<licznik_liczb<<endl;

    dane_wejsciowe.close();

    ROZMIAR_TABLICY=licznik_liczb;
    tablica_danych=new int[ROZMIAR_TABLICY];

    dane_wejsciowe.open("dane_wejsciowe.txt");

    if(!dane_wejsciowe)
    {
        cout<<"Nie mozna odczytac pliku";
        exit(1);
    }

    licznik_liczb=0;

    while(dane_wejsciowe>>liczba)
    {
        tablica_danych[licznik_liczb]=liczba;
        licznik_liczb++;
    }

    dane_wejsciowe.close();

}

void zapis_wyniku(void)
{
    ofstream zapis_wyniku;
    zapis_wyniku.open("wynik.txt");

    if(!zapis_wyniku)
    {
        cout<<"Nie mozna odczytac pliku";
        exit(1);
    }

    for(int i=0;i<ROZMIAR_TABLICY;i++)
    {
        zapis_wyniku<<tablica_danych[i];
    }

    zapis_wyniku.close();
}

