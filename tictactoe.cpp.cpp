#include <bits/stdc++.h>

using namespace std;

int board[9];
int turn;
int mul(int a, int b, int c);


int checkwin(int p)
{
	if (board[0] == p && board[1] == p && board[2] == p)
	{
		return p;
	}
	if (board[3] == p && board[4] == p && board[5] == p)
	{
		return p;
	}
	if (board[6] == p && board[7] == p && board[8] == p)
	{
		return p;
	}
	if (board[0] == p && board[3] == p && board[6] == p)
	{
		return p;
	}
	if (board[1] == p && board[4] == p && board[7] == p)
	{
		return p;
	}
	if (board[2] == p && board[5] == p && board[8] == p)
	{
		return p;
	}
	if (board[0] == p && board[4] == p && board[8] == p)
	{
		return p;
	}
	if (board[2] == p && board[4] == p && board[6] == p)
	{
		return p;
	}

	return 0;
}


int posswin(int p)
{
	int i;
	for (i = 0; i < 9; i++)
	{
		if (board[i] == 2)
		{

			if (mul(board[0], board[1], board[2]) == p * p * 2)
			{
				for (i = 0; i < 3; i++)
				{
					if (board[i] == 2)
						return i;
				}
			}

			if (mul(board[3], board[4], board[5]) == p * p * 2)
			{
				for (i = 3; i < 6; i++)
				{
					if (board[i] == 2)
						return i;
				}
			}

			if (mul(board[6], board[7], board[8]) == p * p * 2)
			{
				for (i = 6; i < 9; i++)
				{
					if (board[i] == 2)
						return i;
				}
			}

			if (mul(board[0], board[3], board[6]) == p * p * 2)
			{
				for (i = 0; i < 7; i += 3)
				{
					if (board[i] == 2)
						return i;
				}
			}

			if (mul(board[1], board[4], board[7]) == p * p * 2)
			{
				for (i = 1; i < 8; i += 3)
				{
					if (board[i] == 2)
						return i;
				}
			}

			if (mul(board[2], board[5], board[8]) == p * p * 2)
			{
				for (i = 2; i < 9; i += 3)
				{
					if (board[i] == 2)
						return i;
				}
			}

			if (mul(board[0], board[4], board[8]) == p * p * 2)
			{
				for (i = 0; i < 9; i += 4)
				{
					if (board[i] == 2)
						return i;
				}
			}

			if (mul(board[2], board[4], board[6]) == p * p * 2)
			{
				for (i = 2; i < 7; i += 4)
				{
					if (board[i] == 2)
						return i;
				}
			}
		}
	}

	return 0;
}



int mul(int a, int b, int c)
{
	return a * b * c;
}

int makemove()
{

	if (board[4] == 2)
		return 4;
	else
	{
		for (int i = 1; i < 8; i += 2)
		{
			if (board[i] == 2)
				return i;
		}
	}
}

void go(int n)
{
	if (turn % 2 == 0)
		board[n] = 5;
	else
		board[n] = 3;
}

//void incturn()


void print()
{
	cout << endl;

	if (turn % 2 == 0)
		cout << "Computer's move: " << endl;
	if (turn % 2 != 0)
		cout << "Enter your move: " << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "   ";
		if (board[3 * i + 0] == 3)
			cout << "X";
		else if (board[3 * i + 0] == 5)
			cout << "O";
		else
			cout << " ";
		cout << " | ";
		if (board[3 * i + 1] == 3)
			cout << "X";
		else if (board[3 * i + 1] == 5)
			cout << "O";
		else
			cout << " ";
		cout << " | ";
		if (board[3 * i + 2] == 3)
			cout << "X";
		else if (board[3 * i + 2] == 5)
			cout << "O";
		else
			cout << " ";
		cout << "   " << endl;

		if (i < 2)
		{
			cout << "---------------" << endl;
		}
	}

	cout << endl;
}

int main()
{
	int o;
	// cout<<"Turn: 1,2"<<endl;
	// cin>>turn;

	turn = 1;
	for (int i = 0; i < 9; i++)
	{
		board[i] = 2;
	}

	print();
turn1:
	cout << "Enter position to play: ";
	cin >> o;
	o--;
	if (board[o] != 2)
	{
		cout << "Position already filled!" << endl;
		goto turn1;
	}
	else
		go(o);
	if (checkwin(3) == 3)
	{
		cout << "Player wins!" << endl;
		return 0;
	}

	print();

	turn++;
	if (board[4] == 2)
		go(4);
	else
		go(0);
	if (checkwin(5) == 5)
	{
		print();
		cout << "Computer wins!" << endl;
		return 0;
	}

	print();

	turn++;
turn3:
	cout << "Enter position to play: ";
	cin >> o;
	o--;
	if (board[o] != 2)
	{
		cout << "Position already filled!" << endl;
		goto turn3;
	}
	else
		go(o);
	if (checkwin(3) == 3)
	{
		cout << "Player wins!" << endl;
		return 0;
	}

	print();

	turn++;
	if (posswin(3) != 0)
	{
		go(posswin(3));
	}
	else
		go(makemove());
	if (checkwin(5) == 5)
	{
		print();
		cout << "Computer wins!" << endl;
		return 0;
	}

	print();

	turn++;
turn5:
	cout << "Enter position to play: ";
	cin >> o;
	o--;
	if (board[o] != 2)
	{
	cout << "Position already filled!" << endl;
		goto turn5;
	}
	else
		go(o);
	if (checkwin(3) == 3)
	{
		cout << "Player wins!" << endl;
		return 0;
	}

	print();

	turn++;
	if (posswin(5) != 0)
	{
		go(posswin(5));
	}
	else if (posswin(3) != 0)
	{
		go(posswin(3));
	}
	else
		go(makemove());
	if (checkwin(5) == 5)
	{
		print();
	cout << "Position already filled!" << endl;
		return 0;
	}

	print();

	turn++;
turn7:
	cout << "Enter position to play: ";
	cin >> o;
	o--;
	if (board[o] != 2)
	{
		cout << "Position already filled!" << endl;
		goto turn7;
	}
	else
		go(o);
	//cout<<checkwin(3);
	if (checkwin(3) == 3)
	{
		cout << "Player wins!" << endl;
		return 0;
	}

	print();

	turn++;
	if (posswin(5) != 0)
	{
		go(posswin(5));
	}
	else if (posswin(3) != 0)
	{
		go(posswin(3));
	}
	else
		go(makemove());

	if (checkwin(5) == 5)
	{
		print();
		cout << "Computer wins!" << endl;
		return 0;
	}

	print();

	turn++;
turn9:
	cout << "Enter position to play: ";
	cin >> o;
	o--;
	if (board[o] != 2)
	{
	cout << "Position already filled!" << endl;
		goto turn9;
	}
	else
		go(o);
	//cout<<checkwin(3);
	if (checkwin(3) == 3)
	{
		cout << "Player wins!" << endl;
		return 0;
	}

	print();

	cout << "It's a draw !";

	return 0;
}
