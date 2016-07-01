# Examples
## `boost`와`plog`(c++ log library) 를 사용한 예제 코드
1. 코드 설명
- 프로그램 개발할 때 사용하는 로그 라이브러리 래퍼
- [boost v1.60](http://www.boost.org), [plog v1.0.1](https://github.com/SergiusTheBest/plog)라이브러리 필요
                - plog는 header only 형태로 라이브러리 파일이 없음 :-)
- 사용하기 편리한 인터페이스를 가지고 있음 :
-)
- boost 라이브러리를 사용하여 싱글턴 패턴 적용하여 코드 어디서든 호출하여 사용가능
- 환경변수를 사용하여 로그설정
- 설정1:
로그를 남길 디렉터리
- 설정2:
로그 최대 파일 크기
- 설정3:
로그 파일 최대 개수
- 윈도우용
- Custom Appender를 사용하여 OutputDebugString() 함수 호출기능 추가(DebugView에서 로그 확인 가능)
- OS 별 차이점
- Centos:
한 로그 파일에 여러개의 프로세스가 메시지를 하는 경우에도 정상동작함
- Windows(vs2008):한 로그 파일에 여러개의 프로세스가 메시지를 하는 경우 첫번째로 시작된 프로세스만 정상적으로 로그를 남기고 나머지 프로세는 정상적으로 파일을 쓰지 못함
    2. 기타 로그 라이브러리
    - spdlog
    - 기본 로그 기능에 파일명 및 라인번호가 표시되지 않음
    - 파일명 및 라인번호를 찍을 수 있는 기능이 있기는 한걸로 알고 있음
    - header only library
    - easyloggingc++
    - 로그파일 롤링 기능이 미제공
    - header only library
    - log4cplus
    - log4j와 비슷한 사용법
    - header only library 아님
