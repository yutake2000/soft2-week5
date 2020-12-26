CC = gcc
TARGET = mtfuji
OBJS = mtfuji.o func1.o optimize.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

.PHONY: tmpclean clean

tmpclean:
	rm -f *~
clean: tmpclean
	rm -f $(TARGET) $(OBJS)
