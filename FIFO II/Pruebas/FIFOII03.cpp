#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Procesacion{
	
};

int main() {

	int memoriaSize=0;	
    int numProcesos=0;
    cout<<"Ingrese la cantidad de procesos: ";
    cin>>numProcesos;
    memoriaSize=numProcesos;

    vector<int>procesos;
    cout<<"Ingrese los nombres de los procesos:"<<endl;
    //srand(static_cast<unsigned int>(time(NULL))); // Inicializa la semilla aleatoria
    for (int i=0; i<numProcesos; i++) {
        int proceso;
        
        cout<<"Proceso "<< (i+1) <<": ";
        cin>>string<proceso>;
        
        procesos.push_back(proceso);
    }
    cout<<"\n";

    queue<int> memoria;

    float pageHits=0;
    float pageDefaults=0;
	float m=0;
	
    // FIFO
    for (int tiempo = 0; tiempo < procesos.size(); ++tiempo) {
        int procesoActual = procesos[tiempo];

        
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

            
            if (memoria.size() >= memoriaSize) {
                memoria.pop(); 
            }

            
            memoria.push(procesoActual);
        }
		m=m+1;
    }

    cout << "Vector (cola): " << endl;
    for (int i=0; i<procesos.size(); ++i) {
        cout<<procesos[i] << " ";
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
	cout<<"Total (Page Miss + Hit Ratio): "<<tt<<"%";
	
  return 0;
}
	
	int E=0;
	int P=0;
	
	float pageHits=0;
    float pageDefaults=0;
	float m=0;
	
	int Inicio=0;
	int Fin=0;
	int tiempoEspera=0;
	
	int TE=0;
	int TR=0;
	/* En el ciclo del for para registrar los tiempoEspera, que se vayan sumando en TE. */
	int TET= /*(suma de los tiemposEspera) / numProcesos*/
	/* En el ciclo del for para registrar los Fin, que se vayan sumando en TR. */
	int TRT= /*(suma de los tiempos de Fin) / numProcesos*/
	
  return 0;
}
