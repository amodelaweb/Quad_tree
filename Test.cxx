#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <fstream>
#include <stdlib.h>

#include "QuadTree.h"
/* POR JUAN CASTAÑEDA Y FELIPE CONTRERAS :D */

QuadTree<int> cargar(std::string archivo);
bool escribirarch(int **a , QuadTree<int> arbol);

int main(int argc, char const *argv[]) {
  int cc = 2 ;
  QuadTree<int> a = cargar ("image_05.qt");
  int **archfinal = a.makeimage(cc);
  escribirarch(archfinal , a);
  std::cout<<std::endl ;

  return 0;
}
QuadTree<int> cargar(std::string archivo)
{

  std::queue<int> cola;
  std::fstream myfile ;
  myfile.open(archivo , std::fstream::in );
      if (myfile.is_open())
      {
          std::string line;
          std::string xx,yy;
          getline (myfile,line);

          char* str=&line[0];
          xx = strtok (str," ");
          yy  = strtok (NULL,"\n");
          char xc[10],yc[10];
          strcpy(xc,&xx[0]);
          strcpy(yc,&yy[0]);
          int x = atoi(xc);
          int y = atoi(yc);
          int i=0;
          getline (myfile,line);

          std::vector<char> v(line.begin(), line.end());
          for (int i = 0; i < v.size(); i++) {

            cola.push(v[i] - '0');
          }
          myfile.close();
          QuadTree<int> a(x , y);
          int dato = 2 ;
          a.llenarArbol(cola , dato);

          std::cout<<"\n \t === Archivo cargado correctamente. ==="<<std::endl;
          return a;
      }
      else std::cout << "\n \t === No se puede abrir el archivo ===\n";
      return nullptr ;
}

bool escribirarch(int **a , QuadTree<int> arbol){
  std::fstream myfile ;
  myfile.open("imagen.pgm" , std::fstream::out );
  myfile<<"P1"<<std::endl ;
  myfile<<"# Esta es una imagen chida "<<std::endl ;
  myfile<<arbol.geth()<<" "<<arbol.getw()<<std::endl;
  for(int i = 0 ; i < arbol.geth() ; i++){
    for(int j= 0 ; j< arbol.getw() ; j++){
      myfile<<a[i][j]<<" ";
    }
    myfile<<std::endl ;
  }
  myfile.close();
  return true ;
}
