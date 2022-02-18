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

#include "./dual_list.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

template<class T1, class T2>
DualList<T1, T2>::DualList() { }

template<class T1, class T2>
void DualList<T1, T2>::Insert(T1 x1, T2 x2) {
  return;
}

template<class T1, class T2>
int DualList<T1, T2>::Size() const {
  return 0;
}

template<class T1, class T2>
T2 DualList<T1, T2>::ExtractMinKey1() {
  return T2();
}

template<class T1, class T2>
T1 DualList<T1, T2>::ExtractMinKey2() {
  return T1();
}

template<class T1, class T2>
vector<string> DualList<T1, T2>::ListByKey1() const {
  return vector<string>();
}

template<class T1, class T2>
vector<string> DualList<T1, T2>::ListByKey2() const {
  return vector<string>();
}
