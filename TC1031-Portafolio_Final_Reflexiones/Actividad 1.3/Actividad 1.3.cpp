/*
    Evidencia 1.3 - Conceptos Básicos y Algoritmos Fundamentales
    Equipo #5
    Integrantes del equipo:
      Christián Eduardo Terrón García - A00828146
      Juan Angel Mora Moreno - A00517141
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;


// Función que almacena los datos ya ordenados en el archivo
// Complejidad: O(n)
void escribir(vector<vector<string>> bitacora) {
    ofstream archivo("bitacoraOrdenada.txt");
    archivo.close();

    ofstream guardar;
    guardar.open("bitacoraOrdenada.txt", ios::app);
    for (int i = 0; i < bitacora.size(); i++) {
        guardar << bitacora[i][0] << " " << bitacora[i][1] << " " << bitacora[i][2] << " " << bitacora[i][3] << " " << bitacora[i][4] << endl;
    }
    guardar.close();
}


// Función que almacena los datos del archivo en un vector
// Complejidad: 0(n)
void lecturaBitacora(vector<vector<string>>& bitacora) {
    ifstream archivo;
    string sLinea, mes, dia, hora, ip, motivo, motivoBusqueda;
    int iSepPos, n = -1;
    bool verifica;
    archivo.open("bitacora.txt");
    if (archivo.fail()) {
        cout << "No se pudo abrir la bitácora" << endl;
    }
    else
    {
        while (!archivo.eof()) // Mientras no sea el final del archivo
        {
            getline(archivo, sLinea);
            iSepPos = sLinea.find(" ");
            mes = sLinea.substr(0, iSepPos);//
            sLinea.erase(0, iSepPos + 1);
            iSepPos = sLinea.find(" ");
            dia = sLinea.substr(0, iSepPos);//
            sLinea.erase(0, iSepPos + 1);
            iSepPos = sLinea.find(" ");
            hora = sLinea.substr(0, iSepPos);//
            sLinea.erase(0, iSepPos + 1);
            iSepPos = sLinea.find(" ");
            ip = sLinea.substr(0, iSepPos);//
            sLinea.erase(0, iSepPos + 1);
            motivo = sLinea.substr(0, iSepPos);


            n++;
            bitacora.push_back(vector<string>());
            bitacora[n].push_back(mes);
            bitacora[n].push_back(dia);
            bitacora[n].push_back(hora);
            bitacora[n].push_back(ip);
            bitacora[n].push_back(motivo);

        }
        archivo.close();
    }
}



// Complejidad: O(log2 n)
int busqBin(vector<vector<string>>& bitacora, int dia, int ini, int max, int tipo) {
    int fin = bitacora.size() - 1, mit;
    while (ini <= fin) {
        mit = (ini + fin) / 2;
        if (stoi(bitacora[mit][tipo]) == dia) {
            return mit;
        }
        if (stoi(bitacora[mit][tipo]) > dia) {
            fin = mit - 1;
        }
        else {
            ini = mit + 1;
        }
    }
    return -1;
}

// Complejidad: 0(n)
int une(vector<vector<string>>& vec, vector<vector<string>>& aux, int ini, int fin, int tipo) {
    int m = (ini + fin) / 2;
    int i = ini, j = m + 1, k = ini;
    int cant = 0;
    while (i <= m && j <= fin) {
        cant++;
        if (stoi(vec[i][tipo]) <= stoi(vec[j][tipo])) {
            aux[k++] = vec[i++];
        }
        else {
            aux[k++] = vec[j++];
        }
    }
    while (i <= m) {
        aux[k++] = vec[i++];
    }
    while (j <= fin) {
        aux[k++] = vec[j++];
    }
    for (int z = ini; z <= fin; z++) {
        vec[z] = aux[z];
    }
    return cant;
}

// Complejidad: O(log n)
int merge(vector<vector<string>>& vec, vector<vector<string>>& aux, int ini, int fin, int tipo) {
    int cant = 0;
    //Realiza el proceso de division de los arreglos
    if (ini < fin) {
        int m = (ini + fin) / 2;
        cant += merge(vec, aux, ini, m, tipo);
        cant += merge(vec, aux, m + 1, fin, tipo);
        cant += une(vec, aux, ini, fin, tipo);
    }
    return cant;
}

// Función que transforma el string de meses en enteros para facilitar su uso en el vector
// Complejidad: O(n)
void transformMonthsToNumbers(vector<vector<string>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i][0] == "Jan") {
            vec[i][0] = "1";
        }
        else if (vec[i][0] == "Feb") {
            vec[i][0] = "2";
        }
        else if (vec[i][0] == "Mar") {
            vec[i][0] = "3";
        }
        else if (vec[i][0] == "Apr") {
            vec[i][0] = "4";
        }
        else if (vec[i][0] == "May") {
            vec[i][0] = "5";
        }
        else if (vec[i][0] == "Jun") {
            vec[i][0] = "6";
        }
        else if (vec[i][0] == "Jul") {
            vec[i][0] = "7";
        }
        else if (vec[i][0] == "Ago") {
            vec[i][0] = "8";
        }
        else if (vec[i][0] == "Sep") {
            vec[i][0] = "9";
        }
        else if (vec[i][0] == "Oct") {
            vec[i][0] = "10";
        }
        else if (vec[i][0] == "Nov") {
            vec[i][0] = "11";
        }
        else {
            vec[i][0] = "12";
        }
    }
}

// Función que transforma los enteros de vuelta a strings para facilitar su uso en el vector 
// Complejidad: O(n)
void transformNumbersToMonths(vector<vector<string>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i][0] == "1") {
            vec[i][0] = "Jan";
        }
        else if (vec[i][0] == "2") {
            vec[i][0] = "Feb";
        }
        else if (vec[i][0] == "3") {
            vec[i][0] = "Mar";
        }
        else if (vec[i][0] == "4") {
            vec[i][0] = "Apr";
        }
        else if (vec[i][0] == "5") {
            vec[i][0] = "May";
        }
        else if (vec[i][0] == "6") {
            vec[i][0] = "Jun";
        }
        else if (vec[i][0] == "7") {
            vec[i][0] = "Jul";
        }
        else if (vec[i][0] == "8") {
            vec[i][0] = "Ago";
        }
        else if (vec[i][0] == "9") {
            vec[i][0] = "Sep";
        }
        else if (vec[i][0] == "10") {
            vec[i][0] = "Oct";
        }
        else if (vec[i][0] == "11") {
            vec[i][0] = "Nov";
        }
        else {
            vec[i][0] = "Dec";
        }
    }
}

// Función que reemplaza el uso de búsqueda secuencial, es decir identifica el límite máximo del mes
// Complejidad: O()
int mesLimite(vector<vector<string>> vec, int mes, int ini) {
    int cant = ini;
    for (int i = ini; i < vec.size(); i++) {
        if (stoi(vec[i][0]) == mes) {
            cant++;
            if (stoi(vec[i][0]) != mes) {
                return cant;
            }
        }
    }
    return cant;
}

string displayMonth(int month) {
    if (month == 1) {
        return "Jan";
    }
    else if (month == 2) {
        return "Feb";
    }
    else if (month == 3) {
        return "Mar";
    }
    else if (month == 4) {
        return "Apr";
    }
    else if (month == 5) {
        return "May";
    }
    else if (month == 6) {
        return "Jun";
    }
    else if (month == 7) {
        return "Jul";
    }
    else if (month == 8) {
        return "Ago";
    }
    else if (month == 9) {
        return "Sep";
    }
    else if (month == 10) {
        return "Oct";
    }
    else if (month == 11) {
        return "Nov";
    }
    else {
        return "Dec";
    }
}


int main() {
    int n = 0, q = 1, d1, d2, m1, m2, x, ini = 0, max, e = -1;
    vector<vector<string>> bitacora;
    vector<vector<int>> limitesMes;
    lecturaBitacora(bitacora);
    for (int i = 0; i < bitacora.size(); i++) {
        cout << bitacora[i][0] << " " << bitacora[i][1] << " " << bitacora[i][2] << " " << bitacora[i][3] << " " << bitacora[i][4] << endl;
    }

    x = bitacora.size();
    vector<vector<string>> aux(x);

    //Transforma meses a numeros
    transformMonthsToNumbers(bitacora);

    //Ordena Meses
    merge(bitacora, aux, 0, x - 1, 0);

    //Ordena Dias por Mes
    for (int i = 0; i < 12; i++) {
        max = mesLimite(bitacora, i + 1, ini);
        merge(bitacora, aux, ini, max - 1, 1);
        e++;
        limitesMes.push_back(vector<int>());
        limitesMes[e].push_back(ini);
        limitesMes[e].push_back(max);
        ini = max;
    }

    //Estructura de la bitacora
    //Bitacora[fila][columna]
    //Columna = 0 -> Mes
    //Columna = 1 -> Dia
    //Columna = 2 -> Hora
    //Columna = 3 -> IP
    //Columna = 4 -> Motivo

    //limiteMes[i][x]
    //x = 0 = Minimo
    //x = 1 = Maximo
    while (q != 0) {
        cout << "Dia Inicio: " << endl;
        cin >> d1;
        cout << "Mes Inicio(Numero): " << endl;
        cin >> m1;

        cout << "Dia Final: " << endl;
        cin >> d2;
        cout << "Mes Final(Numero): " << endl;
        cin >> m2;


        int pos;
        for (int i = d1; i <= 31; i++) {
            pos = busqBin(bitacora, i, limitesMes[m1 - 1][0], limitesMes[m1 - 1][1] - 1, 1);
            if (pos != -1) {
                cout << displayMonth(m1) << " " << bitacora[pos][1] << " " << bitacora[pos][2] << " " << bitacora[pos][3] << " " << bitacora[pos][4] << endl;
            }
        }

        for (int i = m1 + 1; i < m2; i++) {
            for (int j = 0; j <= 31; j++) {
                pos = busqBin(bitacora, j, limitesMes[i - 1][0], limitesMes[i - 1][1] - 1, 1);
                if (pos != -1) {
                    cout << displayMonth(i) << " " << bitacora[pos][1] << " " << bitacora[pos][2] << " " << bitacora[pos][3] << " " << bitacora[pos][4] << endl;
                }
            }
        }

        for (int i = 0; i <= d2; i++) {
            pos = busqBin(bitacora, i, limitesMes[m2 - 1][0], limitesMes[m2 - 1][1] - 1, 1);
            if (pos != -1) {
                cout << displayMonth(m2) << " " << bitacora[pos][1] << " " << bitacora[pos][2] << " " << bitacora[pos][3] << " " << bitacora[pos][4] << endl;
            }
        }
        cout << "Quiere seguir buscando? " << endl;
        cout << "Teclee <0> para no seguir y un <1> para seguir." << endl;
        cin >> q;
    }

    //Transforma numero a Meses
    transformNumbersToMonths(bitacora);
    for (int i = 0; i < bitacora.size(); i++) {
        cout << bitacora[i][0] << " " << bitacora[i][1] << " " << bitacora[i][2] << " " << bitacora[i][3] << " " << bitacora[i][4] << endl;
    }
    // Almacena todos los elementos de la bitácora de forma ordena en nuevo archivo en blanco
    escribir(bitacora);
}