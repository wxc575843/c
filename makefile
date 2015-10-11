# a.out: hello.cpp
# 	clang++ hello.cpp
# r:
# 	/programs/c/a.out
# c:
# 	rm -f a.out

SRCS=hello.cpp
TARG=a.out
CC=clang++
OPTS=-Wall -O
LIBS=

OBJS=$(SRCS:.cpp=.o)
$(TARG):$(OBJS)
	$(CC) -o $(TARG) $(OBJS)

%.o:%.c
	$(CC) -c $< -o $@

c:
	rm -f $(OBJS) $(TARG)
r:
	/programs/c/a.out

