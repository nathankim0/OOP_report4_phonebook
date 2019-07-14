//PhoneClass.h
/*
한국산업기술대_컴퓨터공학과_2015154007_김진엽
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

class Phone { //Phone 클래스
private:
	string name;
	string address;
	string number;
public:
	map<string, vector<string>> contact; //이름 주소 전화번호
	map<string, vector<string>> ::iterator itcontact; //map에 대한 포인터 itcontact선언

	Phone() { //생성자. 제일 처음에 나올 내용들

		cout << "전화번호 관리 프로그램을 시작합니다. 파일로 저장합니다.\n\n";

		ifstream fin("phonebook.dat"); //전에 저장한 phonebook.dat 파일 읽어옴
		if (!fin) {
			cout << "phonebook.dat 파일을 열 수 없습니다.\n";
		}
		else {
			string line;
			vector<string> word;
			while (getline(fin, line)) { word.push_back(line); } 
			int size = word.size();
			for (int i = 0; i < size; i++) {
				//한 줄 씩 읽어온 내용들을 contact map의 각 key와 value (vector)에 저장
				if (i % 3 == 0) {  
					name = word[i]; //첫째줄, 셋째줄 (마다 이름이 있으니까)
					address = word[i + 1]; //그 다음 줄은 주소
					number = word[i + 2]; //그 다음 줄은 전화번호
					contact[name]= vector<string>{ address,number }; //변수에 저장한 값들을 map으로.
				}
			}
			cout << "-----기존 phonebook.dat 내용-----\n";
			if (contact.size() == 0) { cout<< "기존에 저장된 내용이 없습니다. \n새로 입력 해주세요~ ^^\n"; }
			else {
				for (itcontact = contact.begin(); itcontact != contact.end(); itcontact++) { //기존 내용 출력하는 반복문
					//iterator를 이용하여 map의 key, value (vector) 출력
					cout << itcontact->first << endl; //key (이름) 출력
					cout << itcontact->second[0] << endl; //value (주소) 출력
					cout << itcontact->second[1] << endl; //value (전화번호) 출력
				}
			}
			cout << "---------------------------------\n\n";
			system("phonebook.dat");

			
			fin.close();
		}
	}
	void insert() { //0
		cout << "이름>>"; cin >> name; //key값 입력받음
		cin.get(); //개행 바로 안만나게 해주는 역할
		if (contact.find(name) != contact.end()) {
			cout << "이미 있는 이름입니다.\n";
		}
		//key값 검색해서 없으면,
		else {
			cout << "주소>>";
			getline(cin, address);//주소와
			cout << "전화번호>>";
			getline(cin, number); //전화번호를 입력받는다.
			contact[name] = vector<string>{ address,number }; //value vector 에 주소와 전화번호 삽입.
		}
	}
	void del() { //1
		cout << "이름>>"; cin >> name; //삭제하려는 key값
		if (contact.find(name) == contact.end()) cout << "등록되어 있지 않은 이름입니다.\n";
		//key값 검색해서 있으면,
		else {
			contact.erase(name);//삭제.
			cout << name << "는 삭제되었습니다.\n";
		}
	}
	void search() { //2
		cout << "이름>>"; cin >> name; //찾으려는 key값
		if (contact.find(name) != contact.end()) { //찾았을때
			cout << name << " " << contact[name][0] << " " << contact[name][1] << endl; //key, value 출력
		}
		else cout << name << "은 등록되지 않은 사람입니다.\n";
	}
	void show() { //3
		for (itcontact = contact.begin(); itcontact != contact.end(); itcontact++) {
			//iterator를 이용하여 map의 key, value (vector)
			cout << itcontact->first << " "; //key (이름)
			cout << itcontact->second[0] << " "; //value (주소)
			cout << itcontact->second[1] << " \n"; //value (전화번호)
		}
	}
	void save() { //4
		ofstream fout("phonebook.dat");
		if (!fout) { // 열기실패검사
			cout << "phonebook.dat 저장 실패하였습니다.\n";
		}
		else {
			for (itcontact = contact.begin(); itcontact != contact.end(); itcontact++) {
				//iterator를 이용하여 map의 key, value (vector) 저장
				fout << itcontact->first << endl; //key (이름) 저장
				fout << itcontact->second[0] << endl; //value (주소) 저장
				fout << itcontact->second[1] << endl; //value (전화번호) 저장
			}
		}
		fout.close();
	}
};
