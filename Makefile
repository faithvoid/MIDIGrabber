# Compiler settings
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

# RtMidi library location
RTMIDI_INC := /usr/local/include
RTMIDI_LIB := /usr/local/lib

# Executable name
TARGET := midiscanner

# Source files
SRCS := midiscanner.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Dependencies
DEPS := $(OBJS:.o=.d)

# Linker flags
LDFLAGS := -L$(RTMIDI_LIB) -lrtmidi

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@ -I$(RTMIDI_INC)

clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS)

-include $(DEPS)

