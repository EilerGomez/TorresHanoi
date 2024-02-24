#include <iostream>
#include <vector>

using namespace std;

void imprimir_torre(const vector<int>& discos) {
    // Imprimir la representación gráfica de la Torre de Hanoi
    for (auto it = discos.rbegin(); it != discos.rend(); ++it) {
        cout << string(discos.back() - *it, ' ') << string(*it, '*') << "  " << endl;
    }

    // Imprimir la base de la torre
    cout << string(discos.back(), '=') << "  " << endl;
}

int main() {
    // Ejemplo de uso con 7 discos de tamaños diferentes en una torre
    vector<int> discos = {7, 6, 5, 4, 3, 2, 1};
    imprimir_torre(discos);

    return 0;
}

