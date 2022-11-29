#include<iostream>
#include "main/NSS.h"
using namespace std;

int main()
{

   avl a;
   a.insert(2);
   a.insert(3);
   a.insert(4);
   a.preorder();
    return 0;
}