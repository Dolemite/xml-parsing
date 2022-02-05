CPP_OPTIONS = -Wall -g
LIBS = -lxerces-c
TARGET = xml_parser

$(TARGET): xml_parser.o
	g++ -o $(TARGET) xml_parser.o $(LIBS)

xml_parser.o: xml_parser.cpp
	g++ $(CPP_OPTIONS) -c xml_parser.cpp

memcheck: $(TARGET)
	valgrind --leak-check=yes ./$(TARGET)

clean: 
	rm *.o xml_parser
