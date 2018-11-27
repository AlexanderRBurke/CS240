#ifndef H_Node_H
#define H_Node_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Edge.h"

using namespace std;

class Node{
	public:
                string name;
                vector<Edge> edges;

                void insertEdge(Edge edge); 
                //Node *next= nullptr;
                Node(string name);
};

void Node::insertEdge(Edge edge){
    edges.insert(edge);
}

Node::Node(string name){
    this->name = name;
}

#endif
