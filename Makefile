CC := clang++
CFLAGS := -O3 -march=native -std=c++17 -Wall -Wextra -pipe
LDFLAGS := -Llib/mysql/lib64
LIB := -lmysqlcppconnx
INC := -Iinclude -Ilib/mysql/include

TARGET := openlibraryhub
SRC := src/util.cpp src/entities.cpp src/dao.cpp src/main.cpp
OBJ := $(SRC:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LIB) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
