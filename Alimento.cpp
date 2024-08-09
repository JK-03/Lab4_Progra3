#include "Alimento.h"

Alimento::Alimento(const QString& nombre, double precio, const QString& fechaCaducidad, const QString& refrigerado)
    : Producto(nombre, precio), fechaCaducidad(fechaCaducidad), refrigerado(refrigerado) { }

QString Alimento::getDetalles() const {
    return QString("Nombre: %1\nPrecio: %2\nFecha de Caducidad: %3\nRefrigerado: %4")
        .arg(getNombre())
        .arg(getPrecio())
        .arg(fechaCaducidad)
        .arg(refrigerado);
}
