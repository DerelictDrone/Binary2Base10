Developed with Borland TurboC++ for dos using the following settings:

Compiler
	Code Generation
		Model: Large
		Assume SS Equals DS: Default for memory model
		[ ] Treat enums as ints
		[ ] Word alignment
		[X] Unsigned characters
		[X] Pre-compiled headers
		No Defines
	Advanced Code Generation
		Floating Point: Emulation
		Instruction Set: 8088/8086
		[X] Generate underbars
		[ ] Line numbers debug info
		[X] Debug info in OBJs
		[X] Fast floating point
		[X] Fast huge pointers
		[ ] Generate COMDEFs
		[X] Automatic far data
		Far Data Threshold: 32767
	Entry/Exit Code Generation
		Prolog/Epilog Code Generation: Standard
		Calling Convention: C
		[X] Standard stack frame
		[ ] Test stack overflow
	C++ Options
		Use C++ Compiler: CPP extension
		Template Generation: Smart
		C++ Virtual Tables: Smart
		[X] Out-of-line inline functions
		[ ] Far virtual tables
	Optimization Options
		[ ] Suppress Redundant Loads
		[ ] Jump optimization
		Register Variables: Automatic
		Optimize for: Size
	Source Options:
		Keywords: Turbo C++
		[ ] Nested comments
		Identifier Length: 32
Make
	Break Make On: Errors
	After Compiling: Run linker
Linker
	[ ] Initialize Segments
	[X] Default libraries
	[ ] Warn duplicate Symbols
	[X] "No stack" warning
	[X] Case-sensitive link
	Map File: Off
	Output: Standard EXE
Debugging
	Source Debugging: On
	Display Swapping: Smart
	[X] Show inherited
	[X] Show methods
	Show both (hex and decimal)
	Program Heap Size: 64K bytes