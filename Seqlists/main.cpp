#include <iostream>
#include"SeqList.h"
#include"LinkList.h"
using namespace std;

int main(){
	
	int a[5] = { 1, 3, 2, 4, 5 };
	
	//SeqList<int> seq(a,5);
	//seq.Delete(2);
	//seq.Insert(2,8);
	//seq.PrintList();
	//seq.~SeqList();
	LinkList<int> link(a, 5);
	
	link.PrintList();
	int x=link.Get(1);
	int x1 = link.Locate(3);
	cout << x1;
	system("pause");
	return 0;
}
