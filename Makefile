
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

SRC_DIR=src
HEADER_DIR=$(SRC_DIR)/headers
IMPL_DIR=$(SRC_DIR)
TEST_DIR=$(SRC_DIR)/tests
BUILD_DIR=build
EXECUTABLE=lmp

CC=clang

lmp: src/main.c out_dir
	$(CC) -o $(BUILD_DIR)/bin/$(EXECUTABLE) -I$(HEADER_DIR) $(SRC_DIR)/main.c

test: lmp
	cp doc/myTestLiterateProgram.lmp bin/
	cd bin; ./lmp myTestLiterateProgram.lmp

clean:
	rm -Rf $(BUILD_DIR)

out_dir: # Output directory structure
	mkdir -p $(BUILD_DIR)/bin #$(BUILD_DIR)/obj

new_header: 
	.scripts/new_header.sh $(name) $(HEADER_DIR)

new_impl: 
	.scripts/new_impl.sh $(name) $(SRC_DIR)

