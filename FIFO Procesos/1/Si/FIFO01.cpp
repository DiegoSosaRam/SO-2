#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Tama�o de la memoria (n�mero de frames)
//const int memoriaSize = 4;
//const int m=0;

int main() {
	int memoriaSize=0;
	cout<<"Ingrese la cantidad de frames: ";
	cin>> memoriaSize;	
    // Lista de procesos
    vector<int> procesos;
    procesos.push_back(5);
    procesos.push_back(2);
    procesos.push_back(4);
    procesos.push_back(2);
    procesos.push_back(7);
    procesos.push_back(0);
    procesos.push_back(9);
    procesos.push_back(5);
    procesos.push_back(2);
    procesos.push_back(3);
    procesos.push_back(0);
    procesos.push_back(1);
    procesos.push_back(8);
    procesos.push_back(6);
    procesos.push_back(7);
    procesos.push_back(4);
    procesos.push_back(7);

    // Inicializar la memoria como una cola (queue)
    queue<int> memoria;
    
    // Conteo de Page Hits y Page Defaults y los tiempos (m)
    float pageHits=0;
    float pageDefaults=0;
	float m=0;
    // Ejecutar el algoritmo FIFO
    for (int tiempo = 0; tiempo < procesos.size(); ++tiempo) {
        int procesoActual = procesos[tiempo];

        // Verificar si el proceso est� en la memoria (cola)
        bool pageHit = false;
        queue<int> colaTemporal = memoria;
        while (!colaTemporal.empty()) {
            int procesoEnCola = colaTemporal.front();
            colaTemporal.pop();
            if (procesoEnCola == procesoActual) {
                pageHit = true;
                break;
            }
        }

        if (pageHit) {
            pageHits++;
        } else {
            pageDefaults++;

            // Si la cola est� llena, eliminar el proceso m�s antiguo
            if (memoria.size() >= memoriaSize) {
                memoria.pop(); // Con pop se elimina
            }

            // Agregar el nuevo proceso a la cola (memoria)
            memoria.push(procesoActual);
        }
		m=m+1;
    }
    
    // Mostrar la cola inicial
    cout << "Cola Inicial: " << endl;
    for (int i = 0; i < procesos.size(); ++i) {
        cout << procesos[i] << " ";
    }
    
    cout<<"\n";
    cout<<"\n";
    cout<<"Tiempos: " << m <<"\n";
    cout<<"\n";
    cout<<"Frames: " << memoriaSize <<"\n";
    cout<<"\n";
    cout<<"Page Hits: " << pageHits <<endl;
    cout<<"\n";
	cout<<"Page Defaults: " << pageDefaults <<endl;
	cout<<"\n";
	float pm=(pageDefaults/m)*100;
	cout<<"Page Miss = ("<< pageDefaults<<"/"<<m<<")*100 = "<< pm;
	cout<<"\n";
	cout<<"\n";
	float hr=(pageHits/m)*100;
	cout<<"Hit Ratio = ("<< pageHits<<"/"<<m<<")*100 = "<< hr;
	cout<<"\n";
	float tt=pm+hr;
	cout<<"\n";
	cout<<"Total: "<<tt<<"%";
    return 0;
}

