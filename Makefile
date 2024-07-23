CC := clang++
CFLAGS := -O3 -march=native -std=c++17 -Wall -Wextra -pipe
LIB := -Iinclude -Ilib/mysql/include -Llib/mysql/lib64 -lmysqlcppconnx

TARGET := openlibraryhub

.PHONY: all clean

all: $(TARGET)

$(TARGET): src/main.cpp
	@echo Construindo...
	$(CC) $(CFLAGS) $(LIB) $^ -o $@

clean:
	rm $(TARGET)
