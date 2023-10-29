dcpu : dcpu.c
	cc -o dcpu dcpu.c
install :
	cp dcpu /usr/local/bin/
