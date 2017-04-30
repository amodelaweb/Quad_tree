#ifndef ARBOL_QUADTREE_HXX
#define ARBOL_QUADTREE_HXX
#include "QuadTree.h"

template< class T >
QuadTree<T>::QuadTree(int h , int w){
  this->h = h ;
  this->w = w ;
}

template< class T >
QuadTree<T>::QuadTree(NodoQuadTree<T>* root){
  this->root = root ;
}

template< class T >
QuadTree<T>::QuadTree(T& val){
  this->root = new NodoQuadTree<T>(val) ;
}

template< class T >
bool QuadTree<T>::llenarArbol(std::queue<T> cola , T& datopartir) {
  if(!cola.empty()){

    if(cola.front() == datopartir){
      this->root = new NodoQuadTree<T>(cola.front());
      cola.pop() ;
      return this->root->llenarArbol(cola , datopartir) ;
    }else{
      this->root = new NodoQuadTree<T>(cola.front());
      return true ;
    }
  }else{
    return false ;
  }
}

template< class T >
void QuadTree<T>::preOrden(){
  this->root->preOrden();
}

template< class T >
T** QuadTree<T>::makeimage(T& value){
  T **matriz ;
  matriz = new T*[this->w];
  for (int i=0 ; i < this->h ;i++){
    matriz[i] = new T [this->h];
  }
  this->root->makeimage(matriz ,this->w , this->h , value , 0 , 0 );
return matriz ;
}
template< class T >
int QuadTree<T>::geth(){
return this->h ;
}
template< class T >
int QuadTree<T>::getw() {
return this->w ;
}
#endif
