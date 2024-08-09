#include "Canvas.h"
#include "Figura.h"
#include <QPainter>

Canvas::Canvas(QWidget *parent)
    : QWidget(parent)
{
}

void Canvas::addFigura(Figura *figura)
{
    figuras.append(figura);
    update();  // Actualizar el widget para que se repinte
}

void Canvas::clearFiguras()
{
    qDeleteAll(figuras);  // Elimina todas las figuras de la lista y libera memoria
    figuras.clear();      // Limpia la lista
    update();             // Actualizar el widget para que se repinte
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for (Figura *figura : figuras)
    {
        figura->dibujar(&painter);  // Pasar puntero a QPainter
    }
}
