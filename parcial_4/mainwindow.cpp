#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);


    h_limit=1250;                   //Asigna los valores leidos el archivo
    v_limit=670;

    timer= new QTimer(this);
    timert= new QTimer(this);
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit

    ui->graphicsView->setScene(scene);
    ui->centralwidget->adjustSize();
    scene->addRect(scene->sceneRect());
    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer -> start(20);

    connect(timert,SIGNAL(timeout()),this,SLOT(actualizar1()));
    timert -> start(20);

    QTimer * timerr = new QTimer();
    connect(timerr,SIGNAL(timeout()),this,SLOT(creatobjeto()));

    timerr->start(1500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar()
{
    actualizaciones *b;

    for(int i=0;i<specialobject.size();i++){

        specialobject.at(i)->actualizar(v_limit);//actualiza en object
    }
}

void MainWindow::actualizar1()
{
    actualizaciones *b;

    for(int i=0;i<objetoo.size();i++){

        objetoo.at(i)->actualizar1(v_limit);//actualiza en object1
    }
}

void MainWindow::creatobjeto()
{
    objetoo.push_back(new object);
    objetoo[k] -> actualizar1(v_limit);
    objetoo[k] -> setFlag(QGraphicsItem::ItemIsFocusable);
    objetoo[k] -> setFocus();

    scene -> addItem(objetoo[k]);
    k+=1;
}

void MainWindow::bordercollision(actualizaciones *b)//son los choques con los bordes
{
    if (x == 1){
        if(b->get_posX()<(b->get_Radio())){
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(),b->get_Radio(), b->get_posY()) ;//con el borde izquierdo
        }
        if(b->get_posX()>h_limit-b->get_Radio()*2){//posicion con el borde derecho.
            b->set_vel(-1*b->get_e()*b->get_velX(),b->get_velY(), h_limit, b->get_posY());
            x=2;
            niveles();
        }
        if(b->get_posY()<((b->get_Radio()))){//choque con el borde superior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), (b->get_posX()), b->get_Radio());
        }
        if(b->get_posY()>v_limit){//choque con el borde inferior.
            b->set_vel(b->get_velX(),-1*b->get_e()*b->get_velY(), b->get_posX(), (v_limit));
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    x = 1;
    niveles();
    specialobject.push_back(new objeto);
    specialobject[w] -> actualizar(v_limit);
    specialobject[w] -> setFlag(QGraphicsItem::ItemIsFocusable);
    specialobject[w] -> setFocus();

    scene -> addItem(specialobject[w]);
    w+=1;
}

void MainWindow::niveles(){
    if(x == 0){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);
    }
    if(x == 1){
        scene->setSceneRect(0,0,(h_limit-55),v_limit);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
        ui->graphicsView->setScene(scene);
        ui->centralwidget->adjustSize();
        scene->addRect(scene->sceneRect());
        ui->graphicsView->resize(scene->width(),scene->height());
        this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    }
}
