#include "Tarea.h"

Tarea::Tarea(const QString& descripcion, const QDate& fecha)
    : m_descripcion(descripcion), m_fecha(fecha) {}

QString Tarea::descripcion() const {
    return m_descripcion;
}

QDate Tarea::fecha() const {
    return m_fecha;
}
