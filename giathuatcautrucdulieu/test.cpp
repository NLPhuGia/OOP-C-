#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

struct sinhvien {
	char Masv[50];
    char Ten[100];

	double Toan;
	double Ly;
	double Hoa;
};


sinhvien Nhapsv()
{
	sinhvien x;
	cout<<" Nhap ma sinh vien ";
    gets(x.Masv);
	cout << "\nNhap Ten Sinh Vien: ";
    gets(x.Ten);
	cout << "Nhap Diem Toan: ";
	while (true)
	{
		cin >> x.Toan;
		if (cin.fail() || x.Toan>10||x.Toan<0)
		{
			cin.clear();
			_flushall();
			cin.ignore();
			cout << "\nNhap Lai Diem Toan: ";

		}
		else
			break;
	}
	cout << "\nNhap Diem Ly: ";
	while (true)
	{
		cin >> x.Ly;
		if (cin.fail() || x.Ly>10||x.Ly<0)
		{
			cin.clear();
			_flushall();
			cin.ignore();
			cout << "\nNhap Lai Diem Ly: ";

		}
		else
			break;
	}
	cout << "\nNhap Diem Hoa: ";
	while (true)
	{
		cin >> x.Hoa;
		if (cin.fail() || x.Hoa>10||x.Hoa<0)
		{
			cin.clear();
			_flushall();
			cin.ignore();
			cout << "\nNhap Lai Diem Hoa: ";

		}
		else
			break;
	}


	while (getchar() != '\n');/////////////////

	return x;
}


void XuatSinhVien(sinhvien x)
{
	cout << "=================================" << endl;
	cout << "Ma So Sinh Vien: " << x.Masv << "\n";
	cout << "Ten Sinh Vien: " << x.Ten << "\n";
	cout << "Diem Toan: " << x.Toan << "\n";
	cout << "Diem Ly: " << x.Ly << "\n";
	cout << "Diem Hoa: " << x.Hoa << "\n";
}

// d? b�i: Nh?p v�o c�y nh? ph�n c�c s? nguy�n. Xu?t ra m�n h�nh c�c ph?n t? c?a c�y nh? ph�n
// khai b�o c?u tr�c  1 c�i node
struct node
{
	sinhvien sv20139072; // d? li?u c?a node ==> d? li?u m� node s? luu tr?
	struct node *pLeft; // node li�n k?t b�n tr�i c?a c�y <=> c�y con tr�i
	struct node *pRight; // node li�n k?t b�n ph?i c?a c�y <=> c�y con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;
int compare(sinhvien x, sinhvien y)
{
	return strcmp(x.Masv, y.Masv);
}
// kh?i t?o c�y
void KhoiTaoCay(TREE &t)
{
	t = NULL; // c�y r?ng
}

// h�m th�m ph?n t? x v�o c�y nh? ph�n
void ThemNodeVaoCay(TREE &t, sinhvien x)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		NODE *p = new NODE; // kh?i t?o 1 c�i node d? th�m v�o c�y
		p->sv20139072 = x;// th�m d? li?u x v�o data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p ch�nh l� node g?c <=> x ch�nh l� node g?c
	}
	else // c�y c� t?n t?i ph?n t?
 	{
		// n?u ph?n t? th�m v�o m� nh? hon node g?c ==> th�m n� v�o b�n tr�i
		if (compare(t->sv20139072 , x) > 0) 
		{
			ThemNodeVaoCay(t->pLeft, x); // duy?t qua tr�i d? th�m ph?n t? x
		}
		else if (compare(t->sv20139072 ,x) < 0 ) // n?u ph?n t? th�m v�o m� l?n hon node g?c ==> th�m n� v�o b�n ph?i
		{
			ThemNodeVaoCay(t->pRight, x); // duy?t qua ph?i d? th�m ph?n t? x
		}
	}
}


// h�m xu?t c�y nh? ph�n theo NLR
void Duyet_NLR(TREE t)
{ 
	// n?u c�y c�n ph?n t? th� ti?p t?c duy?t
	if (t != NULL)
	{
		XuatSinhVien(t-> sv20139072);
		Duyet_NLR(t->pLeft); // duy?t qua tr�i
		Duyet_NLR(t->pRight); // duy?t qua ph?i
	}
}
// h�m nh?p d? li?u
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t =========== MENU ===========";
		cout << "\n1. Nhap du lieu";
		cout << "\n2. Xuat du lieu cay NLR";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 2)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			
            Nhapsv();
		
			////ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			sinhvien x;
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			
			Duyet_NLR(t);
			cout << "=================================" << endl;
			cout << "Ma So Sinh Vien: " << x.Masv << "\n";
			cout << "Ten Sinh Vien: " << x.Ten << "\n";
			cout << "Diem Toan: " << x.Toan << "\n";
			cout << "Diem Ly: " << x.Ly << "\n";
			cout << "Diem Hoa: " << x.Hoa << "\n";
			system("pause");
		}
		else
		{
			break;
		}
	}
	
}

int main()
{
	TREE t;
	sinhvien x;
	KhoiTaoCay(t);
	Menu(t);
	system("pause");
	return 0;
}
