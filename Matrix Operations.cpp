//============================================================================
// Name        : Main.cpp
// Author      : Mona Roshdibenam.
// Copyright   : October 2018
// Description : Object Oriented ProgrammingI by C++     -Fall 2018
//============================================================================

#include <iostream>
#include<conio.h>
#include<iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

class matrix
{
	
 int a[10][10];

 int row;
 int col;
 
 public:
  		void read(int r, int c);
  		void read1(int r, int c);
  		void display();
  		matrix multiply (matrix m1, matrix m2);
  		matrix addition (matrix m1, matrix m2);
  		matrix subtraction (matrix m1, matrix m2);
  		matrix TransposeMatrix (matrix m);
  		
  		void swapp(matrix m1, int arr[10][10]);
  		
  		double det(int arr[10][10], int row);
  		void minor(int b[10][10], int arr[10][10], int i, int row);
  		
  		void cofactor(int arr[10][10], double inv[10][10], int row, double det);
  		void inverse(int arr[10][10], double inv[10][10], int row, double det);
  		void transpose(float c[10][10], double inv[10][10], int row, double det);
  		void Menu();
  		  
		void setValue(int r,int c) //setter
		{
		  row=r;
		  col=c;
		}
		int getrow() 
		{
			return row;
		}
		int getcol() 
		{
			return col;
		}

};
//==============================================================
//     Reading matrix default
//==============================================================
void matrix :: read1(int r, int c)
{
	 row=r;
	 col=c;
	 
	 for(int i=0; i<r; i++)
	 	for(int j=0; j<c; j++)
		 {
		 	
		 	a[i][j]=1;
		
		 }
		 a[0][3]=-1;
		  a[1][2]=-1;
		  a[2][1]=-1;
		  a[3][0]=-1;
} 
//==============================================================
//     Reading matrixes
//==============================================================
void matrix :: read(int r, int c)
{
	 row=r;
	 col=c;
	 int count=1;
	 for(int i=0; i<r; i++)
	 	for(int j=0; j<c; j++)
		 {
		 	//a[i][j]=count;
		 	//count++;
		  cout<<"A["<<i<<"]["<<j<<"] : ";
		  cin>>a[i][j];
		 }
} 
//==============================================================
//     Printing matrixes
//==============================================================
void matrix :: display()
{
 	for(int i=0; i<row; i++)
 	{
 		for (int j=0; j< col; j++)
  			cout<<setw(4)<<a[i][j];
  		cout<<"\n";
 	}
}
//==============================================================
//     Swapp function
//==============================================================
void matrix :: swapp(matrix m1, int arr[10][10])
{
 	for(int i=0; i<row; i++)
 	{
 		for (int j=0; j< col; j++)
 			arr[i][j]=m1.a[i][j];
 	}
}
//==============================================================
//     Multiplying two matrixes
//==============================================================
matrix matrix :: multiply (matrix m1, matrix m2)
{
 	matrix temp;
 	temp.row=m1.row;
 	temp.col=m2.col;
 	
 	for(int i=0; i<temp.row; i++)
 	{
 		for(int j=0; j<temp.col; j++)
	 	{
	  		temp.a[i][j]=0;
	  		{            
			  for (int k=0; k<m1.col; k++)
	    			temp.a[i][j] += m1.a[i][k]*m2.a[k][j];
	  		}
	 	}
 	}
 	return temp;
}
//==============================================================
//     Adding two Matrixes
//==============================================================
matrix matrix :: addition (matrix m1, matrix m2)
{
 	matrix temp;
 	temp.row=m1.row;
 	temp.col=m1.col;
 	
 	for(int i=0; i<temp.row; i++)
 		for(int j=0; j<temp.col; j++)
	  		temp.a[i][j]= m1.a[i][j]+m2.a[i][j];
 	return temp;
}
//==============================================================
//     Subtracting two Matrixes
//==============================================================
matrix matrix :: subtraction (matrix m1, matrix m2)
{
 	matrix temp;
 	temp.row=m1.row;
 	temp.col=m1.col;
 	
 	for(int i=0; i<temp.row; i++)
 		for(int j=0; j<temp.col; j++)
	  		temp.a[i][j]= m1.a[i][j]-m2.a[i][j];
 	return temp;
}
//==============================================================
//     calculating the transpose of matrix
//==============================================================	
matrix matrix :: TransposeMatrix(matrix m)
{
	matrix temp;
 	temp.row=m.row;
 	temp.col=m.col;
	//cout<<
	for (int i=0;i<temp.col;i++)
	{
		for (int j=0;j<temp.row;j++)
		{
			temp.a[i][j] = m.a[j][i];
			cout<<setw(4)<<temp.a[i][j];
		}
		cout<<"\n";
	}

				
	return temp;
}
//==============================================================
//     calculating the determinte of matrix
//==============================================================
double matrix :: det(int arr[10][10], int row)
{
	int b[10][10]; 
	double sum=0;
	double deter1=0;
	if (row == 1)
		sum=arr[0][0];
	else if(row == 2)
		sum= arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
	else
		for(int i=0;i<row;i++)
		{
			matrix::minor(b, arr, i, row);
			deter1=matrix::det(b,row-1);
			sum = (double) (sum+arr[0][i]*pow(-1,i)*deter1);
			cout<<"    "<<sum;
		}
	return sum; 
}
//==============================================================
//     calculate inverse of matrix
//==============================================================
void matrix :: inverse(int arr[10][10], double inv[10][10], int row, double det)
{
	if(det == 0)
		cout<<"\n The inverse of the entered matrix is not possible\n";
	else if(row == 1)
		inv[0][0] = 1;
	else
		cofactor(arr, inv, row, det);	
}
//==============================================================
//     calculating minor of matrix OR build new matrix : k-had = minor
//==============================================================

void matrix :: minor(int b[10][10], int arr[10][10], int i, int row)
{
	int h=0; int k=0;
	for(int l=1;l<row;l++)
		for(int j=0;j<row;j++)
		{
			if(j == i)
				continue;
			b[h][k] = arr[l][j];
			k++;
			if(k == (row-1))
			{
				h++;
				k=0;
			}
		}
}
//==============================================================
//     calculating the cofactor of matrix
//==============================================================
void matrix :: cofactor(int arr[10][10], double inv[10][10], int row, double det)
{
	int b[10][10];
	float c[10][10];
	int m,k;
	double deter1=0;
	for (int h=0;h<row;h++)
		for (int l=0;l<row;l++)
		{
			m=0;
			k=0;
			for (int i=0;i<row;i++)
				for (int j=0;j<row;j++)
					if (i != h && j != l)
					{
						b[m][k]=arr[i][j];
						if (k<(row-2))
							k++;
						else
						{
							k=0;
							m++;
						}
					}
			deter1=matrix::det(b,row-1);
			c[h][l] = (float) pow(-1,h+l)* deter1;
		}
	transpose(c, inv, row, det);
}

//==============================================================
//     calculating the transpose of matrix (for inversing the matrix)
//==============================================================	
void matrix :: transpose(float c[10][10], double inv[10][10], int row, double det)
{
	float b[10][10];
	for (int i=0;i<row;i++)
		for (int j=0;j<row;j++)
			b[i][j] = c[j][i];
			
	for (int i=0;i<row;i++)
		for (int j=0;j<row;j++)
			inv[i][j] = b[i][j]/det;	
}
//==============================================================
//     Showing main menu
//==============================================================
void matrix::Menu()
{
		system("CLS");
		cout<<" \n\t\t====================================================";
	 	cout << "\n\t\t Project     : Matrix Operations";
	 	cout << "\n\t\t Author      : Mona Roshdibenam";
	 	cout << "\n\t\t Description : Object Oriented ProgrammingI by C++";
		cout << "\n\t\t Copyright   : October 2018";                                           
	 	cout<<" \n\t\t====================================================";
	 	cout << "\n\n\t\t\t  0. Read default Matrixes";
     	cout << "\n\n\t\t\t  1. Read Matrix";
     	cout << "\n\n\t\t\t  2. Matrix addition";
     	cout << "\n\n\t\t\t  3. Matrix subtraction";
     	cout << "\n\n\t\t\t  4. Matrix multiplication";
     	cout << "\n\n\t\t\t  5. Matrix transposition";
     	cout << "\n\n\t\t\t  6. Inverse Matrix";
     	cout << "\n\n\t\t\t  7. Exit Program";
     	cout<<  "\n\t\t===================================================";
     	cout << "\n\n";
     	cout << "\t\t\t Select Your Choice::";
}

int main(int argc, char** argv) 
{
	matrix m1,m2,m3,m4;
 	int choice;
	int r1,c1;
	int r2,c2;
	double deter;
	
	
	while(1) 
	{
		m1.Menu();
		cin>>choice;
     	switch(choice)
     	{
     	case 0://readig default matrixes
     	{
     		 	r1=r2=c1=c2=4;
    	m1.read1(r1,c1);
        m2.read1(r1,c1);
        cout << "==== default first matrix ====\n";
    	m1.display();
    	cout<<"============================= \n";
    	cout << "==== default second matrix ====\n";
    	m2.display();
		 cout<<"============================= \n";
		   	break;	
}
     		case 1:// Reading Matrix
     		     		{

 				cout<<"\n Enter the number rows of the first matrix:";
			 	cin>>r1;
			
			 	cout<<"\n Enter the number columns of the first matrix:";
			 	cin>>c1;
			 	m1.setValue(r1,c1);
			 	
			 	cout<<"\n Enter the number rows of the second matrix:";
			 	cin>>r2;
			 	
			 	cout<<"\n Enter the number columns of the second matrix:";
			 	cin>>c2;
			 	m2.setValue(r2,c2);
			 	
			 	cout<<"============================= \n";
			 	cout<<"\n Enter the elements of first matrix\n";
		   		m1.read(r1,c1);
		   		cout<<"\n Enter the elements of second matrix\n";
		   		m2.read(r2,c2);
		   		cout<<"\n ============================= \n";
		   		m1.display();
		   		cout<<"============================= \n";
		   		m2.display();
		   		cout<<"============================= \n";
		   		break;
 				cout<<"\n Enter the number rows of the first matrix:";
     		}
     		case 2://Matrix addition
			{
				if(r1!=r2||c1!=c2)
					cout<<"Two matrixes are not equal!! \n";
				else
				{
					m4 = m3.addition (m1,m2);
					cout<<"=====The first matrix===== \n";
					m1.display();
		   			cout<<"=====The second matrix===== \n";
		   			m2.display();
		   			cout<<"=====The result of addition===== \n";
					m4.display();
				}
				break;
			}
 			case 3://Matrix Subtraction
			{
				if(r1!=r2||c1!=c2)
					cout<<"Two matrixes are not equal!! \n";
				else
				{
					m4 = m3.subtraction (m1,m2);
					cout<<"=====The first matrix===== \n";
					m1.display();
		   			cout<<"=====The second matrix===== \n";
		   			m2.display();
		   			cout<<"=====The result of Subtraction===== \n";
					m4.display();
				}
				break;
			}
 			case 4: //Matrix multiplication
			{
			 	if(c1!=r2)
			 		cout<<"Matrix multiplication not Possible\n";
				else	     	
				{
					m4 = m3.multiply (m1,m2);
		   			cout<<"=====The first matrix===== \n";
					m1.display();
		   			cout<<"=====The second matrix===== \n";
		   			m2.display();
		   			cout<<"=====The result of multiplication===== \n";
		   			m4.display();
				}
				break;
			}
			case 5://Matrix Transposition
			{
				
				cout<<"=====The first matrix===== \n";
				m1.display();
				cout<<"=====The transpose of the first matrix===== \n";
				m4 = m3.TransposeMatrix (m1);
				//m4.display();
				
				
				cout<<"=====The second matrix===== \n";
				m2.display();
				cout<<"=====The transpose of the second matrix===== \n";
				m4 = m3.TransposeMatrix (m2);
	   			
	   			//m4.display();
				break;
			}
			case 6:
			cout<<"=====The first matrix===== \n";
				m1.display();	
			{
				if(r1!=c1||r1!=c2)
					cout<<"The dimensions of the matrixes are not equal!! \n";
				else
				{
					double inv[10][10];
					int arr[10][10];
					m1.swapp(m1,arr);
					deter = m1.det(arr,r1);
					m1.inverse(arr, inv, r1, deter);
				
					cout<<"=====The result of the inverse the first matrix===== \n";
					for(int i=0; i<r1; i++)
				 	{
				 		for (int j=0; j< c1; j++)
				  			cout<<"  "<<inv[i][j]<<" \t     ";
				  		cout<<"\n";
				 	}
				}
				break;
			}
			case 7:
			{
			   	system("CLS");
			   	exit(0);
	   			break;
	   		}
	   		default : 
			{
				cout<<"\n\n\t\t Invalid input";
				cout<<"\n\n\t\tPress Enter to continue";
	   		}
     	}
     	getche();
	}
	return 0;
}
