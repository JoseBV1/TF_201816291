#include "pch.h"
#include "iostream"
#include "conio.h"
#include <stack>
#include <queue>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Nodo.h"
using namespace std;
using namespace System;

template <typename T>
class Calculadora 
{
private:
    Node *ptrTop;
    Node* ptrTopDistrito;
    int length;
    string paraArchivo;
    int lengthDistrito;
    int personasVulnerables;
    int opcionElegida;
    int distrito; 
    float* elems; int primerintentoDistrito;  int primerintento;
    float* elemsInfec; 
    int capacity; 
    ofstream archivo;
  

public:
    Calculadora(int capacity = 37) : ptrTopDistrito(nullptr), ptrTop(nullptr), lengthDistrito(0) , length(0), elemsInfec(new float[capacity]), elems(new float[capacity])
    {     
         personasVulnerables = 0;
         distrito = 0;
         primerintentoDistrito = 0;
         primerintento = 0;
    }
    ~Calculadora()
    {
        while (ptrTop != nullptr) {
            auto aux = ptrTop;
            ptrTop = aux->next;
            delete aux;
        }
        while (ptrTopDistrito != nullptr) {
            auto aux = ptrTop;
            ptrTop = aux->next;
            delete aux;
        }
    }   
    void addFirst(float elem, float elemDis, string ok) {
        if (ok == "Distrito")
        {
            ptrTopDistrito= new Node(elem, elemDis, ptrTopDistrito);
            lengthDistrito++;
        }
        else {
            ptrTop = new Node(elem, elemDis, ptrTop);
            length++;
        }
    }
    int size(string ok) {
        if (ok == "Distrito")
        {
            return lengthDistrito;
        }
        else return length;
    }
    string getStringArchivo()
    {
        return paraArchivo;
    }
    void setString(string ok)
    {
        this->paraArchivo = ok;
    }
void menu()
{

    asignarNumeroDePersonasAListas(); 
    asignarPoblacionConConvid();
    while (!(opcionElegida==5))
    {
        opcionElegida = 0;
        personasVulnerables = 0;
        distrito = 0;
        system("CLS");
        cout << "Bienvenido a la calcudora de riesgo, presiona una tecla."; getch();
        while (!(personasVulnerables >= 1))
        {
            cout << "\nIngrese la cantidad de personas que va a comprar en tu casa: "; cin >> personasVulnerables;
            //push(personasVulnerables, personasVulnerables, "No");
            if (primerintento == 0) {
                primerintento = 5;
            addFirst(personasVulnerables, personasVulnerables, "No");
        }
            else
            { 
                addFinal(personasVulnerables, personasVulnerables, "no");
            }
        }
        cout << "\nLas personas vulnerables de tu casa son: " << personasVulnerables;
        cout << "\n1.-San Juan de Lurigancho\n2.-El Callao\n3.-San Martín De Porres\n4.-Villa el Salvador\n5.-Ate\n6.-Lima\n7.-San Juan de Miraflores\n8.-La Victoria\n9.-Villa Maria del Triunfo\n10.-Santiago de Surco\n11.-El Agustino\n12.-Comas\n13.-Santa Anita\n14.-Chorrillos\n15.-Rimac\n16.-Los Olivos\n17.-La Molina\n18.-Jesús María\n19.-Independencia\n20.-San Miguel\n21.-Breña\n22.-Carabayllo\n23.-San Borja\n24.-Puente Piedra\n25.-Surquillo\n26.-Miraflores\n27.-Lince\n28.-San Luis\n29.-Pueblo Libre\n30.-Ventanilla\n31.-Carmen de la Legua\n32.-Magdalena del Mar\n33.-San Isidro\n34.-Chaclacayo\n35.-Lurigancho\n36.-Lurin\n37.-Bellavista";
        while (!(distrito >= 1) && (distrito <= 37))
        {
            cout << "\n¿De qué parte de Lima eres? Cóloque el número: ";
            cin >> distrito;
            //push(distrito, distrito, "Distrito");    
           if (primerintentoDistrito == 0)
           {
               primerintentoDistrito = 5;
            addFirst(distrito, distrito, "Distrito");
        }
           else {
               addFinal(distrito, distrito, "Distrito");
           }
        }
        if (distrito >= 38)
        {
            distrito = 37;
            addFinal(distrito, distrito, "Distrito");
        }
        cout << "\nEres del distrito: " << distrito;
        cout << "\n¿Qué operación deseas hacer?";
        cout << "\n1.- Mostrar distritos e infectados.";
        cout << "\n2.- Mostrar porcentaje de riesgo para todas las seleccionadas.\n";
        cout << "3.- Seguir insertando personas vulnerables para más calculos.\n";
        cout << "4.- Mostrar registros de personas vulnerables. \n";
        cout << "5.- Salir del ciclo while.\n";
        while (!(opcionElegida >= 1 && opcionElegida <= 5)) {
        cin >> opcionElegida;
        if (opcionElegida == 1)
        {
            cout << "Numero de personas por distrito\t-\tNúmero de personas con Covid: ";
            for (int i = 0; i < 37; i++)
            {
                cout << "\n" << i << ":    " << elems[i] << "\t\t\t\t\t" << elemsInfec[i]; //O(n)
            }

        }
        else if (opcionElegida == 2)
        {
            int i = 1;
            int posElem = 0;
            archivo.open("LuisMartinCanavalSanchezEsDios.txt", ios::app);
            archivo << "\n - OTRA OPERACIÓN - ";
            for (int i = 0; i < size("no"); i++)
            {
               // setString("Hola lo amo profe");
                cout << "\nEl porcentaje de riesgo de contagio que tienes en tu distrito " << getPos(i, "Distrito") << " y con " << getPos(i, "NO") << " personas vulnerables es: (" << i << ") " << (getPos(i, "NO") / (elems[distrito - 1] - elemsInfec[distrito - 1])) * 100;
                archivo << "\nEl porcentaje de riesgo de contagio que tienes en tu distrito " << getPos(i, "Distrito") << " y con " << getPos(i, "NO") << " personas vulnerables es: (" << i << ") " << (getPos(i, "NO") / (elems[distrito - 1] - elemsInfec[distrito - 1])) * 100;
            }

        }
        else if (opcionElegida == 3)
        {
        }
        else if (opcionElegida == 4)
        {
            cout << "Personas Vulnerables: ";
            for (int i = 0; i < size("ok"); i++)
            {

                cout << getPos(i, "NO") << " - ";
            }
            cout << endl;
            cout << "Distrito seleccionado: ";
            for (int i = 0; i < size("Distrito"); i++)
            {
                cout << getPos(i, "Distrito") << " - ";
            }
        }
        else if (opcionElegida == 5) { 
            break; 
        }
       }
        getch();
    }  
}
void addFinal(float elem, float elemDis, string ok) {
    if (ok == "Distrito")
    {
        addPos(elem,elemDis, lengthDistrito, "Distrito");
    }
    else {
        addPos(elem,elemDis, length, "no");
    }
}
void addPos(float elem,float elemDis, int pos, string ok) {
    if (ok == "Distrito")
    {
        if (pos < 0 || pos > lengthDistrito) {
            return;
        }
        else if (pos == 0) {
            addFirst(elem, elemDis,"Distrito");
        }
        else {
            auto aux = ptrTopDistrito;
            for (int c = 1; c < pos; ++c) {
                aux = aux->next;
            }
            aux->next = new Node(elem,elemDis, aux->next);
            ++lengthDistrito;
        }
    }
    else {
        if (pos < 0 || pos > length) {
            return;
        }
        else if (pos == 0) {
            addFirst(elem, elemDis, "no");
        }
        else {
            auto aux = ptrTop;
            for (int c = 1; c < pos; ++c) {
                aux = aux->next;
            }
            aux->next = new Node(elem,elemDis, aux->next);
            ++length;
        }
    }
}

float getPos(int pos, string ok) {
    if (ok == "Distrito")
    {
        if (pos < 0 || pos >= lengthDistrito) {
            return -0.000001;
        }
        else if (pos == 0) {
            return getFirst("Distrito");
        }
        else {
            auto aux = ptrTopDistrito;
            for (int c = 0; c < pos; ++c) {
                aux = aux->next;
            }
            return aux->elemDistrito;
        }
    }
    else {
        if (pos < 0 || pos >= length) {
            return -0.000001;
        }
        else if (pos == 0) {
            return getFirst("NO");
        }
        else {
            auto aux = ptrTop;
            for (int c = 0; c < pos; ++c) {
                aux = aux->next;
            }
            return aux->elem;
        }
    }
}  
float getFirst(string ok) {
    if (ok == "Distrito")
    {
        if (lengthDistrito > 0) {
            return ptrTopDistrito->elemDistrito;
        }
        return -0.000001;
    }
    else {
    if (length > 0) {
        return ptrTop->elem;
    }
    return -0.000001;
}
}

void asignarNumeroDePersonasAListas()
{
    elems[0] = 1069566; //sjl
    elems[1] = 410640; //el callao
    elems[2] = 686703; //smp
    elems[3] = 454114; //villa el savaldor
    elems[4] = 611081; //ate
    elems[5] = 276857; //lima 
    elems[6] = 400630; //sjm
    elems[7] = 175372; //la victoria
    elems[8] = 441239; //villa maria del triunfo
    elems[9] = 338509; //santiago de surco 
    elems[10] = 190961; //el agustino 
    elems[11] = 522760; //comas 
    elems[12] = 223447; //santa anita
    elems[13] = 322066; //chorrillos 
    elems[14] = 167286; //rimac
    elems[15] = 365921;  //los olivos
    elems[16] = 166912; //la molina
    elems[17] = 71514; //jesus maria
    elems[18] = 216764; //independencia
    elems[19] = 135366; //san miguel 
    elems[20] = 77116; //breña
    elems[21] = 290311; //carabayllo
    elems[22] = 111808;// san borja
    elems[23] = 336928; //puente piedra
    elems[24] = 91686; //surquillo
    elems[25] = 82805; //miraflores
    elems[26] = 51144; //lince
    elems[27] = 57530; //san luis
    elems[28] = 76437; //pueblo libre
    elems[29] = 355830; //ventanilla
    elems[30] = 41431; //carmen de la legua
    elems[31] = 54566; //magdalena del mar
    elems[32] = 55006; //san isidro
    elems[33] = 43355; //chaclacayo
    elems[34] = 212987; //lurigancho
    elems[35] = 82319; //lurin
    elems[36] = 72665; //bellavista
}
    void asignarPoblacionConConvid()
    {
        //27 de aril casos
        elemsInfec[0] = 754; //sjl
        elemsInfec[1] = 638;  //el callao
        elemsInfec[2] = 598;  //smp
        elemsInfec[3] = 564;  //villa el savaldor
        elemsInfec[4] = 503;  //ate
        elemsInfec[5] = 472;  //lima 
        elemsInfec[6] = 467;  //sjm
        elemsInfec[7] = 417;  //la victoria
        elemsInfec[8] = 399;  //villa maria del triunfo
        elemsInfec[9] = 397;  //santiago de surco 
        elemsInfec[10] = 371;   //el agustino 
        elemsInfec[11] = 366;   //comas 
        elemsInfec[12] = 305;   //santa anita
        elemsInfec[13] = 298;   //chorrillos 
        elemsInfec[14] = 265;   //rimac
        elemsInfec[15] = 246;    //los olivos
        elemsInfec[16] = 199;   //la molina
        elemsInfec[17] = 171;  //jesus maria
        elemsInfec[18] = 164;   //independencia
        elemsInfec[19] = 156;   //san miguel 
        elemsInfec[20] = 155;  //breña
        elemsInfec[21] = 143;   //carabayllo
        elemsInfec[22] = 139;  // san borja
        elemsInfec[23] = 139;   //puente piedra
        elemsInfec[24] = 138;  //surquillo
        elemsInfec[25] = 131;  //miraflores
        elemsInfec[26] = 110;  //lince
        elemsInfec[27] = 103;  //san luis
        elemsInfec[28] = 99;  //pueblo libre
        elemsInfec[29] = 89;   //ventanilla
        elemsInfec[30] = 80;  //carmen de la legua
        elemsInfec[31] = 72;  //magdalena del mar
        elemsInfec[32] = 66;  //san isidro
        elemsInfec[33] = 64;  //chaclacayo
        elemsInfec[34] = 64;   //lurigancho
        elemsInfec[35] = 50;  //lurin
        elemsInfec[36] = 47;  //bellavista
    }
};

int main()
{
    Calculadora<int> *cal = new Calculadora<int>;
    cal->menu();
   
    return 0;
}
