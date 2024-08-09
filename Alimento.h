#ifndef ALIMENTO_H
#define ALIMENTO_H

#include "Producto.h"

class Alimento : public Producto {
public:
    Alimento(const QString& nombre, double precio, const QString& fechaCaducidad, const QString& refrigerado);

    QString getDetalles() const override;

private:
    QString fechaCaducidad;
    QString refrigerado;
};

#endif // ALIMENTO_H
