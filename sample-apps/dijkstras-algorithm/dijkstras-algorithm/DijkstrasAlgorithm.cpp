#include "DijkstrasAlgorithm.h"

map<int, int> Node::path_weight;

void Dijkstras::findShortestPath(Graph &graph)
{
	// Pop the root node off of the priority queue.
	Node temp;

	// Visit the neighbor of each node in the tree starting
	// from the root.
	while (!myPQ.empty())
	{
		temp = myPQ.top();
		for (Node neighbor : temp.neighbors)
		{
			int weightThroughEdge = Node::path_weight[temp.id] + neighbor.edge;
			if (weightThroughEdge < Node::path_weight[neighbor.id] && previousNode[temp.id] != neighbor.id)
			{
				Node::path_weight[neighbor.id] = weightThroughEdge;
				previousNode[neighbor.id] = temp.id;
				myPQ.push(graph.nodes[neighbor.id]);
			}
		}
		myPQ.pop();
	}
}
void Dijkstras::printShortestPath(int nodeId)
{
	cout << "Shortest Path (" << "Node(start)"
		<< "-->"
		<< "Node(end)" << "): Path"<<endl << endl;
	for (auto const& x : previousNode)
	{
		cout << "Shortest Path (" << nodeId
			<< "-->"
			<< x.first << "): ";
		print(x.first);
		cout << endl;
	}
}
void Dijkstras::print(int key)
{
	if (previousNode[key] == 0)
	{
		cout << previousNode[key] << "--" << key << " ";
		return;
	}
	else
	{
		print(previousNode[key]);
		cout << previousNode[key] << "--" << key << " ";
	}

}

void Graph::printTree()
{
	// Breadth first search through the tree
	// printing the neighbors of each node
	// at each level
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << "\n" << "Node:" << nodes[i].id << "\n";
		for (int j = 0; j < nodes[i].neighbors.size(); j++)
		{
			cout << "neighbor:";
			cout << nodes[i].neighbors[j].id << "\n";
		}
	}
}
void Graph::addEdge(Node* temp, int dest, int weight)
{
	Node neighbor;
	neighbor.id = dest;
	neighbor.edge = weight;
	temp->neighbors.push_back(neighbor);
}
Graph::Graph(int V)
{
	for (int i = 0; i < V; i++)
	{
		Node temp;
		temp.id = i;
		nodes.push_back(temp);
	}
}
