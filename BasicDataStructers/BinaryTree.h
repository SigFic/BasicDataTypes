#pragma once
#pragma once

template <typename TNode>
class Node
{
public:
	Node(TNode Value) :
		Left{ nullptr },
		Right{ nullptr }
	{
		this->Data = Value;
	}
	~Node()
	{
		if (Left)
		{
			delete Left;
			Left = nullptr;
		}

		if (Right)
		{
			delete Right;
			Right = nullptr;
		}
	}

	Node* Left;
	Node* Right;
	TNode Data;
private:

};


template <typename TBinaryTree>
class BinaryTree
{
public:
	BinaryTree()
	{
		Root = nullptr;
		NodeCount = 0;
	}
	//~BinaryTree()
	void Add(TBinaryTree Value)
	{
		if (NodeCount <= 0)
		{
			Root = new Node<TBinaryTree>(Value);
			NodeCount++;
		}
		else
		{
			Add(Value, Root);
		}
	}

	void DeleteNode(TBinaryTree Value)
	{
		if (Root)
		{
			DeleteNode(Value, Root);
		}
	}

	inline bool IsEmpty()
	{
		return (NodeCount <= 0);
	}

	bool IsExist(TBinaryTree Value)
	{
		if (Root)
		{
			return IsExist(Value, Root);
		}
		else
		{
			false;
		}
	}

	inline int GetNodeCount()
	{
		return NodeCount;
	}

	TBinaryTree GetMax()
	{
		return GetMax(Root);
	}

	void PreOrderTraverse()
	{
		PreOrderTraverse(Root);
	}

	void PostOrderTraverse()
	{
		PostOrderTraverse(Root);
	}

	void InOrderTraverse()
	{
		InOrderTraverse(Root);
	}


private:
	TBinaryTree GetMax(Node<TBinaryTree>* CurrentNode)
	{
		if (CurrentNode)
		{
			if (CurrentNode->Right)
			{
				return GetMax(CurrentNode->Right);
			}

			return CurrentNode->Data;
		}

		throw std::out_of_range("out of Range GetMax()");
	}

	void Add(TBinaryTree Value, Node<TBinaryTree>* CurrentNode)
	{
		if (CurrentNode->Data > Value)
		{
			if (CurrentNode->Left)
			{
				Add(Value, CurrentNode->Left);
			}
			else
			{
				CurrentNode->Left = new Node<TBinaryTree>(Value);
				NodeCount++;
			}
		}

		else if (CurrentNode->Data < Value)
		{
			if (CurrentNode->Right)
			{
				Add(Value, CurrentNode->Right);
			}
			else
			{
				CurrentNode->Right = new Node<TBinaryTree>(Value);
				NodeCount++;
			}
		}
		else return;
	}

	bool IsExist(TBinaryTree Value, Node<TBinaryTree>* CurrentNode)
	{
		if (CurrentNode->Data > Value)
		{
			if (CurrentNode->Left)
			{
				return IsExist(Value, CurrentNode->Left);
			}
			return false;
		}

		else if (CurrentNode->Data < Value)
		{
			if (CurrentNode->Right)
			{
				return IsExist(Value, CurrentNode->Right);
			}

			return false;
		}
		else
		{
			return true;
		}
	}

	void DeleteNode(TBinaryTree Value, Node<TBinaryTree>*& CurrentNode)
	{
		if (!CurrentNode) return;

		if (CurrentNode->Data > Value)
		{
			DeleteNode(Value, CurrentNode->Left);
		}

		else if (CurrentNode->Data < Value)
		{
			DeleteNode(Value, CurrentNode->Right);
		}

		else
		{
			if (CurrentNode->Left && CurrentNode->Right)
			{
				CurrentNode->Data = GetMax(CurrentNode->Left);
				DeleteNode(CurrentNode->Data, CurrentNode->Left);
			}
			else
			{
				Node<TBinaryTree>* NodeToDelete = CurrentNode;

				if (CurrentNode->Right == nullptr)
				{
					CurrentNode = CurrentNode->Left;
				}

				else if (CurrentNode->Left == nullptr)
				{
					CurrentNode = CurrentNode->Right;
				}

				else
				{
					CurrentNode = nullptr;
				}

				delete NodeToDelete;
				NodeCount--;
			}
		}
	}

	void PreOrderTraverse(Node<TBinaryTree>* CurrentNode)
	{
		if (CurrentNode)
		{
			std::cout << CurrentNode->Data << " - ";

			if (CurrentNode->Left)
			{
				PreOrderTraverse(CurrentNode->Left);
			}

			if (CurrentNode->Right)
			{
				PreOrderTraverse(CurrentNode->Right);
			}
		}
	}

	void PostOrderTraverse(Node<TBinaryTree>* CurrentNode)
	{
		if (CurrentNode)
		{
			if (CurrentNode->Left)
			{
				PostOrderTraverse(CurrentNode->Left);
			}

			if (CurrentNode->Right)
			{
				PostOrderTraverse(CurrentNode->Right);
			}

			std::cout << CurrentNode->Data << " - ";
		}
	}

	void InOrderTraverse(Node<TBinaryTree>* CurrentNode)
	{
		if (CurrentNode)
		{
			if (CurrentNode->Left)
			{
				InOrderTraverse(CurrentNode->Left);
			}

			std::cout << CurrentNode->Data << " - ";

			if (CurrentNode->Right)
			{
				InOrderTraverse(CurrentNode->Right);
			}
		}
	}

	Node<TBinaryTree>* Root;
	int NodeCount;
public:
};
