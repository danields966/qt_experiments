#include <QApplication>
#include <QtWidgets>
#include <QIcon>

#include "lineedits/lineedits.h"
#include "calculator/calculator.h"
#include "dragdroprobot/coloritem.h"
#include "dragdroprobot/robot.h"
#include "hexeditor/hexwindow.h"

int main(int argc, char **argv)
{

    QApplication app(argc, argv);

    // Line Edits
    LineEdits lineedits;
    lineedits.setGeometry(100, 100, 450, 300);
    lineedits.show();

    // Calculator
    Calculator calc;
    calc.setGeometry(100, 500, calc.width(), calc.height());
    calc.show();

    // Hex Editor
    Q_INIT_RESOURCE(qhexedit);
    app.setApplicationName("QHexEdit");
    app.setOrganizationName("QHexEdit");
    app.setWindowIcon(QIcon(":images/qhexedit.ico"));

    QCommandLineParser parser;
    parser.addPositionalArgument("file", "File to open");
    parser.addHelpOption();
    parser.process(app);
    HexWindow *hexWin = new HexWindow;
    if(!parser.positionalArguments().isEmpty())
        hexWin->loadFile(parser.positionalArguments().at(0));
    hexWin->setGeometry(650, 100, 600, 350);
    hexWin->show();

    // Robot
    QGraphicsScene scene(-150, -150, 300, 300);

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
    view.setGeometry(650, 500, 350, 350);
    view.show();

    return app.exec();
}

