SHELL := /bin/bash
OPTION = -j 3

all : 
	incltouch.x
	make $(OPTION) -C tcpip/
	make $(OPTION) -C src/
	make $(OPTION) -C database/
	make $(OPTION) -C obj/

clean :
	rm *.x obj/*.?
	rm *.so

# incltouch will touch source files, according to inclusion of header files.
# incltouch generate tree of header inclusion.
# So it can track inclusion tree. 
# But there is one including rule.
# Any header file that is made by you and will be edited should use " ", not < >.
# Any header files that will not be edited by you should use < >. ie)standard library.
# And you should alwasy use directory structure.
# root dir - src directories.
#          |- src2 directory
#          |- src3 : src name can vary.
#          |- obj : object files will be placed here
#          |- tst : test files will be placed here
# And you should not add include path except -I../ and library include directory.
# In the end, the header inclusion will be like #include "src/header.h" when
# it is in the different directory.
# Or "header.h" when it is in the same directory.

