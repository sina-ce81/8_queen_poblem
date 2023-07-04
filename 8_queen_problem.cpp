#include <iostream>
using namespace std;
class Item {
public:
	int data;
	Item* next;
	Item()
	{
		data = 0;
		next = NULL;
	}
};
class Stack
{
	Item* top;
public:
	Stack();
	~Stack();
	bool isempty();
	void push(int);
	int pop();
private:

};

Stack::Stack()
{
	top = NULL;
}
Stack::~Stack()
{
}
bool Stack::isempty()
{
	if (top == NULL)
		return true;
	else
		return false;
}
void Stack::push(int data)
{
	Item* node = new Item();
	node->data = data;
	if (isempty())
	{
		node->next = NULL;
		top = node;
	}
	else {
		node->next = top;
		top = node;
	}
}
int Stack::pop()
{
	int data;
	Item* del = top;
	data = top->data;
	top = top->next;
	delete del;
	return data;
}


bool Check(bool b[8][8], int row, int col)
{
	for (int i = 0; i < 8; i++)
	{
		if (b[row][i] || b[i][col]) { return true; }
	}

	for (int r = row, c = col; r < 8 && c >= 0; r++, c--)
	{
		if (b[r][c]) { return true; }
	}

	for (int r = row, c = col; r < 8 && c < 8; r++, c++)
	{
		if (b[r][c]) { return true; }
	}

	for (int r = row, c = col; r >= 0 && c >= 0; r--, c--)
	{
		if (b[r][c]) { return true; }
	}

	for (int r = row, c = col; r >= 0 && c < 8; r--, c++)
	{
		if (b[r][c]) { return true; }
	}

	return false;
}

int main()
{

	bool b[8][8];

	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			b[r][c] = false;
		}
	}
	int row = 0, col = 0;
	int queens = 0;
	Stack rows, cols;
	rows.push(row);
	cols.push(col);
	b[row][col] = true;
	row++;
	while (queens < 7)
	{
		if (!Check(b, row, col))
		{
			queens++;
			rows.push(row);
			cols.push(col);
			b[row][col] = true;
			row++;
			col = 0;
		}
		else {
			col++;
			if (col > 7) {
				row = rows.pop();
				col = cols.pop();
				b[row][col] = false;
				col++;
				queens--;
			}
		}
	}
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (b[r][c] == true)
			{

				cout << "vazir" << "(" << r << "):" << "(" << r << "," << c << ")" << endl;

			}
		}
	}

	return 0;
}