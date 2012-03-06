<!--#include virtual="layout/top.shtml" -->
<table width="50%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">Time Server</label></td>
		<td>
			<div id="time_p">
			<input type="radio" id="dhcp_d" name="dhcp_status" value="1" checked /><label for="dhcp_d">Disable</label>
			<input type="radio" id="dhcp_e" name="dhcp_status" value="2"  /><label for="dhcp_e">Enable</label>
			</div>
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
<script type="text/javascript">
$(function(){
	$('#time_p').buttonset();
});
</script>
<!--#include virtual="layout/bottom.shtml" -->