<form action="index.lp" method="post">
<table width="50%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">Tool</label></td>
		<td>
			<input type="radio" id="dhcp_d" name="dhcp_status" value="1" checked /><label for="dhcp_d">Ping</label>
			<input type="radio" id="dhcp_e" name="dhcp_status" value="2"  /><label for="dhcp_e">Traceroute</label>
		</td>
	</tr>
	<tr>
		<td><label for="password">IP Address/DomainName</label></td>
		<td><input type="text" value="192.168.1.100"/></td>
	</tr>
	<tr>
		<td><label for="password">Ping Count</label></td>
		<td><input type="text" value="192.168.1.199"/> (1-50)</td>
	</tr>
	<tr>
		<td><label for="password">Ping Packet Size</label></td>
		<td><input type="text" value="120" style="width: 50px"/>(4-1472 Bytes)</td>
	</tr>
	<tr>
		<td><label for="password">Ping Timeout</label></td>
		<td><input type="text" value="20" style="width: 50px"/>(100-2000 Milliseconds)</td>
	</tr>
	<tr>
		<td><label for="password">Traceroute Max TTL</label></td>
		<td><input type="text" value="12"/>(1-30)</td>
	</tr>
	<tr>
		<td>&nbsp;</td>			
		<td><button id="save-btn">Start</button></td>
	</tr>
	<tr>
		<td colspan="2"><fieldset style="height:180px"><legend><h2>Results</h2></legend></fieldset></td><td>&nbsp;</td>
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