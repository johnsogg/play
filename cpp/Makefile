# Points to the root of Google Test, relative to where this file is.
GTEST_DIR = /Users/johnsogg/Downloads/gtest-1.6.0

# All tests produced by this Makefile.  ADD TO THIS LIST.
TESTS = sample1_unittest sample9_unittest tree_test

# Where to find user code.
USER_DIR = .

# Flags passed to the preprocessor.
CPPFLAGS += -I$(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.

all : $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a tree_test *.o

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

sample1.o : $(USER_DIR)/sample1.cc $(USER_DIR)/sample1.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1.cc

sample1_unittest.o : $(USER_DIR)/sample1_unittest.cc \
                     $(USER_DIR)/sample1.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample1_unittest.cc

sample1_unittest : sample1.o sample1_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

sample9_unittest.o : $(USER_DIR)/sample9_unittest.cc \
                     $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/sample9_unittest.cc

sample9_unittest : sample9_unittest.o gtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

tree.o : $(USER_DIR)/tree.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/tree.cpp

tree_test.o : tree.o $(USER_DIR)/tree_test.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/tree_test.cpp

tree_test : tree_test.o tree.o RetroPrinter.o gtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

RetroPrinter.o : $(USER_DIR)/RetroPrinter.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_DIR)/RetroPrinter.cpp

