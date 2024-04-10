//
// Created by talleux on 4/10/24.
//

#include "Inputs.hpp"

#include <utility>
#include <algorithm>
#include <array>
#include <memory>
#include <stdexcept>

bool exec(const char* cmd, std::string &result)
{
    std::array<char, 128> buffer{};
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        return true;
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return false;
}

Inputs::Inputs(std::string deviceName, int numDevice, int numChannels, int sampleRate, int bufferSize)
{
    setSampleSpec(sampleRate, numChannels);
    _deviceName = std::move(deviceName);
    _numDevice = numDevice;
    _bufferSize = bufferSize;

    std::string nameToShowInput = _deviceName + "_Virtual_Input";
    std::replace(nameToShowInput.begin(), nameToShowInput.end(), ' ', '_');

    bool error;
    std::string result;

    std::string command = "pactl load-module module-null-sink sink_name=" + nameToShowInput + "_" + std::to_string(_numDevice) + " sink_properties=device.description=" + nameToShowInput + "_" + std::to_string(_numDevice);

    error = exec(command.c_str(), result);

    if (error) {
        fprintf(stderr, "Échec de l'initialisation de l'entrée virtuelle %d\n", _numDevice);
        _isReady = false;
        return;
    }

    _id = (int)strtol(result.c_str(), nullptr, 10);

    std::string nameToShowCapture = _deviceName + "_Capture_Device";

    _simple = pa_simple_new(nullptr, (nameToShowCapture + "_" + std::to_string(_numDevice)).c_str(), PA_STREAM_RECORD, nullptr, (nameToShowCapture + "_" + std::to_string(_numDevice)).c_str(), &_sampleSpec, nullptr, nullptr, nullptr);
    if (!_simple) {
        fprintf(stderr, "Échec de l'initialisation de l'entrée virtuelle %d\n", _numDevice);
        _isReady = false;
        return;
    }

    _isReady = true;
}

Inputs::~Inputs()
{
    int error;

    std::string command = "pactl unload-module " + std::to_string(_id);

    error = system(command.c_str());
    if (error != 0) {
        fprintf(stderr, "Échec de la suppression de l'entrée virtuelle %d\n", _numDevice);
        pa_simple_free(_simple);
        _isReady = false;
        return;
    }

    pa_simple_free(_simple);

    _isReady = false;
}

void Inputs::setSampleSpec(int sampleRate, int numChannels)
{
    _sampleSpec.rate = sampleRate;
    _sampleSpec.channels = numChannels;
    _sampleSpec.format = PA_SAMPLE_S16LE;
}


