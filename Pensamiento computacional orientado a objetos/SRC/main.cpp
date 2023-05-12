//Francisco Rocha Juárez. A01730560
//Jesús Jimenez Aguilar. A01735227

#include<iostream>
#include<vector>
#include<sstream>
#include"Producto.cpp"
#include<fstream>
using namespace std;

int main() {
  bool menu=true;
  cout<<"Lista de pedidos"<<endl;
  vector<Producto> pedidos;//Se declara un vector que contendra todos los pedidos
  //El while mostrará el menú hasta que el usuario decida salir
  while (menu=true){
    cout<<"\nMENU\n1. Ver pedidos\n2. Agregar pedido\n3. Cargar pedidos desde archivo\n4. Guardar los pedidos en un archivo\n5.Eliminar un pedido\n0. Salir\nSeleccione una opcion:";
    int seleccion;
    cin>>seleccion;

    //Opcion 1: Mostrar todos los pedidos
    if (seleccion==1){
      string impresion_pedidos;
      //Se recorre todo el vector con el for para poder imprimir cada pedido
      for (int i = 0; i < pedidos.size(); i++) {
        impresion_pedidos="\nPedido "+ to_string(i+1)+":\n"+pedidos[i].to_string();
        cout<<impresion_pedidos;
      }
    }

    //Opcion 2:Agregar pedido
    else if (seleccion==2){
      string categoria,articulo,nombre,telefono,direccion,metodopago;
      int cantidad,numerorastreo;
      double precio;
      //Se piden todos los datos del pedido que se quiere agregar
      cout<<"Escriba la categoria del producto: ";
      cin>>categoria;
      cout<<"Escriba el nombre del producto: ";
      cin>>articulo;
      cout<<"Escriba el precio: ";
      cin>>precio;
      cout<<"Escriba la cantidad: ";
      cin>>cantidad;
      cout<<"Escriba el nombre del cliente: ";
      cin>>nombre;
      cout<<"Escriba el número de telefono del cliente: ";
      cin>>telefono;
      cout<<"Escriba la dirección del cliente: ";
      cin>>direccion;
      cout<<"Escribe el método de pago: ";
      cin>>metodopago;
      cout<<"Escribe el número de rastreo: ";
      cin>>numerorastreo;
      //Se guardan los datos de la persona en objetos tipo cliente
      Cliente persona;
      persona.setNombre(nombre);
      persona.setTelefono(telefono);
      persona.setDireccion(direccion);
      //Se agrega un nuevo pedido al final del vector con los datos recabados
      Producto *pNuevo;
      pNuevo=new Producto(categoria,articulo,precio,cantidad,persona,metodopago,numerorastreo);
      pedidos.push_back(*pNuevo);
    }


    //Opcion 3: Cargar pedidos de un archivo
    else if (seleccion==3){
      string nombrearchivo,a,categorial,articulol,nombrel,telefonol,direccionl,metodopagol;
      ifstream lector;
      int npedidos,cantidadl,numerorastreol;
      double preciol;
      //Se pide el nombre del archivo que se quiere cargar
      cout<<"Introduzca el nombre del archivo (incluya la terminacion .txt): ";
      cin>>nombrearchivo;
      //Se abre el archivo
      lector.open(nombrearchivo);
      //Si se abre con éxito se realiza todo el proceso
      if(lector.is_open()){
      //Se lee la primera linea, que es el numero de pedidos y lo convierte a entero
      lector>>a;
      npedidos=stoi(a);
      getline(lector,a);
      //Se van a leer todos los datos de un pedido el mismo número de veces que el número de pedidos que haya
      for (int i=0;i<npedidos;i++){
        getline(lector,a);
        categorial=a;
        getline(lector,a);
        articulol=a;
        getline(lector,a);
        preciol=stod(a);
        getline(lector,a);
        cantidadl=stoi(a);
        getline(lector,a);
        nombrel=a;
        getline(lector,a);
        telefonol=a;
        getline(lector,a);
        direccionl=a;
        getline(lector,a);
        metodopagol=a;
        getline(lector,a);
        numerorastreol=stoi(a);
        //Se agregan los datos de la persona a objetos de persona
        Cliente personal;
        personal.setNombre(nombrel);
        personal.setTelefono(telefonol);
        personal.setDireccion(direccionl);
        //Agregar el pedido al vector
        Producto *pNuevo2;
        pNuevo2=new Producto(categorial,articulol,preciol,cantidadl,personal,metodopagol,numerorastreol);
        pedidos.push_back(*pNuevo2);
      }
      //Se cierra el archivo
      lector.close();
      cout<<"Pedidos cargados con exito.\n";
      }
      else{
        cout<<"No se pudo abrir el archivo.\n";
      }
    }

    //Opcion 4:Guardar todos los pedidos en un archivo
    else if (seleccion==4){
      ofstream escritor;
      string nombrearchivo2;
      //Se pide el nombre del archivo
      cout<<"Escriba el nombre con el que desea guardar su archivo (incluya la terminacion .txt): ";
      cin>>nombrearchivo2;
      //Se abre el archivo
      escritor.open(nombrearchivo2);
      //Si el archivo se abre con exito se realiza todo
      if (escritor.is_open()){
      //Se escribe en la primera linea del archivo el número de vuelos que hay
      escritor<<pedidos.size()<<endl;
      //Se van a escribir todos los datos de un pedido el mismo número de veces que el número de pedidos que haya
      for(int i=0;i<pedidos.size();i++){
        escritor<<pedidos[i].getCategoria()<<endl;
        escritor<<pedidos[i].getArticulo()<<endl;
        escritor<<pedidos[i].getPrecio()<<endl;
        escritor<<pedidos[i].getCantidad()<<endl;
        escritor<<pedidos[i].getPersona().getNombre()<<endl;
        escritor<<pedidos[i].getPersona().getTelefono()<<endl;
        escritor<<pedidos[i].getPersona().getDireccion()<<endl;
        escritor<<pedidos[i].getMetodoPago()<<endl;
        escritor<<pedidos[i].getNumeroRastreo()<<endl;
      }
      //Se cierra el archivo
      escritor.close();
      cout<<"Vuelos guardados con exito\n";
    }
    else{
      cout<<"No se pudo abrir el archivo.\n";
    }
  }
//Opcion 5:Eliminar un pedido
  else if (seleccion==5){
        int validar=-1;
        //Se pide el numero de pedido que se desea borrar
        cout<<"Introduzca el nombre del producto que desea eliminar: ";
        int elim;
        cin>>elim;
        //Se recorre el vector para buscar el pedido
        for (int i = 0; i < pedidos.size(); i++) {
          //Si coinciden los numeros de rastreo se elimina el correspondiente
          if (pedidos[i].getNumeroRastreo()==elim){
            pedidos[i] = Producto();
            cout<<"Pedido eliminado";
            validar=1;
          }
        }
        if (validar=-1){
          cout<<"No se encontro el pedido\n";
        }
      }

    //Opcion 0: Salir
    else if (seleccion==0){
      break;//Se sale del ciclo
    }

    //Opcion no válida
    else{
      cout<<"Opcion invalida";
    }
  }
  return 0;
}
