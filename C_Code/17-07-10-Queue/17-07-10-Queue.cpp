#include <iostream>
using namespace std;

void main(){
	int tail = 0;
	int a[10];
	int max = 10;

	int insert;

	while (true){
		cout << "�Է� : 1, ��� : 2, ���� : -1 >>> ";
		cin >> insert;
		if (insert == -1)
			break;
		else if (insert == 1){
			if (tail + 1 < 10){
				cout << "[�Է�]" << "���� �Է� >>> ";
				cin >> a[tail];
				tail++;
			}
			else{
				cout << "�̹� ��ȭ�����Դϴ�" << endl;
			}
		}
		else if (insert == 2){
			cout << "[���]";
			if (tail > 0){
				cout << a[0] << "���" << endl;
				for (int i = 0; i < tail-1; i++){
					a[i] = a[i + 1];
				}
				tail--;
			}
			else {
				cout << "������ �������� �����ϴ�" << endl;
			}
		}
		else{
			cout << "�� �� �Է��Ͽ����ϴ�." << endl;
		}

		for (int i = 0; i< tail; i++){
			cout << a[i] << " ";
		} cout << endl << endl;
	}
}