# mysh: mysh.c
# 	gcc mysh.c -o mysh
# run:
# 	./mysh
# clear:
# 	rm -f mysh

SRCS=mysh.c
TARG=mysh
CC=gcc
OPTS=-Wall -O
LIBS=

OBJS=$(SRCS:.c=.o)
$(TARG):$(OBJS)
	$(CC) -o $(TARG) $(OBJS)

%.o:%.c
	$(CC) -c $< -o $@

clear:
	rm -f $(OBJS) $(TARG)
r:
	./mysh

