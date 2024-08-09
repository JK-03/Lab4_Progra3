#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QList>

class Figura;

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    void addFigura(Figura *figura);
    void clearFiguras();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QList<Figura*> figuras;
};

#endif // CANVAS_H
