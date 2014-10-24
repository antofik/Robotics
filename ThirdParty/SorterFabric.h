#ifndef SORTER_FABRIC_H
#define SORTER_FABRIC_H

#include "colordetector.h"
#include "cpucksorter.h"
#include "PuckMover/servopuckmover.h"

CPuckSorter* sorterFabric(const SColorDetectorParams& CDParams, const SServoPuckMoverParams& moverParams, int ColorDetector_device);

#endif // SORTER_FABRIC_H
