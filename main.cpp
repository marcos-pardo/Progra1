#include <iostream>
#include <vector>

using namespace std;


// Defino la estructura
struct Serie{
    double media;
    int maximo;
    int minimo;
};


// Creamos la funcion pedida que devuelve un tipo de estructura
struct Serie func(vector <int> vec){
    struct Serie res;

    res.media = 0;
    res.maximo = vec.at(0);
    res.minimo = vec.at(0);

    for(auto elem: vec){
        res.media += elem; // Sumamos todos los valores de vec para hacer la media

        if(elem > res.maximo){
            res.maximo = elem; // Vamos comparando para poder sacar el maximo
        }

        if(elem < res.minimo){
            res.minimo = elem; // Vamos comparando para poder sacar el minimo
        }

    }

    res.media /= vec.size(); // Dividimos entre el tamaño del vector para sacar la media

    return res; // Devolvemos el struct con los valores almacenados
}

int main()
{
    vector <int> serie;
    int tamaño;

    Serie s; // Declaramos una estructura

    serie.push_back(1); // Introducimos 1 ya que es el primer numero de la serie
    serie.push_back(2); // Introducimos 1 ya que es el primer numero de la serie

    cout << "Cuantos numeros quieres sacar de la serie: ";
    cin >> tamaño;

    for(int i = 0; i < tamaño-2; i++){
        serie.push_back(serie.at(i+1) - 2 * serie.at(i)); //Almacenamos en el vector los valores
    }

    cout << "{";
    for(auto elem: serie){
        cout << elem << ", "; // Imprimimos los datos de la serie
    }
    cout << "}\n";

    s = func(serie); // Llamamos a la funcion que hemos creado
    cout << "La media de nuestro struct creado es: " << s.media << endl;
    cout << "El maximo de nuestro struct creado es: " << s.maximo << endl;
    cout << "El minimo de nuestro struct creado es: " << s.minimo << endl;

}
