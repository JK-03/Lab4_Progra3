#include "InventarioModel.h"
#include <QDebug>

InventarioModel::InventarioModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int InventarioModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return productos.size();
}

int InventarioModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4; // Número de columnas en la tabla
}

QVariant InventarioModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    int row = index.row();
    int column = index.column();
    if (row < 0 || row >= productos.size()) {
        return QVariant();
    }

    Producto *producto = productos[row];

    switch (column) {
    case 0:
        return producto->getNombre();
    case 1:
        return producto->getPrecio();
    case 2:
        return producto->getDetalles();
    case 3:
        return "";
    default:
        return QVariant();
    }
}

QVariant InventarioModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0:
            return "Nombre";
        case 1:
            return "Precio";
        case 2:
            return "Detalles";
        case 3:
            return "Otro";
        default:
            return QVariant();
        }
    }
    return QVariant();
}

void InventarioModel::agregarProducto(Producto *producto)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    productos.append(producto);
    endInsertRows();
}

void InventarioModel::eliminarProducto(int row)
{
    if (row < 0 || row >= productos.size()) {
        return;
    }

    beginRemoveRows(QModelIndex(), row, row);
    delete productos.takeAt(row);
    endRemoveRows();
}

void InventarioModel::modificarProducto(int row, Producto *producto)
{
    if (row < 0 || row >= productos.size()) {
        return;
    }

    productos[row] = producto;
    emit dataChanged(index(row, 0), index(row, columnCount() - 1));
}
