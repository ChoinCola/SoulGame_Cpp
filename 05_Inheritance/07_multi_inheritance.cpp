#include <iostream>
// 이중상속 에 대한 이야기
using namespace std;

class USBDevice
{
	int id;

public:
	USBDevice() = default;

	USBDevice(int id) : id(id) {}

	auto GetId() const { return id; }
	void PlugAndPlay() {}
};

class NetworkDevice
{
	int id;

public:
	NetworkDevice() = default;

	NetworkDevice(int id) : id(id) {}

	auto GetId() const { return id; }
	void Networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice // 상속받는것 이 두가지로 이중상속을 한다.
{
public:
	USBNetworkDevice(int usbId, int netId)
		: USBDevice(usbId), NetworkDevice(netId)
	{}

	USBNetworkDevice(int id)
		: USBDevice(id), NetworkDevice(id)
	{}

};

int main()
{
	USBNetworkDevice device(1, 2);

	device.PlugAndPlay();
	device.Networking();

	device.USBDevice::GetId();
	device.NetworkDevice::GetId();

	return 0;
}