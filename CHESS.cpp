#include <iostream>
using namespace std;

int checkmate=1,checkmate2=1,turn=1,castB1=0,castB2=0,castW1=0,castW2=0,castallW=0,castallB=0;

//FUCTION TO DISPLAY BOARD
void display(int A[9][9], int n)
{   
	cout<<"___________________________________________________________________"<<endl ;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j <= 8; j++)
        {
            if(A[i][j] == 100 || A[i][j] == 101)
            {
                cout << " " << " | "<<"\t";
            }
            else if(i==8 && j>0)cout<<char(65+A[i][j])<<" | "<<"\t";
            else if(A[i][j] == 21)
            {
                wcout << "p" << " | "<<"\t";
            }
            else if(A[i][j] == 31)
            {
                wcout << "r" << " | "<<"\t";
            }
            else if(A[i][j] == 41)
            {
                wcout << "k" << " | "<<"\t";
            }
            else if(A[i][j] == 51)
            {
                wcout << "b" << " | "<<"\t";
            }
            else if(A[i][j] == 61)
            {
                wcout << "q" << " | "<<"\t";
            }
            else if(A[i][j] == 71)
            {
                wcout << "ki" << " | "<<"\t";
            }
            else if(A[i][j] == 20)
            {
                wcout << "P" << " | "<<"\t";
            }
            else if(A[i][j] == 30)
            {
                wcout << "R" << " | "<<"\t";
            }
            else if(A[i][j] == 40)
            {
                wcout << "K" << " | "<<"\t";
            }
            else if(A[i][j] == 50)
            {
                wcout << "B" << " | "<<"\t";
            }
            else if(A[i][j] == 60)
            {
                wcout << "Q" << " | "<<"\t";
            }
            else if(A[i][j] == 70)
            {
                wcout << "KI" << " | "<<"\t";
            }
            else if(A[i][j] == 102)
            {
                cout << "* | "<<"\t";
            }
            else if(A[i][j] == 103)
            {
                cout << "X | "<<"\t";
            }
            else
            {
                cout <<" "<<A[i][j] <<"|"<<"\t";
            }
        }
        cout <<endl<< "___________________________________________________________________"<<endl ;
    }
}
//FUNCTIONS DECLARATION
void queen(int A[9][9],int n,int y,int i,int j); //complete
void rook(int A[9][9],int n,int y,int i,int j); //complete
void bishop(int A[9][9],int n,int y,int i,int j); //complete
void king(int A[9][9],int n,int y1,int i,int j); //complete
void knight(int A[9][9],int n,int y1,int i,int j); //complete
void pawnW(int A[9][9],int n,int i,int j); //complete
void pawnB(int A[9][9],int n,int i,int j); //complete
void coordinate(int &x1,int &y1); //complete
void game(int X[9][9],int n); //complete
void game1(int X[9][9],int A[9][9],int n,int i,int j,int u); //complete
void piece(int X[9][9],int A[9][9],int n,int i,int j,int ask); //complete
void change(int X[9][9],int i,int j); //complete
void castling(int X[9][9],int A[9][9],int n); //complete

//coordinate intake functions
void coordinate(int X[9][9],int Z[9][9],int &x1, int &y1) 
{
    enum Letters {A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8, M = 1000};
    string s;
    Letters i;
    cout << "Enter coordinate of the piece : ";
    cin >> s;
    cout<<endl;
    switch (s[0]) {
        case 'A':
            i = A;
            break;
        case 'B':
            i = B;
            break;
        case 'C':
            i = C;
            break;
        case 'D':
            i = D;
            break;
        case 'E':
            i = E;
            break;
        case 'F':
            i = F;
            break;
        case 'G':
            i = G;
            break;
        case 'H':
            i = H;
            break;
        case 'a':
            i = A;
            break;
        case 'b':
            i = B;
            break;
        case 'c':
            i = C;
            break;
        case 'd':
            i = D;
            break;
        case 'e':
            i = E;
            break;
        case 'f':
            i = F;
            break;
        case 'g':
            i = G;
            break;
        case 'h':
            i = H;
            break;
        case 'Z':
        	y1=101;
        	x1=0;
        	castling(X,Z,9);
        	return;
        case 'z':
        	y1=101;
        	x1=0;
        	castling(X,Z,9);
        	return;
        default:
            cout << "Invalid input!" << endl;
            coordinate(X,Z,x1,y1);
            return;
    }
	switch (s[1]) {
        case '1':
            y1 = 1;
            break;
        case '2':
            y1 = 2;
            break;
        case '3':
            y1 = 3;
            break;
        case '4':
            y1 = 4;
            break;
        case '5':
            y1 = 5;
            break;
        case '6':
            y1 = 6;
            break;
        case '7':
            y1 = 7;
            break;
        case '8':
            y1 = 8;
            break;
        default:
            cout << "Invalid input!" << endl;
            coordinate(X,Z,x1,y1);
            return;
        }
            

    x1=i;
    y1=8-y1;
    return;
}

//additional function
//function to check piece and give its resp. movement
void piece(int X[9][9],int A[9][9],int n,int i,int j,int ask)
{
	switch (A[i][j]) 
	{
        case 21:
            pawnW(A,9,i,j);
            break;
        case 31:
            rook(A,9,0,i,j);
            break;
        case 41:
            knight(A,9,0,i,j);
            break;
        case 51:
            bishop(A,9,0,i,j);
            break;
        case 61:
            queen(A,9,0,i,j);
            break;
        case 71:
            king(A,9,0,i,j);
            break;
        case 20:
            pawnB(A,9,i,j);
            break;
        case 30:
            rook(A,9,1,i,j);
            break;
        case 40:
            knight(A,9,1,i,j);
            break;
        case 50:
            bishop(A,9,1,i,j);
            break;
        case 60:
            queen(A,9,1,i,j);
            break;
        case 70:
            king(A,9,1,i,j);
            break;
        default:
            cout << "Invalid input!" << endl;
            game(X,9);
            return;
    }
    if(ask==0)
    {
    	display(A,9);
    	return;
	}
    return;
}

//castling function includes proper rules for castling
void castling(int X[9][9],int A[9][9],int n)
{
	int i,j;
	if(turn%2==0)
	{
		if(castallB==0)
		{
			i=0;
			j=5;
		}
		else
		{
			cout<<"castling not possible. "<<endl;
			return;
		}
	}
	else
	{
		if(castallW==0)
		{
			i=7;
			j=5;
		}
		else
		{
			cout<<"castling not possible. "<<endl;
			return;
		}
	}
	cout<<"1 to castle for queen side "<<endl<<"2 to castle for king side: ";
	char l;
	cin>>l;
	cout<<endl;
	if(l=='1')
	{
		
		if(A[i][j-1]==100 && A[i][j-2]==100 && A[i][j-3]==100 && (A[i][j-4]==31||A[i][j-4]==30))
		{
			for(int x=0;x<n;x++)
			{
				for(int y=0;y<n;y++)
				{
					if(A[i][j]%2==1)
					{
						if (castW1==0)
						{
							if (A[x][y]%2==0 && A[x][y]<100 && A[x][y]>15)
							{
								piece(X,A,n,x,y,1);
							}
						}
						else
						{
							cout<<"rook already moved castling not possible "<<endl;
							return;
						}
					}
					else if(A[i][j]%2==0)
					{
						if (castB1==0)
						{
							if (A[x][y]%2==1 && A[x][y]<100 && A[x][y]>15)
							{
								piece(X,A,n,x,y,1);
							}
						}
						else 
						{
							cout<<"rook already moved castling not possible "<<endl;
							return;
						}
					}
				}
			}
			if(A[i][j-1]==100 && A[i][j-2]==100 && A[i][j-3]==100 && A[i][j]!=103 && A[i][j-4]!=103)
			{
				X[i][j-2]=X[i][j];
				X[i][j]=100;
				X[i][j-1]=X[i][j-4];
				X[i][j-4]=100;
				if(turn%2==0)
				{
					castallB++;
				}
				else
				{
					castallW++;
				}
			}
			else
			cout<<"CASTLING FROM QUEEN SIDE IS NOT POSSIBLE"<<endl;
			return;
		}
		else
		{
		cout<<"CASTLING FROM QUEEN SIDE IS NOT POSSIBLE"<<endl;
		return;
		}
	}
	else if(l=='2')
	{
		if(A[i][j+1]==100 && A[i][j+2]==100 )
		{
			for(int x=0;x<n;x++)
			{
				for(int y=0;y<n;y++)
				{
					if(A[i][j]%2==1)
					{
						if (castW2==0)
						{
							if (A[x][y]%2==0 && A[x][y]<100 && A[x][y]>15)
							{
								piece(X,A,n,x,y,1);
							}
						}
						else
						{
							cout<<"rook already moved castling not possible "<<endl;
							return;
						}
					}
					else if(A[i][j]%2==0)
					{
						if (castB2==0)
						{
							if (A[x][y]%2==1 && A[x][y]<100 && A[x][y]>15)
							{
								piece(X,A,n,x,y,1);
							}
						}
						else 
						{
							cout<<"rook already moved castling not possible "<<endl;
							return;
						}
					}
				}
			}
			if(A[i][j+1]==100 && A[i][j+2]==100 && A[i][j]!=103 && A[i][j+3]!=103)
			{
				X[i][j+2]=X[i][j];
				X[i][j]=100;
				X[i][j+1]=X[i][j+3];
				X[i][j+3]=100;
				if(turn%2==0)
				{
					castallB++;
				}
				else
				{
					castallW++;
				}
			}
			else
			{
			cout<<"CASTLING FROM KING SIDE IS NOT POSSIBLE"<<endl;
			return;
			}
		}
		else
		{
		cout<<"CASTLING FROM KING SIDE IS NOT POSSIBLE"<<endl;
		return;
		}
	}
	return;
}
//function to change the pawn piece at the end file
void change(int X[9][9],int i,int j)
{
	cout<<"ENTER DESIRED NUMBER TO CONVERT YOUR PAWN:"<<endl<<"1 TO QUEEN"<<endl<<"2 TO ROOK"<<endl<<"3 TO BISHOP"<<endl<<"4 TO KNIGHT: ";
	char o;
	cin>>o;
	cout<<endl;
	if(X[i][j]%2==0)
	{
		switch(o)
		{
			case '1':
				X[i][j]=60;
				break;
			case '2':
				X[i][j]=30;
			case '3':
				X[i][j]=50;
			case '4':
				X[i][j]=40;
			default:
				cout<<"wrong input try again: "<<endl;
				change(X,i,j);
				
		}
	}
	else
	{
		switch(o)
		{
			case '1':
				X[i][j]=61;
				break;
			case '2':
				X[i][j]=31;
			case '3':
				X[i][j]=51;
			case '4':
				X[i][j]=41;
			default:
				cout<<"wrong input try again: "<<endl;
				change(X,i,j);
		}
		
	}
}
//coordinate for main game framework
//(first part of game)
void game(int X[9][9],int n)
{
    int A[9][9];
    copy(&X[0][0],&X[0][0]+9*9,&A[0][0]); //creates a copy array to show moves
    int i,j;
    if(turn%2==0)
    {
    	cout<<endl<<"BLACK TO MOVE"<<endl;
    	display(X,n); //display of default board
    	cout<<endl;
    	cout<<"Enter (Z or z) for castling the king "<<endl;
    	coordinate(X,A,j,i); //calls fun. to intake piece to check its movement
    	if(i>100)
    	{
    		return;
		}
    	cout<<endl;
    	if(A[i][j]%2==0)
    	{
    		piece(X,A,9,i,j,0); //checks the piece and shows its movement
    		game1(X,A,n,i,j,1); // further game process    		
		}
		else 
		{
		cout<<"wrong piece , select again "<<endl;
		game(A,9);
		}
	}
	else
    {
    	cout<<endl<<"WHITE TO MOVE"<<endl;
    	display(X,n); //display of default board
    	cout<<endl;
    	cout<<"Enter (Z or z) for castling the king "<<endl;
    	coordinate(X,A,j,i); //calls fun. to intake piece to check its movement
    	if(i>100)
    	{
    		return;
		}
		cout<<endl;
    	if(A[i][j]%2!=0)
    	{
    		piece(X,A,9,i,j,0); //checks the piece and shows its movement
    		game1(X,A,n,i,j,1); // further game process    		
		}
		else 
		{
		cout<<"wrong piece , select again "<<endl;
		game(X,9);
		}
	}
    return;
}
//(second part of the game)
void game1(int X[9][9],int A[9][9],int n,int i,int j,int u) //incomplete
{
    int x,y,t1=1;
    char p,t;
    if(u==1)
	{
  		cout<<endl<<" 1 to move the piece "<<endl<<" 2 to see another piece movement: ";
  		cin>>p;
  		cout<<endl;
  	 	if(p=='1')
     	{
			coordinate(X,A,y,x);
       	 	if(A[x][y]==103||A[x][y]==102)
			{
				if(X[x][y]==71)
				{
					checkmate++; // to see white checkmate condition
				}
				else if(X[x][y]==70)
				{
					checkmate2++; // to see black checkmate condition
				}
				else if(A[i][j]==20||A[i][j]==21)
       		{
       		     if(x==0||x==7)
				    {
					       change(X,x,y);
				    }
       		}
				else if(A[i][j]==31 && i==7 && j==1)
				{
					castW1++;
				}
				else if(A[i][j]==31 && i==7 && j==9)
				{
					castW2++;
				}
				else if(A[i][j]==30 && i==0 && j==1)
				{
					castB1++;
				}
				else if(A[i][j]==30 && i==7 && j==9)
				{
					castB2++;
				}
				else if(A[i][j]==71 && i==7 && j==5)
				{
					castallW++;
				}
				else if(A[i][j]==70 && i==0 && j==5)
				{
					castallB++;
				}
        		X[x][y]=A[i][j];
       	 	X[i][j]=100;
       	 	display(X,9);
      	    }
       		else
       		{
       			while(t1==1)
				{
       				cout<<endl<<"wrong input"<<endl<<"1 to select the same piece movement"<<endl<<"2 to select another piece"<<endl;
       				cin>>t;
       				if(t=='1')
       				{
       					t1++;
       					game1(X,A,n,i,j,0);
       				}
       				else if(t=='2')
       				{
       					t1++;
					    game(X,n);
					}
				}
			}
      	}
		else if(p=='2')	 
		{
			game(X,n);
		}
 		else
		{
 			cout<<endl<<"wrong input"<<endl;
 			game1(X,A,n,i,j,1);
 		}
 	}
    else
	{
		coordinate(X,A,y,x);
        if(A[x][y]==102||A[x][y]==103)
		{
			if(X[x][y]==71)
			{
				checkmate++;
			}
			else if(X[x][y]==70)
			{
				checkmate2++;
			}
			else if(A[i][j]==20||A[i][j]==21)
       	{
       			if(x==0||x==7)
					{
					   	change(X,x,y);
					}
       	 }
       	     else if(A[i][j]==31 && i==7 && j==1)
				{
					castW1++;
				}
				else if(A[i][j]==31 && i==7 && j==9)
				{
					castW2++;
				}
				else if(A[i][j]==30 && i==0 && j==1)
				{
					castB1++;
				}
				else if(A[i][j]==30 && i==0 && j==9)
				{
					castB2++;
				}
				else if(A[i][j]==71 && i==7 && j==5)
				{
					castallW++;
				}
				else if(A[i][j]==70 && i==0 && j==5)
				{
					castallB++;
				}
        	X[x][y]=A[i][j];
       	 X[i][j]=100;
        	display(X,9);
        }
        else
        {
        	while(t1==1)
				{
       				cout<<endl<<"wrong input"<<endl<<"1 to select the same piece movement"<<endl<<"2 to select another piece"<<endl;
       				cin>>t;
       				if(t=='1')
       				{
       					t1++;
       					game1(X,A,n,i,j,0);
       				}
       				else if(t=='2')
       				{
       					t1++;
					    game(X,n);
					}
				}
 	    }
 	}
    
    return;
}

    
//pieces movement function
//queen movement
void queen(int A[9][9],int n,int y,int i,int j) //y should be =0 for white movement and =1 for black movement
{
    bool right = false;
    bool left = false;
    bool front = false;
    bool back = false;
    bool d1 = false;
    bool d2 = false;
    bool d3 = false;
    bool d4 = false;
    int x = 1;

    while(x < n) 
    {
        if(i+x < 8 && right==false)  //for right movement
        {
            if(A[i+x][j] < 100) 
            {
                if(A[i+x][j]%2!=y)
                right = true; 
                else{ 
                A[i+x][j]=103;
                right=true;
                }
            }
            else A[i+x][j] = 102; 
        }

        if(i-x >=0 && left==false) //for left movement
        {
            if(A[i-x][j] < 100)
            {
                if(A[i-x][j]%2!=y)
                left =true;
                else{
                A[i-x][j]=103;
                left=true;
                }
             }
            else A[i-x][j] = 102;
        }

        if(j+x < n && front==false) //for front movement
        {
            if(A[i][j+x] < 100)
            {
                if(A[i][j+x]%2!=y)
                front = true;
                else{
                    A[i][j+x]=103;
                    front=true;
                }
            }
            else A[i][j+x] = 102;
        }

        if(j-x > 0 && back==false) //for back movement 
        {
            if(A[i][j-x] < 100)
            {
                if(A[i][j-x]%2!=y)
                back = true;
                else{
                    A[i][j-x]=103;
                    back=true;
                }
            }
            else A[i][j-x] = 102;
        }
            
        if(i+x < 8 && j+x < n && d1==false) //for diagonal movement 
        {
             if(A[i+x][j+x] < 100)
             {
                 if(A[i+x][j+x]%2!=y)
                    d1 = true;
                 else
                 A[i+x][j+x]=103;
                 d1=true;
             }
        else A[i+x][j+x] = 102;
        }

        if(i+x < 8 && j-x > 0 && d2==false) //for diagonal movement
        {
             if(A[i+x][j-x] < 100){
                 if(A[i+x][j-x]%2!=y)
                    d2 = true;
                  else{
                  A[i+x][j-x]=103;
                  d2=true;
                  }
        }
        else A[i+x][j-x] = 102;
        }
        
        if (i-x >= 0 && j+x < n && d3==false) //for diagonal movement
		{
            if(A[i-x][j+x] < 100)
            {
                if(A[i-x][j+x]%2!=y)
                    d3 = true;
                else{
                A[i-x][j+x]=103;
                d3=true;
                }
            }
        else A[i-x][j+x] = 102;
        }

        if(i-x >= 0 && j-x > 0 && d4==false) //for diagonal movement
        {
            if(A[i-x][j-x] < 100){
                if(A[i+x][j+x]%2!=y)
                        d4 = true;
                else{
                    A[i-x][j-x]=103;
                    d4 =true;
                }
        }
        else A[i-x][j-x] = 102;
        }
        x++;
    }
        return;
}

//rook movement
void rook(int A[9][9],int n,int y,int i,int j) //y should be =1 for black movement and =0 for white movement
{
    bool right = false;
    bool left = false; 
    bool front = false;
    bool back = false;
    int x = 1;

    while(x < n) 
    {
        if(i+x < 8 && right==false) //for right movement
        {
            if(A[i+x][j] < 100) 
            {
                if(A[i+x][j]%2!=y)
                right = true; 
                else{ 
                A[i+x][j]=103;
                right=true;
                }
            }
            else A[i+x][j] = 102; 
        }

        if(i-x >=0 && left==false) //for left movement
        {
            if(A[i-x][j] < 100)
            {
                if(A[i-x][j]%2!=y)
                left =true;
                else{
                A[i-x][j]=103;
                left=true;
                }
             }
            else A[i-x][j] = 102;
        }

        if(j+x < n && front==false) //for forward movement
        {
            if(A[i][j+x] < 100)
            {
                if(A[i][j+x]%2!=y)
                front = true;
                else{
                    A[i][j+x]=103;
                    front=true;
                }
            }
            else A[i][j+x] = 102;
        }

        if(j-x > 0 && back==false) //for backward movement
        {
            if(A[i][j-x] < 100)
            {
                if(A[i][j-x]%2!=y)
                back = true;
                else{
                    A[i][j-x]=103;
                    back=true;
                }
            }
            else A[i][j-x] = 102;
        }
        
        x++;
    }
    return;
}

//bishop movement
void bishop(int A[9][9],int n,int y,int i,int j) // y shopul be =0 for white movement and =1 for black movement
{
    bool d1 = false;
    bool d2 = false;
    bool d3 = false;
    bool d4 = false;
    int x = 1;

    while(x < n) 
    {
        if(i+x < 8 && j+x < n && d1==false) //for diagonal movement
        {
             if(A[i+x][j+x] < 100)
             {
                 if(A[i+x][j+x]%2!=y)
                    d1 = true;
                 else
                 A[i+x][j+x]=103;
                 d1=true;
             }
        else A[i+x][j+x] = 102;
        }

        if(i+x < 8 && j-x > 0 && d2==false) //for diagonal movement
        {
             if(A[i+x][j-x] < 100){
                 if(A[i+x][j-x]%2!=y)
                    d2 = true;
                  else{
                  A[i+x][j-x]=103;
                  d2=true;
                  }
        }
        else A[i+x][j-x] = 102;
        }
        
        if (i-x >= 0 && j+x < n && d3==false) //for diagonal movement
		{
            if(A[i-x][j+x] < 100)
            {
                if(A[i-x][j+x]%2!=y)
                    d3 = true;
                else{
                A[i-x][j+x]=103;
                d3=true;
                }
            }
        else A[i-x][j+x] = 102;
        }

        if(i-x >= 0 && j-x > 0 && d4==false) //for diagonal movement
        {
            if(A[i-x][j-x] < 100){
                if(A[i+x][j+x]%2!=y)
                        d4 = true;
                else{
                    A[i-x][j-x]=103;
                    d4 =true;
                }
        }
        else A[i-x][j-x] = 102;
        }
        x++;
    }
        return;
}


//knight movement
void knight(int A[9][9], int n,int y1, int i, int j) //y1 should be =0 for white movement and =1 for black movement
{
    int moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for(int k=0; k<8; k++)
    {
        int x = i + moves[k][0];
        int y = j + moves[k][1];

        if(x >= 0 && x < 8 && y > 0 && y < n )
        {
             if(A[x][y]<100)
             {
                 if(A[x][x]%2==y1) 
				 {
                 A[x][y]= 103;
                 }
             }
             else
             A[x][y]=102;
        }
    }
    return;
}

//king movement
void king(int A[9][9], int n,int y1, int i, int j) //y1 should be =0 for white movement and =1 for black movement
{
    int moves[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1,-1}, {-1, 1}};

    for(int k=0; k<8; k++)
    {
        int x = i + moves[k][0];
        int y = j + moves[k][1];

        if(x >= 0 && x < 8 && y > 0 && y < n )
        {
             if(A[x][y]<100)
             {
             if(A[x][x]%2==y1) 
             A[x][y]= 103;
             }
             else
             A[x][y]=102;
        }
    }
    return;
}

//pawn movement for white piece
void pawnW(int A[9][9], int n, int i, int j)
{
    int moves[2][2] = { {-1,1}, {-1,-1} };

    int x = i -1;
    int y = j + 0;

        if (x >= 0 && x < n && y >= 0 && y < n && A[x][y] >= 100) A[x][y] = 102;
        for (int k = 0; k < 2; k++) {
            x = i + moves[k][0];
            y = j + moves[k][1];

            if (x >= 0 && x < n && y > 0 && y < n) {
                if (A[x][y] < 100 && A[x][y] % 2 == 0)A[x][y] = 103;
              }
        }
        
    if (i == 6) {
            x = i -2;
            y = j +0;
            if (x >= 0 && x < n && y >= 0 && y < n && A[x][y] >= 100) A[x][y] = 102;
        }
        return;
}

//pawn movement for black piece 
void pawnB(int A[9][9], int n, int i, int j)
{
    int moves[2][2] = { {1,1}, {1,-1} };

    int x = i +1;
    int y = j + 0;

    	if ( x < n && y < n && A[x][y] >= 100) A[x][y] = 102;
    	for (int k = 0; k < 2; k++) 
		{
            x = i + moves[k][0];
            y = j + moves[k][1];

            if (x < 8 && y > 0 && y < n) 
			{
                if (A[x][y] < 100 && A[x][y] % 2 != 0)A[x][y] = 103;
            }
        }
        
    	if (i == 1) 
		{
            x = i +2;
            y = j +0;
            if (x < n && y < n && A[x][y] >= 100) A[x][y] = 102;
        }
  
        return;
}
    


int main()
{
    int X1[9][9]={{8,30,40,50,60,70,50,40,30},{7,20,20,20,20,20,20,20,20},{6,100,100,100,100,100,100,100,100},{5,100,100,100,100,100,100,100,100},{4,100,100,100,100,100,100,100,100},{3,100,100,100,100,100,100,100,100},{2,21,21,21,21,21,21,21,21},{1,31,41,51,61,71,51,41,31},{101,0,1,2,3,4,5,6,7}};
    while(checkmate==1&&checkmate2==1)
    {
    	game(X1,9);
    	turn++;
    }
	if(checkmate==2)
	{
		cout<<"black won the game"<<endl;
	}
   else if(checkmate2==2)
   {
   	cout<<"white won the game "<<endl;
   }
}
