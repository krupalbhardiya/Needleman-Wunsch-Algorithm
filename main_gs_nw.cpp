#include <iostream>
#include <string>
using namespace std;
int MatVal(int, int);
int error();
void NW (int, int, int, int, int, int,int, string, string,int);

int cv = 0;

int main()
{
	string varA;
	string varB; 
	int L1;
	int L2;
	int x;
	int y;
	int u;
	int z;
	int m;
	int Value;
	int max;
	int gap;
	char temp;
	
  cout << "Welcome to Needleman Wunsch Program for Amino Acids" << endl;   
  cout << "Enter the first sequence:" << endl;
  cout << "Valid letters are A,R,N,D,C,Q,E,G,H,I,L,K,M,F,P,S,T,W,Y,V :" << endl; 
  
  cin >> varA;
  //cout << varA << endl;
  
  cout << "Enter the second sequence:" << endl;
  cout << "Valid letters are A,R,N,D,C,Q,E,G,H,I,L,K,M,F,P,S,T,W,Y,V :" << endl; 
  cin >> varB;
  //cout << varB << endl;

  cout << varA.size() << endl;
  cout << varB.size() << endl;
  
  cout << "Enter the gap penalty:" << endl;
  cin >> gap;
  
  L1 = varA.size();
  L2 = varB.size();
  
  char* Lup1 = NULL;  
  Lup1 = new char[L1+1]; 
  
  for (u=0; u<L1; u++) 
  {
	  temp = varA[u];
      Lup1[u+1] = temp;   
	//  cout << Lup1[u+1] << endl;
  }
	
  char* Lup2 = NULL;   
  Lup2 = new char[L2+1]; 
  
  
  for (z=0; z<L2; z++) 
  {
      temp = varB[z]; 
	  Lup2[z+1] = temp;
	//  cout << Lup2[z+1] << endl;
  }
  Lup1[0] = '*';
  Lup2[0] = '*';
 // cout << Lup1[0] << endl;
 // cout << Lup2[0] << endl;
  
  //Find max value of L1 and L2 and store it into max ******************************************************
  if (L1 >= L2)
  {
	max = L1;
  }
  else
  {
	max = L2;
  }
 
//   cout << "Matrix Check" << endl;
//  cout << MatVal('*','h')<< endl;
 
 
	//Value = MatVal (varA[0],varB[0]);
	
	//cout << varA[0] << endl;
	//cout << varB[0] << endl;
	//cout << int(varA[0]) << endl;
	//cout << int(varB[0]) << endl;
	//cout << Value;
	
	int finish = 0;
	
	cout << "These Are the Sequence and Traceback matricies:" << endl;
	
	 for( y = 0; y <= L2; y++ )
        {
		
		for( x = 0; x <= L1; x++ )
			{
			Value = MatVal(Lup1[x],Lup2[y]);
			NW(x,y,L1,L2,Value,gap,max,varA,varB,finish);			
			}
			cout << endl;
		}
	finish  = 1;
	NW(x,y,L1,L2,Value,gap,max,varA,varB,finish);
		
		return 0;
	}
		

	
		
void NW(int i, int j, int L1, int L2, int Value, int gap2, int max, string varA, string varB,int finish)
{
	static int **DA = NULL;
	static int **TB = NULL;
	
	//cout << "Value=" << Value<<endl;
	
	//--------------------------------------------------------------
	if (finish == 0)
	{
	
	if ((i == 0) && (j == 0))
	{		
		DA = new int* [L1+1];
		TB = new int* [L1+1];
		
		for(int f=0;f<L1+1;f++){
			DA[f]=new int[L2+1];
			TB[f]=new int[L2+1];
		}
		
		for(int f=0;f<L1+1;f++)
		{
			for(int g=0;g<L2+1;g++)
			{
				DA[f][g] = 0;
				TB[f][g] = 0;
			}
		}
	}
		
	if( DA == NULL ){
		cout << "Error using DA without initialization" << endl;
	}


	
	//---------------------------------------------------------------
	
	
	//Function to Check Diagnal Value   *************************************************
	int var;
	int diag;
	int up;
	int left;

	
	if (i == 0 && j == 0)
	{		
		diag = 0;
	}

	
	else
	{	
		if (i == 0 || j == 0)
		{		
			diag = 0;
		}

		else
		{
			var = DA[i-1][j-1];	
			diag = var + Value;	
		}

		if (i == 0)
		{		
			diag = -500;
		}
		if (j == 0)
		{		
			diag = -500;
		}
		
		
	}	
	
	// cout << diag << endl;
	// cout << gap2 << endl;
	
	// Function to check left  ***********************************************************
	if (i == 0) 
	{
		//left = 0 - gap2 ;
		left = -5000 ;
	}
	else
	{	
		var = DA[i-1][j];
		left = var - gap2;
	}		
	//Function to check up		**********************************************************
	
	if (j == 0) 
	{
		//up = 0 - gap2 ;
		up = -5000 ;
	}
	else
	{	
		var = DA[i][j-1];
		up = var - gap2;
		
	}	
	
	// Function that finds the max value from the above three functions and enterers *************************************************
	// The value into the DA matrix
	// The location into the TB matrix
	// int location;
	
	
    if ((diag >= up) && (diag >= left))
    {
      DA[i][j] = diag;
	  TB[i][j] = 1;
	}
    else if ((up >= diag) && (up >= left))
    {
      DA[i][j] = up;
	  TB[i][j] = 2;
	}
    else if ((left >= diag) && (left >= up))
    {
      DA[i][j] = left;
	  TB[i][j] = 3;
	}
	
	
	cout << DA[i][j] << "	";
	cout << TB[i][j] << "      ";
	
	}
	
// *********************************************************************************
  // Traceback

	if (finish == 1)
	{
	
int LocA = L1;
int LocB = L2;
int h;
int m;
int p;
int spot;
int location;
location = max+1;
int max2;
max2 =max;
char* RegB = NULL;
char* RegA = NULL;

RegA = new char[location]; 
RegB = new char[location]; 

		for( m = 0; m < max; m++ )
        {
		
				spot = TB[LocA][LocB];
				
				if (spot == 1)
				{
				RegA[max2-1] = varA[LocA-1];
				RegB[max2-1] = varB[LocB-1];
				LocA--;
				LocB--;
				max2--;
				}
				
				if (spot == 2)
				{
				RegA[max2-1] = '-';
				RegB[max2-1] = varB[LocB-1];
				LocB--;
				max2--;
				}
	
				if (spot == 3)
				{
				RegA[max2-1] = varA[LocA-1];
				RegB[max2-1] = '-';
				LocA--;
				max2--;
				}
			
			
		}
 
	for(h=0;h < max;h++)
	{
		cout << RegA[h];
	}
	
	cout << endl;
	
	for(h=0;h < max;h++)
	{
		cout << RegB[h];
	}
	
	int NWscore;
	NWscore = 0;
	int temp2;
	for(h=0;h < max;h++)
	{
		temp2 = MatVal(RegA[h], RegB[h]);
		NWscore = NWscore + temp2;
	}
	cout << endl <<"The Needleman Wunsch Score is: " << NWscore ;
	}
	
}
	
	
int error()
{
  cout << "You have entered an invalid letter" << endl;   
  cout << "Valid letters are A,R,N,D,C,Q,E,G,H,I,L,K,M,F,P,S,T,W,Y,V :" << endl; 
  cout << "-----------------------------------------------------------" << endl; 
  cout << "-----------------------------------------------------------" << endl; 
  main();
		
	return 0;    
	}
	
	
	
	
int MatVal(int am1, int am2)
{

	int SymA;
	int SymB;
								   
	int sub[21][21] = {  { 4, -1, -2, -2,  0, -1, -1,  0, -2, -1, -1, -1, -1, -2, -1,  1,  0, -3, -2,  0, 0}, 
					     {-1,  5,  0, -2, -3,  1,  0, -2,  0, -3, -2,  2, -1, -3, -2, -1, -1, -3, -2, -3, 0},
					     {-2,  0,  6,  1, -3,  0,  0,  0,  1, -3, -3,  0, -2, -3, -2,  1,  0, -4, -2, -3, 0}, 
					     {-2, -2,  1,  6, -3,  0,  2, -1, -1, -3, -4, -1, -3, -3, -1,  0, -1, -4, -3, -3, 0}, 
					     { 0, -3, -3, -3,  9, -3, -4, -3, -3, -1, -1, -3, -1, -2, -3, -1, -1, -2, -2, -1, 0}, 
				         {-1,  1,  0,  0, -3,  5,  2, -2,  0, -3, -2,  1,  0, -3, -1,  0, -1, -2, -1, -2, 0},
					     {-1,  0,  0,  2, -4,  2,  5, -2,  0, -3, -3,  1, -2, -3, -1,  0, -1, -3, -2, -2, 0},  
					     { 0, -2,  0, -1, -3, -2, -2,  6, -2, -4, -4, -2, -3, -3, -2,  0, -2, -2, -3, -3, 0}, 
					     {-2,  0,  1, -1, -3,  0,  0, -2,  8, -3, -3, -1, -2, -1, -2, -1, -2, -2,  2, -3, 0}, 
						 {-1, -3, -3, -3, -1, -3, -3, -4, -3,  4,  2, -3,  1,  0, -3, -2, -1, -3, -1,  3, 0}, 
						 {-1, -2, -3, -4, -1, -2, -3, -4, -3,  2,  4, -2,  2,  0, -3, -2, -1, -2, -1,  1, 0}, 
						 {-1,  2,  0, -1, -3,  1,  1, -2, -1, -3, -2,  5, -1, -3, -1,  0, -1, -3, -2, -2, 0}, 
						 {-1, -1, -2, -3, -1,  0, -2, -3, -2,  1,  2, -1,  5,  0, -2, -1, -1, -1, -1,  1, 0}, 
						 {-2, -3, -3, -3, -2, -3, -3, -3, -1,  0,  0, -3,  0,  6, -4, -2, -2,  1,  3, -1, 0}, 
						 {-1, -2, -2, -1, -3, -1, -1, -2, -2, -3, -3, -1, -2, -4,  7, -1, -1, -4, -3, -2, 0},  
						 { 1, -1,  1,  0, -1,  0,  0,  0, -1, -2, -2,  0, -1, -2, -1,  4,  1, -3, -2, -2, 0},  
						 { 0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -2, -1,  1,  5, -2, -2,  0, 0},  
						 {-3, -3, -4, -4, -2, -2, -3, -2, -2, -3, -2, -3, -1,  1, -4, -3, -2, 11,  2, -3, 0}, 
						 {-2, -2, -2, -3, -2, -1, -2, -3,  2, -1, -1, -2, -1,  3, -3, -2, -2,  2,  7, -1, 0},  
						 { 0, -3, -3, -3, -1, -2, -2, -3, -3,  3,  1, -2,  1, -1, -2, -2,  0, -3, -1,  4, 0},
						 { 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0}}; 
		
		switch (am1)
    {
         case 'A':
            SymA = 0;
            break;
         case 'a':
            SymA = 0;
            break;
			
		 case 'R':
            SymA = 1;
            break;
         case 'r':
            SymA = 1;
            break;
			
		case 'N':
            SymA = 2;
            break;
         case 'n':
            SymA = 2;
            break;
			
		 case 'D':
            SymA = 3;
            break;
         case 'd':
            SymA = 3;
            break;
			
		 case 'C':
            SymA = 4;
            break;
         case 'c':
            SymA = 4;
            break;
			
		case 'Q':
            SymA = 5;
            break;
         case 'q':
            SymA = 5;
            break;
			
		 case 'E':
            SymA = 6;
            break;
         case 'e':
            SymA = 6;
            break;
			
		 case 'G':
            SymA = 7;
            break;
         case 'g':
            SymA = 7;
            break;
			
		case 'H':
            SymA = 8;
            break;
         case 'h':
            SymA = 8;
            break;
			
		case 'I':
            SymA = 9;
            break;
         case 'i':
            SymA = 9;
            break;
			
		 case 'L':
            SymA = 10;
            break;
         case 'l':
            SymA = 10;
            break;
			
		case 'K':
            SymA = 11;
            break;
         case 'k':
            SymA = 11;
            break;
		
		 case 'M':
            SymA = 12;
            break;
         case 'm':
            SymA = 12;
            break;
			
		 case 'F':
            SymA = 13;
            break;
         case 'f':
            SymA = 13;
            break;
			
		case 'P':
            SymA = 14;
            break;
         case 'p':
            SymA = 14;
            break;
			
		case 'S':
            SymA = 15;
            break;
         case 's':
            SymA = 15;
            break;
			
		 case 'T':
            SymA = 16;
            break;
         case 't':
            SymA = 16;
            break;
			
		case 'W':
            SymA = 17;
            break;
         case 'w':
            SymA = 17;
            break;
			
		 case 'Y':
            SymA = 18;
            break;
         case 'y':
            SymA = 18;
            break;
			
		 case 'V':
            SymA = 19;
            break;
         case 'v':
            SymA = 19;
            break;
			
		case '*':
            SymA = 20;
            break;
			
		case '-':
            return -10;
            break;
	
         default:
            error();
    }
	
	
	switch (am2)
    {
         case 'A':
            SymB = 0;
            break;
         case 'a':
            SymB = 0;
            break;
			
		 case 'R':
            SymB = 1;
            break;
         case 'r':
            SymB = 1;
            break;
			
		case 'N':
            SymB = 2;
            break;
         case 'n':
            SymB = 2;
            break;
			
		 case 'D':
            SymB = 3;
            break;
         case 'd':
            SymB = 3;
            break;
			
		 case 'C':
            SymB = 4;
            break;
         case 'c':
            SymB = 4;
            break;
			
		case 'Q':
            SymB = 5;
            break;
         case 'q':
            SymB = 5;
            break;
			
		 case 'E':
            SymB = 6;
            break;
         case 'e':
            SymB = 6;
            break;
			
		 case 'G':
            SymB = 7;
            break;
         case 'g':
            SymB = 7;
            break;
			
		case 'H':
            SymB = 8;
            break;
         case 'h':
            SymB = 8;
            break;
			
		case 'I':
            SymB = 9;
            break;
         case 'i':
            SymB = 9;
            break;
			
		 case 'L':
            SymB = 10;
            break;
         case 'l':
            SymB = 10;
            break;
			
		case 'K':
            SymB = 11;
            break;
         case 'k':
            SymB = 11;
            break;
		
		 case 'M':
            SymB = 12;
            break;
         case 'm':
            SymB = 12;
            break;
			
		 case 'F':
            SymB = 13;
            break;
         case 'f':
            SymB = 13;
            break;
			
		case 'P':
            SymB = 14;
            break;
         case 'p':
            SymB = 14;
            break;
			
		case 'S':
            SymB = 15;
            break;
         case 's':
            SymB = 15;
            break;
			
		 case 'T':
            SymB = 16;
            break;
         case 't':
            SymB = 16;
            break;
			
		case 'W':
            SymB = 17;
            break;
         case 'w':
            SymB = 17;
            break;
			
		 case 'Y':
            SymB = 18;
            break;
         case 'y':
            SymB = 18;
            break;
			
		 case 'V':
            SymB = 19;
            break;
         case 'v':
            SymB = 19;
            break;
		
		case '*':
            SymB = 20;
            break;
			
		case '-':
            return -10;
            break;
		
         default:
            error();
    }
		

	return sub[SymA][SymB];    
	}
		