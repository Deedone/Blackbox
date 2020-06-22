

.PHONY: install

blackbox: 
	gcc main.c -lX11 -o blackbox

install: blackbox
	cp blackbox /usr/bin/blackbox 


