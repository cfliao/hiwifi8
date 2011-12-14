
#include "soapH.h"

struct cwmp__DeviceIdStruct deviceid = 
{

	.Manufacturer = "HiWiFi",
	.OUI = "b0487a",
	.ProductClass = "Internet Gateway",
	.SerialNumber = "b0:48:7a:2e:3d:34"
};

struct cwmp__DeviceIdStruct* cwmp_getDeviceId()
{
	return &deviceid;
}

struct EventList* cwmp_getEventList()
{
	static struct EventList eventlist;
	static struct cwmp__EventStruct event[1] = 
	{
		{
			.EventCode = "0 BOOTSTRAP",
			.CommandKey = NULL
		}
	};

	eventlist.__size = 1;
	eventlist.__ptrEventStruct = malloc(sizeof(struct cwmp__EventStruct*)*1);
	eventlist.__ptrEventStruct[0] = &event[0];

	return &eventlist;
}

struct ParameterValueList paramList;

struct cwmp__ParameterValueStruct paramValue[] = 
{
	{
		.Name = "Device.DeviceInfo.HardwareVersion",
		.Value= "version 1"
	},

	{
		.Name = "Device.DeviceInfo.SoftwareVersion",
		.Value= "version 3.0"
	}
};

struct ParameterValueList * cwmp_get_ParameterValueList()
{
	paramList.__size = 2;

	paramList.__ptrParameterValueStruct = malloc(
		sizeof(struct cwmp__ParameterValueStruct*)* 2);

	paramList.__ptrParameterValueStruct[0] = &paramValue[0];
	paramList.__ptrParameterValueStruct[1] = &paramValue[1];
		
	return &paramList;

}

