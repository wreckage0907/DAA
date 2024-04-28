#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int vertex, vector< vector<int> >& graph, vector<int>& colour, int c) {
    for(int i=0; i<graph.size(); i++) {
        if(graph[vertex][i] && c == colour[i]) {
            return false;
        }
    }
    return true;
}

bool graphColouring(vector< vector<int> >& graph, vector<int>& colour, int vertex, int numColours) {
    if(vertex == graph.size()) {
        return true;
    }
    for(int i = 1; i <= numColours; i++) {
        if(isSafe(vertex, graph, colour, i)) {
            colour[vertex] = i;
            if (graphColouring(graph, colour, vertex + 1, numColours)) {
                return true;
            }
            colour[vertex] = 0;
        }
    }
    return false;
}

int main() {
    int n, temp, numColours;
    vector< vector<int> > graph = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
    /*cin >> n;
    for(int i=0; i<n; i++) {
        vector<int> temp1;
        for(int j=0; j<n; j++) {
            cin >> temp;
            temp1.push_back(temp);
        }
        graph.push_back(temp1);
    }*/
    cin >> numColours;
    vector<int> colour(graph.size(), 0);
    if(graphColouring(graph, colour, 0, numColours)) {
        for(int i=0; i<colour.size(); i++) {
            cout << "Vertex " << i << " : Colour " << colour[i] << endl;
        }
    }
    else {
        cout << "Solution does not exist";
    }
}