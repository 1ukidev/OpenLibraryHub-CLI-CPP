CC := g++
CFLAGS := -Os -march=native -s -Wall -Wextra -std=c++17 -pipe
LIB := -Ilib/mysql/include -Llib/mysql/lib64 -lmysqlcppconnx

TARGET := openlibraryhub

.PHONY: all clean

all: $(TARGET)

$(TARGET): src/main.cpp
	@echo Construindo...
	$(CC) $(CFLAGS) $(LIB) $^ -o $@

clean:
	rm $(TARGET)
