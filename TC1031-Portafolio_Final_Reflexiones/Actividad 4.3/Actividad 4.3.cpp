// Actividad 4.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Complejidad: O(n)
// Función que convierte una iP solicitada a una donde ya no contenga un puerto 
string ipWithoutPort(string ip) {
    int pos = 0;
    string newIp;
    bool verifica = false;
    while (pos < ip.size() && verifica == false) {
        if (ip[pos] == ':') {
            verifica = true;
        }
        else {
            newIp = newIp + ip[pos];
        }

        pos++;
    }
    return newIp;
}

// Complejidad: O(n)
// Función que carga a la lista de adjacencia los datos leidos de la biácora y consigue identificar tanto las ips con mayor incidencia como sus outdegrees respectivos
int loadData(unordered_map<string, pair<int, int>>& nodos_ips, vector<vector<int>>& listAdj) {
    ifstream archivo;
    int max = 0, antMax;
    vector<string> maxIP;
    int iSepPos, n, m, numNodoOrigen, numNodoDestino, contAcc = 0, cont = 0;
    long long ipAnt = 0, ipActual = 0;
    string sLinea, mes, dia, hora, ip, motivo, ipClean, nStr, mStr, ipOrigen, ipDestino;
    archivo.open("bitacoraACT4_3(B).txt");
    getline(archivo, sLinea);

    iSepPos = sLinea.find(" ");
    nStr = sLinea.substr(0, iSepPos);
    sLinea.erase(0, iSepPos + 1);
    iSepPos = sLinea.find(" ");
    mStr = sLinea.substr(0, iSepPos);
    n = stoi(nStr);
    m = stoi(mStr);
    cout << "Cargando informacion" << endl;
    for (int i = 0; i < n; i++) {
        getline(archivo, sLinea);
        pair<int, int> uno;
        uno.first = i;
        uno.second = 0;
        nodos_ips[sLinea] = uno;
        
    }
    listAdj.resize(n);
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
        ipOrigen = sLinea.substr(0, iSepPos);//
        ipOrigen = ipWithoutPort(ipOrigen);

        sLinea.erase(0, iSepPos + 1);
        iSepPos = sLinea.find(" ");
        ipDestino = sLinea.substr(0, iSepPos);//
        ipDestino = ipWithoutPort(ipDestino);

        sLinea.erase(0, iSepPos + 1);
        motivo = sLinea.substr(0, iSepPos);
        if (cont != m) {
            numNodoOrigen = nodos_ips[ipOrigen].first;
            numNodoDestino = nodos_ips[ipDestino].first;

            listAdj[numNodoOrigen].push_back(numNodoDestino);
            nodos_ips[ipOrigen].second++;
            if (max < nodos_ips[ipOrigen].second) {
                antMax = max;
                max = nodos_ips[ipOrigen].second;
                if (max > antMax) {
                    maxIP.clear();
                }
                
            }
            if (max == nodos_ips[ipOrigen].second) {
                maxIP.push_back(ipOrigen);
            }
        }
        cont++;
        
    }
    archivo.close();
    cout << "IPs con mayor incidencia: \n" << endl;
    for (int i = 0; i < maxIP.size(); i++) {
        cout << "Incidentes: " << max << "  IP: " << maxIP[i] << endl;
    }    
    return max;
}

// Complejidad: O(n)
// Función que imprime el recorrido de DFS tomando en cuenta el tamaño de la lista
void printListAdj(vector<vector<int>>& listAdj) {
    for (int i = 0; i < listAdj.size(); i++) {
        cout << "   " << (i + 1) << "   ";
        for (int j = 0; j < listAdj[i].size(); j++) {           
            cout << "  -  " << (listAdj[i][j] + 1);
        }
        cout << endl;
    }
}

// Complejidad: O(n + m)
// Función que almacena las cantidades de arcos que salen de un nodo (outdegree) y que además imprime el recorrido de la lista tomando en cuenta el tamaño del outdegree
void LoadOutDegree(vector<int>& outDegree, vector<vector<int>>& listAdj, int max) {
    int n = listAdj.size();
    outDegree.resize(n);
    for (int i = 0; i < n; i++) {
        outDegree[i] = 0;
    }


    for (int i = 0; i < listAdj.size(); i++) {
        outDegree[i] = listAdj[i].size();
    }



    cout << "\nNodos en Lista de Adjacencia con outDegree: \n" << endl;
    for (int i = 0; i < outDegree.size(); i++) {
        if (outDegree[i] == max) {
            cout << "Nodo: " << i << "  Numero de incidencias: " << outDegree[i] << endl;
        }
    }

}

int main()
{
    unordered_map <string, pair<int, int>> nodos_ips;
    vector<vector<int>> listAdj;
    vector<int> outDegree;
    int max;
    max = loadData(nodos_ips, listAdj);
    //printListAdj(listAdj);
    LoadOutDegree(outDegree, listAdj, max);
}

