@{
	require("uci")

	u = uci.cursor()
	t = uci.cursor(nil, "/var/state")
		
	ipaddr=u:get("network", "lan", "ipaddr")
	if ipaddr == nil then
		ipaddr = t:get("network", "lan", "ipaddr")
		netmask = t:get("network", "lan", "netmask")
	else
		netmask = u:get("network", "lan", "netmask")
	end
	
	f = io.open("/sys/devices/platform/ag71xx.1/net/eth0/address", "r")
	if f ~= nil then
		macaddr = f:read("*all")
		f:close()
	end
}
<form action="index.lp" method="post" id='lan_form'>
<table width="50%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="mac">MAC Address</label></td>
		<td><span id='mac'>@macaddr</span></td>
	</tr>
	<tr>
		<td><label for="ipaddr">IP Address</label></td>
		<td><input type="text" name='ipaddr' value="@ipaddr"/></td>
	</tr>
	<tr>
		<td><label for="netmask">Subnet Mask</label></td>
		<td><input type="text" name='netmask' value="@netmask"/></td>
	</tr>
	<tr>
		<td colspan="2"><hr/></td>
	</tr>
	<tr>
		<td>&nbsp;</td>
		<td><button id="save-btn">Save</button></td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
</table>
</form>
<script type="text/javascript">
$(function(){
});
</script>
