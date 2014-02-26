// Needleman Wunsch Algorithm for Amino Acids
// The BLOSUM50 matrix is hard coded into the program
// Code Written By Gerard Spivey


#include "headers.h"
#include "MatVal.h"
#include "NW.h"

using namespace std;

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
		
	
	
