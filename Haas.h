// ©2024 JDSherbert. All Rights Reserved.

#pragma once

#include <iostream>
#include <vector>

class Haas
{
public:
    Haas(int delayInMilliseconds);

    float ProcessSample(float input, bool isLeftChannel);

private:
    static constexpr int sampleRate = 44100;  // Adjust based on your sample rate
    std::vector<float> delayBuffer;
    size_t writeIndex;
};
