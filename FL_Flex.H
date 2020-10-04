#include <FL/Fl.H>
#include <FL/Fl_Group.H>

#include <vector>

struct Fl_Flex : public Fl_Group
{
  static const int ROW = 0;
  static const int COLUMN = 1;

  Fl_Flex(int direction);
  Fl_Flex(int w, int h, int direction);
  Fl_Flex(int x, int y, int w, int h, int direction);

  virtual void end();
  virtual void resize(int x, int y, int w, int h);

  void setSize(Fl_Widget* w, int size);

private:
  //const size_t margin = 5;
  const size_t margin = 0;
  const size_t pad = 5;

  int direction;
  std::vector<Fl_Widget*> setsized;

  void debug();
  void resizeRow(int x, int y, int w, int h);
  void resizeCol(int x, int y, int w, int h);

  bool isSetSize(Fl_Widget* w);

}; 

