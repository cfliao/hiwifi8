@{
	uci = require("uci")
	x = uci:cursor()
	ut= uci:cursor(nil, "/var/state")
		
	proto = x:get("network", "wan", "proto")
	username= x:get("network", "wan", "username")
	password= x:get("network", "wan", "password")

	ipaddr = ut:get("network", "wan", "ipaddr")
	gateway= ut:get("network", "wan", "gateway")
}

<form action="index.lp" method="post">
<table width="80%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">Connection Type</label></td>
		<td>
			<select name="proto" default="@proto">
				<option value="dhcp">Dynamic IP</option>
				<option value="static">Static IP</option>
				<option value="pppoe">PPPoE</option>
				<option value="pptp">PPTP</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">PPPoE Connection</label></td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;User Name</label></td>
		<td><input type="text" name="username" value="@username" /></td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;Password</label></td>
		<td><input type="password" name="password" value="@password"/></td>
	</tr>
	<tr>
		<td><label for="password">Default Gateway</label></td>
		<td><input type="text" name="gateway" value="@gateway" /></td>
	</tr>
	<tr>
		<td><label for="password">Connection Mode</label></td>
		<td>
			<div id="conn_mode">
			<input type="radio" id="conn_mode1" name="pppoe_mode" value="1" /><label for="conn_mode1">On Demand</label>
			<input type="radio" id="conn_mode2" name="pppoe_mode" value="2" /><label for="conn_mode2">Automatically</label>
			<input type="radio" id="conn_mode3" name="pppoe_mode" value="3" /><label for="conn_mode3">Time-based</label>
			<input type="radio" id="conn_mode4" name="pppoe_mode" value="4" checked /><label for="conn_mode4">Manually</label>
			</div>
		</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;Max Idle Time</label></td>
		<td><input type="text" name="maxidle" value="" style="width: 80px"/>minutes (0 means remain active at all times.)</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;Period of Time</label></td>
		<td>
			<select id="begin_h" name="begin_h">
			</select>:
			<select  id="begin_m" name="begin_m">
			</select>(HH:MM) to
			<select id="end_h" name="end_h">
			</select>:
			<select  id="end_m" name="end_m">
			</select>(HH:MM)
		</td>
	</tr>
	<tr>
		<td colspan="2">&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;</label></td>
		<td>
			<button>Connect Now</button>
			<button>Disconnect</button>
		</td>
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
	for(var i =0; i<=24; i++)
		$("#begin_h,#end_h").append("<option value='" + i + "'>" + i + "</option>");
	for(var i =0; i<=59; i+=5)
		$("#begin_m,#end_m").append("<option value='" + i + "'>" + i + "</option>");
});
</script>