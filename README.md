# FL_Flex
A sizer for FLTK which allows for laying out the interface using rows and columns.
This is a similar approach to that taken by the HTML Flexbox module.

```
// Create a column sizer
Fl_Flex* col = new Fl_Flex(Fl_Flex::COLUMN);

// Add two buttons to the column
Fl_Button* expanding = new Fl_Button(0, 0, 0, 0, "Expanding");
Fl_Button* normal = new Fl_Button(0, 0, 0, 0, "Normal");

// Set the height of the non expanding button to 30
col->setSize(normal, 30);
col->end();
```

```
// Create a row sizer
Fl_Flex* row = new Fl_Flex(Fl_Flex::ROW);

// Add two buttons to the row
Fl_Button* expanding = new Fl_Button(0, 0, 0, 0, "Expanding");
Fl_Button* normal = new Fl_Button(0, 0, 0, 0, "Normal");

// Set the width of the non expanding button to 100
row->setSize(normal, 100);
row->end();
```

## Login Sample
![Image of login sample](doc/login.png)

## Demo Sample
![Image of demo sample](doc/demo.png)
