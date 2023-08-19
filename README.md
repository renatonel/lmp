# Literate My Program
This is my go at a literate programming system.  

The input is a set of markdown files. Output is the source files and executables when tangled, and HTML files when weaved.

## Building
`make`

## Running
To run it: `lmp myTestLiterateProgram.lmp`, which will both wave and
tangle the program.

To just weave: `lmp --weave myTestLiterateProgram.lmp`
To just tangle: `lmp --tangle myTestLiterateProgram.lmp`

## Developing
To create new header file
	`make new_header name=<filename>`

To create new implementation file
	`make new_impl name=<filename>`

To create both new header and implementation file
	`make new_header new_impl name=<filename>`

Note that you do not add the file extension after `name=<filename>`
