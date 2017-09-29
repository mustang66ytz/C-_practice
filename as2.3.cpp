#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Board
{
public:
	Board();
	void SetCell(int player, int row, int col, char c);
	void Print(int player);
private:
	int size;
	vector<vector<char> > matrix;//(int, vector<char> (int));
};



Board::Board()
  :size(19),
    matrix(size,vector<char>(size))
{
	//matrix.resize(size,vector<char>(size));
	
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			matrix[i][j] = '.';
		}
	}
}



void Board::SetCell(int player, int row, int col, char c)
{
	int m = 19;
	int n = 19;
		
	matrix[row][col] = c;	
}



void Board::Print(int player)
{
	int m=19;
	int n=19;

	if(player == 0)
	{	
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
	
		}
	}
	if(player == 1)
	{	
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				cout<<matrix[m-i-1][n-j-1]<<" ";
			}
			cout<<endl;
	
		}
	}


}




int main()
{
	Board game;
	cout<<"This is the board" <<endl;
	int m =19, n = 19;
	int row, col;
	char c = '.';
	int player;

	game.Print(1);

	bool keepgo = 1;
	bool status = 1;

	cout<<"Please input your player number: "<<endl;
	cin>>player;


	while(keepgo)
	{
		cout<<"Enter the row number: "<<endl;
		cin>>row;
		cout<<"Enter the column number: "<<endl;
		cin>>col;
		cout<<"Enter the character you wanna change to: "<<endl;
		cin>>c;		
		game.SetCell(player, row, col, c);

		cout<<"board upadte..."<<endl;
		game.Print(player);
		cout<<"Enter '0' to finish or '1' to continue"<<endl;
		cin>>keepgo;

	}
	
}
