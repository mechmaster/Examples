#include <QApplication>

#include "MyWidget.h"

int main(int argc, char *argv[])
{
  QApplication a(argc,argv);

  MyWidget form;
  form.EmitSignal();

  return a.exec();
}
