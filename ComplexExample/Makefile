CC = clang++
ARCH = -arch x86_64

# Flags for the C++ compiler - C++11 standard, full warnings
CFLAGS = -c -std=c++11 -Wall -Wpedantic

# Include path (add if needed)
INCFLAGS = 

# Flags for the linker (add if needed)
LDFLAGS = 

# Source files to compiler
SOURCES = Complex.cpp complexMain.cpp

# Object files to build - a .o file for each .cpp file
OBJECTS = $(SOURCES:.cpp=.o)

# Executable to build
EXECUTABLE = complexTest

# Build options

# By default, clean up and build the executable
default: clean $(EXECUTABLE);

# Compile object files from .cpp
.cpp.o:
	$(CC) $(CFLAGS) $(INCFLAGS) $< -o $@
	
# To build the target, link the object files together
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(ARCH) $(LDFLAGS) $(OBJECTS) -o $@
	
# To clean up, remove all object files, executable, Emacs temp files, core
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *~ core