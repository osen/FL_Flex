#include "FL_Flex.H"

#include <FL/Fl.H>

bool Fl_Flex::_debug = false;

Fl_Flex::Fl_Flex(uchar direction) : Fl_Group(0, 0, 0, 0, 0) { type(direction); debug(); }

Fl_Flex::Fl_Flex(int w, int h, uchar direction) : Fl_Group(0, 0, w, h, 0) { type(direction); debug(); }

Fl_Flex::Fl_Flex(int x, int y, int w, int h, uchar direction) : Fl_Group(x, y, w, h, 0) { type(direction); debug(); }

Fl_Flex::Fl_Flex(int x, int y, int w, int h, const char *label) : Fl_Group(x, y, w, h, label) { type(ROW); debug(); }

void Fl_Flex::debug()
{
  // Color the rows and columns to help facilitate development.
  if (!_debug)
    return;

  if(type() == ROW)
  {
    color(fl_rgb_color(200, 0, 0));
    box(FL_BORDER_BOX);
  }
  else
  {
    color(fl_rgb_color(0, 0, 200));
    box(FL_BORDER_BOX);
  }
}

void Fl_Flex::resizeRow(int x, int y, int w, int h)
{
  int cc = children();
  int padW = w - _margin * 2;

  // Calculate total width minus padding
  for(int i = 1; i < cc; i++)
  {
    padW -= 5;
  }

  int cx = x + _margin;
  int nrs = 0;

  // Precalculate remaining size to resize to
  // Calculate non-resizable width total
  for(int i = 0; i < cc; i++)
  {
    Fl_Widget *c = child(i);

    if(isSetSize(c))
    {
      nrs += c->w();
    }
  }

  // Set children to shared width of remaining
  for(int i = 0; i < cc; i++)
  {
    Fl_Widget *c = child(i);

    if(isSetSize(c))
    {
      c->resize(cx, y + _margin, c->w(), h - _margin * 2);
    }
    else
    {
      c->resize(cx, y + _margin, (padW - nrs) / (cc - (int)setsized.size()), h - _margin * 2);
    }

    cx += c->w() + _pad;
  }
}

void Fl_Flex::resizeCol(int x, int y, int w, int h)
{
  int cc = children();
  int padH = h - _margin * 2;

  // Calculate total height minus padding
  for(int i = 1; i < cc; i++)
  {
    padH -= _pad;
  }

  int cy = y + _margin;
  int nrs = 0;

  // Precalculate remaining size to resize to
  // Calculate non-resizable height total
  for(int i = 0; i < cc; i++)
  {
    Fl_Widget *c = child(i);

    if(isSetSize(c))
    {
      nrs += c->h();
    }
  }

  // Set children to shared width of remaining
  for(int i = 0; i < cc; i++)
  {
    Fl_Widget *c = child(i);

    if(isSetSize(c))
    {
      c->resize(x + _margin, cy, w - _margin * 2, c->h());
    }
    else
    {
      // [cc - (int)setsized.size()] allows negative.
      // This is very handy to allow resizable items to have negative height
      // allowing one on the top and bottom to center contents even if container
      // is too small.
      c->resize(x + _margin, cy, w - _margin * 2,
        (padH - nrs) / (cc - (int)setsized.size()));
    }

    cy += c->h() + _pad;
  }
}

void Fl_Flex::resize(int x, int y, int w, int h)
{
  Fl_Widget::resize(x, y, w, h);

  if(type() == COLUMN)
  {
    resizeCol(x, y, w, h);
  }
  else
  {
    resizeRow(x, y, w, h);
  }
}

void Fl_Flex::end()
{
  Fl_Group::end();
  resize(x(), y(), w(), h());
}

void Fl_Flex::setSize(Fl_Widget* w, int size)
{
  w->resize(0, 0, size, size);

  for(size_t i = 0; i < setsized.size(); i++)
  {
    if(setsized.at(i) == w)
    {
      return;
    }
  }

  setsized.push_back(w);
}

bool Fl_Flex::isSetSize(Fl_Widget* w)
{
  for(size_t i = 0; i < setsized.size(); i++)
  {
    if(w == setsized.at(i))
    {
      return true;
    }
  }

  return false;
}

