#include "headers.h"
#include "MatVal.h"
using namespace std;

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
	cout << endl <<"The Needleman Wunsch Score is: " << NWscore << endl;
	}
	
}
	
	
