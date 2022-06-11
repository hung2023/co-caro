#include <iostream>
#include <windows.h>

using namespace std;

char a[3][3]={'0','1','2','3','4','5','6','7','8'};
int x,y;
char nguoichoiX = 'X';
char nguoichoiO = 'O';
/*
a00 a01 a02
a10 a11 a12
a20 a21 a22
*/
//ve ban co
void vebanco()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ;j++)
		{
			cout<<a[i][j]<<"  ";
		}
		cout<<"\n\n";
	}
}
//nhap vi tri thay X vao vi tri tuong ung
void thayX()
{
	cout<<"nhap vi tri tuong ung voi so ma ban muon danh, luot X: ";
	cin>>x;
	while(x > 8)
	{
		if(x > 8)
		{
			cout<<"\nNhap lai!\nNhap vi tri tuong ung voi so ma ban muon danh, luot X: ";
			cin>>x;
		}
	}
	if(x <= 2)
	{
		for(int i = 0 ; i <= 2 ;i++)
		{
			if(x == i)
			{
				a[0][i] = nguoichoiX;
			}
		}
	}
	else if(x <= 5 && x >= 3)
	{
		for(int i = 0 ; i <= 2 ;i++)
		{
			if(x - 3 == i)
			{
				a[1][i] = nguoichoiX;
			}
		}
	}
	else if(x <= 8 && x >= 6)
	{
		for(int i = 0 ; i <= 2 ;i++)
		{
			if(x - 6 == i)
			{
				a[2][i] = nguoichoiX;
			}
		}
	}
}
//nhap vi tri thay O vao vi tri tuong ung
void thayO()
{
	cout<<"nhap vi tri tuong ung voi so ma ban muon danh, luot O: ";
	cin>>y;
	while(y > 8)
	{
		if(y > 8) cout<<"\nNhap lai!\nNhap vi tri tuong ung voi so ma ban muon danh, luot O: ";
		cin>>y;
	}
	if(y <= 2)
	{
		for(int i = 0 ; i <= 2 ;i++)
		{
			if(y  == i)
			{
				a[0][i] = nguoichoiO;
			}
		}
	}
	else if(y <= 5 && y >= 3)
	{
		for(int i = 0 ; i <= 2 ;i++)
		{
			if(y - 3 == i)
			{
				a[1][i] = nguoichoiO;
			}
		}
	}
	else if(y <= 8 && y >= 6)
	{
		for(int i = 0 ; i <= 2 ;i++)
		{
			if(y - 6 == i)
			{
				a[2][i] = nguoichoiO;
			}
		}
	}
}
//tim nguoi thang
char ktra()
{
	if(a[0][0] == 'X' && a[0][1] == 'X' && a[0][2] == 'X'||
	   a[1][0] == 'X' && a[1][1] == 'X' && a[1][2] == 'X'||
	   a[2][0] == 'X' && a[2][1] == 'X' && a[2][2] == 'X'||
	   /*hang ngang */
	   a[0][0] == 'X' && a[1][0] == 'X' && a[2][0] == 'X'||
	   a[0][1] == 'X' && a[1][1] == 'X' && a[2][1] == 'X'||
	   a[0][2] == 'X' && a[1][2] == 'X' && a[2][2] == 'X'||
	   /* hang doc*/
	   a[0][0] == 'X' && a[1][1] == 'X' && a[2][2] == 'X'||
	   a[0][2] == 'X' && a[1][1] == 'X' && a[2][0] == 'X'
	   /* duong cheo*/)
	{
	   	return 'X';
	}
	else if(a[0][0] == 'O' && a[0][1] == 'O' && a[0][2] == 'O'||
	        a[1][0] == 'O' && a[1][1] == 'O' && a[1][2] == 'O'||
	        a[2][0] == 'O' && a[2][1] == 'O' && a[2][2] == 'O'||
	        /*hang ngang */
	        a[0][0] == 'O' && a[1][0] == 'O' && a[2][0] == 'O'||
	        a[0][1] == 'O' && a[1][1] == 'O' && a[2][1] == 'O'||
	        a[0][2] == 'O' && a[1][2] == 'O' && a[2][2] == 'O'||
	        /* hang doc*/
     	    a[0][0] == 'O' && a[1][1] == 'O' && a[2][2] == 'O'||
	        a[0][2] == 'O' && a[1][1] == 'O' && a[2][0] == 'O'
	        /* duong cheo*/)
	{
	   	return 'O';
	}
	return 'hoa';
}
int tim_ng_thang()
{
	int b;
	if(ktra() == 'X')
	{
			cout<<"\nX da thang!\n";
			b = 10;
	}
	else if(ktra() == 'O')
	{
		cout<<"\nO da thang!\n";
		b = 10;
	}
	else if(ktra() == 'Hoa')
	{
		cout<<"Hoa!\n";
		b = 10;
	}
	return b;
}

void reset_game()
{
	a[0][0] = '0';
	a[0][1] = '1';
	a[0][2] = '2';
	a[1][0] = '3';
	a[1][1] = '4';
	a[1][2] = '5';
	a[2][0] = '6';
	a[2][1] = '7';
	a[2][2] = '8';
}
int main()
{
	system("color 02");
	int luachon;
	while(luachon != 0)
	{
		reset_game();
	    	vebanco();	
		while(true)
		{
			thayX();
			vebanco();
			if(tim_ng_thang() == 10) break;
			thayO();
			vebanco();
			if(tim_ng_thang() == 10) break;
		}
		cout<<"thoat: 0  choi tiep: nhap so bat ki \nLua chon cua ban: ";
		cin>>luachon;
	}
	return 0;
}


