#pragma once
#include<vector>
#include<iostream>

using namespace std;

class Graph {

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix.resize(numVertices);
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i].resize(numVertices);
        }
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void removeEdge(int u, int v) {
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
    }

    bool isEdge(int u, int v) {
        return adjMatrix[u][v] == 1;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << i << ": ";
            for (int j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] == 1) {
                    std::cout << j << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    void DFS(int start) {
        vector<bool> visited(numVertices, false);

        DFS(start, visited);
    }

    void BFS(int start) {
        vector<bool> visited(numVertices, false);
        vector<bool> explored(numVertices, false);
        std::cout << start << " - ";
        visited[start] = true;
        BFS(start, visited, explored);
    }

private:
    void BFS(int start, vector<bool>& visited, vector<bool>& explored) {


        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[start][i] == 1 && !visited[i])
            {
                std::cout << i << " - ";
                visited[i] = true;
            }
        }

        explored[start] = true;

        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[start][i] == 1 && !explored[i])
            {
                BFS(i, visited, explored);
            }
        }
    }

    void DFS(int start, vector<bool>& visited) {
        std::cout << start << " - ";
        visited[start] = true;
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[start][i] == 1 && !visited[i]) {
                DFS(i, visited);
            }
        }
    }

    int numVertices;
    vector<vector<int>> adjMatrix;


};
