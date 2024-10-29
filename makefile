CC = gcc
FLAGS = -g -o
CFLAGS = -fopenmp
TARGET = main
  
all: $(TARGET)
  
$(TARGET): *.c
	$(CC) $(FLAGS) $(TARGET) *.c $(CFLAGS)
  
clean:
	rm -f $(TARGET)

# gcc -g -o main main.c -fopenmp