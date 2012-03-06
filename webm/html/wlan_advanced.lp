<!--#include virtual="layout/top.shtml" -->
<form action="" method="post">
<table width="50%" border="0"  style="margin: 10px">
	<tr><td colspan="2">&nbsp;</td></tr>
	<tr>
		<td colspan="2"><span id="validateTips" /></td>
	</tr>
	<tr>
		<td><label for="name">DHCP Server</label></td>
		<td>
			<select>
				<option>高</option>
				<option>中</option>
				<option>低</option>
			</select>
		</td>
	</tr>
	<tr>
		<td><label for="password">Beacon时槽</label></td>
		<td><input type="text" value="100"/></td>
	</tr>
	<tr>
		<td><label for="password">RTS时槽</label></td>
		<td><input type="text" value="2346" /></td>
	</tr>
	<tr>
		<td><label for="password">分片阈值</label></td>
		<td><input type="text" value="2346" style="width: 50px"/>Minutes</td>
	</tr>
	<tr>
		<td><label for="password">DTIM阈值</label></td>
		<td><input type="text" value="1" /></td>
	</tr>
	<tr>
		<td><label for="password">WMM功能</label></td>
		<td>
			<input type="radio" id="wmm_e" name="wmm_e" value="1" checked /><label for="dhcp_d">开启</label>
			<input type="radio" id="wmm_d" name="wmm_d" value="2"  /><label for="dhcp_e">关闭</label>
		</td>
	</tr>
	<tr>
		<td><label for="password">Short GI</label></td>
		<td>
			<input type="radio" id="wmm_e" name="wmm_e" value="1" checked /><label for="dhcp_d">开启</label>
			<input type="radio" id="wmm_d" name="wmm_d" value="2"  /><label for="dhcp_e">关闭</label>		
		</td>
	</tr>
	<tr>
		<td><label for="password">AP隔离</label></td>
		<td>
			<input type="radio" id="wmm_e" name="wmm_e" value="1" checked /><label for="dhcp_d">开启</label>
			<input type="radio" id="wmm_d" name="wmm_d" value="2"  /><label for="dhcp_e">关闭</label>		
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

});
</script>
<!--#include virtual="layout/bottom.shtml" -->