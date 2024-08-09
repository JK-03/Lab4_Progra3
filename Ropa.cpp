#include "Ropa.h"

Ropa::Ropa(const QString& nombre, double precio, const QString& talla, const QString& material)
    : Producto(nombre, precio), talla(talla), material(material) {}

QString Ropa::getDetalles() const {
    return QString("Talla: %1, Material: %2").arg(talla).arg(material);
}
