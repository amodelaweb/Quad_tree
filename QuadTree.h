#ifndef ARBOL_QUADTREE_H
#define ARBOL_QUADTREE_H
/* JUAN CASTAÑEDA Y FELIPE CONTRERAS :D */

#include "NodoQuadTree.h"
#include <iostream>
#include <queue>

template< class T >

class QuadTree{
protected:
  NodoQuadTree<T>* root ;
  int h ;
   int w ;
public:
  QuadTree(int h , int w);
  ~QuadTree() = default ;
  QuadTree(NodoQuadTree<T>* root);
  QuadTree(T& val);
  bool llenarArbol(std::queue<T> cola , T& datopartir) ;
  void preOrden() ;
  int geth();
  int getw() ;
  T** makeimage(T& value);


};
#include "QuadTree.hxx"

#endif
