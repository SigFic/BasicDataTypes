#pragma once

template <typename TQueue, unsigned int Size>
class CircularQueue
{
public:
	CircularQueue() :
		Front(0),
		Back(0),
		Count(0)
	{

	}
	~CircularQueue();

	void enqueue(TQueue data)
	{
		if (Count == Size)
		{
			throw std::exception("add(): There is no any empty cell , can't be added!");
		}

		else if (Count == 0)
		{
			Queue[Front] = data;
			Count++;
		}

		else
		{
			Back = (Back + 1) % Size;
			Queue[Back] = data;
			Count++;
		}

	}

	TQueue dequeue()
	{
		if (Count == 0)
		{
			throw std::exception("remove(): there is no element!");
		}

		else if (Count == 1)
		{
			int index = Front;
			Front = Back = (Front + 1) % Size;
			Count--;
			return Queue[index];
		}

		else
		{
			int index = Front;
			Front = (Front + 1) % Size;
			Count--;

			return Queue[index];
		}
	}

	TQueue peek()
	{
		if (Count == 0)
		{
			throw std::exception("Peek(): there is no element!");
		}
		else
		{
			return Queue[Back];
		}
	}

	int size()
	{
		return Count;
	}

	bool IsEmpty()
	{
		return (Count == 0);
	}



private:
	int Front;
	int Back;
	int Count;
	TQueue Queue[Size];

public:

	void PrintScreen()
	{
		for (int i = 0; i < Count; i++)
		{
			std::cout << " - " << Queue[(Front + i) % Size] << " - " << std::endl;
		}
	}
};

