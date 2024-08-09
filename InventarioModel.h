#ifndef INVENTARIOMODEL_H
#define INVENTARIOMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "Producto.h"

class InventarioModel : public QAbstractTableModel {
    Q_OBJECT

public:
    InventarioModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void agregarProducto(Producto *producto);
    void eliminarProducto(int row);
    void modificarProducto(int row, Producto *producto);

private:
    QList<Producto*> productos;
};

#endif // INVENTARIOMODEL_H
