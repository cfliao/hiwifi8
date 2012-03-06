<!--#include virtual="layout/top.shtml" -->
<form action="" method="">
<table width="80%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">Connection Type</label></td>
		<td>
			<select name="conn_type">
				<option>Dynamic IP</option>
				<option>Static IP</option>
				<option>PPPoE</option>
				<option>PPTP</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">PPPoE Connection</label></td>
		<td>&nbsp;</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;User Name</label></td>
		<td><input type="text" value="user123@adsl" /></td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;Password</label></td>
		<td><input type="password" value="1234567"/></td>
	</tr>
	<tr>
		<td><label for="password">Default Gateway</label></td>
		<td><input type="text" value="192.168.1.1" /></td>
	</tr>
	<tr>
		<td><label for="password">Connection Mode</label></td>
		<td>
			<div id="conn_mode">
			<input type="radio" id="conn_mode1" name="dhcp_status" value="1" /><label for="conn_mode1">On Demand</label>
			<input type="radio" id="conn_mode2" name="dhcp_status" value="2" /><label for="conn_mode2">Automatically</label>
			<input type="radio" id="conn_mode3" name="dhcp_status" value="3" /><label for="conn_mode3">Time-based</label>
			<input type="radio" id="conn_mode4" name="dhcp_status" value="4" checked /><label for="conn_mode4">Manually</label>
			</div>
		</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;Max Idle Time</label></td>
		<td><input type="text" value="" style="width: 80px"/>minutes (0 means remain active at all times.)</td>
	</tr>
	<tr>
		<td><label for="password">&nbsp;&nbsp;&nbsp;&nbsp;Period of Time</label></td>
		<td>
			<select id="begin_h" />
			</select>:
			<select  id="begin_m">
			</select>(HH:MM) to
			<select id="end_h">
			</select>:
			<select  id="end_m">
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
<!--#include virtual="layout/bottom.shtml" -->