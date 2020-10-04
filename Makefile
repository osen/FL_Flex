CXXFLAGS=-I/usr/local/include -I/usr/X11R6/include
LDFLAGS=-L/usr/local/lib -lfltk

LSRC= \
  login.cpp \
  FL_Flex.cpp

DSRC= \
  demo.cpp \
  FL_Flex.cpp

all:
	c++ -ologin $(CXXFLAGS) $(LSRC) $(LDFLAGS)
	c++ -odemo $(CXXFLAGS) $(DSRC) $(LDFLAGS)

clean:
	rm -f login
	rm -f demo
