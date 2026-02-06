#ifndef EMG_PROCESSING_H
#define EMG_PROCESSING_H

#include <stdio.h>
#include <stdint.h>

typedef struct {
    float rectified;
    float envelope;
} ProcessedEMG;

float rectifier(float input);
float envelopeDetectorLPF(float input, float prevEnvelope);
ProcessedEMG processEMGSample(float sample);

#endif 