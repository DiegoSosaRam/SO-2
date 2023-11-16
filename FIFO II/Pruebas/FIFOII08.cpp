#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Proceso {
    string nombre;
    int llegada;
    int tCPU;
    int espera;
    int ejecucion;
    int fin;
    //int inicio;
};

int main() {
	int TR=0, TE=0, tiempo=0;
	//int fini=0;
	int sumFin=0;
    int numProcesos=0;
    cout<<"Ingrese la cantidad de procesos: ";
    cin>>numProcesos;

    vector<Proceso> procesos;
    cout<<endl;
    for (int i=0; i<numProcesos; i++) {
        Proceso proceso;
        cout<<"Nombre del proceso " << (i + 1) << ": ";
        cin>>proceso.nombre;
        cout<<"Tiempo de llegada del proceso " << proceso.nombre << ": ";
        cin>>proceso.llegada;
        cout<<"Tiempo de CPU del proceso " << proceso.nombre << ": ";
        cin>>proceso.tCPU;
        proceso.espera=0;
        proceso.ejecucion=0;
        proceso.fin=0;
        procesos.push_back(proceso);
        cout<<endl;
    }
    cout<<endl;

	//Establece los timepos
	int sumaTCPU=0;
	for (int j=0; j<numProcesos; j++) {
	    sumaTCPU+=procesos[j].tCPU;
	}

    queue<Proceso> memoria;
    vector<string> memoriaV;

    do{
		for (int z=0; z<numProcesos; z++) {
			//Se verifica si el proceso z ha llegado en o antes del tiempo actual (tiempo)
		    if (procesos[z].llegada <= tiempo && procesos[z].ejecucion < procesos[z].tCPU) {
		        memoria.push(procesos[z]);
		        memoriaV.push_back(procesos[z].nombre);
		        procesos[z].ejecucion++;
		        break;
		    }
		}

        if (!memoria.empty()){
            Proceso procesoActual = memoria.front();
            memoria.pop();
            procesoActual.espera += memoria.size();
            tiempo++;
    
            // Verificar si el proceso ha terminado
            if (procesoActual.ejecucion==procesoActual.tCPU){
                procesoActual.fin==tiempo;
                //fini=fini+1;
            }
            
        } else {
            tiempo++;
        }
        
    } while (tiempo<sumaTCPU);
    
	cout<<endl;
    cout<<"Cola: (";
    for (size_t c=0; c<memoriaV.size(); ++c) {
        cout<<memoriaV[c];
        if (c<memoriaV.size()-1) {
            cout<<", ";
        }
    }
    cout<<")"<<endl;
    
    
    for(int f=0; f<=numProcesos; f++){
    	sumFin+=procesos[f].fin;
	}
    
    
    for(int t=0; t<numProcesos; t++) {
        cout<<"Proceso: " <<procesos[t].nombre<<", "; 
        //cout<<"Inicio: "<<procesos[t].inicio<<", ";
		cout<<"fin: "<<procesos[t].fin<<endl;
    }
    
	TR=sumFin/numProcesos;
	TE=tiempo/numProcesos;
	cout<<"TR: "<<sumaTCPU<<" ut"<<endl;
	cout<<"TE: "<<tiempo<<" ut"<<endl;

    return 0;
}
