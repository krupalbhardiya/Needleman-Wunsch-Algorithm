#include "headers.h"
#include "error.h"

using namespace std;

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
		
