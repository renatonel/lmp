
# To make executable
# $ make
#
# To cleanup old builds
# $ make clean
#
# To create new header file
# 	make new_header name=filename
#
# To create new implementation file
# 	make new_impl name=filename
#
# To create both new header and implementation file
# 	make new_header new_impl name=filename

# Build Configuration
SRC_DIR=src
HEADER_DIR=$(SRC_DIR)/headers
IMPL_DIR=$(SRC_DIR)
TEST_DIR=$(SRC_DIR)/tests
BUILD_DIR=build
EXECUTABLE=lmp

CC=clang
DEBUG_OPTS=-g


# Main executable(s)
lmp: src/main.c out_dir
	$(CC) -o $(BUILD_DIR)/bin/$(EXECUTABLE) -I$(HEADER_DIR) $(SRC_DIR)/main.c

clean:
	rm -Rf $(BUILD_DIR)

doc: Doxyfile
	doxygen ./Doxyfile

# Dependencies
out_dir: # Output directory structure
	mkdir -p $(BUILD_DIR)/bin #$(BUILD_DIR)/obj


# Tests
test_linked_list: test_dir
	$(CC) $(DEBUG_OPTS) \
		-o $(BUILD_DIR)/tests/linked_list_test \
		-I$(HEADER_DIR) \
		$(TEST_DIR)/linked_list_test.c \
		$(IMPL_DIR)/linked_list.c
	
	$(BUILD_DIR)/tests/linked_list_test

test_keyvalue: test_dir
	$(CC) $(DEBUG_OPTS) \
		-o $(BUILD_DIR)/tests/keyvalue_test \
		-I$(HEADER_DIR) \
		$(TEST_DIR)/keyvalue_test.c \
		$(IMPL_DIR)/keyvalue.c

	$(BUILD_DIR)/tests/keyvalue_test


tests: test_dir test_linked_list test_keyvalue



test_dir: # location of test executables
	mkdir -p $(BUILD_DIR)/tests


# Scaffolding targets
new_header: 
	.scripts/new_header.sh $(name) $(HEADER_DIR)

new_impl: 
	.scripts/new_impl.sh $(name) $(SRC_DIR)

new_test:
	.scripts/new_test.sh $(name) $(TEST_DIR)
