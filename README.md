### Summary

Sample project that demonstrates how to use xerces-c 3.1 to parse out the book titles from books.xml using the xerces-c DOM API. This is an old hat exercise, but a necessary one to compile and run legacy applications on new target platforms.

### Requirements
* xercesc 3.1.x
* valgrind

### To Run

    make
    ./xml_parser

### Memory validation

    make memcheck

Uses valgrind to verify that there are no memory leaks present.