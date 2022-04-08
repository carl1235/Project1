#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>

#include "Edge.h"
#include "Graph.h"
#include "Vertex.h"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"

using namespace std;

int main(){
    Graph* a1 = new DirectedGraph();  //Empty Graph
    
    //Graphs D and Dag of type DAG
    Graph* D = new UndirectedGraph();
    Graph* Dag = new UndirectedGraph();
//    Graph* Directed = new DirectedGraph();
    
    //All Vertices
//    vector<Vertex>* allVertices = nullptr;
//    
//    while (true)
//    {
//        cin << ID << Value;
//        allVertices->push_back(*new Vertex(1,"Montreal"));
//    }
//    
//    allVertices->begin();
    
    Vertex *vd1 = new Vertex(1,"Montreal");
    Vertex *vd2 = new Vertex(2,"Toronto");
    Vertex *vd3 = new Vertex(3,"Ottawa");
    Vertex *vd4 = new Vertex(4,"Edmonton");
    Vertex *vd5 = new Vertex(5, "Quebec City");
    
    
    vd5->set_position(0);
    Vertex *vd11 = new Vertex(1,"New York");
    Vertex *vd21 = new Vertex(2,"Los Angeles");
    Vertex *vd31 = new Vertex(3,"Florida");
    Vertex *vd41 = new Vertex(4,"Texas");
    Vertex *vd51 = new Vertex(5, "Chicago");
    
    //Add Vertices to Dag
    Dag->addVertex(vd1);
    Dag->addVertex(vd2);
    Dag->addVertex(vd3);
    Dag->addVertex(vd4);
    Dag->addVertex(vd5);
    
    //Add Vertices to D
    D->addVertex(vd11);
    D->addVertex(vd21);
    D->addVertex(vd31);
    D->addVertex(vd41);
    D->addVertex(vd51);
    
    //All Edges
    Edge edM1(1000, vd1, vd2);
    Edge edM2(500, vd2, vd5);
    Edge edM3(5000, vd1, vd4);
    Edge edM4(5352, vd1, vd5);
    
    Edge edT1(628, vd2, vd3);
    Edge edT2(802, vd2, vd4);
    
    Edge edO1(500, vd3, vd5);
    Edge edO2(4000, vd3, vd4);
    Edge edO3(250, vd3, vd1);
    
    Edge edE1(5200, vd4, vd5);
    
    Edge edM21(500, vd11, vd31);
    Edge edM31(5000, vd11, vd41);
    
    Edge edT21(802, vd21, vd41);
    
    Edge edO11(500, vd31, vd51);
  
    //Adding Edges to Dag

    Dag->addEdge(edM1);
    Dag->addEdge(edM2);
    Dag->addEdge(edM3);
    Dag->addEdge(edM4);
    
    //Removing Vertex
    Dag->removeEdge(edM4);
    
    Dag->addEdge(edT1);
    Dag->addEdge(edT2);
    
    Dag->addEdge(edO1);
    
    Dag->addEdge(edE1);
    
    //Search for Edge
    Dag->searchEdge(edO1);
    
    D->addEdge(edM21);
    D->addEdge(edM31);
    
    D->addEdge(edT21);
    
    D->addEdge(edO11);
    
    cout << Dag;
    Dag->printAllPaths(vd1->get_position(), vd5->get_position());
    cout << endl;
    
    cout << D;
    D->printAllPaths(vd11->get_ID(), vd21->get_ID());
    cout << endl;
    
    //Search for Vertex
    cout << "Id of Los Angeles: " << D->searchVertex(vd21);
    
    //Casting Graphs
    DirectedGraph Dag1 = *dynamic_cast<DirectedGraph*>(Dag);
    DirectedGraph D1 = *dynamic_cast<DirectedGraph*>(D);
    DirectedGraph a2 = *dynamic_cast<DirectedGraph*>(a1);
    
    //Print both DAG graphs
    cout << Dag;
    cout << D;
    
    //Checks if D is equal to Dag
    cout << "Is graph D is equal to Dag?\n";
    if (D == Dag)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    //Checks if D is smaller than Dag
    cout << "Is graph D is smaller to Dag?\n";
    if (D < Dag)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    //Post increment
    cout << "Post Increment: ";
    Dag1++;
    cout << Dag;
    
    //Pre increment
    cout << "Pre Increment: ";
    ++Dag1;
    cout << Dag;
    
//    //Addition of 2 Graphs
//    cout << "SUM:";
//    a2 = Dag1 + D1;
//    cout << a1;
    
    //Makes D equal to Dag
    cout << "D = Dag: ";
    D = Dag;
    if (D == Dag)
        cout << "True"<< endl;
    else
        cout << "False"<< endl;
    
    cout << D;
    cout << Dag;
    
    D->clean();
    
    delete a1;
    
    return 0;
}
