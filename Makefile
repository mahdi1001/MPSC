CXX=g++
CXXFLAGS += -std=c++14 -Wall -Werror -Wextra -pedantic-errors
LDFLAGS=-lpthread
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)

OUTPUT := mpsc


all: $(OBJECTS) $(OUTPUT)
.c.o:
	$(CXX) $(CXXFLAGS) $< -o $@
$(OUTPUT): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(OUTPUT)  $(OBJECTS) $(LDFLAGS)

Test: $(OBJECTS)
	ar -cvq libMPSC.a consumer.o producer.o queue.o sleepThread.o
install:
	mv libMPSC.a /usr/lib/
clean:
	$(RM) $(OUTPUT) 
	$(RM) $(wildcard *.o)
	$(RM) libMPSC.a
