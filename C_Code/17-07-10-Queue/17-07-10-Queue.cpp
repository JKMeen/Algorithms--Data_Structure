#include <iostream>
using namespace std;

void main(){
	int tail = 0;
	int a[10];
	int max = 10;

	int insert;

	while (true){
		cout << "입력 : 1, 출력 : 2, 종료 : -1 >>> ";
		cin >> insert;
		if (insert == -1)
			break;
		else if (insert == 1){
			if (tail + 1 < 10){
				cout << "[입력]" << "숫자 입력 >>> ";
				cin >> a[tail];
				tail++;
			}
			else{
				cout << "이미 포화상태입니다" << endl;
			}
		}
		else if (insert == 2){
			cout << "[출력]";
			if (tail > 0){
				cout << a[0] << "출력" << endl;
				for (int i = 0; i < tail-1; i++){
					a[i] = a[i + 1];
				}
				tail--;
			}
			else {
				cout << "삭제할 아이템이 없습니다" << endl;
			}
		}
		else{
			cout << "잘 못 입력하였습니다." << endl;
		}

		for (int i = 0; i< tail; i++){
			cout << a[i] << " ";
		} cout << endl << endl;
	}
}