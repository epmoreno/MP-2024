#include <iostream>

using namespace std;

struct Asignatura{
    string nombre;
    Asignatura **asignaturas_dependientes;
    int num_asignaturas_dependientes;
};

string *prerrequisitosAsignatura(const Asignatura &asignatura){
    int num_prerequisitos = asignatura.num_asignaturas_dependientes;// Numero de prerrequisitos
    string *prerrequisitos = new string[num_prerequisitos];// Vector que contendra los prerrequisitos
    for (int i = 0; i < num_prerequisitos; i++){// Recorremos el vector de prerrequisitos
        prerrequisitos[i] = asignatura.asignaturas_dependientes[i]->nombre;// Agregamos el nombre del prerrequisito al vector
    }
    return prerrequisitos;
}

int main(){
    /**
     * Usaremos una vector de asignaturas para almacenar todas las asignaturas. 
     * Cada asignatura tendrá un vector de punteros a las asignaturas de las que dependa (o apuntará a nullptr si no tiene prerequisitos).
     */
    int num_asignaturas = 4;// Nunero de asignaturas
    Asignatura **asignaturas = new Asignatura*[num_asignaturas];// Vector que contrendra la asginaturas
    
    // Creamos las asignaturas
    Asignatura fp = {"Fundamentos de Programacion", nullptr, 1};
    Asignatura ed = {"Estructura de Datos", nullptr, 2};
    Asignatura mp = {"Metodologia de la Programacion",nullptr,1};
    Asignatura cal = {"Calculo", nullptr, 0};
    
    // Asignamos las asignaturas
    asignaturas[0] = &fp, asignaturas[1] = &mp, asignaturas[2] = &cal, asignaturas[3] = &ed;

    // Asignamos las asignaturas dependientes
    fp.asignaturas_dependientes = new Asignatura*[1];
    fp.asignaturas_dependientes[0] = &mp;

    mp.asignaturas_dependientes = new Asignatura*[1];
    mp.asignaturas_dependientes[0] = &fp;

    ed.asignaturas_dependientes = new Asignatura*[2];
    ed.asignaturas_dependientes[0] = &mp;
    ed.asignaturas_dependientes[1] = &fp;

    // Imprimimos los prerrequisitos de cada asignatura
    string *prerrequisitosFP = prerrequisitosAsignatura(fp);
    cout <<"- Dependencais de la asignatura '" << fp.nombre << "' -> ";
    for (int i = 0; i < fp.num_asignaturas_dependientes; i++){
        cout << prerrequisitosFP[i];
        if (i < fp.num_asignaturas_dependientes-1){
            cout << ", ";
        }
    }
    cout << endl;

    string *prerrequisitosMP = prerrequisitosAsignatura(mp);
    cout <<"- Dependencias de la asignatura '" << mp.nombre << "' -> ";
    for (int i = 0; i < mp.num_asignaturas_dependientes; i++){
        cout << prerrequisitosMP[i] << " ";
        if (i < mp.num_asignaturas_dependientes-1){
            cout << ", ";
        }
    }
    cout << endl;

    string *prerrequisitosED = prerrequisitosAsignatura(ed);
    cout <<"- Dependencais de la asignatura '" << ed.nombre << "' -> ";
    for (int i = 0; i < ed.num_asignaturas_dependientes; i++){
        cout << prerrequisitosED[i];
        if (i < ed.num_asignaturas_dependientes-1){
            cout << ", ";
        }
    }
    cout << endl;

    // Liberamos la memoria reservada para el vector de prerrequisitos
    delete[] prerrequisitosFP;
    delete[] prerrequisitosMP;
    delete[] prerrequisitosED;

    // Liberamos la memoria reservada para las asignaturas y las dependencias de estas
    for (int i = 0; i < num_asignaturas; i++){
        delete[] asignaturas[i]->asignaturas_dependientes;// Liberamos la memoria reservada para el vector de asignaturas dependientes
    }
    delete[] asignaturas;// Liberamos la memoria reservada para el vector de asignaturas
}