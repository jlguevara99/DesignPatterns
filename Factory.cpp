#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class Guardian{
public:
  static Guardian *crear_guardian(int opcion);
  int vida;
  virtual void saludar() = 0;
  virtual int atacar() = 0;
  int getVida() {
    return vida;
  }
  void setVida(int newVida){
    vida = newVida;
  }
};

int main(){
  srand (time(NULL));
  vector<Guardian*> equipo;
  vector<Guardian*> enemigos;
  int opcion = 1;
  int limite = 0;
  cout<<"El equipo consta de 3 guardianes"<<endl<<endl;
  while (limite < 3) {
    cout<<"****Agregar Guardián****"<<endl<<"1 Cazador"<<endl<<"2 Hechicero"<<endl<<"3 Titán"<<endl;
    cin>>opcion;
    equipo.push_back(Guardian::crear_guardian(opcion));
    limite++;
  }

  //Elije los miembros del equipo enemigo al azar
  int opcion2;
  for (int i = 0; i < 3; i++) {
    opcion2 = rand() % 1 + 2;
    enemigos.push_back(Guardian::crear_guardian(opcion2));
  }
  //los equipos saludan
  cout<<endl<<"Mi equipo: "<<endl;
  for (int i = 0; i < 3; i++) {
    cout<<i+1<<" ";
    equipo[i]->saludar();
  }
  cout<<endl<<"Equipo enemigo: "<<endl;
  for (int i = 0; i < 3; i++) {
    cout<<i+1<<" ";
    enemigos[i]->saludar();
  }

  cout<<endl<<endl<<endl<<"SIMULACION DE BATALLA"<<endl;
  int k = 0;
  int ganar = 0;
  while (true) {
      int ataque1 = equipo[k]->atacar();
      int ataque2 = enemigos[k]->atacar();
      if(equipo[k]->getVida() > 0){
        if(enemigos[0]->getVida() > 0){
          enemigos[0]->setVida(enemigos[0]->getVida()-ataque1);
          cout<<"Aliado "<<k+1<<" ataca con "<<ataque1<<" de daño al enemigo 1"<<endl;
        }else if(enemigos[1]->getVida() > 0){
          enemigos[1]->setVida(enemigos[1]->getVida()-ataque1);
          cout<<"Aliado "<<k+1<<" ataca con "<<ataque1<<" de daño al enemigo 2"<<endl;
        }else if(enemigos[2]->getVida() > 0){
          enemigos[2]->setVida(enemigos[2]->getVida()-ataque1);
          cout<<"Aliado "<<k+1<<" ataca con "<<ataque1<<" de daño al enemigo 3"<<endl;
        }else{
          ganar = 1;
          break;
        }
      }

      if(enemigos[k]->getVida() > 0){
        if(equipo[0]->getVida() > 0){
          equipo[0]->setVida(equipo[0]->getVida()-ataque2);
          cout<<"Enemigo "<<k+1<<" ataca con "<<ataque2<<" de daño al aliado 1"<<endl;
        }else if(equipo[1]->getVida() > 0){
          equipo[1]->setVida(equipo[1]->getVida()-ataque2);
          cout<<"Enemigo "<<k+1<<" ataca con "<<ataque2<<" de daño al aliado 2"<<endl;
        }else if(equipo[2]->getVida() > 0){
          equipo[2]->setVida(equipo[2]->getVida()-ataque2);
          cout<<"Enemigo "<<k+1<<" ataca con "<<ataque2<<" de daño al aliado 3"<<endl;
        }else{
          ganar = 2;
          break;
        }
      }

      if(k < 2){
        k++;
      }else{
        k = 0;
      }
  }
  if(ganar == 1){
    cout<<endl<<endl<<"Ha ganado mi equipo"<<endl;
  }else{
    cout<<endl<<endl<<"Ha ganado el equipo enemigo"<<endl;
  }

  for (int i = 0; i < 3; i++) {
    delete equipo[i];
    delete enemigos[i];
  }
};

class Cazador: public Guardian{
public:
  Cazador(){
    vida = 100;
  }
  void saludar(){
    cout<<"Soy un Cazador, vida: " <<vida<<endl;
  }
  int atacar(){
    int damage = rand() % 30 + 15;
    int multiplicador = rand() % 10 + 1;
    if(multiplicador > 3){
      damage *= 1.6;
    }
    return damage;
  }
};

class Hechicero: public Guardian{
public:
  Hechicero(){
    vida = 110;
  }
  void saludar(){
    cout<<"Soy un Hechicero, vida: "<<vida<<endl;
  }
  int atacar(){
    int damage = rand() % 40 + 25;
    int multiplicador = rand() % 10 + 1;
    if(multiplicador > 5){
      damage *= 1.5;
    }
    return damage;
  }
};

class Titan: public Guardian{
public:
  Titan(){
    vida = 120;
  }
  void saludar(){
    cout<<"Soy un Titán, vida: "<<vida<<endl;
  }
  int atacar(){
    int damage = rand() % 50 + 35;
    int multiplicador = rand() % 10 + 1;
    if(multiplicador > 7){
      damage *= 1.4;
    }
    return damage;
  }
};

Guardian *Guardian::crear_guardian(int opcion){
  if (opcion == 1)
    return new Cazador;
  else if (opcion == 2)
    return new Hechicero;
  else
    return new Titan;
}
