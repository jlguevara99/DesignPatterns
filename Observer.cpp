#include <iostream>
#include <vector>

using namespace std;
int a = 0;
class Tienda {
  double precioPS4;
  double precioXBOX;
  double precioSwitch;
  vector<class Observer*> lista;
public:
  double getPrecioPS4(){
    return precioPS4;
  }
  double getPrecioXBOX(){
    return precioXBOX;
  }
  double getPrecioSwitch(){
    return precioSwitch;
  }
  void setPrecioPS4(double nprecio) {
    precioPS4 = nprecio;
    notify();
  }
  void setPrecioXBOX(double nprecio){
    precioXBOX = nprecio;
    notify();
  }
  void setPrecioSwitch(double nprecio){
    precioSwitch = nprecio;
    notify();
  }

  void agregarObservador(Observer *observer){
    lista.push_back(observer);
  }
  void eliminarObservador(Observer *observer){
  }

  void notify();

};

class Observer{
  Tienda *tienda;
public:
  Observer(Tienda *ntienda){
    tienda = ntienda;
    tienda->agregarObservador(this);
  }
  virtual void update() = 0;
protected:
  Tienda* getTienda(){
    return tienda;
  }
};

void Tienda::notify(){
  for (int i = 0; i < lista.size(); i++) {
    lista[i]->update();
  }
}

class Cliente : public Observer{
  int pos;
public:
  Cliente(Tienda *tienda) : Observer(tienda){
    pos = ++a;
  }
  void update(){
    double pP = getTienda()->getPrecioPS4();
    double pX = getTienda()->getPrecioXBOX();
    double pS = getTienda()->getPrecioSwitch();
    cout<<endl<<"Cambio recibido en el observador "<<pos<<": "<<endl<<"PS4: "<<pP<<endl<<"XBOX: "<<pX<<endl<<"Switch: "<<pS<<endl<<endl;
  }
};

int main(){
  Tienda *tienda = new Tienda();

  Cliente cliente(tienda);
  Cliente cliente2(tienda);
  int opcion;

  do {
    cout<<"Cambiar precios: "<<endl<<"1. PS4"<<endl<<"2. XBOX"<<endl<<"3. Switch"<<endl<<"4. Salir"<<endl;
    cin>>opcion;
    if(opcion == 4){
      continue;
    }
    cout<<"Ingrese nuevo precio: "<<endl;
    double nprecio;
    cin>>nprecio;

    if(opcion == 1){
      tienda->setPrecioPS4(nprecio);
    }else if(opcion == 2){
      tienda->setPrecioXBOX(nprecio);
    }else if(opcion == 3){
      tienda->setPrecioSwitch(nprecio);
    }
  } while(opcion != 4);
  return 0;
};
