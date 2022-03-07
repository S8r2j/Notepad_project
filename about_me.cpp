#include "about_me.h"
#include "ui_about_me.h"

about_me::about_me(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about_me)
{
    ui->setupUi(this);
//    QFile file("C:/Users/myide/Documents/notepad/resume.txt");
//    if(!file.open(QFile::ReadOnly| QFile::Text))
//    {
//        QMessageBox::warning(this,"Info","This file cannot be opened");
//    }
//    QTextStream out(&file);
//    QString text= out.readAll();
//    ui->textBrowser->setPlainText(text);
//    file.flush();
    QString str= ("Suraj Sharma,,surajaskmini@gmail.com..+977 9819692679,,Dharan, Janakpur..EDUCATION,,Bachelor of Engineering (B.E), Computer Science & Engineering,,Purwanchal Campus,,2019 - 2023..Senior Secondary (XII), Science,,NASA National Secondary School,,(NATIONAL EXAMINATION BOARD board),,Year of completion: 2019,,CGPA: 3.25/4..Secondary (X),,New English HIgher Secondary Boarding School,,(NEB board),,Year of completion: 2017,,CGPA: 3.22/4..TRAININGS/ COURSES,,Web Design,,ACES(Association Of Computer Engineering Students), Dharan,,Mar 2019 - Mar 2019,,Association of Computer Engineering Students had organized one week of web design crash course which was about to make us aware about the process through which basic websites can be mad..ACADEMICS/ PERSONAL PROJECTS,,Database Management System,,https://drive.google.com/drive/folders/1Wiwe4IT7fUlorSeLICP1DzKqzOFgBmlv?usp=sharing,,I had worked on MY SQL for the database management. This project is the console based management system. I used C++ language to link with the database and modify those database using cpp language.,,Restaurant Management Service,,https://drive.google.com/drive/folders/1SRWVYIrucY58idLOst_bzVD734JqZmGt?usp=sharing,,I had made a project of UI from Qt creator. This project allows the user to select their preferred items by themselves without asking for any help in the restaurant. This will allow the restaurants to provide quality services to the customer..SKILLS,,C++ Programming,,Intermediate,,MySQL,,Beginner,,Data Structures,,Beginner..ACCOMPLISHMENTS,,I have been recognized by Microsoft as the Microsoft Innovative Educator");
    str.replace(",,","\n");
    str.replace("..","\n\n");
    ui->textBrowser->setText(str);
}

about_me::~about_me()
{
    delete ui;
}
