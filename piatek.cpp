#include <fstream>
#include <iostream>
using namespace std;

int main()
{

    int piatek =0;
    int tab[200];

    fstream plik5;
    plik5.open("przyklad.txt");
    for (int i =0; i<200; i++)
    {
        plik5>>tab[i];
    }


    for (int i = 0; i < 200; i++) {
    cout << tab[i] << " ";
}

    for(int o =0; o<200; o++)
    {
        for(int u =0; u<200; u++)
        {
            for(int j =0; j<200; j++)
            {
                for(int k =0; k<200; k++)
                {
                    for(int m =0; m<200; m++)
                    {
                        if (tab[o] !=tab[u]&&tab[o]!=tab[j]&&tab[o]!=tab[k]&&tab[o] !=tab[m]&&tab[u]!=tab[j]&&tab[u]!=tab[k]&&tab[u]!=tab[m]&&tab[j] !=tab[k]&&tab[j]!=tab[m]&&tab[k]!=tab[m])
                        {
                            if (tab[o]%tab[u]==0&&tab[u]%tab[j]==0&&tab[j]%tab[k]==0&&tab[k]%tab[m]==0)
                            {
                                cout << tab[o] <<" " << tab[u]<< " "<< tab[j]<< " "<< tab[k]<< " " << tab[m] << endl;
                                piatek++;
                            }


                        }
                    }
                }
            }


        }
    }

    cout << piatek << endl;
}
