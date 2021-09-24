#include "FL_Flex.H"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>

#include <iostream>
#include <string>

Fl_Button* createButton(const char* caption)
{
  Fl_Button *rtn = new Fl_Button(0, 0, 120, 30, caption);
  rtn->color(fl_rgb_color(225, 225, 225));

  return rtn;
}

Fl_Flex* createMiddle()
{
  Fl_Flex* row = new Fl_Flex(Fl_Flex::ROW);
  {
    Fl_Button *cancel = createButton("Cancel");
    Fl_Box *box = new Fl_Box(0, 0, 120, 10, "Box");
    Fl_Button *ok = createButton("OK");
    Fl_Input *input = new Fl_Input(0, 0, 120, 10, "");

    Fl_Flex* col2 = new Fl_Flex(Fl_Flex::COLUMN);
    {
      createButton("Top");
      col2->end();
    }

    row->setSize(box, 30);
    row->setSize(col2, 100);
    row->end();
  }

  return row;
}

int main(int argc, char **argv) {
  Fl::scheme("gtk+");
  //Fl::scheme("gleam");
  //Fl::scheme("plastic");

  Fl_Window *window = new Fl_Double_Window(100, 100, "Simple GUI Example");
  {
    Fl_Flex* col = new Fl_Flex(5, 5, 90, 90, Fl_Flex::COLUMN);
    {
      Fl_Flex* row = new Fl_Flex(Fl_Flex::ROW);
      {
        Fl_Button *cancel = createButton("Cancel");
        Fl_Box *box = new Fl_Box(0, 0, 120, 10, "Box");
        Fl_Button *ok = createButton("OK");
        Fl_Input *input = new Fl_Input(0, 0, 120, 10, "");

        Fl_Flex* col2 = new Fl_Flex(Fl_Flex::COLUMN);
        {
          col2->resizable(createButton("Top"));
          createButton("Bottom");
          col2->end();
        }

        row->resizable(box);
        row->end();
      }
      col->setSize(createMiddle(), 30);
      Fl_Button *ub1 = createButton("Something1");
      row = new Fl_Flex(Fl_Flex::ROW);
      {
        Fl_Button *cancel = createButton("Cancel");
        Fl_Button *ok = createButton("OK");
        Fl_Input *input = new Fl_Input(0, 0, 120, 10, "");

        row->setSize(cancel, 100);
        row->setSize(ok, 100);
        row->end();
      }
      Fl_Button *ub2 = createButton("Something2");

      col->setSize(row, 30);
      col->end();
    }
    window->resizable(col);
    window->color(fl_rgb_color(250, 250, 250));
    window->end();
  }

  window->size_range(550, 250);
  window->resize(0, 0, 640, 480);
  window->show(argc, argv);
  return Fl::run();
}
