AddObject  = {
	ObjectName = '',
	ParameterKey = ''
}

AddObjectResponse = {
	InstanceNumber = 0,
	Status = 0
}

DeleteObject = {
	ObjectName = "",
	ParameterKey = ""
}
DeleteObjectResponse = {
	Status = 0
}

Download = {
	CommandKey = "",
	FileType = "",
	URL = "",
	Username = "",
	Password = "",
	FileSize = "",
	TargetFileName = "",
	DelaySeconds = "",
	SuccessURL = "",
	FailureURL
}

DownloadResponse = {
	Status = "",
	StartTime = "",
	CompleteTime = ""
}

FactoryReset = { }
FactoryResetResponse = {}

GetRPCMethods = {}
GetRPCMethodsResponse = {
	_name = 'MethodList',
	string = {
		
	}
}

Reboot = {
	CommandKey = ''
}

RebootResponse = {}

function luacwmp(len, soap)

end

function Inform()
return [[
<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope
 xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/"
 xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/"
 xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
 xmlns:xsd="http://www.w3.org/2001/XMLSchema"
 xmlns:cwmp="urn:dslforum-org:cwmp-1-2">
 <SOAP-ENV:Header>
  <cwmp:HoldRequests SOAP-ENV:mustUnderstand=""></cwmp:HoldRequests>
  <cwmp:ID SOAP-ENV:mustUnderstand=""></cwmp:ID>
 </SOAP-ENV:Header>
 <SOAP-ENV:Body>
   <cwmp:Inform>
    <DeviceId>
     <Manufacturer></Manufacturer>
     <OUI></OUI>
     <ProductClass></ProductClass>
     <SerialNumber></SerialNumber>
    </DeviceId>
    <Event SOAP-ENC:arrayType="cwmp:EventStruct[1]">
     <EventStruct>
      <EventCode></EventCode>
      <CommandKey></CommandKey>
     </EventStruct>
    </Event>
    <MaxEnvelopes>0</MaxEnvelopes>
    <CurrentTime></CurrentTime>
    <RetryCount>0</RetryCount>
    <ParameterList SOAP-ENC:arrayType="cwmp:ParameterValueStruct[1]">
     <ParameterValueStruct>
      <Name></Name>
      <Value></Value>
     </ParameterValueStruct>
    </ParameterList>
   </cwmp:Inform>

 </SOAP-ENV:Body>
</SOAP-ENV:Envelope>
]]
end
