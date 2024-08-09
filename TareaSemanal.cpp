#include "TareaSemanal.h"

TareaSemanal::TareaSemanal(const QString& descripcion, const QDate& fecha)
    : Tarea(descripcion, fecha) {}

QString TareaSemanal::tipo() const {
    return "Semanal";
}
