# PatternViewer
정의 : Micro Pattern Compiler 에 생성된 .pat 파일을 분석 및 사용자 편의 인터페이스 제공을 목표로 한다. 

# System Interfaces.
- Input은 Micro Pattern Compiler의 Output인 Object File(*.pat)이 사용된다.
- QT GUI의 interface는 FILE HEADER, COMMON HEADER, COMMON BODY, BLOCK HEADER, BLOCK BODY으로 구성한다.
- Object File(*.pat)은 QT 라이브러리를 통해 사용된다.

# 개발 환경
- OS : CentOS7-x86_64-DVD-2003
- VMware : VMware Workstation 15 Player-15.5.6-16341506
- Kernel : 3.10.0-1127.el7.x86_64
- GUI : Qt version 5.8.0 
- Editor
- QtCreator: 4.2.1
- GCC : 5.3.1 20160406(Red Hat 5.3.1-6),64bit

# Operation
진행 완료
-	사용자는 실행파일(.exe)를 이용하여 동작시킨다. 
-	QT에서 제공되는 QFileDialog Class를 이용하여 Object File(*.pat)를 Load를 한다.
-	Load 된 File를 GUI에서 Object File Format(*.pat)에 맞춰 데이터를 출력한다. 
-	사용자는 GUI에서 제공되는 함수를 이용하여 데이터를 검색할 수 있다. -> 구현 완료
-	Load 된 데이터에 대한 정보를 GUI 환경에서 출력한다. ->GUI 구현 완료 및 추가적으로 함수 작성 완료.
-	단어 검색 시, modeless dialog 기능을 제공한다.
-	원본 Object 파일(*.pat) 및 파일 포맷에 맞춘 View가 함께 제공된다. 


# 구현
# MainWindow 
![image](https://user-images.githubusercontent.com/58155067/144032374-7775420c-2b59-4604-b9d2-c40fcd1cc346.png)

# 파일 로드 후 1/2 
![image](https://user-images.githubusercontent.com/58155067/144032576-d3b37fd6-7fe7-48d5-811b-2423a3041281.png)

# 파일 로드 후 2/2 
![image](https://user-images.githubusercontent.com/58155067/144032647-cc0db992-0429-41b4-9bb2-2e6ecbd2155a.png)

