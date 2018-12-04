#ifndef H_Node_H
#define H_Node_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <climits>
#include "Edge.h"

using namespace std;

class Node{
        public:
                string name;
                vector<Edge> edges;
                Node* pi;
                Edge* piFlight;
                int visited;
                int dist;
                void insertEdge(Edge edge); 
                //Node *next= nullptr;
                Node(string name);
                Node();
                friend ostream& operator<<(ostream& out, const Node& n);
};

Node::Node(){

}

void Node::insertEdge(Edge edge){
        edges.push_back(edge);
}

Node::Node(string name){
        this->name = name;
        pi = nullptr;
        piFlight = nullptr;
        visited =0;
        dist=INT_MAX;
}

ostream& operator<<(ostream& out, const Node& n){
        out<<n.name;
        return out; 
}
#endif
