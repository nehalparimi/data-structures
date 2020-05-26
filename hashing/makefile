CC = g++
CFLAGS = -Wall
LLDIR = ../linkedlist
NODE_H = $(LLDIR)/node.h
LINKED_LIST = $(LLDIR)/linked-list.cpp


hm: hashmap.cpp $(NODE_H) $(LINKED_LIST)
	$(CC) hashmap.cpp $(LINKED_LIST) -o hm $(CFLAGS) -std=c++11
clean:
	rm hm
