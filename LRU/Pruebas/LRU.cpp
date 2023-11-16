#include <iostream>
#include <queue>
#include <list>

using namespace std;

int main() {
	int m=0;
    int memoriaSize = 0;
    cout << "Ingrese la cantidad de frames: ";
    cin >> memoriaSize;

    int numProcesos = 0;
    cout << "Ingrese la cantidad de procesos: ";
    cin >> numProcesos;

    // Lista de procesos (lista enlazada doble)
    list<int> procesos;

    cout << "Ingrese los procesos, uno por uno:" << endl;
    for (int i = 0; i < numProcesos; ++i) {
        int proceso;
        cout << "Proceso " << (i + 1) << ": ";
        cin >> proceso;

        // Buscar el proceso en la memoria
        list<int>::iterator it = procesos.begin();
        bool found = false;

        while (it != procesos.end()) {
            if (*it == proceso) {
                found = true;
                break;
            }
            ++it;
        }

        if (found) {
            // Proceso en memoria (Page Hit)
            procesos.erase(it);
        } else {
            // Proceso no en memoria (Page Default)
            if (procesos.size() >= memoriaSize) {
                // Si la memoria está llena, eliminar el proceso menos recientemente usado (el último en la lista)
                procesos.pop_back();
            }
        }

        // Agregar el nuevo proceso al frente de la lista (el más reciente)
        procesos.push_front(proceso);
        m=m+1;
    }

    // Conteo de Page Hits y Page Defaults
    float pageDefaults = numProcesos - procesos.size();
    float pageHits = procesos.size();

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
	cout<<"Total (Page Miss + Hit Ratio): "<<tt<<"%";
	

    return 0;
}

