#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits>
#include <fstream>

using namespace std;
int definiciondificultad();
void guardartexto(string a,int p);
void lectorpuntajes();
int error();
void puntuaciones();
int menu();
void barra();
void vector(int);
void espacio();
void historia(string);
int dificultaduno();
void historiados();
void historiatres();
void historiacuatro();
void historiacinco();
void historiafin();

//globales
int puntaje=1000;
int escudo=0;
int vida=3;
int camino=0;
string cont;
string linea;
string cadenatexto;
ofstream archivoguarda("puntajes.txt");
ifstream archivo("puntajes.txt");

int main() {
	int a=0;
	srand(time(NULL));
	int salidamenu;
	
	do{
	salidamenu=menu();
	espacio();
	if (salidamenu==2){
		puntuaciones();
		}
	
	if(salidamenu==1){
	string nombre;
	cout<<"Programa de navidad\n\nIngrese su nick name: ";cin>>nombre;	
	
	espacio();
	historia(nombre);
	espacio();
	
	//diciultad del juego
	definiciondificultad();
	
	
	//Comienzo del juego
	if(vida>0){
	barra();historiados();espacio();
	a=1+rand()%(15-1);barra();vector(a);espacio();}
	if(vida>0){	
	barra();historiatres();espacio();
	a=1+rand()%(15-1);barra();vector(a);espacio();}
	if(vida>0){
	barra();historiacuatro();espacio();
	a=1+rand()%(15-1);barra();vector(a);espacio();}
	if(vida>0){
	barra();historiacinco();espacio();
	a=1+rand()%(15-1);barra();vector(a);espacio();}
	if(vida>0){
	barra();historiafin();espacio();}
	if(vida<1){
	cout<<"Perdiste tu puntaje es:\n";barra();
	cout<<"Presione cualquier tecla para continuar: ";cin>>cont;
	cout << "\033[2J\033[1;1H";
		}
	if(vida>0){
	cout<<"tu puntaje es:\n";barra();
	cout<<"Presione cualquier tecla para continuar: ";cin>>cont;
	cout << "\033[2J\033[1;1H";
	}
	guardartexto(nombre,puntaje);

	salidamenu=1;
}
	
	
	}while(salidamenu!=3);
    return 0;
}
//Funcion
int definiciondificultad(){
	//dificultad del juego
	int dificultad=dificultaduno();
	espacio();
	if(dificultad==1){
		puntaje=5000;
		escudo=1;
		vida=2;
	}
	else if(dificultad==2){
		puntaje=5000;
		escudo=0;
		vida=2;
	}
	else if(dificultad==3){
		puntaje=5000;
		escudo=0;
		vida=1;
	}
	
	return 0;
}
int error(){
	
	while (true) {
        if (cin >> camino && camino >= 1 && camino <= 3)break;
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return camino;
}
void puntuaciones(){
	cout <<"\nlos puntajes son:\n ";
	lectorpuntajes();
	
	cout<<"\n\nFIN, APLASTE CUALQUIER TECLA PARA CONTINUAR";cin>>camino;
	cout << "\033[2J\033[1;1H";

	}
int menu(){
	int menun;
	cout<<"Menu principal:\n";
		cout<<"(1)Nuevo juego\n";
		cout<<"(2)Puntajes\n";
		cout<<"(3)Salir\n";
		cout<<"Ingrese 1, 2, 3: ";
		menun=error();
		cout << "\033[2J\033[1;1H";

	return menun;
}
void historia(string nombre){
	 //En esta parte del programa se cuenta la historia que va a seguir y para que el texto sea mas legible utilizo varios cout
	 	char resp;
	 cout<<"En un reino lejano, los sabios reyes magos recibieron la noticia del nacimiento del nino";
	 cout<<"\nJesus, un acontecimiento celestial que exigia la entrega de regalos especiales: wifi, ";
	 cout<<"\ncelular y Un libro de C++. Con la firme determinacion de llevar a cabo esta sagrada tarea, los ";
	 cout<<"\nreyes magos decidieron confiar la mision a un/a joven valeros@ llamad@ "<<nombre<<endl;
	 cout<<"\n"<<nombre<<", lleno de honor y humildad, acepto la encomienda con gratitud. Su mision era ";
	 cout<<"\nclara: emprender un viaje lleno de desafios para llevar los preciados presentes al ";
	 cout<<"\nrecien nacido Mesias. Los reyes magos le advirtieron sobre los multiples obstaculos ";
	 cout<<"\nque encontraria en su camino, pruebas que pondrian a prueba su coraje y lealtad."<<endl;
	 cout<<"\nGuiado por la misteriosa estrella de Belen,"<<nombre<<" se lanzo a la aventura. Su viaje lo ";
	 cout<<"\nllevaria a traves de paisajes deslumbrantes y peligrosos, desde desiertos implacables ";
	 cout<<"\nhasta bosques enigmaticos y montanas majestuosas. En cada paso, se enfrentaria";
	 cout<<"\na desafios que solo un corazon valiente podria superar.\n";
	 cout<<"\n\n";

	 cout<<"Acepta el reto? s/n: ";cin>>resp;


	 resp = tolower(resp);
	 if (resp!='s'){ cout<<"\nEl programa se cerrara";abort() ;}
	 
}
void barra(){
	
	cout<<"-----------------------------------------------------\n";
	cout<<"|Puntaje: "<<puntaje<<"       Ptos de vida: "<<vida<<"       Escudo: "<<escudo<<"|\n";
	cout<<"-----------------------------------------------------\n";
}
void vector(int a){
	 
	 switch (a) {
        case 1:
            cout << "\nUn herrero Piensa que lo estas robando \n-1000 puntos" << endl;
            cout << "Pulse cualquier tecla para continuar:";
            cin>>cont;
            cout << "\033[2J\033[1;1H";
            puntaje=puntaje-1000;
            break;
        case 2:
            cout << "\nUn zombie te ataca \n2 vida menos" << endl;
            cout << "Pulse cualquier tecla para continuar:";
            cin>>cont;
             cout << "\033[2J\033[1;1H";
            for (int i=0;i<2;i++){if (escudo==0){vida--;}
            else{escudo--;}}
            break;
        case 3:
            cout << "\nEcontraste soldados que te dan su armadura\n escudo mas 1"<<endl;
            cout << "Pulse cualquier tecla para continuar:";
            cin>>cont;
            cout << "\033[2J\033[1;1H";
            escudo++;
            break;
        case 4:
            cout << "\nEncuentras un dragon 2 vida menos" << endl;
            cout << "Pulse cualquier tecla para continuar:";
            cin>>cont;
            cout << "\033[2J\033[1;1H";

            for (int i=0;i<2;i++){
            if (escudo==0){vida--;}
            else{escudo--;}}
            break;
        case 5:
            cout << "\nTe encuentras con un grupo de bandidos. \n1000 puntos menos" << endl;
            cout << "Pulse cualquier tecla para continuar:";
            cin>>cont;
            cout << "\033[2J\033[1;1H";

            puntaje-=1000;
            break;
        case 6:
            cout << "\nEncontraste un ciclope gigante. \n2 vida menos " << endl;
            cout << "Pulse cualquier tecla para continuar:";cin>>cont;
            cout << "\033[2J\033[1;1H";

            for (int i=0;i<2;i++){
            if (escudo==0){vida--;}
            else{escudo--;}}
            break;
        case 7:
           cout << "\nTe encuentras con una criatura mística malvada. \n-1 de vida" << endl;
           cout << "Pulse cualquier tecla para continuar:";cin>>cont;
           cout << "\033[2J\033[1;1H";

           if (escudo==0){vida--;}
            else{escudo--;}
            break;
        case 8:
            cout << "\nTe encuentras un antiguo pergamino con un hechizo. \n+1000 puntos" << endl;
            cout << "Pulse cualquier tecla para continuar:";cin>>cont;
            cout << "\033[2J\033[1;1H";

            puntaje+=1000;
            break;
        case 9:
            cout << "\nEncontraste una araña gigante \nmenos 1 vida" << endl;
            cout << "Pulse cualquier tecla para continuar:";cin>>cont;
            cout << "\033[2J\033[1;1H";

            if (escudo==0){vida--;}
            else{escudo--;}
            break;
        case 10:
            cout << "\nhas encontrado un tesoro! \n+1000 puntos" << endl;
            cout << "Pulse cualquier tecla para continuar:";cin>>cont;
            cout << "\033[2J\033[1;1H";
            puntaje+=1000;
            break;
        case 11:
           cout << "\nDescubriste una vida adicional. ¡Ahora tiene mas energia!\nvida +1" << endl;
           cout << "Pulse cualquier tecla para continuar:";cin>>cont;
           vida++;
           	  cout << "\033[2J\033[1;1H";

            break;
        case 12:
            cout << "\nEncontraste un escudo protector. ¡Ahora estas mas seguro!\nescudo +1" << endl;
            cout << "Pulse cualquier tecla para continuar:";cin>>cont;
            	  cout << "\033[2J\033[1;1H";

            escudo++;
            break;
        case 13:
         cout << "\nEncontraste puntos de experiencia . ¡Cada paso le hace mas fuerte!\n +1000 puntos" << endl;
         cout << "Pulse cualquier tecla para continuar:";cin>>cont;
         cout << "\033[2J\033[1;1H";

         puntaje+=1000;
            break;
   
        case 14:
            cout << "\nEcontraste oro \n+1000 puntos" << endl;
            cout << "Pulse cualquier tecla para continuar:";cin>>cont;
            cout << "\033[2J\033[1;1H";

            puntaje+=1000;
            
            break;}

	
}
void espacio(){
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\033[2J\033[1;1H";
}
int dificultaduno(){
	int dificultad;
	cout<<"";
	cout<<"Guiado por la estrella de Belen, se encontraba en las faldas de una majestuosa ";
	cout<<"\nmontana, parte de su viaje para llevar los regalos al nino Jesus. A medida que ";
	cout<<"\nascendia, llego a un punto donde el sendero se dividia en tres caminos distintos. La ";
	cout<<"\neleccion del camino correcto era crucial para superar los desafíos y continuar con la ";
	cout<<"\nmision sagrada. ";
	cout<<"\n\n(1)Camino del Encanto(Facil) ";
	cout<<"\n(2)Camino del Bosque Magico(Medio)";
	cout<<"\n(3)Camino de duendes y escarpos(dificil)";
	cout<<"\n\n\n\nSe encontra ante estas tres opciones cruciales. Cada camino presentaba sus";
	cout<<"\npropios desafios y recompensas. La eleccion dependeria de la valentia y la sabiduria ";
	cout<<"\nmarcando el inicio de una serie de decisiones que darian forma a su epica ";
	cout<<"\ntravesia hacia Belen.";
	cout<<"\nQue camino deberia va a tomar: ";
	dificultad=error();
	
	return dificultad;	
}
void historiados(){
	cout<<"\nSiguiendo el sendero el cual comenzaba ascendiendo por la montana escarpada, avanzaste con";
	cout<<"\ntenacidad y coraje. Las rocas sueltas crujian bajo tus pies, y las pendientes";
	cout<<"\npronunciadas te desafiaban en cada paso. Sin embargo, la esperanza de llegar a Belen ";
	cout<<"\ny cumplir la sagrada mision iluminaba tu determinacion.\n";
	
	cout<<"\nDespues de una ardua ascension, llegaste a la cima de la montana, solo para ";
	cout<<"\nencontrarte con una nueva encrucijada. Frente a ti se extendian tres opciones, cada ";
	cout<<"\nuna envuelta en un misterio palpable. El paisaje panoramico dejaba entrever la ";
	cout<<"\ngrandeza del viaje que habias emprendido\n";
	
	cout<<"\nSin definir las opciones, te encontraste frente a la incertidumbre. El destino de tu ";
	cout<<"\ntravesia dependía ahora de tus elecciones en este punto crucial. Hacia donde ";
	cout<<"\ndirigirias tus pasos en esta cumbre desafiante? El camino se abria ante ti, esperando tu ";
	cout<<"\ndecision para continuar el epico viaje hacia Belen.";
	cout<<"\n(1)El Sendero de la Niebla";
	cout<<"\n(2)El Pasadizo Subterraneo de las Ruinas Olvidadas:";
	cout<<"\n(3)La Ruta de las Estatuas Ancestrales:";
	cout<<"\nEscriba el numero de su eleccion(1/2/3): ";
	error();
}
void historiatres(){
	cout << "Avanzando te adentraste en una nueva tierra donde los paisajes eran cambiantes." << endl;
    cout << "Las colinas ondulantes y los valles profundos te llevaron a un nuevo cruce de caminos." << endl;
    cout << "Ante ti, tres opciones se revelaron, cada una con su propio enigma." << endl;

    cout << "\n(3) El primer sendero serpenteador llevaba a traves de un bosque espeso." << endl;
    cout << "(2) El segundo camino se dirigia hacia un rio caudaloso." << endl;
    cout << "(1) El tercer sendero ascendia por una colina empinada." << endl;

    cout << "\nAnte estas opciones, el destino de tu travesia reposaba nuevamente en tus manos." << endl;
    cout << "Cual de estos caminos seguirias para continuar la busqueda de Belen?" << endl;
    cout << "Ingresa el numero correspondiente al camino que elijas: ";
	error();
    
}
void historiacuatro(){
	cout << "Siguiendo despues de lo que has encontrado, continuaste con el camino seleccionado y te encontraste con un nuevo cruce." << endl;
    cout << "Tres opciones se presentaron ante ti, cada una envuelta en un misterio aun mayor." << endl;

    cout << "\n(1) El primer sendero se dirigia a traves de un desierto vasto y abrasador." << endl;
    cout << "(2) El segundo camino serpenteador llevaba a un bosque de arboles ancestrales." << endl;
    cout << "(3) El tercer sendero ascendia por una montana nevada y fria." << endl;

    cout << "\nNuevamente, debias decidir la direccion de tu viaje." << endl;
    cout << "Que sendero elegirias ahora en tu travesia hacia Belen?" << endl;
	cout << "\nIngresa el numero correspondiente al camino que elijas: ";
    error();
}
void historiacinco(){
	cout << "Continuas al alba, la luz tenue del amanecer iluminaba tu camino mientras te enfrentabas a la encrucijada." << endl;
    cout << "Habias recorrido un largo trecho en tu epico viaje hacia Belen, y el destino aun se mantenia velado en misterio." << endl;

    cout << "\nEn esta encrucijada, te enfrentaste a tres nuevas opciones que ampliaban las posibilidades de tu viaje:" << endl;

    cout << "(1)Un estrecho camino que se adentraba en un canon profundo, rodeado por altos acantilados." << endl;
    cout << "(2)Un sendero que llevaba a traves de un valle verde y exuberante, salpicado por arroyos y flores silvestres." << endl;
    cout << "(3)Un ascenso desafiante por una cordillera de picos imponentes, ofreciendo vistas majestuosas pero exigiendo resistencia." << endl;

    cout << "\nLas opciones se desplegaron ante ti, cada una con su propio conjunto de desafios y bellezas." << endl;
    cout << "El destino seguia siendo incierto, y las elecciones que hicieras marcarian el rumbo de tu odisea hacia Belen." << endl;
    cout << "Cual seria tu proxima eleccion en este viaje lleno de misterios, mientras el sol ascendia en el horizonte y " << endl;
    cout << "pintaba de colores calidos el paisaje que se extendia ante ti?" << endl;
    cout << "\n\nIngresa el numero correspondiente al camino que elijas: ";
	error();
	}
void historiafin(){
	cout << "\n\nGuiado por las elecciones que tomaste en tu intrepido viaje, avanzaste por el camino ";
	cout << "\nque seleccionaste en la encrucijada al amanecer. El paisaje cambiante te llevo a traves ";
	cout << "\nde desafios y maravillas, pero finalmente, la estrella de Belen te guio hacia el humilde";
	cout << "\nestablo donde reposaba el nino Jesus.";

	cout << "\n\nAl entrar, la luz calida de la estrella ilumino la escena. En el pesebre, viste al nino ";
	cout << "\nenvuelto en panales, con una tranquilidad que irradiaba paz y esperanza. Los Reyes ";
	cout << "\nMagos, que habian llegado antes que tu, presentaban sus regalos al recien nacido.";

	cout << "\n\nTe uniste a ellos, ofreciendo los tesoros que habias llevado con tanto esfuerzo: wifi, ";
	cout << "\ncomputadoras y libros de c++. El aire estaba impregnado de serenidad, y el mundo parecia ";
	cout << "\ndetenerse por un momento mientras contemplabas al Mesias recien nacido.";

	cout << "\n\nTu odisea, llena de desafios y elecciones, culminó en este humilde establo. La alegria ";
	cout << "\nde haber cumplido la sagrada mision envolvia tu corazon. Los Reyes Magos y pastores ";
	cout << "\npresentes compartian en silencio la maravilla de aquel instante unico.";

	cout << "\n\nLa estrella de Belen, que habia guiado tu camino, continuaba brillando en lo alto, como ";
	cout << "\nun faro de luz divina. En la quietud del establo, comprendiste la importancia de tu viaje ";
	cout << "\ny el papel que desempenaste en la historia sagrada.";
	cout<<"\n\nFIN, APLASTE CUALQUIER TECLA PARA CONTINUAR";cin>>camino;

}
void lectorpuntajes(){
	
	while(getline(archivo,linea))cadenatexto+=linea+"\n";	
	archivo.close();
	cout<< cadenatexto << endl;
	
}

void guardartexto(string a,int p){
	
	archivoguarda<<"\n"<<a<<"   "<<p;
}
