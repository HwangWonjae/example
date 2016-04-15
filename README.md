# example
# plog(c++ log library) example
+ 프로그램 개발할 때 사용하는 로그 라이브러리 래퍼
+ boost 라이브러리를 사용하여 싱글턴 패턴 적용하여 코드 어디서든 호출하여 사용가능
+ 환경변수를 사용하여 로그설정
+ 설정1: 로그를 남길 디렉터리 
+ 설정2: 로그 최대 파일 크기 
+ 설정3: 로그 파일 최대 개수
+ 윈도우용
+ Custom Appender를 사용하여 OutputDebugString() 함수 호출기능 추가(DebugView에서 로그 확인 가능)
