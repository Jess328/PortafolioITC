//Act 2.3 - Actividad Integral estructura de datos lineales (Evidencia Competencia)

//A01734879 Alejandro Armenta Arellano
//A01735227 Jesús Jiménez Aguilar
//A01735346 Daniela Berenice Hernandez de Vicente

//Fecha de creación: 08 de octubre de 2021
//Fecha de modificación: 18 de octubre de 2021

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Clase del Nodo
template <class T>
class NodeD{
  private:
      T data;
      NodeD<T> *Izq;
      NodeD<T> *Der;
  public:
      NodeD(T data){
          this->data = data;
          this->Izq = nullptr;
          this->Der = nullptr;
      }
      NodeD(T data, NodeD<T> *Izq, NodeD<T> *Der){
          this->data = data;
          this->Izq = Izq;
          this->Der = Der;
      }

      T getData(){
          return this->data;
      }
      NodeD<T>* getIzq(){
          return this->Izq;
      }
      NodeD<T>* getDer(){
          return this->Der;
      }
      void setData(T data){
          this->data = data;
      }
      void setIzq(NodeD<T> *Izq){
          this->Izq = Izq;
      }
      void setDer(NodeD<T> *Der){
          this->Der = Der;
      }
};

// Definición de la Linked List
template <class T>
class LinkedList{
  private:
    NodeD<T> *head;
    int size;

  public:
    LinkedList(){
      head = nullptr;
      size = 0;
    }
    ~LinkedList(){
      deleteAll();
    }

    // Liberar memoria (Destructor)
    // Complejidad: O(n)
    void deleteAll(){
      NodeD<T> *current = head;
      while(head != nullptr){
        head = head->getDer();
        delete current;
        current = head;
      }
      size = 0;
    }

    // Función que regresa el tamaño de la lista
    int getSize(){
      return size;
    }

    // Función que verifica si la posicion esta dentro de la lista y si si lo esta lo busca y que te regresa el valor
    // Complejidad: O(n)
    T getData(int pos){
      if(pos > size || pos < 1){
        return 0;
      }
      if(size == 0){
        return 0;
      }
      else{
        NodeD<T> *current = head;
        for(int i = 1; i < pos; i++){
          current = current->getDer();
        }
        T elem = current->getData();
        return elem;
      }
    }

    // Función que agrega un elemento en la posición incial de la lista
    // Complejidad: O(1)
    void addFirst(T data){
      head = new NodeD<T>(data, nullptr, head);
      size++;
    }

    // Función que agrega un elemento en la posición final de la lista
    // Complejidad: O(n)
    void addLast(T data){
      NodeD<T> *current = head;
      if(size == 0){
        addFirst(data);
        return;
      }
      while(current->getDer() != nullptr){
        current = current->getDer();
      }
      current->setDer(new NodeD<T>(data, current, nullptr));
      size++;
    }

    // Función que agrega un elemento en cualquier posición de la lista dependiendo de su tamaño o de si esta vacía.
    // Complejidad: O(n)
    void create(T data, int pos){
      if(pos < 0 || size == 0){
        addFirst(data);
        return;
      }
      NodeD<T> *current = head;
      if(pos > size){
        while(current->getDer() != nullptr){
          current = current->getDer();
        }
        current->setDer(new NodeD<T>(data, current, nullptr));
        size++;
        return;
      }
      for(int i = 1; i < pos-1; i++){
        current = current->getDer();
      }
      NodeD<T> *adelante = current->getDer();
      current->setDer(new NodeD<T>(data, current, adelante));
      current = current->getDer();
      size++;
      return;
    }

    // Función que retorna la posicion de acuerdo al valor que se le da
    // Complejidad: O(n)
    int readData(T data){
      int pos = -1;
      NodeD<T> *current = head;
      for(int i = 1; i <= size; i++){
        if(current->getData() == data){
          pos = i;
          return pos;
        }
        else{
          current = current->getDer();
        }
      }
      return pos;
    }

    // Función que actualiza la lista mediante un valor
    // Complejidad: O(n)
    bool updateData(T data, T nData){
      int pos = readData(data);
      if(pos == -1){
        return false;
      }
      else{
        NodeD<T> *current = head;
        for(int i = 1; i < pos; i++){
          current = current->getDer();
        }
        current->setData(nData);
        return true;
      }
    }

    // Función que actualiza la lista mediante una posicion
    // Complejidad: O(n)
    bool updateWPos(int pos, T nData){
      if(pos < 1 || pos > size){
        return false;
      }
      else{
        NodeD<T> *current = head;
        for(int i = 1; i < pos; i++){
          current = current->getDer();
        }
        current->setData(nData);
        return true;
      }
    }

    // Función que elimina un elemento que se define
    // Complejidad: O(n)
    bool deleteAt(T data){
      int pos = readData(data);
      if(pos == -1){
        return false;
      }
      if(pos == 1){
        NodeD<T> *current = head;
        head = current->getDer();
        delete current;
        size--;
        return true;
      }
      else{
        NodeD<T> *current = head;
        for(int i = 1; i < pos - 1; i++){
          current = current->getDer();
        }
        NodeD<T> *temp = current->getDer();
        NodeD<T> *nuevo = temp->getDer();
        current->setDer(nuevo);
        delete temp;
        size--;
        return true;
      }
    }
};

LinkedList<string> list;

// Funciones IP
// Complejidad: O(1)
string getIP(string ip, int port){
  ip = ip.substr(15, 25);
  int search = ip.find(" ");
  if(search == 0){
    ip = ip.substr(1, 25);
  }
  search = ip.find(":");
  if(port == 0){
    ip = ip.substr(0, search); // En caso de que el puerto sea 0 solo se busca un 0 despues del ':'
  }
  else{
    ip = ip.substr(0, search + 5); // En el caso de que no lo sea se separa el valor de la ipd el del puerto
  }
  return ip;
}

// Función que sirve para separa los valores numericos de la ip de sus '.'
// Complejidad: O(1)
int separarIP(string ip, int parte){
  string ip2;
  if(parte == 1){
    ip2 = ip.substr(0, ip.find('.'));
    return stoi(ip2);
  }
  if(parte == 2){
    ip2 = ip.substr(ip.find('.') + 1, 10);
    ip2 = ip2.substr(0, ip2.find('.'));
    return stoi(ip2);
  }
  if(parte == 3){
    ip2 = ip.substr(ip.find('.') + 1, 10);
    ip2 = ip2.substr(ip2.find('.') + 1, 10);
    ip2 = ip2.substr(0, ip2.find('.'));
    return stoi(ip2);
  }
  if(parte == 4){
    ip2 = ip.substr(ip.find('.') + 1, 10);
    ip2 = ip2.substr(ip2.find('.') + 1, 10);
    ip2 = ip2.substr(ip2.find('.') + 1, 10);
    return stoi(ip2);
  }
  else{
    ip2 = "0";
    return stoi(ip2);
  }
}

// Funcion para cambiar el ip de un string a un long long
// Complejidad: O(n)
long long numIP(string ip){
  string uni0 = "", ip2;
  for(int i = 1; i <= 4; i++){
    ip2 = to_string(separarIP(ip, i)); // Se utiliza separarIP para obtener solo los valores numericos
    while(ip2.size() < 3){
      ip2 = "0" + ip2;
    }
    uni0 = uni0 + ip2;
  }
  return stoll(uni0);
}

// Función de implementacion del pivote en el nodo que se usará a la hora de ordenar
// Complejidad: O(n)
int particion(int inicio, int fin){
  long long valpivote = numIP(getIP(list.getData(inicio), 0));
  int j = inicio, pivote;
  string aux;
  for(int i = inicio + 1; i <= fin; i++){
    if(((numIP(getIP(list.getData(i), 0))) < valpivote)){
      j = j + 1;
      aux = list.getData(i);
      list.updateWPos(i, list.getData(j));
      list.updateWPos(j, aux);
    }
  }
  pivote = j;
  aux = list.getData(inicio);
  list.updateWPos(inicio, list.getData(j));
  list.updateWPos(j, aux);
  return pivote;
}

// Metodo de Ordenamiento
// Complejidad: O(n)
void quickSort(int inicio, int fin){
  int pivote;
  if(inicio < fin){
    pivote = particion(inicio, fin);
    quickSort(inicio, pivote - 1);
    quickSort(pivote + 1, fin);
  }
}

int main(){
  ifstream in("bitacora.txt");
  ofstream data;
  if(in.fail()){
    return 0;
  }
  else{
    string s;
    while(getline(in, s)){
      list.addLast(s); // agregar cada elemento a la lista
    }
    in.close();
  }
  quickSort(1, list.getSize());

  data.open("Sorted.txt", ios::out);
  for(int i = 1; i <= list.getSize(); i++){
    data << list.getData(i);
    if(i != list.getSize()){
      data << endl;
    }
  }
  data.close();

  string ipI, ipF;
  cin >> ipI;
  cin >> ipF;

  // Busqueda Secuencial
  int ipIP = 0, ipFP = 0;
  for(int i = 1; i <= list.getSize(); i++){
    if(getIP(list.getData(i), 1) == ipI){
      ipIP = i;
    }
    if(getIP(list.getData(i), 1) == ipF){
      ipFP = i;
    }
  }

  if(ipIP != 0 || ipFP != 0){
   // Si los rangos son encontrados se crea el archivo donde se insertaran los datos dentro del rango
   ofstream datos2;
   datos2.open("SortedData.txt", ios::out);
   // Si los rangos son encontrados se crea el archivo donde se insertaran los datos dentro del rango
   for(int i = ipFP; i >= ipIP; i--){
     datos2 << list.getData(i);
     cout << list.getData(i) << endl;
     if(i != ipIP){
       datos2 << endl;
     }
   }
   datos2.close();
 }

  list.deleteAll();
  return 0;

}
