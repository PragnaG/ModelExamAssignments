#include "widget.h"
#include<QTextEdit>
#include<QPushButton>
#include<QDebug>
#include<QLabel>
#include<QColorDialog>
#include<QFont>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //To create a FONT
    QFont labelFont("Times",20,QFont::Bold);

    //To create a LABEL
    QLabel *mLabel=new QLabel("This is My Sentence",this);

    //Set the FONT to LABEL
    mLabel->setFont(labelFont);

    //Move the LABEL
    mLabel->move(100,25);

    //To apply COLOR to LABEL and BACKGROUND COLOR to LABEL
    QPalette label;

        label.setColor(QPalette::Window,Qt::yellow);

        label.setColor(QPalette::WindowText,Qt::red);

        mLabel->setAutoFillBackground(true);

        mLabel->setPalette(label);

    //Create a TextEdit
        QTextEdit *text=new QTextEdit(this);

         text->move(70,55);

         connect(text,&QTextEdit::textChanged,[=](){

         qDebug()<<"Text Changed"; });

    //Create a PushButton for CUT
         QPushButton *cut=new QPushButton("cut",this);

          cut->setMinimumSize(50,25);

          cut->move(10,250);

          connect(cut,&QPushButton::clicked,[=](){

           text->cut(); });

    //Create a PushButton for COPY
          QPushButton *copy=new QPushButton("copy",this);

           copy->setMinimumSize(50,25);

           copy->move(110,250);

           connect(copy,&QPushButton::clicked,[=](){

            text->copy(); });

    //Create a PushButton for PASTE
                 QPushButton *paste=new QPushButton("paste",this);

                  paste->setMinimumSize(50,25);

                  paste->move(210,250);

                  connect(paste,&QPushButton::clicked,[=](){

                   text->paste(); });

     //Create a PushButton for UNDO
                  QPushButton *undo=new QPushButton("undo",this);

                    undo->setMinimumSize(50,25);

                    undo->move(10,280);

                    connect(undo,&QPushButton::clicked,[=](){

                     text->undo(); });

     //Create a PushButton for REDO
                   QPushButton *redo=new QPushButton("redo",this);

                       redo->setMinimumSize(50,25);

                       redo->move(110,280);

                       connect(redo,&QPushButton::clicked,[=](){

                        text->redo(); });


      //Create a PushButton for Html button

          QPushButton *html=new QPushButton("HTML",this);

           html->setMinimumSize(100,25);

           html->move(120,310);

           connect(html,&QPushButton::clicked,[=](){

            text->setHtml("<h1>Title</h1><p>Three districts:</br> <ul><li>X</li><li>Y</li><li>Z</li></ul></p>");  });

}

Widget::~Widget()
{

}

