#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include <QTextEdit>
#include "Canvas.h"
#include "ComandoNegrita.h"
#include "ComandoCursiva.h"
#include "ComandoSubrayado.h"
#include "InventarioModel.h"
#include "Electronico.h"
#include "Ropa.h"
#include "Alimento.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class cframe;
}
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_negritaButton_clicked();


    void on_cursivaButton_clicked();

    void on_subrayadoButton_clicked();

    void on_normalButton_clicked();

    void on_agregarBoton_clicked();

    void on_tipoProducto_currentIndexChanged(int index);

    void on_eliminarBoton_clicked();

    void on_modificarBoton_clicked();

private:
    Ui::cframe *ui;
    Canvas *canvas;
    QTextEdit *textEdit;
    InventarioModel *model;

    void actualizarEtiquetas();
};
#endif // CFRAME_H
