Static libraries are just collections of object files that are linked into the program during the linking phase of compilation, and are not relevant during runtime. 'ar' which stand for 'archiver' is a basic tool used to create static libraries. Furthermore, stactic libraries end with .a extension which stand for 'archive'.
 
libmy.a file is a static library that contains a list of specific functions

create_static_lib.sh is a script that creates a static library called liball.a from all the .c files that are in the current directory.
