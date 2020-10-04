#include "FL_Flex.H"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>

#include <iostream>
#include <string>
#include <vector>

Fl_Button* createButton(const char* caption)
{
  Fl_Button *rtn = new Fl_Button(0, 0, 100, 25, caption);
  rtn->color(fl_rgb_color(225, 225, 225));

  return rtn;
}

void buttonsPanel(Fl_Flex* parent)
{
  new Fl_Box(0, 0, 0, 0, "");
  Fl_Box* w = new Fl_Box(0, 0, 0, 0, "Welcome to Flex Login");

  Fl_Flex* urow = new Fl_Flex(Fl_Flex::ROW);
  {
    Fl_Box* b = new Fl_Box(0, 0, 0, 0, "Username:");
    b->align(FL_ALIGN_INSIDE | FL_ALIGN_RIGHT);
    Fl_Input *username = new Fl_Input(0, 0, 0, 0, "");

    urow->setSize(username, 180);
    urow->end();
  }

  Fl_Flex* prow = new Fl_Flex(Fl_Flex::ROW);
  {
    Fl_Box* b = new Fl_Box(0, 0, 0, 0, "Password:");
    b->align(FL_ALIGN_INSIDE | FL_ALIGN_RIGHT);
    Fl_Input *password = new Fl_Input(0, 0, 0, 0, "");

    prow->setSize(password, 180);
    prow->end();
  }

  Fl_Box* pad = new Fl_Box(0, 0, 0, 0, "");

  Fl_Flex* brow = new Fl_Flex(Fl_Flex::ROW);
  {
    new Fl_Box(0, 0, 0, 0, "");
    Fl_Button *reg = createButton("Register");
    Fl_Button *login = createButton("Login");

    brow->setSize(reg, 80);
    brow->setSize(login, 80);
    brow->end();
  }

  Fl_Box* b = new Fl_Box(0, 0, 0, 0, "");

  new Fl_Box(0, 0, 0, 0, "");

  parent->setSize(w, 60);
  parent->setSize(urow, 30);
  parent->setSize(prow, 30);
  parent->setSize(pad, 1);
  parent->setSize(brow, 30);
  parent->setSize(b, 30);
}

void middlePanel(Fl_Flex* parent)
{
  new Fl_Box(0, 0, 0, 0, "");

  Fl_Box *box = new Fl_Box(0, 0, 0, 0, "Image");
  box->box(FL_BORDER_BOX);
  box->color(fl_rgb_color(0, 200, 0));
  Fl_Box *spacer = new Fl_Box(0, 0, 0, 0, "");

  Fl_Flex* bp = new Fl_Flex(Fl_Flex::COLUMN);
  buttonsPanel(bp);
  bp->end();

  new Fl_Box(0, 0, 0, 0, "");

  parent->setSize(box, 200);
  parent->setSize(spacer, 10);
  parent->setSize(bp, 300);
}

void mainPanel(Fl_Flex* parent)
{
  new Fl_Box(0, 0, 0, 0, "");

  Fl_Flex* mp = new Fl_Flex(Fl_Flex::ROW);
  middlePanel(mp);
  mp->end();

  new Fl_Box(0, 0, 0, 0, "");

  parent->setSize(mp, 200);
}

int main(int argc, char **argv) {
  Fl::scheme("gtk+");
  //Fl::scheme("gleam");
  //Fl::scheme("plastic");

  Fl_Window *window = new Fl_Double_Window(100, 100, "Simple GUI Example");
  {
    Fl_Flex* col = new Fl_Flex(5, 5, 90, 90, Fl_Flex::COLUMN);
    mainPanel(col);
    col->end();

    window->resizable(col);
    window->color(fl_rgb_color(250, 250, 250));
    window->end();
  }

  window->resize(0, 0, 640, 480);
  window->size_range(550, 250);
  window->show(argc, argv);

  return Fl::run();
}
