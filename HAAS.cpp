// ©2024 JDSherbert. All Rights Reserved.

#include "AudioDelay.h"

HAAS::HAAS(int delayInMilliseconds) 
: delayInSamples(delayInMilliseconds * sampleRate / 1000)
, writeIndex(0) 
{
    delayBuffer.resize(delayInSamples, 0);
}

float HAAS::ProcessSample(float input, bool isLeftChannel);
{
    float delayedSample = delayBuffer[writeIndex];
    delayBuffer[writeIndex] = input;

    writeIndex = (writeIndex + 1) % delayBuffer.size();

    // Pan the delayed signal based on the channel
    float pan = isLeftChannel ? 0.8 : 0.2;  // Adjust panning values
    return (1 - pan) * input + pan * delayedSample;
}
