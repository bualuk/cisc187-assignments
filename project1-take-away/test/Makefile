ok       := (echo -e "\033[1;32mOK\033[0m")
fail     := (echo -e "\033[1;31mfail\033[0m"; exit 1)
srcs=   ../options.cpp \
		../game.cpp \
		../computer_player.cpp 

objs=$(srcs:%.cpp=%.o)
incl=$(srcs:%.cpp=%.h)
CXX=g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
CXXFLAGS+= -Wno-write-strings
INCLUDES+=-I../../../examples/ -I/var2/lopt/include

CXXFLAGS+= ${INCLUDES}

files    := $(incl) $(srcs) ../main.cpp

PROGS := step1 step2 step3 step4 step5 step6 step7 step8 step9 step10 step11 step12 step13

.PHONY: clean $(PROGS)

all: ${PROGS}

step1:
	@for f in $(files); do \
		echo -n "verify $$f exists: "; \
		test -r $$f && $(ok) || $(fail); \
	done

step2: clean
	@echo -e "\033[1;32mtest struct mesa::option\033[0m"
	$(CXX) ${CXXFLAGS} ${@}.cpp -o $@ 
	./$@

step3: clean
	@echo -e "\033[1;32mtest usage\033[0m"
	$(CXX) ${CXXFLAGS} ${@}.cpp ../options.cpp -o $@ 
	./$@

step4: clean
	@echo -e "\033[1;32mtest help\033[0m"
	$(CXX) ${CXXFLAGS} ${@}.cpp ../options.cpp -o $@ 
	./$@

step5: clean
	@echo -e "\033[1;32mtest get_options\033[0m"
	$(CXX) ${CXXFLAGS} -Wno-writable-strings ${@}.cpp ../options.cpp -o $@ 
	./$@

step6: clean
	@echo -e "\033[1;32mtest get_entry\033[0m"
	$(CXX) ${CXXFLAGS} ${@}.cpp ../options.cpp ../game.cpp ../computer_player.cpp -o $@ 
	./$@

step7: clean
	@echo -e "\033[1;32mtest get_value\033[0m"
	$(CXX) ${CXXFLAGS} ${@}.cpp ../options.cpp ../game.cpp ../computer_player.cpp -o $@ 
	./$@

step8: clean
	@echo -e "\033[1;32mtest computer_player take_one\033[0m"
	$(CXX) ${CXXFLAGS} ${@}.cpp ../computer_player.cpp -o $@ 
	./$@

step9: clean
	@echo -e "\033[1;32mtest computer_player take_some\033[0m"
	$(CXX) ${CXXFLAGS} ${@}.cpp ../computer_player.cpp -o $@ 
	./$@

step10: clean
	@echo -e "\033[1;32mtest computer_player evaluate\033[0m"
	$(CXX) ${CXXFLAGS} ${@}.cpp ../computer_player.cpp -o $@ 
	./$@

clean : 
	rm -rf ${PROGS} *.dSYM






