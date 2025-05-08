# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Source and object files
SRCDIR = .
CLASSDIR = class
OBJDIR = obj

SOURCES = $(SRCDIR)/main.cpp $(CLASSDIR)/pawn.cpp $(CLASSDIR)/map.cpp
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(notdir $(SOURCES)))

TARGET = main

# Create object directory if it doesn't exist
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(CLASSDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Clean build files
.PHONY: clean
clean:
	rm -rf $(OBJDIR) *.o $(TARGET)

