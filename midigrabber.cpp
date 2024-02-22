#include <iostream>
#include <rtmidi/RtMidi.h>

void listMIDIDevices() {
    RtMidiIn midiin;
    unsigned int portCount = midiin.getPortCount();
    std::cout << "- MIDIGrabber by faithvoid -" << std::endl;
    std::cout << "- Grabs easy-to-parse MIDI data from your controller! -" << std::endl;
    std::cout << "Available MIDI devices:" << std::endl;
    for (unsigned int i = 0; i < portCount; ++i) {
        std::string portName = midiin.getPortName(i);
        std::cout << i << ": " << portName << std::endl;
    }
}

void MIDIReadCallback(double timeStamp, std::vector<unsigned char> *message, void *userData) {
    int status = message->at(0) & 0xF0; // Mask out channel
    int channel = message->at(0) & 0x0F;

    if (status == 0x80 || status == 0x90) { // Note off or Note on
        std::cout << "Channel: " << channel + 1 << ", Note: " << static_cast<int>(message->at(1)) << ", Velocity: " << static_cast<int>(message->at(2)) << std::endl;
    } else if (status == 0xB0) { // Control Change
        std::cout << "Channel: " << channel + 1 << ", Control Change (CC): " << static_cast<int>(message->at(1)) << ", Value: " << static_cast<int>(message->at(2)) << std::endl;
    }
}

int main() {
    listMIDIDevices();

    std::cout << "Enter the number of the MIDI device you want to use: ";
    unsigned int selectedIndex;
    std::cin >> selectedIndex;

    RtMidiIn midiin;
    if (selectedIndex < midiin.getPortCount()) {
        midiin.openPort(selectedIndex);
        midiin.setCallback(MIDIReadCallback);
        std::cout << "Reading MIDI messages from device: " << selectedIndex << std::endl;
    } else {
        std::cout << "Invalid device number!" << std::endl;
        return 1;
    }

    char input;
    std::cout << "Press 'q' to quit." << std::endl;
    std::cin >> input;

    return 0;
}
