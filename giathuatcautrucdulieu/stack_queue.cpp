/*=================================== STACK - NGĂN XẾP =================================== 
Stack là 1 cấu trúc trừu tượng, các đối tượng trong stack phải làm việc theo 1 cơ chế
LIFO(LAST IN FIRST OUT) - đối tượng nào vào sau thì sẽ ra trước

IsEmpty: kiểm tra xem stack có rỗng hay không
Push: thêm 1 đối tượng vào đầu stack <=> theo cơ chế LIFO
Pop: lấy phần tử đầu stack và trả về giá trị của đối tượng đầu stack
đồng thời phải hủy nó đi
Top: xem thông tin của phần tử đầu stack và không hủy nó đi

===================== CODE ===================== */
#include<iostream>
using namespace std;

/*
Nhập danh sách stack chứa các số nguyên, sau đó xuất ra màn hình các giá trị số nguyên đó

*/

// khai báo cấu trúc của 1 cái node trong stack
struct node
{
	int data; // stack đang chứa các số nguyên
	struct node *pNext; // con trỏ liên kết giữa các node với nhau
};
typedef struct node NODE;

// khai báo cấu trúc của stack
struct stack
{
	NODE *pTop; // dùng con trỏ đầu để quản lí stack
};
typedef struct stack STACK;

// hàm khởi tạo stack
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

// hàm khởi tạo 1 cái node
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thêm giá trị của biến x vào trong data của cái node
	p->pNext = NULL;
	return p;
}

// =============== KIỂM TRA STACK CÓ RỖNG HAY KHÔNG ===============
bool IsEmpty(STACK s)
{
	// nếu danh sách rỗng
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;// danh sách có phần tử
}

// =============== THÊM 1 PHẦN TỬ VÀO ĐẦU STACK- LIFO ===============
bool Push(STACK &s, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// nếu danh sách rỗng
	if (IsEmpty(s) == true)
	{
		s.pTop = p; // node p chính là node đầu stack
	}
	else // danh sách đã có phần tử
	{
		p->pNext = s.pTop; // cho con trỏ của node p trỏ đến node đầu danh sách <=> tạo kiên kết
		s.pTop = p; // cập nhật lại node đầu
	}
	return true;
}

// =============== LẤY PHẦN TỬ ĐẦU STACK VÀ HỦY NÓ ĐI - LIFO ===============
bool Pop(STACK &s, int &x) // x chính là giá trị cần lấy trong node
{
	// nếu danh sách rỗng
	if (IsEmpty(s) == true)
	{
		return false;
	}
	else
	{
		NODE *p = s.pTop; // node p chính là node thế mạng để tí nữa chúng ta xóa nó đi
		x = p->data; // gán giá trị của node đầu stack vào biến x	
		s.pTop = s.pTop->pNext; // cập nhật node đầu stack là node tiếp theo	
		delete p; // xóa node đầu stack vừa lấy 
		
	}
	return true;// lấy phần tử đầu stack thành công
}


// =============== XEM THÔNG TIN CỦA PHẦN TỬ ĐẦU STACK - KHÔNG CÓ HỦY NÓ ĐI NHÉ ===============
bool Top(STACK &s, int &x) // x chính là giá trị cần lấy ra để xem
{
	if (IsEmpty(s) == true)
	{
		return false;
	}
	x = s.pTop->data; // lấy giá trị của phần tử đầu stack ra để xem
	return true;
}

// hàm xuất danh sách stack
void XuatStack(STACK s)
{
	while (IsEmpty(s) == false)
	{
		int x;
		Pop(s, x);
		cout << x << " ";
	}

	if (IsEmpty(s) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}

// hàm nhập danh sách các số nguyên trong stack
void NhapStack(STACK &s)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them phan tu vao stack - Push";
		cout << "\n\t2. Xuat danh sach stack ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau stack - Top";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode( x);
			Push(s, p);
		}
		else if (luachon == 2)
		{
			XuatStack(s);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(s, x);
			cout << "\nPhan tu dau stack la: " << x;
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
	STACK s;
	KhoiTaoStack(s);

	NhapStack(s);

	system("pause");
	return 0;
}



/*
=================================== QUEUE - HÀNG ĐỢI =================================== 
Queue là 1 cấu trừu tượng, các đối tượng trong queue phải làm việc theo 1 cơ chế
FIFO(FIRST IN FIRST OUT) - đối tượng nào vào trước thì sẽ ra trước

IsEmpty: kiểm tra xem queue có rỗng hay không
Push: thêm 1 đối tượng vào cuối queue  <=> theo cơ chế FIFO
Pop: lấy phần tử đầu queue  và trả về giá trị của đối tượng đầu queue 
đồng thời phải hủy nó đi
Top: xem thông tin của phần tử đầu queue và không hủy nó đi

===================== CODE =====================

#include<iostream>
using namespace std;

/*
Nhập danh sách queue chứa các số nguyên, sau đó xuất ra màn hình các giá trị số nguyên đó

*/

// khai báo cấu trúc của 1 cái node trong queue
/*
struct node
{
	 int data; // queue đang chứa các số nguyên
	struct node *pNext; // con trỏ liên kết giữa các node với nhau
};
typedef struct node NODE;

// khai báo cấu trúc của queue
struct queue
{
	NODE *pHead; //  con trỏ đầu
	NODE *pTail; // con trỏ cuối 
};
typedef struct queue QUEUE;

// hàm khởi tạo queue
void KhoiTaoQueue(QUEUE &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

// hàm khởi tạo 1 cái node

// =============== KIỂM TRA QUEUE CÓ RỖNG HAY KHÔNG ===============
bool IsEmpty(QUEUE q)
{
	// nếu danh sách rỗng
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;// danh sách có phần tử
}

// =============== THÊM 1 PHẦN TỬ VÀO CUỐI QUEUE- FIFO ===============
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}

	// nếu danh sách rỗng
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; // node p chính là node đầu và node cuối
	}
	else // danh sách đã có phần tử
	{
		q.pTail->pNext = p; // liên kết con trỏ cuối của danh sách với phần tử p cần thêm vào
		q.pTail = p; // cập nhật lại con trỏ cuối là node p
	}
	return true;
}

// =============== LẤY PHẦN TỬ ĐẦU QUEUE VÀ HỦY NÓ ĐI - FIFO ===============
bool Pop(QUEUE &q, int &x) // x chính là giá trị cần lấy trong node
{
	// nếu danh sách rỗng
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE *p = q.pHead; // node p chính là node thế mạng để tí nữa chúng ta xóa nó đi
		x = p->data; // gán giá trị của node đầu stack vào biến x	
		q.pHead = q.pHead->pNext; // cập nhật node đầu queue là node tiếp theo	
		delete p; // xóa node đầu queue vừa lấy 

	}
	return true;// lấy phần tử đầu queue thành công
}


// =============== XEM THÔNG TIN CỦA PHẦN TỬ ĐẦU QUEUE - KHÔNG CÓ HỦY NÓ ĐI NHÉ ===============
bool Top(QUEUE &q, int &x) // x chính là giá trị cần lấy ra để xem
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data; // lấy giá trị của phần tử đầu queue ra để xem
	return true;
}

// hàm xuất danh sách queue
void XuatQueue(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		int x;
		Pop(q, x);
		cout << x << " ";
	}

	if (IsEmpty(q) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}

// hàm nhập danh sách các số nguyên trong queue
void NhapQueue(QUEUE &q)
{
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Them phan tu vao queue - Push";
		cout << "\n\t2. Xuat danh sach queue ra man hinh - Pop";
		cout << "\n\t3. Xem thong tin phan tu dau queue - Top";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== End ==============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			int x;
			cout << "\nNhap phan tu can them: ";
			cin >> x;
			NODE *p = KhoiTaoNode(x);
			Push(q, p);
		}
		else if (luachon == 2)
		{
			XuatQueue(q);
			system("pause");
		}
		else if (luachon == 3)
		{
			int x;
			Top(q, x);
			cout << "\nPhan tu dau queue la: " << x;
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
	QUEUE q;
	KhoiTaoQueue(q);

	NhapQueue(q);

	system("pause");
	return 0;
}


*/

