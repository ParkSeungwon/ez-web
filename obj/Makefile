CXX = g++
OBJ = $(wildcard *.src.o)
EXE = $(patsubst %.x, ../%.x, $(wildcard *.x))
LDFLAGS = -L.. -Wl,-rpath=.
LDLIBS = -lzeta -lmysqlcppconn -ljsoncpp -lpthread -lrt -lstdc++fs
#filesystem library should be next to zeta library

all : ../libzeta.so $(EXE)

../libzeta.so : $(wildcard *.tcpip.o) $(wildcard *.database.o)
	$(CXX) -shared -o $@ $^

../%.src.x : %.src.x $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

#    $@ |현재 목표 파일의 이름
#    $* | 확장자를 제외한 현재 목표 파일의 이름
#    $< | 현재 필수 조건 파일 중 첫 번째 파일 이름
#    $? | 현재 대상보다 최슨에 변경된 함수 조건 파일 이름
#    $^ | 현재 모든 필수 조건 파일들

