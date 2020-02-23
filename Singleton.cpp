#include <iostream>
#include <string>

using namespace std;

class Juego{
private:
  Juego(){
    for (int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++){
        tablero[i][j] = ' ';
      }
    }
    turno = 1;
  }
  static Juego* _instancia;
  string jugador1;
  string jugador2;
  char tablero[3][3];
  int turno;
public:
  static Juego* getInstance(){
    if(_instancia == NULL){
      _instancia = new Juego();
    }
    return _instancia;
  }

  string getJugador1(){
    return jugador1;
  }

  string getJugador2(){
    return jugador2;
  }

  //Devuelve el nombre del jugador en el turno actual
  string getJugadorTurno(){
    if(turno == 1){
      return jugador1;
    }else{
      return jugador2;
    }
  }

  void setJugadores(string N1, string N2){
    jugador1 = N1;
    jugador2 = N2;
  }

  //Poner X o O en el tablero
  int setPos(int i, int j){
    if(i < 0 || i > 2 || j < 0 || j > 2 ){
      cout<<"Posición fuera de los límites (0-2), intente de nuevo"<<endl;
      return 1;
    }else{
      if(tablero[i][j] == ' '){
        if(turno == 1){
          tablero[i][j] = 'X';
          turno = 2;
        }else{
          tablero[i][j] = 'O';
          turno = 1;
        }
        return 0;
      }else{
        cout<<"Posición ocupada, intente de nuevo"<<endl;
        return 1;
      }
    }
  }

  //Imprime el tablero
  void printT(){
    for (int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++){
        cout<<"["<<tablero[i][j]<<"]";
      }
      cout<<endl;
    }
  }

  int verificar(){
    int win = 0;
    //Empate
    int cont = 0;
    for (int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++){
        if(tablero[i][j] != ' '){
          cont++;
        }
      }
    }
    if(cont == 9){
      win = 3;
    }
    //X
    if(tablero[0][0] == 'X' && tablero[0][1] == 'X' && tablero[0][2] == 'X'){win = 1;}
    if(tablero[1][0] == 'X' && tablero[1][1] == 'X' && tablero[1][2] == 'X'){win = 1;}
    if(tablero[2][0] == 'X' && tablero[2][1] == 'X' && tablero[2][2] == 'X'){win = 1;}
    if(tablero[0][0] == 'X' && tablero[1][0] == 'X' && tablero[2][0] == 'X'){win = 1;}
    if(tablero[0][1] == 'X' && tablero[1][1] == 'X' && tablero[2][1] == 'X'){win = 1;}
    if(tablero[0][2] == 'X' && tablero[1][2] == 'X' && tablero[2][2] == 'X'){win = 1;}
    if(tablero[0][0] == 'X' && tablero[1][1] == 'X' && tablero[2][2] == 'X'){win = 1;}
    if(tablero[0][2] == 'X' && tablero[1][1] == 'X' && tablero[2][0] == 'X'){win = 1;}

    //O
    if(tablero[0][0] == 'O' && tablero[0][1] == 'O' && tablero[0][2] == 'O'){win = 2;}
    if(tablero[1][0] == 'O' && tablero[1][1] == 'O' && tablero[1][2] == 'O'){win = 2;}
    if(tablero[2][0] == 'O' && tablero[2][1] == 'O' && tablero[2][2] == 'O'){win = 2;}
    if(tablero[0][0] == 'O' && tablero[1][0] == 'O' && tablero[2][0] == 'O'){win = 2;}
    if(tablero[0][1] == 'O' && tablero[1][1] == 'O' && tablero[2][1] == 'O'){win = 2;}
    if(tablero[0][2] == 'O' && tablero[1][2] == 'O' && tablero[2][2] == 'O'){win = 2;}
    if(tablero[0][0] == 'O' && tablero[1][1] == 'O' && tablero[2][2] == 'O'){win = 2;}
    if(tablero[0][2] == 'O' && tablero[1][1] == 'O' && tablero[2][0] == 'O'){win = 2;}

    return win;
  }

};

Juego * Juego::_instancia;

int main(){
  string j1 = " ",j2 = " ";
  Juego *juego = Juego::getInstance();
  cout<<"Nombre del jugador 1: ";
  cin>>j1;
  cout<<endl<<"Nombre del jugador 2: ";
  cin>>j2;
  cout<<endl;
  juego->setJugadores(j1,j2);
  cout<<"¡BIENVENIDOS!"<<endl;
  juego->printT();

  //Jugar
  int win = 0;
  do {
    cout<<endl<<"Turno de "<<juego->getJugadorTurno()<<endl;
    int i = 0,j = 0;
    cout<<"Ingrese posición de línea(0-2): ";
    cin>>i;
    cout<<endl<<"Ingrese posición de columna(0-2): ";
    cin>>j;
    cout<<endl;
    juego->setPos(i,j);
    juego->printT();
    win = juego->verificar();
  } while(win == 0);

  if(win == 1){
    cout<<"¡FELICIDADES! Ha ganado "<<juego->getJugador1()<<endl;
  }else if(win == 2){
    cout<<"¡FELICIDADES! Ha ganado "<<juego->getJugador2()<<endl;
  }else{
    cout<<"Ha sido un EMPATE!"<<endl;
  }

  return 0;
};
