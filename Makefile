
TARGET = lcs_length_functions
BIN_DIR = bin
DEBUG_DIR = debug
RELEASE_DIR = release


CC = g++


CFLAGS += -std=c++1y


DEBUG_FLAGS += -g -O0


RELEASE_FLAGS += -O3 -s -DNDEBUG


LFLAGS += -std=c++1y


SOURCES += \
	main.cpp


first: release


bin_dir:
	mkdir -p $(BIN_DIR)


debug_dir: bin_dir
	mkdir -p $(BIN_DIR)/$(DEBUG_DIR)


release_dir: bin_dir
	mkdir -p $(BIN_DIR)/$(RELEASE_DIR)


debug: debug_dir $(SOURCES)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SOURCES) $(LFLAGS) -o $(BIN_DIR)/$(DEBUG_DIR)/$(TARGET)


release: release_dir $(SOURCES)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) $(SOURCES) $(LFLAGS) -o $(BIN_DIR)/$(RELEASE_DIR)/$(TARGET)


clean:
	rm -f $(BIN_DIR)/$(DEBUG_DIR)/$(TARGET)
	rm -f $(BIN_DIR)/$(RELEASE_DIR)/$(TARGET)

