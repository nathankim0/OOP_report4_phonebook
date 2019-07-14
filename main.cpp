//main.cpp
/*
한국산업기술대_컴퓨터공학과_2015154007_김진엽
*/
#include "PhoneClass.h"

int main() {
	Phone a; //객체
	int i; //메뉴 입력시 사용
	bool done = true; //종료 입력시 사용함

	while (done) {
		cout << "0: 삽입. 1:삭제, 2:찾기, 3:전체보기,4 :파일저장, 5:종료>>";
		cin >> i;
		switch (i) {
		case 0:
			a.insert(); //삽입
			break;
		case 1:
			a.del(); //삭제
			break;
		case 2:
			a.search(); //찾기
			break;
		case 3:
			a.show(); //파일 불러와서 전체보기
			break;
		case 4:
			a.save(); //파일 저장
			break;
		case 5:
			done = false; //종료
			break;
		default:
			cout << "다시 입력해주세요 ~ ^^\n";
			cin.get();
			break;
		}
	}

}