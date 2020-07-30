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
    actualizaciones *c;

    for(int i=0;i<objetoo.size();i++){

        objetoo.at(i)->actualizar1(v_limit);//actualiza en object1
        bordercollision(objetoo.at(i)->getobject());//actualiza el choque con el borde

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

void MainWindow::platforms()
{
        obstaculos *plat = new obstaculos();
        scene->addItem(plat);
}

void MainWindow::bordercollision(actualizaciones *c)//son los choques con los bordes
{
    if (x == 1){
        if(c->get_posX()<(c->get_Radio())){
            c->set_vel(-5*c->get_e()*c->get_velX(),c->get_velY(),c->get_Radio(), c->get_posY()) ;//con el corde izquierdo
        }
        if(c->get_posX()>h_limit-c->get_Radio()*2){//posicion con el corde derecho.
            c->set_vel(-5*c->get_e()*c->get_velX(),c->get_velY(), c->get_posX(), c->get_posY());
        }
        if(c->get_posY()<((c->get_Radio()))){//choque con el corde superior.
            //scene->removeItem(objetoo.back());                //remueve 1
            //objetoo.removeAt(k);                              //lo elimina de la lista
        }
        if(c->get_posY()>v_limit){//choque con el corde inferior.
            c->set_vel(c->get_velX(),-5*c->get_e()*c->get_velY(), c->get_posX(), (v_limit));
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
        QTimer *timer5 = new QTimer();
        QObject :: connect(timer5, SIGNAL(timeout()), this, SLOT(platforms()));
        timer5->start(3000);
    }
}
