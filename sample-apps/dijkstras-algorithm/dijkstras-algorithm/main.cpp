#include "PriorityQueue.h"
#include "DijkstrasAlgorithm.h"
#include <climits>
using namespace std;

int main()
{
#ifdef PRINT_PRIORITY_QUEUE
    // The PriorityQueue object below instantiates a class
    // object that is an example of a priority queue. Done just
    // to demonstrate how they work. The STL provides an easy to 
    // use implementation of a priority queue
    PriorityQueue pq;

    // Note: The element's value decides priority

    pq.push(3);
    pq.push(2);
    pq.push(15);

    cout << "Size is " << pq.size() << endl;

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    pq.push(5);
    pq.push(4);
    pq.push(45);

    cout << endl << "Size is " << pq.size() << endl;

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << endl << std::boolalpha << pq.empty();

    pq.top();    // top operation on an empty heap
    pq.pop();    // pop operation on an empty heap
#endif // PRINT_PRIORITY_QUEUE



    // Now it's time for Dijkstras Algorithm processing
    // First we'll build a graph of nodes with edges connecting
    // them. 
    int V = 9;

    Graph graph(V);

    // Graph is built by creating edges that connect
    // each node so Node 0 to Node 1 has an edge weight of 4.
    // i.e Edge: 0--1  Weight: 4,
    //     Edge: 0--7  Weight: 8
    // etc...
    graph.addEdge(&graph.nodes[0], 1, 4);
    graph.addEdge(&graph.nodes[0], 7, 8);
    graph.addEdge(&graph.nodes[1], 2, 8);
    graph.addEdge(&graph.nodes[1], 7, 11);
    graph.addEdge(&graph.nodes[1], 0, 4);
    graph.addEdge(&graph.nodes[2], 3, 7);
    graph.addEdge(&graph.nodes[2], 8, 2);
    graph.addEdge(&graph.nodes[2], 5, 4);
    graph.addEdge(&graph.nodes[2], 1, 8);
    graph.addEdge(&graph.nodes[3], 4, 9);
    graph.addEdge(&graph.nodes[3], 5, 14);
    graph.addEdge(&graph.nodes[3], 2, 7);
    graph.addEdge(&graph.nodes[4], 5, 10);
    graph.addEdge(&graph.nodes[4], 3, 9);
    graph.addEdge(&graph.nodes[5], 6, 2);
    graph.addEdge(&graph.nodes[5], 2, 4);
    graph.addEdge(&graph.nodes[5], 3, 14);
    graph.addEdge(&graph.nodes[5], 4, 10);
    graph.addEdge(&graph.nodes[6], 7, 1);
    graph.addEdge(&graph.nodes[6], 8, 6);
    graph.addEdge(&graph.nodes[6], 5, 2);
    graph.addEdge(&graph.nodes[7], 8, 7);
    graph.addEdge(&graph.nodes[7], 0, 8);
    graph.addEdge(&graph.nodes[7], 1, 11);
    graph.addEdge(&graph.nodes[7], 6, 1);
    graph.addEdge(&graph.nodes[8], 2, 2);
    graph.addEdge(&graph.nodes[8], 7, 7);
    graph.addEdge(&graph.nodes[8], 6, 6);

    // Let's have a look at our tree
    cout << "Tree breakdown of nodes and neighbors";
    graph.printTree();

    // Next we initialize path weight map.
    for (int i = 0; i < graph.nodes.size(); i++)
    {
        ((i == 0) ? Node::path_weight[graph.nodes[i].id] = 0 : Node::path_weight[graph.nodes[i].id] = INT_MAX);
    }

    // Now we can create our priority que. I decided to use the STL priority_queue
    // class to make things easier since it is templated already. 
    // Create a min prioirity queue based on the weight of each path
    // priority_queue<Node, vector<Node>, compareWeights> myPQ;
    Dijkstras Algorithm;

    // Add 1 nodes to the priority queue.
    Algorithm.myPQ.push(graph.nodes[0]);

    // Let's take a look at our priority queue. Node Id 0 should be on top.
    cout << endl << "Top element in Priority Queue:" <<endl << 
        "Node: " << Algorithm.myPQ.top().id << endl << endl;

    // Now it's time to find the shortest path from start node to all
    // all other nodes in the graph!

    cout << "Find the shortest path to each node in our tree starting with Node 0" << endl << endl;
    Algorithm.findShortestPath(graph);
    Algorithm.printShortestPath(0);

    return 0;

}

