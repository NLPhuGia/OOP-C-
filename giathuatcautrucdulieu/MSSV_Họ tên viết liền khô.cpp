/*


#include<iostream>
using namespace std;

struct tNode{
	int data;
	tNode *pLeft, *pRight;
};


tNode *root;

//create empty tree
void createEmptyTree(){
	root = NULL;
}

//create new node
tNode *newNode(int data){
	tNode *node = new tNode;
	if(node==NULL){//cannot allocate memory
		exit(1);
	}else{
		node->data = data;
		node->pLeft = NULL;
		node->pRight = NULL;
	}
	return node;
}
//insert new Node into tree
tNode *insertNode(tNode *node, int value){
	if(node!=NULL){
		if(node->data == value){
			return node;
		}else if(node->data > value){
			node->pLeft = insertNode(node->pLeft, value);
		}else{
			node->pRight = insertNode(node->pRight, value);
		}
	}else{
		node = newNode(value);
	}
	return node;
}

void NLR(tNode *root){
	if(root!=NULL){
		if(root!=NULL){
		  cout<<root->data<<" ";
		}
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}

tNode *searchNodeByRecursion(tNode *root, int x){
	if(root != NULL ){
		if(root->data == x){
			return root;
		}
		if(root->data > x){
			return searchNodeByRecursion(root->pLeft,x);
		}else{
			return searchNodeByRecursion(root->pRight,x);
		}
	}
	return NULL;
}

tNode *searchNodeWithoutRecursion(tNode *root, int x){
	tNode *p=root;
	while(p != NULL){
		if(p->data == x){
			return p;
		}else if(p->data > x){
			p = p->pLeft;
		}else{
			p = p->pRight;
		}
	}
	return NULL;
}

tNode *minValueNode(tNode *node){
	tNode *current = node;
	while(current && current->pLeft != NULL){
		current = current->pLeft;
	}
	return current;
}

tNode *deleteNode(tNode *root, int x){
	if(root == NULL){
		return root;
	}
	if(root->data > x){
		root->pLeft = deleteNode(root->pLeft, x);
	}else if(root->data < x){
		root->pRight = deleteNode(root->pRight, x);
	}else{
		tNode *p = root;
		if(root->pLeft == NULL){
			root=root->pRight;
			delete p;
		}else if(root->pRight== NULL){
			root=root->pLeft;
			delete p;
		}else{
			tNode *temp = minValueNode(root->pRight);
			root->data = temp->data;
			root->pRight = deleteNode(root->pRight, temp->data);
		}
	}
	return root;
}

int main()
{
	//create binary search tree
	createEmptyTree();
	root = insertNode(root, 8);
	root = insertNode(root, 3);
	root = insertNode(root, 1);
	root = insertNode(root, 6);
	root = insertNode(root, 7);
	root = insertNode(root, 10);
	root = insertNode(root, 14);
	root = insertNode(root, 4);
	cout<<"traverse tree with NLR:";
	NLR(root);
	tNode *temp = searchNodeWithoutRecursion(root, 10);
	if(temp!=NULL){
		cout<<endl<<"Found x=10";
	}else{
		cout<<endl<<"Cannot found x=10";
	}
	root = deleteNode(root, 3);
	cout<<endl<<"traverse tree with NLR after delete node:";
	NLR(root);
	system("pause");
}
*/
#include<iostream>
using namespace std;


struct node
{
	int data; // d??? li???u c???a node ==> d??? li???u m?? node s??? l??u tr???
	struct node *pLeft; // node li??n k???t b??n tr??i c???a c??y <=> c??y con tr??i
	struct node *pRight; // node li??n k???t b??n ph???i c???a c??y <=> c??y con ph???i
};
typedef struct node NODE;
typedef NODE* TREE;

// kh???i t???o c??y
void KhoiTaoCay(TREE &t)
{
	t = NULL; // c??y r???ng
}

// h??m th??m ph???n t??? x v??o c??y nh??? ph??n
void ThemNodeVaoCay(TREE &t, int x)
{
	// n???u c??y r???ng
	if (t == NULL)
	{
		NODE *p = new NODE; // kh???i t???o 1 c??i node ????? th??m v??o c??y
		p->data = x;// th??m d??? li???u x v??o data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;// node p ch??nh l?? node g???c <=> x ch??nh l?? node g???c
	}
	else // c??y c?? t???n t???i ph???n t???
 	{
		// n???u ph???n t??? th??m v??o m?? nh??? h??n node g???c ==> th??m n?? v??o b??n tr??i
		if (t->data > x)
		{
			ThemNodeVaoCay(t->pLeft, x); // duy???t qua tr??i ????? th??m ph???n t??? x
		}
		else if (t->data < x) // n???u ph???n t??? th??m v??o m?? l???n h??n node g???c ==> th??m n?? v??o b??n ph???i
		{
			ThemNodeVaoCay(t->pRight, x); // duy???t qua ph???i ????? th??m ph???n t??? x
		}
	}
}

// h??m xu???t c??y nh??? ph??n theo NLR
void Duyet_NLR(TREE t)
{ 
	// n???u c??y c??n ph???n t??? th?? ti???p t???c duy???t
	if (t != NULL)
	{
		cout << t->data << " "; // xu???t d??? li???u trong node
		Duyet_NLR(t->pLeft); // duy???t qua tr??i
		Duyet_NLR(t->pRight); // duy???t qua ph???i
	}
}
NODE* TimKiem(TREE t, int x)
{ 
	// n???u c??y r???ng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// n???u ph???n t??? c???n t??m ki???m m?? nh??? h??n node g???c th?? duy???t(????? quy) sang b??n tr??i ????? t??m
		if (x < t->data)
		{
			TimKiem(t->pLeft, x);
		}
		else if (x > t->data) // duy???t sang b??n ph???i
		{
			TimKiem(t->pRight, x);
		}
		else // <=> t->data == x
		{
			return t; // tr??? v??? node c???n t??m ki???m
		}
	}

}
void XoaNode(TREE &t, int data) // data ch??nh l?? gi?? tr??? c???a c??i node c???n x??a
{
	// n???u nh?? c??y ??ang r???ng
	if (t == NULL)
	{
		return; // k???t th??c h??m
	}
	else
	{
		// n???u nh?? data nh??? h??n node g???c
		if (data < t->data)
		{
			XoaNode(t->pLeft, data); // duy???t sang nh??nh tr??i c???a c??y 
		}
		else if (data > t->data)
		{
			XoaNode(t->pRight, data); // duy???t sang nh??nh ph???i c???a c??y 
		}
		else // data == t->data - ???? t??m ra c??i node c???n x??a
		{
			NODE *X = t; // node X l?? node th??? m???ng - t?? n???a ch??ng ta s??? x??a n??
			// n???u nh?? nh??nh tr??i b???ng NULL <=> ????y l?? c??y c?? 1 con ch??nh l?? con ph???i
			if (t->pLeft == NULL)
			{
				// duy???t sang ph???i c???a c??i node c???n x??a ????? c???p nh???t m???i li??n k???t gi???a node 
				// cha c???a node c???n x??a v???i node con c???a node c???n x??a
				t = t->pRight; 
			}
			else if (t->pRight == NULL)
			{
				// duy???t sang tr??i c???a c??i node c???n x??a ????? c???p nh???t m???i li??n k???t gi???a node 
				// cha c???a node c???n x??a v???i node con c???a node c???n x??a
				t = t->pLeft;
			}
			
			delete X; // x??a node c???n x??a
		}
	}
}

// h??m nh???p d??? li???u
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
		if (luachon < 0 || luachon > 2)
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