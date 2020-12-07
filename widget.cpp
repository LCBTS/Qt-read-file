 #include "widget.h"
#include "ui_widget.h"
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextCodec>
//文件流
//文本流
//数据流  二机制格式的
#include<QTextStream>  //操作的数据类型，基础数据类型 ：int ，float  ，atring。
#include<QDataStream>//qlmage  apoint  qrect1,不依赖平台
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
//      QString file= QFileDialog::getOpenFileName(this,"open","D://");
//      if(file.isEmpty()==true)
//      {
//          QMessageBox::warning(this,"warning","selaect file faild");
//      return;
//      }
//      ui->lineEdit->setText(file);
//      //创建一个文件对象
//      //默认读取文件格式：utf8
//      QFile filename(file);
//      QTextCodec*code=QTextCodec::codecForName("gdk");
//      //指定打开方式
//      bool isok=filename.open(QFile::ReadOnly);
//     if(isok==false)
//     {
//         QMessageBox::critical(this,"error","file open falid");
//         return;
//     }
//     //读文件
////    QByteArray array= filename.readAll();
//     //读行的方法
//     QByteArray array;
//     while(!filename.atEnd())
//     {
//         array+=filename.readLine();
//     }
//    //显示文本框
//    ui->textEdit->setText(code->toUnicode(array));
//    //写文件
//    char buf[128]={0};
//    filename.write(QString("happy").toUtf8());
//    filename.write(buf,strlen(buf))
//     filename.write(buf);
//    //关闭文件
//    filename.close();
//    });
//////////////////////////文件流
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
      QString file= QFileDialog::getOpenFileName(this,"open","D://");
      if(file.isEmpty()==true)
      {
          QMessageBox::warning(this,"warning","selaect file faild");
      return;
      }
      ui->lineEdit->setText(file);
      //创建一个文件对象
      //默认读取文件格式：utf8
      QFile filename(file);
      //指定打开方式
      bool isok=filename.open(QFile::ReadOnly);
     if(isok==false)
     {
         QMessageBox::critical(this,"error","file open falid");
         return;
     }
  //创建流对象
     QTextStream strea(&filename);//设置io设备给流对象
     //读行的方法
     QByteArray array;
     strea.readAll();
     while(false==strea.atEnd())

     {
         array+=filename.readLine();
     }
//    //显示文本框
     ui->textEdit->setText(array);
    //关闭文件
    filename.close();
    });

}

Widget::~Widget()
{
    delete ui;
}
