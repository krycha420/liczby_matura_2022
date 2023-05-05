#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main()
{
    string liczba, pierwsza;
    int ile =0, czynniki, dzielnik = 2, ileczynnikow=0, maksczynnikow =0, liczzmaksczynn =0, kopia =0, n = 0, trojek =0, piatek =0, ileroznych =0, rozny, ostdzielnik = 1, maxroznychczynnik = 0;
    int t[200];
    int tab[200];
    ifstream plik;
    plik.open("liczby.txt");
    {
        for(int i =0; i<200; i++)
        {
            plik>>liczba;

            if(liczba[0]==liczba[liczba.length()-1])
            {
                ile++;

            }
        }
    }

    ifstream plik2;
    plik2.open("liczby.txt");
    for(int i =0; i<200; i++)
    {
        plik2>>liczba;

        if(liczba[0]==liczba[liczba.length()-1])
        {
            pierwsza = liczba;
            break;
        }
    }

    cout<<"TAKICH LICZB JEST: "<<ile<<" A PIERWSZA JEST: "<<pierwsza<<endl;

    ifstream plik3;
    plik3.open("liczby.txt");
    for(int i =0; i<200; i++)
    {
        plik3>>czynniki;
        kopia = czynniki;
        ileczynnikow =0;
        ileroznych = 0;
        while(czynniki>1)
        {
            if (czynniki%dzielnik==0)
            {
                if(dzielnik != ostdzielnik)
                {
                    ileroznych++;
                    if (ileroznych>maxroznychczynnik)
                    {
                        maxroznychczynnik = ileroznych;
                        rozny = kopia;
                    }
                    ostdzielnik = dzielnik;
                }
                ileczynnikow++;
                czynniki = czynniki/dzielnik;
                dzielnik = 2;
                if (ileczynnikow>maksczynnikow)
                {
                    maksczynnikow = ileczynnikow;
                    liczzmaksczynn = kopia;
                }

            }
            else
            {
                dzielnik++;
            }







        }
    }

    cout <<"MAKSYMALNIE CZYNNIKOW: " << maksczynnikow<< "  LICZBY: "<< liczzmaksczynn << endl;
    cout <<"MAKSYMALNIE ROZNYCH CZYNNIKOW: " << maxroznychczynnik<< "  LICZBY: "<< rozny << endl;

    ifstream plik4;
    ofstream out3("trojki.txt");
    plik4.open("liczby.txt");
    for (int i =0; i<200; i++)
    {
        plik4>>tab[i];
    }
    for(int j =0; j<200; j++)
    {
        for(int k =0; k<200; k++)
        {
            for(int m =0; m<200; m++)
            {
                if (tab[m]!=tab[k]&&tab[j]!=tab[m]&&tab[j]!=tab[k])
                {
                    if (tab[m]%tab[k]==0&&tab[k]%tab[j]==0)
                    {
                        out3<<tab[j] << " "<< tab[k]<< " " << tab[m]<<endl;
                        trojek ++;
                    }
                }
            }
        }
    }
    out3.close();
    cout <<"JEST TROJEK: "<<trojek << endl;

    ofstream out5("piatki.txt");
    ifstream plik5;
    plik5.open("liczby.txt");
    for (int i = 0; i < 200; i++)
    {
        plik5 >> t[i];
    }
    sort(t, t+200);
    piatek =0;
        for (int a = 0; a < 200; a++)
    {
        for (int b = a + 1; b < 200; b++)
        {
            if (t[b] % t[a] != 0)
                continue;
            for (int c = b + 1; c < 200; c++)
            {
                if (t[c] % t[b] != 0)
                    continue;
                for (int d = c + 1; d < 200; d++)
                {
                    if (t[d] % t[c] != 0)
                        continue;
                    for (int e = d + 1; e < 200; e++)
                    {
                        if( t[e] % t[d] != 0)
                            continue;
                        out5 << t[a] << " " << t[b] << " " << t[c] << " " << t[d] << " " << t[e] << endl;
                        piatek++;
                    }
                }
            }
        }
    }
    out5.close();
    cout << "JEST PIATEK: "<< piatek<< endl;
}


