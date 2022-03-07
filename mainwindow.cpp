#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->setPlainText("");
}

void MainWindow::on_actionSave_triggered()
{
    QString savef= QFileDialog::getSaveFileName(this,"Save");
    if(savef.isEmpty())
    {
        return;
    }
    else
    {
        QFile file(savef);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            return;
        }
        else
        {
            QTextStream ss(&file);
            ss<<ui->plainTextEdit->toPlainText()<<"\n";
            file.close();
        }
    }
}


void MainWindow::on_actionOpen_triggered()
{

   QString fyl= QFileDialog::getOpenFileName(this,"open a file");
   if(!fyl.isEmpty())
   {
       QFile file(fyl);
       if(file.open(QFile::ReadOnly|QFile::Text))
       {
           notepadfile=fyl;
           QTextStream rd(&file);
           QString text = rd.readAll();
           file.close();
           ui->plainTextEdit->setPlainText(text);
       }
   }
}


void MainWindow::on_actionExit_triggered()
{
    exit(0);
}


void MainWindow::on_actionCut_triggered()
{
    ui->plainTextEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->plainTextEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->plainTextEdit->paste();
}


void MainWindow::on_actionDelete_triggered()
{
    ui->plainTextEdit->textCursor().selectedText().clear();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->plainTextEdit->redo();
}

void MainWindow::on_actionBold_triggered()
{
    ui->plainTextEdit->setStyleSheet("font-weight:bold,color-black");
}


void MainWindow::on_actionUnbold_triggered()
{
     ui->plainTextEdit->setStyleSheet("font-weight:normal,color-black");
}


void MainWindow::on_actionSuperscript_triggered()
{
   QString text = ui->plainTextEdit->textCursor().selectedText();
   QTextCharFormat chara;
   chara.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
   ui->plainTextEdit->textCursor().insertText(QString("%1").arg(text),chara);
    ui->plainTextEdit->textCursor().removeSelectedText();
}


void MainWindow::on_actionSubscript_triggered()
{
    QString text = ui->plainTextEdit->textCursor().selectedText();
    QTextCharFormat chara;
    chara.setVerticalAlignment(QTextCharFormat::AlignSubScript);
    ui->plainTextEdit->textCursor().insertText(QString("%1").arg(text),chara);
    ui->plainTextEdit->textCursor().removeSelectedText();
}


void MainWindow::on_actionAbout_Me_triggered()
{
    dev = new about_me (this);
    dev->show();
}






