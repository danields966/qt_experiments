#include "window.h"

#include <QApplication>

#include <QtWidgets>

#include "coloritem.h"
#include "robot.h"

#include <calculator.h>
#include <math.h>
#include "mainwindow.h"

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene)
    {
    }

protected:
    void resizeEvent(QResizeEvent *) override
    {
    }
};

int main(int argc, char **argv)
{

    QApplication app(argc, argv);
    Window w;
    w.show();

    QDesktopWidget widget;
    QRect screenGeometry = widget.screenGeometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();
    int x=(width - w.width()) / 4.0;
    int y=(height - w.height()) / 4.0;
    w.setGeometry(x,y,w.width(),w.height());
    w.show();

    Calculator calc;
    calc.setGeometry(x,y*3,calc.width(),calc.height());
    calc.show();
    // return a.exec();

    // QApplication app(argc, argv);

    QGraphicsScene scene(-200, -200, 400, 400);

    for (int i = 0; i < 10; ++i) {
        ColorItem *item = new ColorItem;
        item->setPos(::sin((i * 6.28) / 10.0) * 150,
                     ::cos((i * 6.28) / 10.0) * 150);

        scene.addItem(item);
    }

    Robot *robot = new Robot;
    robot->setTransform(QTransform::fromScale(1.2, 1.2), true);
    robot->setPos(0, -20);
    scene.addItem(robot);
    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(230, 200, 167));
    view.setWindowTitle("Drag and Drop Robot");
    view.setGeometry(x*3,y,view.width(),view.height());
    view.show();

    Q_INIT_RESOURCE(qhexedit);
    // QApplication app(argc, argv);
    app.setApplicationName("QHexEdit");
    app.setOrganizationName("QHexEdit");
    app.setWindowIcon(QIcon(":images/qhexedit.ico"));

    // Identify locale and load translation if available
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("qhexedit_") + locale);
    app.installTranslator(&translator);

    QCommandLineParser parser;
    parser.addPositionalArgument("file", "File to open");
    parser.addHelpOption();
    parser.process(app);
    MainWindow *mainWin = new MainWindow;
    if(!parser.positionalArguments().isEmpty())
        mainWin->loadFile(parser.positionalArguments().at(0));
    mainWin->show();

    return app.exec();
}

