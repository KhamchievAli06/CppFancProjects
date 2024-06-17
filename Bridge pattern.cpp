#include <iostream>
using namespace std;




class Device {

public:
	virtual bool isEnabeled() = 0;

	virtual void enable() = 0;

	virtual void disable() = 0;

	virtual int getVolume() = 0;

	virtual void setVolume(int percent) = 0;

	virtual int getChannel() = 0;

	virtual void setChannel(int channel) = 0;

};

class Radio :public Device {
	bool enabled;
	int chanel;
	int volume;
public:

	bool isEnabeled() {
		return enabled;
	}

	void enable() {
		enabled = true;
	}

	void disable() {
		enabled = false;
	}

	int getVolume() {
		if (enabled == true) {
			return volume;
		}
		else {
			cout << "radio is not enabled" << endl;
		}
	}

	void setVolume(int percent) {
		if (enabled == true) {
			if (percent >= 0 && percent <= 100) {
				volume = percent;
			}
			else {
				cout << "incorrect volume" << endl;
			}
		}
		else {
			cout << "radio is not enabled" << endl;
		}
	}

	void setChannel(int channel) {
		if (enabled == true) {
			if (channel > 0) {
				chanel = channel;
			}
			else {
				cout << "incorrect channel" << endl;
			}
		}
		else {
			cout << "radio is not enabled" << endl;
		}
	}

	int getChannel() {
		if (enabled == true) {
			return chanel;
		}
		else {
			cout << "radio is not enabled" << endl;
		}
	}


};

class TV :public Device {
private:
	bool enabled;
	int chanel;
	int volume;
public:


	bool isEnabeled() {
		return enabled;
	}

	void enable() {
		enabled = true;
	}

	void disable() {
		enabled = false;
	}

	int getVolume() {
		if (enabled == true) {
			return volume;
		}
		else {
			cout << "TV  is not enabled" << endl;
		}
	}

	void setVolume(int percent) {
		if (enabled == true) {
			if (percent >= 0 && percent <= 100) {
				volume = percent;
			}
			else {
				cout << "incorrect volume" << endl;
			}
		}
		else {
			cout << "TV  is not enabled" << endl;
		}
	}

	void setChannel(int channel) {
		if (enabled == true) {
			if (channel > 0) {
				chanel = channel;
			}
			else {
				cout << "incorrect channel" << endl;
			}
		}
		else {
			cout << "TV  is not enabled" << endl;
		}
	}

	int getChannel() {
		if (enabled == true) {
			return chanel;
		}
		else {
			cout << "TV  is not enabled" << endl;
		}
	}
};


class Remote {
private:
	Device* device;
public:
	Remote(Device* device) : device(device) {}
	void togglePower() {
		if (device->isEnabeled() == true) {
			device->disable();
			cout << "Device  is disabled" << endl;
		}
		else {
			device->enable();
			cout << " Power is toggeled" << endl;

		}
	}

	void volumeDown() {
		if (device->getVolume() > 0) {
			device->setVolume(device->getVolume() - 1);
			cout << " Volume is downed" << endl;

		}
		else {
			cout << "Volume is minimized" << endl;
		}
	}

	void volumeUP() {
		device->setVolume(device->getVolume() + 1);
		cout << " Volume is upped" << endl;
	}

	void channelDown() {
		if (device->getChannel() > 0) {
			device->setChannel(device->getChannel() - 1);
			cout << " Channel is downed" << endl;
		}
		else {
			cout << "It`s a first channel" << endl;
		}
	}

	void channelUp() {
		device->setChannel(device->getChannel() + 1);
		cout << " Channel is upped" << endl;
	}

};



int main()
{


	TV* tv1 = new TV();
	Remote device(tv1);

	tv1->enable();
	device.togglePower();



}
