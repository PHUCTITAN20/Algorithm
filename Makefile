CC=gcc
CXX=g++
CFLAGS=-std=c99 -Wall
CXXFLAGS=-std=c++11 -Wall
BIN=bin

C_TARGETS= \
$(BIN)/Cau_1 \
$(BIN)/Cau_2 \
$(BIN)/Cau_3 \
$(BIN)/Cau_4 \
$(BIN)/Cau_5 \
$(BIN)/Cau_6 \
$(BIN)/Cau_7 \
$(BIN)/Cau_8 \
$(BIN)/Cau_9 \
$(BIN)/Cau_10 \

CPP_TARGETS= \
$(BIN)/BubbleSort \
$(BIN)/Insertionsort \
$(BIN)/QuickSort \
$(BIN)/Untitled-1 \
$(BIN)/Untitled-2

all: $(C_TARGETS) $(CPP_TARGETS)

$(BIN):
	mkdir -p $(BIN)

$(BIN)/Cau_1: DATA\ STRUCTURE/Cau_1.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_1.c' -o $@
$(BIN)/Cau_2: DATA\ STRUCTURE/Cau_2.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_2.c' -o $@
$(BIN)/Cau_3: DATA\ STRUCTURE/Cau_3.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_3.c' -o $@
$(BIN)/Cau_4: DATA\ STRUCTURE/Cau_4.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_4.c' -o $@
$(BIN)/Cau_5: DATA\ STRUCTURE/Cau_5.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_5.c' -o $@
$(BIN)/Cau_6: DATA\ STRUCTURE/Cau_6.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_6.c' -o $@
$(BIN)/Cau_7: DATA\ STRUCTURE/Cau_7.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_7.c' -o $@
$(BIN)/Cau_8: DATA\ STRUCTURE/Cau_8.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_8.c' -o $@
$(BIN)/Cau_9: DATA\ STRUCTURE/Cau_9.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_9.c' -o $@
$(BIN)/Cau_10: DATA\ STRUCTURE/Cau_10.c | $(BIN)
	$(CC) $(CFLAGS) 'DATA STRUCTURE/Cau_10.c' -o $@

$(BIN)/BubbleSort: agorithm/BubbleSort.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@
$(BIN)/Insertionsort: agorithm/Insertionsort.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@
$(BIN)/QuickSort: agorithm/QuickSort.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@
$(BIN)/Untitled-1: agorithm/Untitled-1.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@
$(BIN)/Untitled-2: agorithm/Untitled-2.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(BIN)
