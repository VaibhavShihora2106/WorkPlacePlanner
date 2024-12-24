#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsPathItem>
#include <QListWidgetItem>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QComboBox>
#include <QFileDialog>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addItemToScene(QListWidgetItem *item);
    void addProductToScene();
    void exportToXML();
    void uploadAssets();
    void importFromXML();
    void deleteSelectedItem();
    void zoomIn();
    void zoomOut();

    // New Menu Options
    void saveFile();
    void saveFileAs();
    void addTextField();
    void drawCircle();
    void drawRectangle();
    void drawTriangle();
    void enableCustomDrawing();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    QComboBox *productComboBox;
    double currentScaleFactor;

    // Custom Drawing
    QGraphicsPathItem *customPathItem;
    bool customDrawingEnabled;
    QPainterPath customPath;

    // Helper Functions
    void setupUI();
    void setupMenuBar();
    void drawGrid();
    void drawSections();
};

#endif // MAINWINDOW_H
