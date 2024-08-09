#include "TareaDiaria.h"

TareaDiaria::TareaDiaria(const QString& descripcion, const QDate& fecha)
    : Tarea(descripcion, fecha) {}

QString TareaDiaria::tipo() const {
    return "Diaria";
}
