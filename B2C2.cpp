#include <iostream>
#include <stdio.h>
#include <conio.h>
#define MAX 100
using namespace std;
void nhap (int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout<<"nhap a["<<i<<"] = ";
		cin>>a[i];
	}
}
void xuat(int a[], int n)
{
	for (int i=0; i<n; i++)
       cout<<a[i]<<"\t";
	cout<<endl;
}
int them(int a[],int &n, int x)
{
	if(n < MAX)
	{ 
		a[n] = x;
	    n++;
	     return 1;
	}
	else
	     return 0;
		
}
int timkiem(int a[],int n, int x)
{
	int i = 0;
	while((i < n) && (a[i]!= x))
	{	
		i++;
		if(i == n )
			return -1;
	}
	return i;
}
int xoa(int a[], int &n, int i)
{
	if (i>=0 && i < n)
	{
	for (int j=i; j<n-1; j++)
		a[j] = a[j+1];
	n--;
	return 1;
}
return 0;
}

int timxoa(int a[],int&n,int x)
{
	for (int i = 0;i < n;i++)
		if(a[i] == x)
		{
			xoa(a,n,i);
			return 1;
		}
		return 0;
}

int tim_Kiem_Nhi_Phan(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			right = mid - 1;
		else
			if (a[mid] < x)
				left = mid + 1;
	}
	return -1;
}
int main()
{
	int a[MAX];
	int n,x,i;
	int chon;
	bool in = false;

	do{
		system("cls");
		cout << "__MENU__ " << endl;
		cout << "1.nhap so luong phan tu\n2,Them 1 phan tu vao danh sach\n3. Viet cac thu tuc xuat cac phan tu danh sach\n4.Viet thu tuc tim 1 phan tu trong danh sach\n5.Viet thu tuc tim 1 phan tu trong danh sach(nhi phan)\n6.Viet thu tuc tim mot phan tu trong danh sach, tim duoc thi xoa\n7.Thoat\nBan chon : ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			{
				 cout<<"Nhap so luong phan tu cua danh sach: ";
		          cin >> n;
		          nhap(a,n);
				  in = true;
				  break;
			}
		case 2:
			if (in)
			{
				cout << " Vui long nhap x can them: ";
				cin >> x;
				i = them(a,n,x);
				if (i == 0)
					cout <<" Danh sach khong the them! ";
				else
					{
						cout <<"Them thanh cong x = " <<x<<" vao ds" << endl;
			            cout <<"Ds sau khi them :";
				        xuat(a,n);
			         }
			}
			else
				cout << "Ban chua nhap mang. Vui long nhap mang." << endl;
				break;
		case 3:
			if (in)
			{
				 cout <<" Mang vua nhap "<< endl;
		      xuat(a,n);
			}
			else
				cout << "Ban chua nhap mang. Vui long nhap mang. " << endl;
				break;
		case 4:
			if (in)
			{
				cout <<"Nhap x can tim : ";
				cin >> x;
				i = timkiem(a,n,x);
				if( i == -1)
					cout <<" Khong tim thay phan tu! ";
				else
					cout <<"Tim thay tai vi tri i =" << i << endl;
			}
			else
				cout << "Ban chua nhap mang. Vui long nhap mang. " << endl;
				break;
		case 5:
			if (in)
			{
				cout << "Nhap phan tu ban can tim: ";
				cin >> x;
				if (tim_Kiem_Nhi_Phan(a, n, x) == -1)
					cout << "Phan tu " << x << " khong co trong danh sach" << endl;
				else
					cout << "Phan tu " << x << " co trong danh sach" << endl;
			}
			else
				cout << "Ban chua nhap mang. Vui long nhap mang. " << endl;
			break;
		case 6:
			if (in)
			{
				cout << "Nhap vi tri can xoa x =";
				cin >> x;
				i = timxoa(a,n,i);
				if(i == 1)
				{
					cout << "Xoa thanh cong!"<< endl;
					cout << "DS sau khi xoa la: "<< endl;
					xuat(a,n);
				}
				else
					cout <<"Khong co phan tu de xoa!"<< endl;
			}
			else
				cout << "Ban chua nhap mang. Vui long nhap mang. " << endl;
				break;
		default:
			cout << "Ban chon thoat" << endl;

		}//switch
		_getch();
	}while( chon < 7 && chon > 0);

	return 0;
	
}