#pragma once


template <typename TNode>
class Nodes
{
public:
	Nodes(TNode data) :
		Next{ nullptr },
		Previous{ nullptr }
	{
		this->data = data;
	}
	/*~Nodes(){
		cout << "sa" << endl;
	}*/

	Nodes* Next;
	Nodes* Previous;
	TNode data;

};


template <typename TStack>
class Stack
{
public:
	Stack()
	{
		First = Top = nullptr;
		NodeCount = 0;
	}
	~Stack()
	{

		int CountOfNode = NodeCount;
		for (int i = 0; i < CountOfNode; i++)
		{
			std::cout << i << "-> silindi" << Top->data << std::endl;
			DeleteNode();
		}
	}


	//this function places given value on top of stack
	void Push(TStack Value)
	{
		Nodes<TStack>* NewNode = new Nodes<TStack>(Value);

		if (NodeCount == 0) // this means no elements in stack
		{
			First = NewNode;
			Top = NewNode;

			NodeCount++;
		}
		else
		{
			Top->Next = NewNode;
			NewNode->Previous = Top;
			Top = NewNode;
			NodeCount++;
		}
	}

	//remove top value of stack without returning
	void DeleteNode()
	{

		if (NodeCount == 0) return;

		else if (NodeCount == 1)
		{
			delete First;
			First = Top = nullptr;
			NodeCount--;
		}

		else
		{
			Top = Top->Previous;
			delete Top->Next;
			Top->Next = nullptr;
			NodeCount--;
		}

	}

	// removes top value from stack and returns it
	TStack Pop()
	{
		if (NodeCount == 0) {
			throw std::out_of_range("Stack has no element Pop(): error");
		}

		else if (NodeCount == 1)
		{
			TStack ValueToReturn = First->data;
			delete First;
			First = Top = nullptr;
			NodeCount--;
			return ValueToReturn;
		}

		else
		{
			TStack ValueToReturn = Top->data;
			Top = Top->Previous;
			delete Top->Next;
			Top->Next = nullptr;
			NodeCount--;
			return ValueToReturn;
		}
	}

	// returns top value from stack without removing it
	TStack Peek()
	{
		if (Top)
		{
			return Top->data;
		}

		throw std::out_of_range("Stack has no element Peek(): error");
	}

	// returns number of elements in stack
	int Size()
	{
		return NodeCount;
	}

	// returns true if stack is empty
	bool IsEmpty()
	{
		return (!First);
	}


private:

	Nodes<TStack>* First;

	int NodeCount;

	Nodes<TStack>* Top;

};



