#include<iostream>
using namespace std;
char space [3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
char token='x'; 
bool tie=false;
 string n1="";
 string n2="";
void functionone(){
	
	cout<<"   |      |"  <<endl;
	cout<<" "<<space[0][0]<<" | "<<space[0][1]<<"    |  "<<space[0][2]<<endl;
	cout<<"___|______|___"<<endl;
	cout<<"   |      |"  <<endl;
	cout<<" "<<space[1][0]<<" | "<<space[1][1]<<"    |  "<<space[1][2]<<endl;
	cout<<"   |      |"  <<endl;
	cout<<"___|______|___"<<endl;
	cout<<" "<<space[2][0]<<" | "<<space[2][1]<<"    |  "<<space[2][2]<<endl;
	cout<<"   |      | " <<endl;
	cout<<"   |      |"  <<endl;
}

void functiontwo(){
   
	int digit;
	if(token=='x')
	{
		cout<<n1<<" "<<"Please enter ";
		cin>>digit;
	}
	if(token=='0')
	{ 
		cout<<n2<<" "<<"Please enter ";
		cin>>digit;
	}
	
	if(digit==1)
	{
		row=0;
		column=0;
	}
		if(digit==2)
	{
		row=0;
		column=1;
	}
		if(digit==3)
	{
		row=0;
		column=2;
	}
		if(digit==4)
	{
		row=1;
		column=0;
	}
		if(digit==5)
	{
		row=1;
		column=1;
	}
		if(digit==6)
	{
		row=1;
		column=2;
	}
		if(digit==7)
	{
		row=2;
		column=0;
	}
		if(digit==8)
	{
		row=2;
		column=1;
	}
		if(digit==9)
	{
		row=2;
		column=2;
	}

	
	else if(digit<1 || digit>9)
	{
		cout<<"Invalid ! "<<endl;
	}

	if(token=='x' && space[row][column] !='x' && space[row][column]!='0')
	{
	   space[row][column]='x';
	   token='0';
	}
    else if(token=='0' && space[row][column]!='x' && space[row][column]!='0')
	{
	   space[row][column]='0';
	   token='x';
	}
	else
	{
		cout<<"There game is draw! Try for one more time"<<endl;
		functiontwo();
	}
	functionone();
}
	bool functionthree()
	{
		for(int i=0;i<3;i++)
		{
			if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
		    return true;
		}
		if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
		{
			return true;
		}
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(space[i][j] != 'x' && space[i][j] != '0')
				{
					return false;
				}
			}
		}
		tie=true;
		return false;
	}
	
int main()
{
	
	cout << "\t\t\t\t +----------------------------------+ " << endl;
    cout << "\t\t\t\t ¦         Welcome to the           ¦ " << endl;
    cout << "\t\t\t\t ¦        Tic Tac Toe Game          ¦ " << endl;
    cout << "\t\t\t\t +----------------------------------+ " << endl;
    cout<<endl;
	cout<<"Enter the name of the first player :";
	cin>>n1;
	cout<<"Enter the name of the second player :";
	cin>>n2;
	cout<<n1<<" is player1 so he/she will play first"<<endl;
	cout<<n2<<" is player2 one so he/she will play second"<<endl;
	
	while(!functionthree())
	{
	functionone();
	functiontwo();
	functionthree();	
	}
	
	if(token=='x' && tie==false)
	{
		cout<<n2<<" "<<"Wins the Game"<<endl;
	}
	else if(token=='0' && tie==false)
	{
		cout<<n1<<" "<<"Wins the Game"<<endl;
	}
	else if(token!='0' && tie!=false)
	{
		cout<<"The game is draw!"<<endl;
		functiontwo();
	}
	return 0;
	
}

	
	
	


