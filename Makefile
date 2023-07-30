# clang -o <output> -I<inc-dir> srcfiles.c

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

HEADER_CONTENT="\
/** $(name).h\n\
 * \n\
 **/\n\
\n\
\#indef __$(name)_H__\n\
\#define __$(name)_H__\n\
\n\
int $(name)();\n\
\n\
\#endif\n"

IMPL_CONTENT="\
/** $(name).c\n\
 * \n\
 **/\n\
\n\
\#include <$(name).h>\n\
\n\
int $(name)() {\n\
}\
\n"

lmp: src/main.c out_dir
	clang -o bin/lmp src/main.c

test: lmp
	cp doc/myTestLiterateProgram.lmp bin/
	cd bin; ./lmp myTestLiterateProgram.lmp

clean:
	rm -Rf bin

out_dir: # Output directory structure
	mkdir -p bin

# create new include file
# usage:
# 	make new_header name=filename
# 	make new_header new_impl name=filename
new_header: 
	mkdir -p src/headers
	echo $(HEADER_CONTENT) > src/headers/$(name).h

# create new implementation file
# usage:
# 	make new_impl name=filename
# 	make new_header new_impl name=filename
new_impl: 
	mkdir -p src
	echo $(IMPL_CONTENT) > src/$(name).c
	
