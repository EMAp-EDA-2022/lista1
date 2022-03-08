// Copyright (c) 2022

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
// ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
// TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
// PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
// SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
// ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.

#include "./dual_list_sol.h"
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <exception>
#include <sstream>

using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
using std::to_string;
using std::exception;
using std::stringstream;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "Attempt to extract from an empty list";
  }
} myex;

template<class T1, class T2>
bool SortByFirst(const pair<T1,T2> &a,
              const pair<T1,T2> &b) {
    if (a.first == b.first) return a.second < b.second;
    return (a.first < b.first);
}

template<class T1, class T2>
bool SortBySec(const pair<T1,T2> &a,
              const pair<T1,T2> &b) {
    if (a.second == b.second) return a.first < b.first;
    return (a.second < b.second);
}

template<class T1, class T2>
vector<string> VectorPairToString(vector<pair<T1, T2>> vec) {
  vector<string> response(vec.size());
  string pair_format;
  for(int i = 0; i < vec.size(); i++){
    string key1, key2;
    key1 = vec[i].first;
    key2 = to_string(vec[i].second);
    pair_format = "(" + key1 + ", " + key2 + ")";
    response[i] = pair_format;
  }
  return response;
}

template<class T1, class T2>
Node<T1, T2>::Node() {
  next = nullptr;
}

template<class T1, class T2>
Node<T1, T2>::Node(T1 x1, T2 x2) {
  key1 = x1;
  key2 = x2;
}

template<class T1, class T2>
DualList<T1, T2>::DualList() { 
  ptr_root = new Node<T1,T2>();
  size = 0;
}

template<class T1, class T2>
void DualList<T1, T2>::Insert(T1 x1, T2 x2) {
  Node<T1, T2>* ptr_new = new Node<T1, T2>(x1, x2);
  ptr_new->next = ptr_root->next;
  ptr_root->next = ptr_new;
  size++;
  return;
}

template<class T1, class T2>
int DualList<T1, T2>::Size() const {
  return size;
}

template<class T1, class T2>
T2 DualList<T1, T2>::ExtractMinKey1() {
  if (size == 0) throw myex; 
  // Começo com dois ponteiros no inicio
  // Um ponteiro vai percorrer a DualList inteira
  // O outro vai armazenar a posição anterior da que vai ser removida
  Node<T1, T2>* ptr_cur = ptr_root;
  Node<T1, T2>* ptr_min = ptr_root;
  while (ptr_cur->next != nullptr) {
    // Se o próximo do cur for menor que o próximo do min, atualiza o min
    if (ptr_cur->next->key1 < ptr_min->next->key1) ptr_min = ptr_cur;
    if ((ptr_cur->next->key1 == ptr_min->next->key1) 
    && (ptr_cur->next->key2 < ptr_min->next->key2)) ptr_min = ptr_cur;
    // cur se torna o próximo
    ptr_cur = ptr_cur->next;
  }
  if (ptr_min->next == nullptr) return T2();
  T2 min = ptr_min->next->key2;
  
  //Remove o nó
  Node<T1, T2>* aux = ptr_min->next;
  ptr_min->next = ptr_min->next->next;
  delete aux;
  size--;
  return min;
}

template<class T1, class T2>
T1 DualList<T1, T2>::ExtractMinKey2() {
  if (size == 0) throw myex; 
  // Começo com dois ponteiros no inicio
  // Um ponteiro vai percorrer a DualList inteira
  // O outro vai armazenar a posição anterior da que vai ser removida
  Node<T1, T2>* ptr_cur = ptr_root;
  Node<T1, T2>* ptr_min = ptr_root;
  while (ptr_cur->next != nullptr) {
    // Se o próximo do cur for menor que o próximo do min, atualiza o min
    if (ptr_cur->next->key2 < ptr_min->next->key2) ptr_min = ptr_cur;
    if ((ptr_cur->next->key2 == ptr_min->next->key2) 
    && (ptr_cur->next->key1 < ptr_min->next->key1)) ptr_min = ptr_cur;
    // cur se torna o próximo
    ptr_cur = ptr_cur->next;
  }
  if (ptr_min->next == nullptr) return T1();
  T1 min = ptr_min->next->key1;
  
  //Remove o nó
  Node<T1, T2>* aux = ptr_min->next;
  ptr_min->next = ptr_min->next->next;
  delete aux;
  size--;
  return min;
}

template<class T1, class T2>
vector<string> DualList<T1, T2>::ListByKey1() const {
  Node<T1, T2>* ptr_cur = ptr_root; 
  vector<pair<T1, T2>> response(size);
  for (int i = 0; i < size; i++) {
    response[i] = make_pair(ptr_cur->next->key1, ptr_cur->next->key2);
    ptr_cur = ptr_cur->next;
  }

  sort(response.begin(), response.end(), SortByFirst<T1, T2>);
  return VectorPairToString(response);
}

template<class T1, class T2>
vector<string> DualList<T1, T2>::ListByKey2() const {
  Node<T1, T2>* ptr_cur = ptr_root; 
  vector<pair<T1, T2>> response(size);
  for (int i = 0; i < size; i++) {
    response[i] = make_pair(ptr_cur->next->key1, ptr_cur->next->key2);
    ptr_cur = ptr_cur->next;
  }
  sort(response.begin(), response.end(), SortBySec<T1, T2>);
  return VectorPairToString(response);
}
