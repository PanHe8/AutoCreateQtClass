#ifndef QTCLASSTEMPLATE_H
#define QTCLASSTEMPLATE_H

constexpr const char* widgets_ui = R"(<ui version="4.0">
 <author/>
 <comment/>
 <exportmacro/>
 <class>TestWidgets</class>
 <widget class="QWidget" name="TestWidgets">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>400</width>
    <height>300</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Form</string>
  </property>
 </widget>
 <pixmapfunction/>
 <connections/>
</ui>
)";

constexpr const char* widgets_h = R"(#ifndef TESTWIDGETS_H
#define TESTWIDGETS_H

#include <QWidget>

namespace Ui {
class TestWidgets;
}

class TestWidgets : public QWidget
{
    Q_OBJECT

public:
    explicit TestWidgets(QWidget *parent = nullptr);
    ~TestWidgets();

private:
    Ui::TestWidgets *ui;
};

#endif // TESTWIDGETS_H
)";

constexpr const char* widgets_cpp = R"(#include "testwidgets.h"
#include "ui_testwidgets.h"

TestWidgets::TestWidgets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidgets)
{
    ui->setupUi(this);
}

TestWidgets::~TestWidgets()
{
    delete ui;
}
)";

constexpr const char* dialog_ui = R"(<ui version="4.0">
 <class>TestDialog</class>
 <widget class="QDialog" name="TestDialog">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>400</width>
    <height>300</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Dialog</string>
  </property>
 </widget>
 <resources/>
 <connections/>
</ui>
)";

constexpr const char* dialog_h = R"(#ifndef TESTDIALOG_H
#define TESTDIALOG_H

#include <QDialog>

namespace Ui {
class TestDialog;
}

class TestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestDialog(QWidget *parent = nullptr);
    ~TestDialog();

private:
    Ui::TestDialog *ui;
};

#endif // TESTDIALOG_H
)";

constexpr const char* dialog_cpp = R"(#include "testdialog.h"
#include "ui_testdialog.h"

TestDialog::TestDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestDialog)
{
    ui->setupUi(this);
}

TestDialog::~TestDialog()
{
    delete ui;
}
)";


#endif //QTCLASSTEMPLATE_H