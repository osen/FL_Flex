CXXFLAGS=`fltk-config --cxxflags`
LDFLAGS=`fltk-config --ldflags`

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
