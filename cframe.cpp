#include "cframe.h"
#include "ui_cframe.h"
#include "Tarea.h"
#include "TareaDiaria.h"
#include "TareaSemanal.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Triangulo.h"
#include "InventarioModel.h"
#include <QListWidget>
#include <QMessageBox>
#include <QInputDialog>

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
    , canvas(new Canvas(this))
{
    ui->setupUi(this);

    if (ui->canvasWidget) {
        QVBoxLayout *layout = new QVBoxLayout(ui->canvasWidget);
        layout->addWidget(canvas);
        ui->canvasWidget->setLayout(layout);
    } else {
    }

    this->setWindowTitle("Laboratorio #4");


    connect(ui->tipoProducto, SIGNAL(currentIndexChanged(int)), this, SLOT(on_tipoProducto_currentIndexChanged(int)));
    actualizarEtiquetas();

    connect(ui->eliminarBoton, &QPushButton::clicked, this, &cframe::on_eliminarBoton_clicked);

    // Configuración del QTableWidget
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Nombre" << "Precio" << "Detalles");

    // Configuración de selección
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

}

cframe::~cframe()
{
    delete ui;
    delete canvas;
}

void cframe::on_tipoProducto_currentIndexChanged(int index) {
    Q_UNUSED(index);
    actualizarEtiquetas();
}

void cframe::on_pushButton_2_clicked()
{
    std::string opcion = "";

    QMessageBox msgBox;
    msgBox.setText("Por favor, seleccione una opción:");

    QPushButton *opcion6 = msgBox.addButton("Salir", QMessageBox::ActionRole);
    QPushButton *opcion5 = msgBox.addButton("Ejercicio #4", QMessageBox::ActionRole);
    QPushButton *opcion4 = msgBox.addButton("Ejercicio #3", QMessageBox::ActionRole);
    QPushButton *opcion3 = msgBox.addButton("Ejercicio #2", QMessageBox::ActionRole);
    QPushButton *opcion2 = msgBox.addButton("Ejercicio #1", QMessageBox::ActionRole);

    msgBox.exec();

    if (msgBox.clickedButton() == opcion2) {
        ui->tabWidget->setCurrentIndex(1);
    } else if (msgBox.clickedButton() == opcion3) {
        ui->tabWidget->setCurrentIndex(2);
    } else if (msgBox.clickedButton() == opcion4) {
        ui->tabWidget->setCurrentIndex(3);
    } else if (msgBox.clickedButton() == opcion5) {
        ui->tabWidget->setCurrentIndex(4);
    } else if (msgBox.clickedButton() == opcion6) {
        this->close();
    }
}

//EJERCICIO #1
void cframe::on_pushButton_clicked()
{
    QString descripcion = ui->TE_Descripcion->toPlainText();
    QDate fecha = ui->DateEdit->date();
    QString tipo = ui->tareaTipo->currentText();

    Tarea *tarea = nullptr;
    if (tipo == "Diaria") {
        tarea = new TareaDiaria(descripcion, fecha);
    } else if (tipo == "Semanal") {
        tarea = new TareaSemanal(descripcion, fecha);
    }

    if (tarea) {
        QListWidgetItem *item = new QListWidgetItem(QString("%1: %2 - %3")
                                                        .arg(tarea->tipo())
                                                        .arg(tarea->descripcion())
                                                        .arg(tarea->fecha().toString()));
        ui->taskList->addItem(item);

        ui->TE_Descripcion->clear();
        ui->DateEdit->clear();
        ui->tareaTipo->setCurrentIndex(0);

        delete tarea;

        QMessageBox::information(this, "Agregar Tarea", "La tarea ha sido agregada exitosamente.");
    }
}

//EJERCICIO #2
void cframe::on_pushButton_3_clicked()
{
    QString tipoFigura = ui->figuraTipo->currentText();
    bool ok;

    canvas->clearFiguras();

    if (tipoFigura == "Círculo") {
        int radio = QInputDialog::getInt(this, "Agregar Círculo", "Radio del círculo:", 50, 1, 1000, 1, &ok);
        if (ok) {
            int canvasWidth = canvas->width();
            int canvasHeight = canvas->height();

            QPoint centro(canvasWidth / 2, canvasHeight / 2);
            Circulo *circulo = new Circulo(centro, radio);
            canvas->addFigura(circulo);
        }
    } else if (tipoFigura == "Rectángulo") {
        int ancho = QInputDialog::getInt(this, "Agregar Rectángulo", "Ancho del rectángulo:", 100, 1, 1000, 1, &ok);
        if (ok) {
            int alto = QInputDialog::getInt(this, "Agregar Rectángulo", "Alto del rectángulo:", 100, 1, 1000, 1, &ok);
            if (ok) {
                int canvasWidth = canvas->width();
                int canvasHeight = canvas->height();

                int x = (canvasWidth - ancho) / 2;
                int y = (canvasHeight - alto) / 2;

                QRect rect(QPoint(x, y), QSize(ancho, alto));
                Rectangulo *rectangulo = new Rectangulo(rect);
                canvas->addFigura(rectangulo);
            }
        }
    } else if (tipoFigura == "Triángulo") {
        int tamaño = QInputDialog::getInt(this, "Agregar Triángulo", "Tamaño del triángulo (base):", 100, 1, 1000, 1, &ok);
        if (ok) {
            int canvasWidth = canvas->width();
            int canvasHeight = canvas->height();

            int halfSize = tamaño / 2;
            QPoint p1(canvasWidth / 2, canvasHeight / 2 - tamaño);
            QPoint p2(canvasWidth / 2 - halfSize, canvasHeight / 2);
            QPoint p3(canvasWidth / 2 + halfSize, canvasHeight / 2);

            QPolygon polygon;
            polygon << p1 << p2 << p3;

            Triangulo *triangulo = new Triangulo(polygon);
            canvas->addFigura(triangulo);
        }
    }
}

//EJERCICIO #3
void cframe::on_negritaButton_clicked()
{
    QTextCursor cursor = ui->TE_Editor->textCursor();
    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    cursor.mergeCharFormat(format);
    ui->TE_Editor->mergeCurrentCharFormat(format);
}

void cframe::on_cursivaButton_clicked()
{
    QTextCursor cursor = ui->TE_Editor->textCursor();
    QTextCharFormat format;
    format.setFontItalic(true);
    cursor.mergeCharFormat(format);
    ui->TE_Editor->mergeCurrentCharFormat(format);
}

void cframe::on_subrayadoButton_clicked()
{
    QTextCursor cursor = ui->TE_Editor->textCursor();
    QTextCharFormat format;
    format.setFontUnderline(true);
    cursor.mergeCharFormat(format);
    ui->TE_Editor->mergeCurrentCharFormat(format);
}

void cframe::on_normalButton_clicked()
{
    ui->negritaButton->setEnabled(false);
    ui->cursivaButton->setEnabled(false);
    ui->subrayadoButton->setEnabled(false);

    QTextCursor cursor = ui->TE_Editor->textCursor();

    if (cursor.hasSelection()) {
        QTextCharFormat normalFormat;
        normalFormat.setFontWeight(QFont::Normal);
        normalFormat.setFontItalic(false);
        normalFormat.setFontUnderline(false);

        cursor.setCharFormat(normalFormat);
        ui->TE_Editor->setTextCursor(cursor);
    }

    ui->negritaButton->setEnabled(true);
    ui->cursivaButton->setEnabled(true);
    ui->subrayadoButton->setEnabled(true);
}

//EJERCICIO #4
void cframe::actualizarEtiquetas() {
    QString tipo = ui->tipoProducto->currentText();
    if (tipo == "Electrónico") {
        ui->LabelP->setText("Marca:");
        ui->LabelS->setText("Garantía (años):");
    } else if (tipo == "Ropa") {
        ui->LabelP->setText("Talla:");
        ui->LabelS->setText("Material:");
    } else if (tipo == "Alimento") {
        ui->LabelP->setText("Fecha de Caducidad:");
        ui->LabelS->setText("Refrigerado:");
    }
}

void cframe::on_agregarBoton_clicked()
{
    QString tipo = ui->tipoProducto->currentText();
    QString nombre = ui->LE_NombreProducto->text();
    double precio = ui->LE_PrecioProducto->value();
    QString adicional = ui->LE_Adicional->text();
    QString adicional2 = ui->LE_Adicional2->text();

    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(nombre));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(precio)));

    QString detalles;
    if (tipo == "Electrónico") {
        detalles = QString("Marca: %1, Garantía: %2").arg(adicional).arg(adicional2);
    } else if (tipo == "Ropa") {
        detalles = QString("Talla: %1, Material: %2").arg(adicional).arg(adicional2);
    } else if (tipo == "Alimento") {
        detalles = QString("Fecha de Caducidad: %1, Refrigerado: %2").arg(adicional).arg(adicional2);
    }

    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(detalles));

    QMessageBox::information(this, "Agregar Producto", "El producto ha sido agregado exitosamente.");
}

void cframe::on_eliminarBoton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();

    if (selectedItems.isEmpty()) {
        return;
    }

    int row = selectedItems.first()->row();
    QString nombreProducto = ui->LE_NombreProducto->text();
    QString nombreEnTabla = ui->tableWidget->item(row, 0)->text();

    if (nombreProducto != nombreEnTabla) {
        return;
    }

    ui->tableWidget->removeRow(row);
}

void cframe::on_modificarBoton_clicked()
{
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();

    if (selectedItems.isEmpty()) {
        qDebug() << "No hay filas seleccionadas para modificar.";
        return;
    }

    int row = selectedItems.first()->row();
    QString nombreProducto = ui->LE_NombreProducto->text();
    double precio = ui->LE_PrecioProducto->value();
    QString tipo = ui->tipoProducto->currentText();
    QString adicional = ui->LE_Adicional->text();
    QString adicional2 = ui->LE_Adicional2->text();

    // Verifica que el nombre del producto coincida con el de la fila seleccionada
    QString nombreEnTabla = ui->tableWidget->item(row, 0)->text();
    if (nombreProducto != nombreEnTabla) {
        qDebug() << "El nombre del producto no coincide.";
        return;
    }

    // Actualiza el nombre y el precio
    ui->tableWidget->item(row, 0)->setText(nombreProducto);
    ui->tableWidget->item(row, 1)->setText(QString::number(precio));

    // Actualiza los detalles dependiendo del tipo
    QString detalles;
    if (tipo == "Electrónico") {
        detalles = QString("Marca: %1, Garantía: %2").arg(adicional).arg(adicional2);
    } else if (tipo == "Ropa") {
        detalles = QString("Talla: %1, Material: %2").arg(adicional).arg(adicional2);
    } else if (tipo == "Alimento") {
        detalles = QString("Fecha de Caducidad: %1, Refrigerado: %2").arg(adicional).arg(adicional2);
    }

    ui->tableWidget->item(row, 2)->setText(detalles);
}
