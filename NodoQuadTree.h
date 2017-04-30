#ifndef NODO_QUADTREE_H
#define NODO_QUADTREE_H
/* POR JUAN CASTAÑEDA Y FELIPE CONTRERAS */

#include <iostream>
#include <queue>

template< class T >

class NodoQuadTree{
protected:
  T dato;
  NodoQuadTree<T>* hijos[4];
public:
  NodoQuadTree();
  ~NodoQuadTree() = default ;
  NodoQuadTree(T& val);
  bool Agregarhijo(int index , NodoQuadTree<T>* hijo);
  NodoQuadTree<T>* obtenerNodo(int index);
  T& obtenerDato();
  bool llenarArbol(std::queue<T>& cola , T& datopartir );
  void preOrden();
  void makeimage(T**matriz , int w , int h , T& val  , int primeraposx , int primeraposy);

};

#include "NodoQuadTree.hxx"

#endif
