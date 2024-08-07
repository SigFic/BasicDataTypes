#include<iostream>
#include<iomanip>
#include "BinaryTree.h"
#include "CircularQueue.h"
#include "Graph.h"
#include "Stack.h"


using namespace std;
#define QUEUESIZE 10

int main()
{
//#define STACK//to active preprocessor block
#ifdef STACK
    Stack<int>* StackINT = new Stack<int>();

    try
    {
        cout << "IsEmpty() : " << StackINT->IsEmpty() << endl;
        cout << endl;

        cout << "Adding 10, 15, 20" << endl;
        StackINT->Push(10);
        StackINT->Push(15);
        StackINT->Push(20);

        cout << "IsEmpty() : " << StackINT->IsEmpty() << endl;
        cout << "Peek():" << StackINT->Peek() << endl;
        cout << endl;

        cout << "1.Pop():" << StackINT->Pop() << endl;
        cout << "2.Pop():" << StackINT->Pop() << endl;
        cout << "3.Pop():" << StackINT->Pop() << endl;
        cout << "IsEmpty() : " << StackINT->IsEmpty() << endl;
        cout << endl;

        cout << "Adding 3 " << endl;
        StackINT->Push(3);
        cout << "Peek():" << StackINT->Peek() << endl;
        cout << "IsEmpty() : " << StackINT->IsEmpty() << endl;
    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

#endif // STACK


 //#define QUEUE //to active preprocessor block
#ifdef QUEUE

    int QueueSize{ 10 };
    CircularQueue<int, QUEUESIZE>* Queue = new CircularQueue<int, QUEUESIZE>();

    try
    {
        cout << "IsEmpty() :" << Queue->IsEmpty() << endl;
        cout << "Number of element :" << Queue->size() << endl;
        cout << "Adding 10, 20, 30, 40, 50" << endl;
        Queue->enqueue(10);
        Queue->enqueue(20);
        Queue->enqueue(30);
        Queue->enqueue(40);
        Queue->enqueue(50);
        cout << "Peek() :" << Queue->peek() << endl;
        cout << "IsEmpty() :" << Queue->IsEmpty() << endl;
        cout << "Number of element :" << Queue->size() << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1.dequeue() :" << Queue->dequeue() << endl;
        cout << "2.dequeue() :" << Queue->dequeue() << endl;
        cout << "3.dequeue() :" << Queue->dequeue() << endl;
        cout << "IsEmpty() :" << Queue->IsEmpty() << endl;
        cout << "Number of element :" << Queue->size() << endl;
        cout << "Peek() :" << Queue->peek() << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Adding 100" << endl;
        Queue->enqueue(100);
        cout << "IsEmpty() :" << Queue->IsEmpty() << endl;
        cout << "Number of element :" << Queue->size() << endl;
        cout << "Peek() :" << Queue->peek() << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "4.dequeue() :" << Queue->dequeue() << endl;
        cout << "5.dequeue() :" << Queue->dequeue() << endl;
        cout << "6.dequeue() :" << Queue->dequeue() << endl;
        cout << "IsEmpty() :" << Queue->IsEmpty() << endl;
        cout << "Number of element :" << Queue->size() << endl;
        cout << "Peek() :" << Queue->peek() << endl;


    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }

#endif // QUEUE


 //#define BINARYTREE //to active preprocessor block
#ifdef BINARYTREE

    BinaryTree<int>* Tree = new BinaryTree<int>();
    cout << "Node Count :" << Tree->GetNodeCount() << endl;
    cout << "Adding 20, 11, 40, 8, 19, 23, 54" << endl;
    Tree->Add(20);//root
    Tree->Add(11);
    Tree->Add(40);
    Tree->Add(8);
    Tree->Add(19);
    Tree->Add(23);
    Tree->Add(54);

    cout << "Node Count :" << Tree->GetNodeCount() << endl;

    cout << endl;
    cout << "In-Order Traverse :" << endl;
    Tree->InOrderTraverse();
    cout << endl;

    cout << endl;
    cout << "Pre-Order Traverse :" << endl;
    Tree->PreOrderTraverse();
    cout << endl;

    cout << endl;
    cout << "Post-Order Traverse :" << endl;
    Tree->PostOrderTraverse();
    cout << endl;

#endif // BINARYTREE


 //#define GRAPH //to active preprocessor block
#ifdef GRAPH
    Graph Graf(10);

    Graf.addEdge(0, 1);
    Graf.addEdge(0, 2);
    Graf.addEdge(1, 2);
    Graf.addEdge(1, 3);
    Graf.addEdge(1, 4);
    Graf.addEdge(5, 6);
    Graf.addEdge(5, 7);
    Graf.addEdge(5, 8);
    Graf.addEdge(7, 8);
    Graf.addEdge(8, 9);
    Graf.addEdge(4, 5);

    cout << "Print Graph(): " << endl;
    Graf.printGraph();
    cout << endl;
    cout << endl;
    cout << "BFS Traverse" << endl;
    Graf.BFS(5);
    cout << endl;
    cout << endl;
    cout << "DFS Traverse" << endl;
    Graf.DFS(5);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
#endif // GRAPH

    return 0;
}
