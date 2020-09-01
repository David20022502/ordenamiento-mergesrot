#include <iostream>
#include <fstream>
using namespace std;
#include <ctime>

void divicion(int a[], int inicial, int final);

void unir(int a[], int pinicial, int pfinal, int medio);
int main()
{
  ofstream guargardatos;
  guargardatos.open(("mergesort.txt"),ios::out);
    int numeros[10];

    srand(time(0));

    for (int i=0; i<6;i++)
    {
        numeros[i]=1+rand()%(50-1);
    }
    guargardatos << "tipo de algoritmo utilizado: mergesort"<< endl;
    guargardatos << "valores almacenados de forma aleatoria " << endl;
    for (int i=0; i<6;i++)
    {

        cout<<numeros[i]<< endl;
        guargardatos<<numeros[i]<< endl;
    }

    divicion(numeros,0,6);

    cout<<endl;
cout << "datos ordenados" << endl;
guargardatos << "datos ordenados" << endl;
    for (int i=1; i<=6;i++)
    {
        cout<<numeros[i] << endl;
        guargardatos<<numeros[i] << endl;
    }
    guargardatos.close();
    return 0;
}


void divicion(int a[], int inicial, int final)
{

    int mitad;

    if (inicial<final)
    {
        mitad=(inicial+final)/2;

        divicion(a,inicial,mitad);

        divicion(a,mitad+1,final);

        unir(a,inicial,final,mitad);
    }

}

void unir(int a[], int pinicial, int pfinal, int medio)
{
    int i, j, k, temp[pfinal-pinicial+1];
	i = pinicial;
	k = 0;
	j = medio + 1;

	while (i <= medio && j <= pfinal)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= medio)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <=pfinal)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = pinicial; i <= pfinal; i++)
	{
		a[i] = temp[i-pinicial];
	}
}
