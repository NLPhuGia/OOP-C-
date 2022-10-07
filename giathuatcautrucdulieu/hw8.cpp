#include<iostream>
using namespace std;


struct node
{
	int data; // d? li?u c?a node ==> d? li?u m� node s? luu tr?
	struct node *pLeft; // node li�n k?t b�n tr�i c?a c�y <=> c�y con tr�i
	struct node *pRight; // node li�n k?t b�n ph?i c?a c�y <=> c�y con ph?i
};
typedef struct node NODE;
typedef NODE* TREE;

// kh?i t?o c�y
void KhoiTaoCay(TREE &t)
{
	t = NULL; // c�y r?ng
}

// h�m th�m ph?n t? x v�o c�y nh? ph�n
void ThemNodeVaoCay(TREE &t, int x)
{
	// n?u c�y r?ng
	if (t == NULL)
	{
		NODE *p = new NODE; // kh?i t?o 1 c�i node d? th�m v�o c�y
		p->data = x;// th�m d? li?u x v�o data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p ch�nh l� node g?c <=> x ch�nh l� node g?c
	}
	else // c�y c� t?n t?i ph?n t?
 	{
		// n?u ph?n t? th�m v�o m� nh? hon node g?c ==> th�m n� v�o b�n tr�i
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); // duy?t qua tr�i d? th�m ph?n t? x
		}
		else if (t->data < x) // n?u ph?n t? th�m v�o m� l?n hon node g?c ==> th�m n� v�o b�n ph?i
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
		cout << t->data << " "; // xu?t d? li?u trong node
		Duyet_NLR(t->pLeft); // duy?t qua tr�i
		Duyet_NLR(t->pRight); // duy?t qua ph?i
	}
}
NODE* TimKiem(TREE t, int x)
{ 
	// n?u c�y r?ng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// n?u ph?n t? c?n t�m ki?m m� nh? hon node g?c th� duy?t(d? quy) sang b�n tr�i d? t�m
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data) // duy?t sang b�n ph?i
		{
			TimKiem(t->pRight, x);
		}
		else // <=> t->data == x
		{
			return t; // tr? v? node c?n t�m ki?m
		}
	}

}
void XoaNode(TREE &t, int data) // data ch�nh l� gi� tr? c?a c�i node c?n x�a
{
	// n?u nhu c�y dang r?ng
	if (t == NULL)
	{
		return; // k?t th�c h�m
	}
	else
	{
		// n?u nhu data nh? hon node g?c
		if (data < t->data)
		{
			XoaNode(t->pLeft, data); // duy?t sang nh�nh tr�i c?a c�y 
		}
		else if (data > t->data)
		{
			XoaNode(t->pRight, data); // duy?t sang nh�nh ph?i c?a c�y 
		}
		else // data == t->data - d� t�m ra c�i node c?n x�a
		{
			NODE *X = t; // node X l� node th? m?ng - t� n?a ch�ng ta s? x�a n�
			// n?u nhu nh�nh tr�i b?ng NULL <=> d�y l� c�y c� 1 con ch�nh l� con ph?i
			if (t->pLeft == NULL)
			{
				// duy?t sang ph?i c?a c�i node c?n x�a d? c?p nh?t m?i li�n k?t gi?a node 
				// cha c?a node c?n x�a v?i node con c?a node c?n x�a
				t = t->pRight; 
			}
			else if (t->pRight == NULL)
			{
				// duy?t sang tr�i c?a c�i node c?n x�a d? c?p nh?t m?i li�n k?t gi?a node 
				// cha c?a node c?n x�a v?i node con c?a node c?n x�a
				t = t->pLeft;
			}
			
			delete X; // x�a node c?n x�a
		}
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
		cout << "\n3.Tim kiem ";
		cout << "\n4.Xoa phan tu";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t ============================";

		int luachon;

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon < 0 || luachon > 4)
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			int x;
			cout << "\nNhap so nguyen x: ";
			cin >> x;
			ThemNodeVaoCay(t, x);
		}
		else if (luachon == 2)
		{
			cout << "\n\t\t DUYET CAY THEO NLR\n";
			Duyet_NLR(t);
			system("pause");
		}
		
		else if(luachon == 3)
		{
			int x;
            cout<< "\nTim kiem phan tu tim kiem: ";
			cin>>x;
			NODE *p = TimKiem(t, x);
			if (p == NULL)
			{
				cout << "\nPhan tu " << x << " khong ton tai trong cay";
			}
			else
			{
				cout << "\nPhan tu " << x << " co ton tai trong cay";
			}
			system("pause");

		}

        else if(luachon == 4)
		{
			int x;
			cout << "\nNhap gia tri can xoa: ";
			cin >> x;
			XoaNode(t, x);
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
	KhoiTaoCay(t);
	Menu(t);

	system("pause");
	return 0;
}
