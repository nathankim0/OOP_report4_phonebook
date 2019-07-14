Screenshots
-----------

### 1) 메뉴실행
![1) 메뉴실행1](https://user-images.githubusercontent.com/37360089/61183355-580dd300-a67b-11e9-8000-32003068524d.PNG)

### 2) 저장된파일을확인하는예
![2) 저장된파일을확인하는예](https://user-images.githubusercontent.com/37360089/61183356-5ba15a00-a67b-11e9-82da-66ae44bbfab0.PNG)

### 3) 파일불러와서 전체보기 예
![3) 파일불러와서 전체보기 예](https://user-images.githubusercontent.com/37360089/61183357-60660e00-a67b-11e9-8edc-2283e1cba710.PNG)

![캡처](https://user-images.githubusercontent.com/37360089/61183365-6cea6680-a67b-11e9-8594-7cafc722f954.PNG)


설명
---------------
일단 간략하게, 헤더 파일에서 Phone 클래스를 구현하였고 메인 파일에서는 Phone 객체를 생성 후에 메뉴를 구현하여 Phone 클래스의 함수들을 호출하였습니다.

main.cpp에서, PhoneClass 헤더파일을 include 하였습니다. while문으로 숫자를 입력하고 바로 끝나지 않게 무한루프로 구현하였고 그 안에 switch문으로 입력한 숫자에 따라 함수를 호출하게 하였습니다.

Phone 클래스에는 처음 프로그램이 시작될 때 작동할 코드를 담은 생성자와, 삽입함수(0번), 삭제함수(1), 찾기함수(2), 전체보기함수(3), 파일저장함수(4)가 있습니다.

먼저, 함수에서 계속 사용될 변수인 string 타입의 name, address, number를 선언합니다. 그리고 map클래스인 contact와 그 컨테이너 원소에 대한 포인터인 itcontact를 선언합니다(나중에 출력, 저장할 때 사용합니다). 여기서, map의 key는 string형, value는 벡터로 선언합니다. 
=> value에 두 개 이상의 값들(각 key값에 대응하는 주소와 전화번호)을 집어넣기 위해. 

생성자에서는 기존에 저장된 phonebook.dat를 불러옵니다(파일 읽기를 위한 스트림 생성, ifstream). 그리고 파일에서 한 줄씩 word 벡터에 push합니다. 그리고 그 벡터에 있는 값들을 전에 선언한 contact에 넣기위해, for문으로 word벡터 사이즈 만큼 첫째줄과 3n째줄은 name에, 그 다음줄은 address에, 그 다음줄은 number에 집어넣고, contact map의 key와 value(벡터)에 넣습니다. 그리고 전부 출력해줍니다. 여기까지가 생성자.

0을 눌러 삽입함수를 호출하면, 중복된 이름을 입력하면 “이미 있는 이름입니다.”를 출력하고 중복되지 않은 이름을 입력하면 주소와 전화번호를 입력하여 contact map에 넣습니다. 

1을 눌러 삭제함수를 호출하면, 입력한 이름이 등록되어 있는 이름일 때 erase를 이용하여 map의 입력한 name(key) 삭제합니다.

2를 눌러 찾기함수를 호출하면, 입력한 이름 key를 끝까지 찾으면 입력한 name과 그 value인 벡터의 [0] (address)과 [1] (전화번호)를 출력합니다. 없으면(못 찾으면) “등록되지 않은 사람입니다.” 출력합니다.

3을 눌러 전체보기함수를 호출하면, 전에 선언한 contact map 컨테이너 원소를 가리키는 포인터인 itcontact를 사용하여, contact의 처음부터 끝까지 쫙 이름(key)과 그 주소와 전화번호 (value, 벡터로 되어있음)를 출력합니다.

4를 눌러 저장함수를 호출하면, 파일 쓰기를 위해 스트림을 생성(ofstream)하여 phonebook.dat에, 전체보기함수의 출력코드를 사용하여 cout을 fout으로 바꾸어서, contact에 현재 저장된 모든 내용들을 저장합니다. , 5는 종료 (while 종결조건에 false되게 함)

