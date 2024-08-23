CC = gcc
#CFLAGS = -Wall -pedantic -g -Werror
STRUCT = struct
STR = str

all: ascii delta_time padding_example printable square car multiplebitfield threebitfield frequency gets_puts str_upper string_sort strlen

ascii: 
	$(CC) $@.c -o $@

delta_time: 
	$(CC) $@.c -o $@

padding_example:
	$(CC) $(STRUCT)/$@.c -o $(STRUCT)/$@

printable:
	$(CC) $@.c -o $@

square:
	$(CC) $@.c -lm -o $@

car:
	$(CC) $(STRUCT)/$@.c -o $(STRUCT)/$@

multiplebitfield:
	$(CC) $(STRUCT)/$@.c -o $(STRUCT)/$@

threebitfield:
	$(CC) $(STRUCT)/$@.c -o $(STRUCT)/$@

frequency:
	$(CC) $(STR)/$@.c -o $(STR)/$@

gets_puts:
	$(CC) $(STR)/$@.c -o $(STR)/$@

#printf:
#	$(CC) $(STR)/$@.c -o $(STR)/$@

str_upper:
	$(CC) $(STR)/$@.c -o $(STR)/$@

string_sort:
	$(CC) $(STR)/$@.c -o $(STR)/$@

strlen:
	$(CC) $(STR)/$@.c -o $(STR)/$@

#$(STRUCT)_with_flexible_array:
#	$(CC) $(STRUCT)/$@.c -o $(STRUCT)/$@

#volatile:
#	$(CC) $@.c -o $@

clean:
	rm -rf ascii delta_time padding_example printable square $(STRUCT)/car $(STRUCT)/multiplebitfield $(STRUCT)/threebitfield $(STRUCT)/padding_example $(STR)/frequency $(STR)/gets_puts $(STR)/printf $(STR)/str_upper $(STR)/string_sort $(STR)/strlen 
