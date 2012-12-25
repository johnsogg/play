#
# Makefile
#
#   You will not need to edit this file. Read on if you are curious.
#
#   This is the script used by 'make' to compile and link your
#   program. The top part defines variables used later. Below, there
#   are targets.
#
#   A concrete example looks like this:
#
#   foo : foo.o $(USER_DIR)/foo_main.cpp
#   	$(CXX) $(CXXFLAGS) -c $(USER_DIR)/foo_main.cpp
#
#   Abstractly, the format is:
#
#   target_name : dependency1 dependency2 ... dependencyN
#   TAB_CHARACTER compiler command to build target_name
#
#   In the concrete example, the target is 'foo', and it depends on
#   two things: foo.o, and the file './foo.cpp'. This means that in
#   order for 'foo' to continue, it has to deal with its dependencies,
#   which may be other targets, or they may be files.
#
#   If the dependency is another target, that target will be run if
#   necessary. If the dependency is a file, it simply checks to see if
#   that file exists.
#
#   It is vitally important to note that after the list of
#   dependencies, there is a new line, and at the start of the next
#   line, before the compilation command, there must be a tab
#   character. If you use spaces (even if it is visually equivalent to
#   a tab character, 'make' will spray this in your eyeballs:
#
#   Makefile:43: *** missing separator.  Stop.
#
#   If you see this error, it means you are using spaces instead of a
#   tab. I realize this is dumb. Sadly, make is sort of of a standard.
#
#   Don't edit the remainder of this file. You may remove this
#   friendly comment block, though.

# Where to find user code.
USER_DIR = .

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra

# House-keeping build targets.

all : linked_list

clean :
	rm -f linked_list *.o

# Build targets for this project.

linked_list.o : $(USER_DIR)/linked_list.cpp
	$(CXX) $(CXXFLAGS) -c $(USER_DIR)/linked_list.cpp

linked_list_main.o : linked_list.o $(USER_DIR)/linked_list_main.cpp
	$(CXX) $(CXXFLAGS) -c $(USER_DIR)/linked_list_main.cpp

linked_list : linked_list_main.o linked_list.o
	$(CXX) $(CXXFLAGS) -lpthread $^ -o $@
