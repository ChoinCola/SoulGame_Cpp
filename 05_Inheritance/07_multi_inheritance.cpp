#include <iostream>
// ���߻�� �� ���� �̾߱�
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

class USBNetworkDevice : public USBDevice, public NetworkDevice // ��ӹ޴°� �� �ΰ����� ���߻���� �Ѵ�.
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