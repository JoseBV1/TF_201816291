#pragma once
#ifndef __NODO_H__
#define __NODO_H__


struct Node {
    float elem;
    float elemDistrito;
    Node* next;
    //T hola;

    Node(float elem,float elemDistrito, Node* next = nullptr)
        : elem(elem), next(next), elemDistrito(elemDistrito) {}
};

#endif
