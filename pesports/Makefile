file=pe-sports-03.cpp
help:
	@echo "I am a Makefile you can just call make without any argument!"
	@echo "To compile the pesports application call make with the compile argument like this"
	@echo "    make compile"

compile:
	g++ pe-sports-01.cpp  -o pe-sports-01 2>&1 | head -n 6 
	g++ pe-sports-02.cpp  -o pe-sports-02 2>&1 | head -n 6 
	g++ xpe-sports-03.cpp  -DXPE  -o xpe-sports-03 2>&1 | head -n 6
	
format:
	astyle $(file)
	# clang-format -i $(file)
