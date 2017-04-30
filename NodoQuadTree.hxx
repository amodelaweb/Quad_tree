#ifndef NODO_QUADTREE_HXX
#define NODO_QUADTREE_HXX

#include "NodoQuadTree.h"

template< class T >
NodoQuadTree<T>::NodoQuadTree(){
  for(int i=0 ; i<4 ; i++){
    this->hijos[i] = nullptr ;
  }
}
template< class T >
NodoQuadTree<T>::NodoQuadTree(T& val){
  this->dato = val ;
  for(int i=0 ; i<4 ; i++){
    this->hijos[i] = nullptr ;
  }
}

template< class T >
bool NodoQuadTree<T>::Agregarhijo(int index , NodoQuadTree<T>* hijo){
  this->hijos[index] = hijo ;
}

template< class T >
NodoQuadTree<T>* NodoQuadTree<T>::obtenerNodo(int index){
  return this->hijos[index] ;
}

template< class T >
T& NodoQuadTree<T>::obtenerDato(){
  return this->dato ;
}

template< class T >
bool NodoQuadTree<T>::llenarArbol(std::queue<T> &cola , T& datopartir ){
  int cont = 0 ;
  while(!cola.empty() && cont < 4){
    int var = cola.front() ;
    this->hijos[cont] = new NodoQuadTree<T>(var);
    cola.pop();
    if(this->hijos[cont]->obtenerDato() == datopartir){
      this->hijos[cont]->llenarArbol(cola , datopartir) ;
    }
    cont++ ;
  }
  return true ;
}

template< class T >
void NodoQuadTree<T>::preOrden() {
  std::cout<<this->obtenerDato() ;
  for(int i = 0 ; i < 4 ; i++){
    if(this->hijos[i] != nullptr){
      this->hijos[i]->preOrden();
    }
  }
}

template< class T >
void NodoQuadTree<T>::makeimage(T**matriz , int w , int h , T& val  , int primeraposx , int primeraposy){

  for(int i=0 ; i<4 ; i++){

    if(this->hijos[i] != nullptr){

      if(this->hijos[i]->obtenerDato() == val ){
        if(i == 0 ){
          this->hijos[i]->makeimage(matriz , (w/2) , (h/2) , val ,primeraposx , primeraposy);
        }
        if(i == 1){
          this->hijos[i]->makeimage(matriz , (w/2) , (h/2) , val , primeraposx + w/2 , primeraposy );
        }
        if(i == 2){
          this->hijos[i]->makeimage(matriz , (w/2) , (h/2) , val , primeraposx + w/2 , primeraposy + h/2 ) ;
        }
        if( i == 3){
          this->hijos[i]->makeimage(matriz , (w/2) , (h/2) , val , primeraposx , primeraposy + h/2 );
        }
      }else{
        if(this->hijos[i] != nullptr){
          if(i == 0 ){
            for(int j= primeraposy ; j< primeraposy + h/2; j++){
              for(int k = primeraposx ;  k < primeraposx + w/2 ; k++){
                matriz[j][k] = this->hijos[i]->obtenerDato() ;
              }
            }
          }
          if(i == 1){
            for(int j = primeraposy  ; j < primeraposy + h/2 ;j++ ){
              for(int k= primeraposx + w/2 ; k < primeraposx + w ; k++){
                matriz[j][k] = this->hijos[i]->obtenerDato() ;
              }
            }
          }
          if(i == 2){
            for(int j= primeraposy + h/2 ; j < primeraposy + h ; j++ ){
              for(int k = primeraposx + w/2 ; k < primeraposx + w ; k++){
                matriz[j][k] = this->hijos[i]->obtenerDato() ;
              }
            }
          }
          if(i == 3){
            for(int j= primeraposy + h/2 ; j< primeraposy +h ; j++){
              for(int k= primeraposx ; k < primeraposx + w/2 ; k++){
                matriz[j][k] = this->hijos[i]->obtenerDato() ;
              }
            }
          }
        }
      }
    }
  }
}



#endif
