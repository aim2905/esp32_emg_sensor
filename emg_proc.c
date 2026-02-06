#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include "emg_proc.h"

#define ALPHA 0.1f      

float rectifier(float input) {
    return fabsf(input);
}

float envelopeDetectorLPF(float input, float prevEnvelope) {
    float rectifiedInput = rectifier(input);
    return ALPHA * rectifiedInput + (1.0f - ALPHA) * prevEnvelope;
}

ProcessedEMG processEMGSample(float sample) {
    static float prevEnvelope = 0.0f;
    ProcessedEMG result;
    result.rectified = rectifier(sample);
    result.envelope = prevEnvelope = envelopeDetectorLPF(sample, prevEnvelope);
    
    return result;
}