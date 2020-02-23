#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pastel{
    string pastel;
    string bizcocho;
    string relleno;
    string topping;
public:
    Pastel(string tipoPastel){
      pastel = tipoPastel;
    }
    void setBizcocho(string tipo){
      bizcocho = tipo;
    }
    void setRelleno(string nRelleno){
      relleno = nRelleno;
    }
    void setTopping(string nTopping){
      topping = nTopping;
    }
    string getBizcocho(){
      return bizcocho;
    }
    string getRelleno(){
       return relleno;
    }
    string getTopping(){
      return topping;
    }

    void mostrar() {
    	cout << "Pastel: "<<pastel<<endl
    		   << "Bizcocho: "<<bizcocho<<endl
    		   << "Relleno: "<<relleno<<endl
           << "Topping: "<<topping<<endl<<endl;
    }
};

class PastelBuilder{
protected:
    Pastel *pastel;
public:
    virtual void buildPastel() = 0;
    virtual void buildBizcocho() = 0;
    virtual void buildRelleno() = 0;
    virtual void buildTopping() = 0;

    Pastel* getPastel(){ return pastel; }
};

class PastelChocolateBuilder: public PastelBuilder {
public:
    void buildPastel(){
      pastel = new Pastel("Pastel de Chocolate");
    }

    void buildBizcocho(){
      pastel->setBizcocho("Bizcocho de Chocolate");
    }

    void buildRelleno(){
      pastel->setRelleno("Relleno de Chocolate");
    }

    void buildTopping(){
      pastel->setTopping("Topping de Fresas");
    }
};

class PastelVainillaBuilder: public PastelBuilder {
public:
    void buildPastel(){
       pastel = new Pastel("Pastel de Vainilla");
    }

    void buildBizcocho(){
      pastel->setBizcocho("Bizcocho de Vainilla");
    }

    void buildRelleno(){
      pastel->setRelleno("Relleno de Arándanos");
    }

    void buildTopping(){
      pastel->setTopping("Topping de Frutas mixtas");
    }
};

class Director{
    PastelBuilder *builder;
public:
    Pastel* crearPastel(PastelBuilder *builder) {
        builder->buildPastel();
        builder->buildBizcocho();
        builder->buildRelleno();
        builder->buildTopping();
        return builder->getPastel();
    }
};

int main() {

  Director dir;
  PastelChocolateBuilder pcb;
  PastelVainillaBuilder pvb;

  vector<Pastel*> pasteles;

  int opcion;
  do {
    cout<<"Agregar Pastel: "<<endl<<"0. Salir"<<endl<<"1. Pastel de Chocolate"<<endl<<"2. Pastel de Vainilla"<<endl;
    cin>>opcion;
    if(opcion == 1){
      Pastel *pastelC = dir.crearPastel(&pcb);
      pasteles.push_back(pastelC);
    }else if(opcion == 2){
      Pastel *pastelV = dir.crearPastel(&pvb);
      pasteles.push_back(pastelV);
    }

  } while(opcion != 0);

  cout<<endl<<"Su orden es: "<<endl<<endl;
	for (int i = 0; i < pasteles.size(); i++) {
    pasteles[i]->mostrar();
  }

  for (int i = 0; i < pasteles.size(); i++) {
    delete pasteles[i];
  }

	return 0;
}
