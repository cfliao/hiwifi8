@{
	require("uci")
	u = uci.cursor()
	t = uci.cursor(nil, "/var/state")

	ipaddr=u:get("network", "lan", "ipaddr")
	if ipaddr == nil then
		ipaddr = t:get("network", "lan", "ipaddr")
	else
		netmask = u:get("network", "lan", "netmask")
	end
	network = ipaddr
	
	start = tostring(network) .. u:get("dhcp", "lan", "start")
	limit = tostring(network) .. u:get("dhcp", "lan", "limit")
	leasetime= u:get("dhcp", "lan", "leasetime")
}
<form action="index.lp" method="post" id="dhcp_form">
<table width="50%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">DHCP Server</label></td>
		<td>
			<div id="dhcp_p">
			<input type="radio" id="dhcp_d" name="status" value="1" checked /><label for="dhcp_d">Disable</label>
			<input type="radio" id="dhcp_e" name="status" value="2"  /><label for="dhcp_e">Enable</label>
			</div>
		</td>
	</tr>
	<tr>
		<td><label for="start">Start IP Address</label></td>
		<td><input type="text" name="start" id="start" value="@start"/></td>
	</tr>
	<tr>
		<td><label for="limit">End IP Address</label></td>
		<td><input type="text" name="limit" id="limit" value="@limit"/></td>
	</tr>
	<tr>
		<td><label for="leasetime">Address Lease Time</label></td>
		<td><input type="text" name="leasetime" id="leasetime" value="@leasetime"/>Hours</td>
	</tr>
	<tr>
		<td><label for="password">Default Gateway</label></td>
		<td><input type="text" name="gateway" id="gateway"/></td>
	</tr>
	<tr>
		<td><label for="password">Default Domain</label></td>
		<td><input type="text" name="domain" id="domain"/>(optional)</td>
	</tr>
	<tr>
		<td><label for="password">Primary DNS</label></td>
		<td><input type="text" name="dns1"/>(optional)</td>
	</tr>
	<tr>
		<td><label for="password">Secondary DNS</label></td>
		<td><input type="text" name="dns2"/>(optional)</td>
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
	$('#dhcp_p').buttonset();
	
	$.ajax({
		url:"/config.xml",
		success:function(xml){
			var v = $(xml).find("configuration network interface lan ipaddr").text().split('.');
			var ipaddr = v[0] + '.' + v[1] + '.' + v[2] + '.';

			$(xml).find("configuration>dhcp").each(function(){
				var start = $(this).find('dhcp>lan>start').text();
				var limit = $(this).find('dhcp>lan>limit').text();
				var leasetime = $(this).find('dhcp>lan>leasetime').text();
				
				$('#start').val(ipaddr + start);
				$('#limit').val(ipaddr + limit);
				$('#leasetime').val(parseInt(leasetime));
			});
        }
    });	

});
</script>